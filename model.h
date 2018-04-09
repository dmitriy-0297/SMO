#ifndef MODEL_H
#define MODEL_H

#include "source.h"
#include "request.h"
#include "buffer.h"
#include "dev.h"
#include "cmath"
#include "dispatchmanager.h"
#include "dispatchservice.h"
#include <vector>
#include <statistics.h>
#include <event.h>

class Model
{
public:
    Model();
    std::vector<Event> events;//события
    std::vector<Device> dvices;//приборы
    std::vector<Source> sorces;//источники
    int flag;//флаг для запуска режима
    int sourceCount;//количество источников
    int requestCount;//количество заявок
    int deviceCount;//количество источников
    double lambda;//интенсивность
    int bufferCount;//количество буферов
    int sizeBuffer; //размер буфер
    double intA; //const для равномерного закона
    double intB; //const для равномерного закона
    Model(double lambda, int sourceCount, int requestCount,
          int sizeBuffer, int deviceCount, double intA, double intB);
    void start(int flag);//функция обеспечивающая начало работы системы
    double getTimeModel();//получение времени работы модели
    int minNum(std::vector<Source> srCount);//поиск минимального значения
    std::vector<Event> getEvents();//возвращение событий
    std::vector<Source> getSrCount();//возвращает вектор источников
    std::vector<Device> getDvCount();//возвращает вектор приборов
};

#endif // MODEL_H
