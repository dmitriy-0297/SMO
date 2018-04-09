#include "dispatchservice.h"
#include "request.h"

void Dispatchservice::getRequest(DevCont& dev, Buffer& buff){
    DevNum = firstDev(dev);
    dev.at(DevNum).timeService(buff.getElement());
}

int Dispatchservice::firstDev(DevCont device){
    DevCont::iterator iter = device.begin();
    for (DevCont::iterator i = device.begin(); i != device.end(); i++) {
        if (i->getServiceTime() < iter->getServiceTime()) {
            iter = i;
        }
    }
    return iter->getDeviceNumber();
}

