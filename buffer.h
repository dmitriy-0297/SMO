#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <vector>
#include "request.h"

typedef std::vector<Request>::iterator Iterator;

class Buffer
{
private:
    int sizeBuf; //размер буфера
    int sourceCount;//количество источников
    int curPriority;//текущий приоритет
public:
    Buffer();
    //Buffer(const Buffer& Buff);
    std::vector<int> vecInd;//вектор индексов
    std::vector<Request> Buff; //контейнер для хранения информации
    Iterator iter; //итератор - выполняет роль указателя
    Buffer(int sizeBuf, int sourceCount);
    void PrintBuff(); // вывод буфера
    bool checkFinishedPac(); //проверка на конец пакета
    int prioritySource();//находит самый высокий приоритет
    void genPack();//генерирует пакет
    Request getElement();//выводит заявку
    Request getReq(int i);//получение элемента из буфера
    int checkBuff();//проверяем буфер на занятость
    };

#endif // BUFFER_H
