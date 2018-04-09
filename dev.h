#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include "request.h"

class Device
{
private:
    double serviceTime; //время обслуживания
    int a,b;//константы для равномерного закона
    int devNum;//номер прибора
    Request currentReq;//текущая заявка
    double sumTimeDev;//суммарное время занятости
    double K;//коэфицент использования прибора

public:
    std::vector<Request> endReq;//вектор отработаных заявок
    Device(double a, double b, int devNum);
    void timeService(Request req);//считает(генерирует) время обслужмвания
    double getServiceTime();//возвращает время обслуживания
    int getDeviceNumber();//возвращает номер прибора
    Request getReq();
    int getSourceNum();//возвращает номер источника
    bool isRequestEarlierDevice(Device& dev, Request& req);
    std::vector<Request> getEndReq();
    void setSumTimeDev(double sumTimeDev);//вводит sum времени работы прибора
    double getSumTimeDev();//возвращает sum времени работы прибора
    void setK(double K);//вводит кофицент
    double getK();//возвращает K
};

#endif // DEVICE_H
