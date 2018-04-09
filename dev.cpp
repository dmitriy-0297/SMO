#include "dev.h"

Device::Device(double a, double b,int devNum)
{
    this->a = a;
    this->b = b;
    this->devNum = devNum;
    this->serviceTime = 0;
    this->currentReq = Request();
    this->sumTimeDev = 0;
}

void Device::timeService(Request req){
    this->currentReq = req;
    //double serviceTime = ((double)rand() / (double)RAND_MAX) * (double(b) - double(a)) + double(a);
    double random = (double)(rand() % 99 + 1.0) / (double)100.0;
    serviceTime =+ double(random*(double(b-a)) + double(a));
    currentReq.setServiceTime(serviceTime);
    endReq.push_back(currentReq);
    sumTimeDev = sumTimeDev + currentReq.getServiceTime();
}
double Device::getServiceTime(){
    return serviceTime;
}

int Device::getDeviceNumber(){
    return devNum;
}

int Device::getSourceNum(){
    return currentReq.getNumberSource();
}
Request Device::getReq(){
    return currentReq;
}

std::vector<Request> Device::getEndReq(){
    return endReq;
}

bool Device::isRequestEarlierDevice(Device& dev, Request& req){
    if(dev.getServiceTime()>req.getTime()){
        return true;
    }else{
        return false;
    }
}
void Device::setSumTimeDev(double sumTimeDev){
    this->sumTimeDev = sumTimeDev;
}
double Device::getSumTimeDev(){
    return sumTimeDev;
}
void Device::setK(double K){
    this->K = K;
}
double Device::getK(){
    return K;
}
