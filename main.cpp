#include "mainwindow.h"

#include <QApplication>
#include "device/device_manager.h"
#include "lua_engine.h"


Lua_engine inst;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    inst.init();
    inst.exe_lua_str("print('result:',agv_GetGlobalVariable(1,'testName'))");
    w.show();
    return a.exec();
}
