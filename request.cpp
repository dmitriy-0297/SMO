#include "request.h"

Request::Request(int requestNumber, int sourceNumber, double timeReq)
{
    this->timeReq = timeReq;
    this->requestNumber = requestNumber;
    this->sourceNumber = sourceNumber;
    this->serviceTime = 0;
    this->buffTime = 0;
    this->endTimeWork = 0;
}

Request::Request(){
    timeReq = -1;
    sourceNumber = -1;
    requestNumber = -1;
}

double Request::getTime(){
    return timeReq;
}
int Request::getNumberReq(){
    return requestNumber;
}
int Request::getNumberSource(){
    return sourceNumber;
}
void Request::setTime(double timeReq){
    this->timeReq = timeReq;
}
void Request::setNumberReq(int requestNumber){
    this->requestNumber=requestNumber;
}
void Request::setNumberSource(int sourceNumber){
    this->sourceNumber=sourceNumber;
}
void Request::setServiceTime(double srTm){
    this->serviceTime = srTm;
}
double Request::getServiceTime(){
    return serviceTime;
}

void Request::setBuffTime(double buffTime){
    this->buffTime = buffTime;
}

double Request::getBuffTime(){
    return buffTime;
}
void Request::setEndTimeWork(double endTimeWork){
    this->endTimeWork = endTimeWork;
}
double Request::getEndTimeWork(){
    return endTimeWork;
}
