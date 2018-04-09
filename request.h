#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include "source.h"

class Request
{
private:
    int requestNumber;//номер заявки
    double timeReq; //время генерирования заявки
    int sourceNumber; //номер источника заявки
    double serviceTime; //время обработки заявки прибором
    double buffTime; //время заявки в буфере
    double endTimeWork;//время когда заявка отработала
public:
    Request(); //пустая заявка
    Request(int requestNumer, int sourceNumber, double timeReg);
    double getTime(); //выводит время
    int getNumberReq(); //выводит номер заявки
    int getNumberSource(); //выводит номер источника
    void setTime(double timeReq);//изменяет время генерации заявки у заявки
    void setNumberReq(int requestNumber);//изменяет номер заявким
    void setNumberSource(int sourceNumber);//изменяет номер источника
    void setServiceTime(double srTm);//заполняет время на приборе
    double getServiceTime();//выводит время на прибора
    void setBuffTime(double buffTime);//добавляет время в буфере
    double getBuffTime();//возвращает время в буфере
    void setEndTimeWork(double endTimeWork);//добавляет время выхода из прибора
    double getEndTimeWork();//возвращает время выхода из прибора
};

#endif // REQUEST_H
