#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iostream>
#include "request.h"

class Request;
class Source {
private:
    int sourceNumber;//номер искочника
    int countReq; //количество заявок сгенерированных источником
    int countDelReq; //количество отказаных заявок
    double pFailure; //вероятность отказа источников
    double tInSys; //седнее время в системе
    double tInBuff; //среднее воемя в буфере
    double tOnDev; //среднее время на источнике
    double dispDev; //дисперсия прибора
    double dispBuff; // дисперсия буфера
public:
    int generationRequestCount;//количество сгенерированых заявок
    double timeGenReq;//время генерации заявки
    double lambda;
    Source(double lambda, int sourceNumber);
    Request requestGeneration();//создание(генерация) заявки
    void clk(); //генерация времни
    double getGenerationTime();//вывод времени
    int getCountReq();//получение количества заявок сгенерированных источником
    void plusCountDelReq();//считает количество отказаных заявок
    int getCountDelReq();//получаем количество отказаных заявок
    int getNumSource();//получаем номер источника
    void setP(double p);//запись p
    double getP();//вывод p
    void setTimeInBuff(double timeBuff);//ввод среднего времеми в буфере
    void setTimeInSys(double timeSys);//ввод среднего времени в системе
    void setTimeOnDev(double timeDev);//ввод среднего времени га приборе
    void setDispDev(double dispDev);//ввод дисперсии прибора
    void setDispBuff(double dispBuff);//ввод дисперсии буфера
    double getTimeInBuff();//вывод среднего времени в буфере
    double getTimeInSys();//вывод среднего времени в системе
    double getTimeInDev();//вывод среднего времени на приборе
    double getDispDev();//вывод дисперсии прибора
    double getDispBuff();//вывод дисперсии буфера
    int getReq();//вывод номера заявки
};

#endif // SOURCE_H
