#include "mainwindow.h"

#include <QApplication>
#include "device/device_manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Device_ns::Device_manager dm;
    dm.build();
    return a.exec();
}
