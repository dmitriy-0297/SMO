#ifndef DISPATCHSERVICE_H
#define DISPATCHSERVICE_H

#include "buffer.h"
#include "request.h"
#include "dev.h"
#include <vector>

typedef std::vector<Device> DevCont;

class Dispatchservice
{
public:
    void getRequest(DevCont& dev, Buffer& buff);//получение заявки
    int firstDev(DevCont device);//позволяет получать номер девайса
private:
    int DevNum;//номер прибора
    int sourceCount;//количество источников
};

#endif // DISPATCHSERVICE_H
