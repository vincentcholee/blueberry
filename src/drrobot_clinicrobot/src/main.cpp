#include <QtGui>
#include <QApplication>
#include "../include/drrobot_clinicrobot/mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    drrobot_clinicrobot::MainWindow w(argc,argv);

    w.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();
    return app.exec();
}
