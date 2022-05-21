#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include "lua_engine.h"


extern Lua_engine inst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString script=ui->textEdit->toPlainText();
    if(script.isEmpty())
    {
        QMessageBox::warning(this, QString("警告") ,QString("文本框不能为空"), QMessageBox::Ok);
    }

    inst.exe_lua_str(script.toUtf8().data());
}
