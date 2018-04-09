#include "source.h"

Source::Source(double lambda, int sourceNumber)
{
    this->sourceNumber=sourceNumber;
    this->lambda = lambda;
    this->timeGenReq = 0;
    this->generationRequestCount = 0;
    this->countReq = 0;
    this->countDelReq = 0;
    this->pFailure = 0;
    this->tInSys = 0;
    this->tInBuff = 0;
    this->tOnDev = 0;
    this->dispDev = 0;
    this->dispBuff = 0;
}

Request Source::requestGeneration(){
    generationRequestCount++;//счетчик заявок в источнике, у каждого источника своя нумерация заявок
    Request req(generationRequestCount, sourceNumber, timeGenReq);
    return req;
}

void Source::clk(){ //генерация времени
    float randInt = (float)(rand() % 99 + 1) / (float)100.0;
        timeGenReq += float(-1.0 / lambda*log(randInt));
    countReq++;

}

double Source::getGenerationTime(){//вывод времени генерации
    return timeGenReq;
}
int Source::getCountReq(){
    return generationRequestCount;
}
void Source::plusCountDelReq(){
    countDelReq++;
}
int Source::getCountDelReq(){
    return countDelReq;
}
int Source::getNumSource(){
    return sourceNumber;
}
void Source::setP(double p){
    pFailure = p;
}
double Source::getP(){
    return pFailure;
}
void Source::setTimeInBuff(double timeBuff){
    this->tInBuff = timeBuff;
}
void Source::setTimeInSys(double timeSys){
    this->tInSys = timeSys;
}
void Source::setTimeOnDev(double timeDev){
    this->tOnDev = timeDev;
}
void Source::setDispDev(double dispDev){
    this->dispDev = dispDev;
}
void Source::setDispBuff(double dispBuff){
    this->dispBuff = dispBuff;
}
double Source::getTimeInBuff(){
    return tInBuff;
}
double Source::getTimeInSys(){
    return tInSys;
}
double Source::getTimeInDev(){
    return tOnDev;
}
double Source::getDispDev(){
    return dispDev;
}
double Source::getDispBuff(){
    return dispBuff;
}
int Source::getReq(){
    return requestGeneration().getNumberReq()-1;
}




