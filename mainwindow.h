#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    int requestCount; //количество заявок
    int sourceCount; //количество источников
    int sizeBuffer; // размер буфера
    double lambda; // итенсивность
    double intA; //const для равномерного закона
    double intB; //const для равномерного закона
    int deviceCount; //количество девайсов
    Model mod;//(lambda, sourceCount, requestCount, sizeBuffer, deviceCount, intA, intB);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
