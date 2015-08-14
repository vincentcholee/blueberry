#include "../include/drrobot_clinicrobot/drrobotsensormapbuild.hpp"

void DrRobotSensorMapBuilder::setDrRobotSensorMapBuilder()
{
    configed = false;
    setPosition = false;

    configedLaser = false;
    fadeOutStep = 3;
    fadeOutRate = 25;
    polarMapTH = 50;

    irUsed = true;
    usUsed = true;
    laserUsed = false;      //default without laser

    iDiffuseCount = 25;
    currentPos.setRobotPosition();
    prePos.setRobotPosition();;
    configData.setConfigData();

    laserConfigData.setLaserConfigData();


    sensorMap.setSensorMapData();
    detectWindowSize = cWinSize;  //0.8mdetectWindowSize

    //do nothing here, using Init() to config it
    for (int i = 0; i < MAPSIZE; i++)
        for (int j = 0; j < MAPSIZE; j++)
        {
            _Occ_Map[i][ j] = 0;
            _pre_Occ_Map[i][j] = 0;
        }
}

bool DrRobotSensorMapBuilder::PreSetPosition(RobotPosition robotPostion)
{
    setPosition = true;
    currentPos = robotPostion;
    prePos = robotPostion;
    return true;
}

bool DrRobotSensorMapBuilder::ConfigLaserSensor(LaserConfigData data)
{
    configedLaser = true;
    laserConfigData = data;
    if (laserConfigData.MaxDis > MAX_LASER_DIS)
    {
        laserConfigData.MaxDis = MAX_LASER_DIS;
        configedLaser = false;
    }
    if (laserConfigData.MinDis < MIN_LASER_DIS)
    {
        laserConfigData.MaxDis = MIN_LASER_DIS;
        configedLaser = false;
    }
    if (laserConfigData.LaserDataLen > MAX_LASER_DATA_LEN)
    {
        laserConfigData.LaserDataLen = MAX_LASER_DATA_LEN;
        configedLaser = false;

    }
    if (laserConfigData.StartStep < 0)
    {
        laserConfigData.StartStep = 0;
        configedLaser = false;
    }
    if (laserConfigData.EndStep > laserConfigData.LaserDataLen)
    {
        laserConfigData.EndStep = laserConfigData.LaserDataLen;
        configedLaser = false;
    }

    return configedLaser ;
}


bool DrRobotSensorMapBuilder::ConfigSensor(ConfigData data)
{
    configData = data;

    if ((configData.IrNum == 0) && (configData.UsNUm == 0))
    {
        configed = false;
        return false;
    }
    else if ((configData.IrNum > MAXIRNUM) || (configData.UsNUm > MAXUSNUM))
    {
        configed = false;
        return false;
    }
    else
    {
        configed = true;
        //config ir and uS
        for (int i = 0; i < configData.IrNum; i++)
        {


            double angle = configData.IrConfigData[i].Angle / 180 * M_PI;
            irObjData[i].cosValue = qCos(angle);
            irObjData[i].sinValue = qSin(angle);
            irObjData[i].OffsetDis = qSqrt((configData.IrConfigData[i].OffsetX) * (configData.IrConfigData[i].OffsetX)
                    + (configData.IrConfigData[i].OffsetY) * (configData.IrConfigData[i].OffsetY));
            irObjData[i].ObjX= 0;
            irObjData[i].ObjY= 0;
            irObjData[i].disValue = 0;
        }

        for (int i = 0; i < configData.UsNUm; i++)
        {

            double angle = configData.UsConfigData[i].Angle / 180 * M_PI;
            usObjData[i].cosValue = qCos(angle);
            usObjData[i].sinValue = qSin(angle);
            usObjData[i].OffsetDis = qSqrt((configData.UsConfigData[i].OffsetX) * (configData.UsConfigData[i].OffsetX)
                    + (configData.UsConfigData[i].OffsetY) * (configData.UsConfigData[i].OffsetY));
            usObjData[i].ObjX = 0;
            usObjData[i].ObjY = 0;
            usObjData[i].disValue = 0;
        }



        return true;
    }
}


bool DrRobotSensorMapBuilder::SetPolarMapTH(int data)
{
    if (data > 0)
    {
        polarMapTH = data;
        return true;
    }
    else
        return false;
}


bool DrRobotSensorMapBuilder::SetFadeOutStep(int data)
{
    if (data > 0)
    {
        fadeOutStep = data;
        return true;
    }
    else
        return false;
}

bool DrRobotSensorMapBuilder::SetFadeOutRate(int data)
{
    if (data > 0)
    {
        fadeOutRate = data;
        iDiffuseCount = fadeOutRate;
        return true;
    }
    else
        return false;
}

bool DrRobotSensorMapBuilder::SetIRUse(bool data)
{
    irUsed = data;
    return true;
}

bool DrRobotSensorMapBuilder::SetUSUse(bool data)
{
    usUsed = data;
    return true;
}
bool DrRobotSensorMapBuilder::SetLaserUse(bool data)
{
    laserUsed = data;
    return true;
}

bool DrRobotSensorMapBuilder::SetDetectDistance(double dis)
{
    dis = dis * 100 * 2;
    if ((dis < 0) && (dis >= cWinSize))
    {
        return false;
    }
    else
    {
        detectWindowSize = (int)(dis);
        return true;
    }
}


bool DrRobotSensorMapBuilder::UpdateSensorInfo(SensorData sensorData, RobotPosition posData)
{
    if ((configed) && (setPosition))
    {
        //upate sensor infor and UpdateMap
        currentPos = posData;

        UpdateSensor(sensorData);


        UpdateSensorMap();

        return true;
    }
    else
    {
        return false;
    }
}


bool DrRobotSensorMapBuilder::UpdateLaserSensorInfo(LaserSensorData laserSensorData)
{
    int end_x = 0;
    int end_y = 0;
    int start_x = MAPCENT;         //always at center
    int start_y = MAPCENT;         //always at center
    double angle = 0;
    double dblX1 = 0;
    double dblY1 = 0;
    double dblX2 = 0;
    double dblY2 = 0;
    if (configedLaser)
    {
        if (laserUsed)
        {
            for (int i = laserConfigData .StartStep ; i < laserConfigData.EndStep  ; i++)
            {

                if (laserSensorData .DisArrayData[i] >= laserConfigData.MinDis)
                {
                    //update non occupied blocks, MAPRAIO will switch unit meter to cm
                    angle = i * laserConfigData.AngleStep + laserConfigData.StartAngle;
                    //x+ point to front
                    dblX1 = laserSensorData.DisArrayData[i] * MAPRATIO * qSin(angle) + laserConfigData.OffsetX;
                    //y + point to left
                    dblY1 = -laserSensorData.DisArrayData[i] * MAPRATIO * qCos(angle) + laserConfigData.OffsetY;

                    //from robot coordinate to global coordinate
                    dblX2 = dblX1 * qCos(currentPos.robotDir) - dblY1 * qSin(currentPos.robotDir);
                    dblY2 = dblX1 * qSin(currentPos.robotDir) + dblY1 * qCos(currentPos.robotDir);

                    end_x = (int)( dblX2 + sign(dblX2) *0.501) + MAPCENT ;
                    end_y = (int)(dblY2 + sign(dblY2) * 0.501) + MAPCENT;

                    if (end_x > MAPSIZE - 2) end_x = MAPSIZE - 2;
                    if (end_y > MAPSIZE - 2) end_y = MAPSIZE - 2;
                    if (end_x < 1) end_x = 1;
                    if (end_y < 1) end_y = 1;

                    OCC_MAP_EMPTY_Update(start_x, start_y, end_x, end_y);

                    if (laserSensorData.DisArrayData[i] < laserSensorData .LaserDisLM)
                    {
                        //update occupied blocks only if the range measurment is not out of range
                        OCC_MAP_OCCUPIED_Update(end_x, end_y);
                    }
                }

            }
        }
    }
    else
    {
        return false;
    }
    return true;

}


void DrRobotSensorMapBuilder::UpdateSensor(SensorData sensorData)
{
    for (int i = 0; i < configData.IrNum; i++)
    {
        if (configData.IrConfigData[i].Weight > 0)        //using it
        {
            double _disValue = sensorData.IrDis[i];

            double dblX1 = _disValue * irObjData[i].cosValue;
            double dblY1 = _disValue * irObjData[i].sinValue;

            double dblX2 = dblX1 + configData.IrConfigData[i].OffsetX;
            double dblY2 = dblY1 + configData.IrConfigData[i].OffsetY;

            irObjData[i].ObjX = dblX2 * qCos(currentPos.robotDir) - dblY2 * qSin(currentPos.robotDir);
            irObjData[i].ObjY = dblX2 * qSin(currentPos.robotDir) + dblY2 * qCos(currentPos.robotDir);

            irObjData[i].disValue = qSqrt(dblX2 * dblX2 + dblY2 * dblY2);
        }
    }
    for (int i = 0; i < configData.UsNUm; i++)
    {
        if (configData.UsConfigData[i].Weight > 0)        //using it
        {
            double _disValue = sensorData.UsDis[i];

            double dblX1 = _disValue * usObjData[i].cosValue;
            double dblY1 = _disValue * usObjData[i].sinValue;

            double dblX2 = dblX1 + configData.UsConfigData[i].OffsetX;
            double dblY2 = dblY1 + configData.UsConfigData[i].OffsetY;

            usObjData[i].ObjX = dblX2 * qCos(currentPos.robotDir) - dblY2 * qSin(currentPos.robotDir);
            usObjData[i].ObjY = dblX2 * qSin(currentPos.robotDir) + dblY2 * qCos(currentPos.robotDir);

            usObjData[i].disValue = qSqrt(dblX2 * dblX2 + dblY2 * dblY2);
        }
    }
}

void DrRobotSensorMapBuilder::UpdateSensorMap()
{
    bool blnModifyX = false;
    bool blnModifyY = false;
    bool blnModifyMap = false;

    int start_x = MAPCENT;         //always at center
    int start_y = MAPCENT;         //always at center
    int end_x = 0;
    int end_y = 0;
    int X_Index = 0;
    int Y_Index = 0;
    double blockangle = 0;
    int midWin = detectWindowSize  / 2;

    double _Ex = currentPos.robotX;
    double _Ey = currentPos.robotY;

    double _preEx = prePos.robotX;
    double _preEy = prePos.robotY;


    // position change too mcuh, reset all sensor map
    if (((int)(fabs(_Ex - _preEx) * 10) >= MAPCENT) || ((int)(fabs(_Ey - _preEy) * 10) >= MAPCENT))
    {
        ResetOccMap();
    }
    else
    {
        blnModifyMap = true;
        //oK, first move the old occ map to new postion
        int iOffsetX = (int)((_Ex - _preEx) * 10);
        int iOffsetY = (int)((_Ey - _preEy) * 10);

        if (iOffsetX != 0)
            blnModifyX = true;
        else
            blnModifyX = false;


        if (iOffsetY != 0)
            blnModifyY = true;
        else
            blnModifyY = false;

        if (blnModifyX || blnModifyY)
        {
            MoveOccMap(iOffsetX, iOffsetY);
        }
    }

    if (blnModifyMap) //refresh sensor map
    {

        if (usUsed)       //use us sensor
        {
            for (int i = 0; i < configData.UsNUm; i++)
            {
                if (configData.UsConfigData[i].Weight > 0)
                {
                    if (usObjData[i].disValue >= (usObjData[i].OffsetDis + USDisLLM))
                    {
                        //update non occupied blocks

                        end_x = (int)(usObjData[i].ObjX * MAPRATIO + sign(usObjData[i].ObjX) * 0.501) + MAPCENT;
                        end_y = (int)(usObjData[i].ObjY * MAPRATIO + sign(usObjData[i].ObjY) * 0.501) + MAPCENT;

                        OCC_MAP_EMPTY_Update(start_x, start_y, end_x, end_y);

                        if (usObjData[i].disValue <= (usObjData[i].OffsetDis + USDisHLM)) //2.5
                        {
                            //update occupied blocks only if the range measurment is not out of range, i.e. not >2.5m
                            OCC_MAP_OCCUPIED_Update(end_x, end_y);
                        }
                    }
                }
            }
        }

        if (irUsed)     //use IR sensor
        {
            for (int i = 0; i < configData.IrNum; i++)
            {
                if (configData.IrConfigData[i].Weight > 0)
                {
                    if (irObjData[i].disValue >= irObjData[i].OffsetDis + IrDisLLM)   // dead zone of 10cm
                    {

                        //updtae non occupied blocks
                        end_x = (int)(irObjData[i].ObjX * MAPRATIO +  sign(irObjData[i].ObjX)* 0.501) + MAPCENT;
                        end_y = (int)((irObjData[i].ObjY * MAPRATIO) + sign(irObjData[i].ObjY) * 0.501) + MAPCENT;

                        OCC_MAP_EMPTY_Update(start_x, start_y, end_x, end_y);


                        if (irObjData[i].disValue <= irObjData[i].OffsetDis + IrDisHLM)     //0.73
                        {

                            //update occupied blocks only if the range measurment is not out of range, ie.e not >80cm
                            OCC_MAP_OCCUPIED_Update(end_x, end_y);

                        }
                    }
                }
            }
        }
        //Sonar Range -> Map occupancy



        //Generating Polar map

        double deltaAngle = M_PI * 2 / (double)MAPSECTIONNUM;

        //reset the historgram
        double distance2COV = 0;

        for (int i = 0; i < MAPSECTIONNUM; i++)
            sensorMap.Polar_Value_Map[i] = 0;


        for (int i = 0; i < detectWindowSize ; i++)
        {
            X_Index = start_x - midWin + i;
            if ((X_Index > 0) && (X_Index < MAPSIZE))
            {

                for (int j = 0; j < detectWindowSize ; j++)
                {
                    //cal angel of each block in the windows
                    Y_Index = start_y - midWin + j;
                    if ((Y_Index > 0) && (Y_Index < MAPSIZE))
                    {
                        //HWin_map(i, j, 1) = CInt((Atn(j - ((cWinSize - 1) / 2 + 1) / i - ((cWinSize - 1) / 2 + 1)) + c2PI + deltaAngle / 2) / deltaAngle)
                        blockangle = calP2PAngle((double)midWin, (double)midWin, (double)i, (double)j);
                        //angle section value 0 - 35
                        HWin_map[i][ j][ 0] = (int)((blockangle + M_PI) / deltaAngle);  //

                        //'cal magnitude of each block, weighted by distance
                        distance2COV = (i - midWin) * (i - midWin) + (j - midWin) * (j - midWin);
                        HWin_map[i][ j][1] = (int)(_Occ_Map[X_Index][Y_Index] * _Occ_Map[X_Index][ Y_Index]
                                    * (1.0 - (1.0 / (double)(2 * (detectWindowSize  - midWin) * (detectWindowSize - midWin))) * distance2COV));


                        //summarizing the historgram
                        sensorMap.Polar_Value_Map[HWin_map[i][ j][ 0]] = sensorMap.Polar_Value_Map[HWin_map[i][j][ 0]] + HWin_map[i][ j][ 1];
                    }
                }
            }
        }

        //SMOOTHING THE POLAR MAP extend 0-35 to 0 -39, 0 -34. 1- 35, 38 - 0, 39 -1
        int extPolar_value_map[cSmoothWinSize + MAPSECTIONNUM];


        for (int i = 0; i < MAPSECTIONNUM; i++)
        {
            extPolar_value_map[i + (cSmoothWinSize) / 2] = sensorMap.Polar_Value_Map[i];
        }

        for (int i = 0; i < cSmoothWinSize / 2; i++)
        {
            extPolar_value_map[(cSmoothWinSize) / 2 - i - 1] = sensorMap.Polar_Value_Map[MAPSECTIONNUM - i - 1];
            extPolar_value_map[MAPSECTIONNUM + (cSmoothWinSize) / 2 + i] = sensorMap.Polar_Value_Map[i];
        }

        for (int i = cSmoothWinSize / 2; i < cSmoothWinSize / 2 + MAPSECTIONNUM; i++)
        {

            //weight = 0, 2, 5, 2, 0
            sensorMap.Polar_Value_Map[i - cSmoothWinSize / 2] = extPolar_value_map[i] * 5;   //midlle section wight = 5


            for (int j = 1; j < cSmoothWinSize / 2; j++)
            {
                sensorMap.Polar_Value_Map[i - cSmoothWinSize / 2] =
                    sensorMap.Polar_Value_Map[i - cSmoothWinSize / 2]
                    + (extPolar_value_map[i + j] + extPolar_value_map[i - j]) * (cSmoothWinSize / 2 - j + 1);
            }


            sensorMap.Polar_Value_Map[i - cSmoothWinSize / 2] = sensorMap.Polar_Value_Map[i - cSmoothWinSize / 2] / 9;  //toatal 3*3 = 9


        }

        //Thresholding and find the valleys
        for (int i = 0; i < MAPSECTIONNUM; i++)
        {
            if (sensorMap.Polar_Value_Map[i] > polarMapTH)
            {
                sensorMap.Polar_Bin_Map[i] = 1;
            }
            else
            {
                sensorMap.Polar_Bin_Map[i] = 0;
            }
        }

    }


    // to update effect from moving object

    if (iDiffuseCount == 0)
    {
        int iFadeOutStep = fadeOutStep;
        for (int i = 0; i < MAPSIZE; i++)
            for (int j = 0; j < MAPSIZE; j++)
            {
                _Occ_Map[i][ j] = ((_Occ_Map[i][ j] - iFadeOutStep) > 0 ? _Occ_Map[i][ j] - iFadeOutStep : 0);
            }
        iDiffuseCount = fadeOutRate;
    }
    else
    {
        iDiffuseCount = iDiffuseCount - 1;
    }

    //here display map

    //copy to preOCC_map
    copyPreOccMap(blnModifyX, blnModifyY);

    //just for testing
   // sensorMap.Polar_Bin_Map[10] = 10;
    emit  mapBuilderServiceCallback(sensorMap);


}

bool DrRobotSensorMapBuilder::OCC_MAP_EMPTY_Update(int start_X_index, int start_Y_index, int end_X_index, int end_Y_index)
{
    int nextY = 0;
    int nextX = 0;
    double tempData = 0;
    if (abs(end_X_index - start_X_index) >= abs(end_Y_index - start_Y_index))
    {
        //<less than 45 o
        if (end_X_index - start_X_index > 1)

            for (int i = 0; i < (end_X_index - start_X_index); i++)
            {
                tempData = (int)((double)i * (end_Y_index - start_Y_index) / (double)(end_X_index - start_X_index));
                nextY = start_Y_index + (int)(tempData + sign (tempData )*0.501);
                if (nextY >= MAPSIZE) nextY = MAPSIZE - 1;
                if (nextY < 0) nextY = 0;
                _Occ_Map[i + start_X_index][ nextY] = (_Occ_Map[i + start_X_index][ nextY] >= cEmptyStep ? _Occ_Map[i + start_X_index][ nextY] - cEmptyStep : 0);
            }
        else
        {
            for (int i = 0; i < (-(end_X_index - start_X_index)); i++)
            {
                tempData = ((double)i * (end_Y_index - start_Y_index) / (double)(end_X_index - start_X_index));
                if (nextY >= MAPSIZE) nextY = MAPSIZE - 1;
                if (nextY < 0) nextY = 0;
                nextY = start_Y_index - (int)(tempData + sign (tempData )*0.501);
                _Occ_Map[start_X_index - i][ nextY] = (_Occ_Map[start_X_index - i][ nextY] >= cEmptyStep ? _Occ_Map[start_X_index - i][ nextY] - cEmptyStep : 0);
            }
        }
    }
    else
    {
        if (end_Y_index - start_Y_index > 1)
        {

            for (int i = 0; i < end_Y_index - start_Y_index; i++)
            {
                tempData = ((double)i * (end_X_index - start_X_index) / (double)(end_Y_index - start_Y_index));
                nextX = start_X_index + (int)(tempData + sign(tempData) * 0.501);
                if (nextX >= MAPSIZE) nextX = MAPSIZE - 1;
                if (nextX < 0) nextX = 0;
                _Occ_Map[nextX][ i + start_Y_index] = (_Occ_Map[nextX][ i + start_Y_index] >= cEmptyStep ? _Occ_Map[nextX][ i + start_Y_index] - 1 : 0);
            }
        }
        else
        {
            for (int i = 0; i < (-(end_Y_index - start_Y_index)); i++)
            {
                tempData = ((double)i * (end_X_index - start_X_index) / (double)(end_Y_index - start_Y_index));
                nextX = start_X_index - (int)(tempData + sign(tempData) * 0.501);
                if (nextX >= MAPSIZE) nextX = MAPSIZE - 1;
                if (nextX < 0) nextX = 0;
                _Occ_Map[nextX][ start_Y_index - i] = (_Occ_Map[nextX][ start_Y_index - i] >= cEmptyStep ? _Occ_Map[nextX][ start_Y_index - i] - 1 : 0);
            }

        }
    }
    return true;
}

bool DrRobotSensorMapBuilder::OCC_MAP_OCCUPIED_Update(int X_Index, int Y_Index)
{

    int delta = 0;

    if ((X_Index > 1) && (X_Index < MAPSIZE) && (Y_Index > 1) && (Y_Index < MAPSIZE))
    {
        //enhancing the grow rate by convolving around the area
        delta = (int)(cOccupiedStep + 0.5 *
            (_Occ_Map[X_Index - 1][ Y_Index - 1] + _Occ_Map[X_Index][ Y_Index - 1]
            + _Occ_Map[X_Index + 1][ Y_Index - 1] + _Occ_Map[X_Index - 1][ Y_Index]
            + _Occ_Map[X_Index + 1][ Y_Index] + _Occ_Map[X_Index - 1][ Y_Index + 1]
            + _Occ_Map[X_Index][ Y_Index + 1] + _Occ_Map[X_Index + 1][ Y_Index + 1]));
        _Occ_Map[X_Index][ Y_Index] = (_Occ_Map[X_Index][ Y_Index] >= cMAx_Occupied - delta ? cMAx_Occupied : _Occ_Map[X_Index][ Y_Index] + delta);
        return true;
    }
    else
    {
        return false;
    }
}
double DrRobotSensorMapBuilder::calP2PAngle(double X1, double Y1, double X2, double Y2)
{
    double result = 0;
    if ((X2 - X1) != 0)
    {
        if ((X2 - X1) > 0)  //atn function only return -PI/2 to P/2 range
        {
            result = qAtan((Y2 - Y1) / (X2 - X1));
        }
        else
        {
            if ((Y2 - Y1) > 0)
                result = M_PI + qAtan((Y2 - Y1) / (X2 - X1));
            else
                result = qAtan((Y2 - Y1) / (X2 - X1)) - M_PI;
        }
    }
    else
    {
        if ((Y2 - Y1) > 0)
            result = M_PI / 2;
        else
            result = -M_PI / 2;
    }
    return result;
}

void DrRobotSensorMapBuilder::copyPreOccMap(bool blnModX, bool blnMody)
{

    for (int i = 0; i < MAPSIZE; i++)
        for (int j = 0; j < MAPSIZE; j++)
            _pre_Occ_Map[i][ j] = _Occ_Map[i][ j];

    //only update the bigger change value
    if (blnModX)
        prePos.robotX = currentPos.robotX;

    if (blnMody)
        prePos.robotY = currentPos.robotY;

}

void DrRobotSensorMapBuilder::ResetOccMap()
{
    for (int i = 0; i < MAPSIZE; i++)
        for (int j = 0; j < MAPSIZE; j++)
        {
            _Occ_Map[i][ j] = 0;
            _pre_Occ_Map[i][ j] = 0;
        }
    prePos.robotX = currentPos.robotX;
    prePos.robotY = currentPos.robotY;
    prePos.robotDir = currentPos.robotDir;


}

void DrRobotSensorMapBuilder::MoveOccMap(int offsetX, int offsetY)
{

    for (int i = 0; i < MAPSIZE; i++)
        for (int j = 0; j < MAPSIZE; j++)
        {
            if (((i + offsetX) < 0) || (i + offsetX >= MAPSIZE)
                || ((j + offsetY) < 0) || ((j + offsetY) >= MAPSIZE))
            {
                _Occ_Map[i][ j] = 0;
            }
            else
            {
                _Occ_Map[i][ j] = _pre_Occ_Map[i + offsetX][ j + offsetY];
            }
        }
}


