#include "mainwindow.h"
#include "iostream"
#include "source.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//request - заявка
//souce - источник
