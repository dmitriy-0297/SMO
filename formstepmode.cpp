#include "formstepmode.h"
#include "ui_formstepmode.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

FormStepMode::FormStepMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStepMode)

{   
    this->clik = 0;
    ui->setupUi(this);
}

void FormStepMode::setEvents(std::vector<Event> &events){
    for(int i = 0; i != int(events.size()); i++){
        this->Events.push_back(events[i]);
    }
}
FormStepMode::~FormStepMode()
{
    delete ui;
}
void FormStepMode::initForm1(int srCount, int dvCount, int clik){
    int sizeTable1 = srCount + dvCount;
    int sizeTable2 = 4;
    model1 = new QStandardItemModel(sizeTable1, sizeTable2, this);
    ui->tableStepMode1->setModel(model1);
    QModelIndex index;
    for(int row1 = 0; row1 < srCount; row1++){
        int col = 0;
        index = model1->index(row1,col);
        model1->setData(index,Events[clik].srCount[row1].getNumSource());
        col++;
        index = model1->index(row1,col);
        model1->setData(index,Events[clik].srCount[row1].getGenerationTime());
        col++;
        index = model1->index(row1,col);
        model1->setData(index,Events[clik].srCount[row1].getCountReq());
        col++;
        index = model1->index(row1,col);
        model1->setData(index,Events[clik].srCount[row1].getCountDelReq());
    }
    int numDev = 1;
    for(int row2 = srCount; row2 < sizeTable1; row2++){
        int col = 0;
        index = model1->index(row2,col);
        model1->setData(index, numDev);
        col++;
        index = model1->index(row2,col);
        model1->setData(index,Events[clik].dvCount[numDev-1].getServiceTime());
        numDev++;
    }
    model1->setHeaderData(0, Qt::Horizontal, "Num");
    model1->setHeaderData(1, Qt::Horizontal, "Time");
    model1->setHeaderData(2, Qt::Horizontal, "ReqCount");
    model1->setHeaderData(3, Qt::Horizontal, "CountDelReq");
    for(int i = 0; i <= sizeTable1; i++){
        if(i <= srCount){
            model1->setHeaderData(i, Qt::Vertical, "Source");
        }
        if(i >= srCount){
            model1->setHeaderData(i, Qt::Vertical, "Device");
        }
    }
}

void FormStepMode::initForm2(int sizeBuff, int clik){
    int sizeTable1 = sizeBuff;
    int sizeTable2 = 4;
    model2 = new QStandardItemModel(sizeTable1, sizeTable2, this);
    ui->tableStepMode2->setModel(model2);
    QModelIndex index;
    for(int row = 0; row < sizeBuff; row++){
        int col = 0;
        index = model2->index(row,col);
        model2->setData(index,row);
        col++;
        index = model2->index(row,col);
        model2->setData(index,Events[clik].Buff.Buff[row].getTime());
        col++;
        index = model2->index(row,col);
        model2->setData(index,Events[clik].Buff.Buff[row].getNumberSource());
        col++;
        index = model2->index(row,col);
        model2->setData(index,Events[clik].Buff.Buff[row].getNumberReq());
    }
    model2->setHeaderData(0, Qt::Horizontal, "Num");
    model2->setHeaderData(1, Qt::Horizontal, "Time");
    model2->setHeaderData(2, Qt::Horizontal, "SourceNum");
    model2->setHeaderData(3, Qt::Horizontal, "ReqNum");
    for(int i = 0; i <= sizeTable2; i++){
        if(i <= sizeBuff){
            model2->setHeaderData(i, Qt::Vertical, "Buffer");
        }
    }
}

void FormStepMode::setSrCount(int srCount){
    this->srCount = srCount;
}

void FormStepMode::setDvCount(int dvCount){
    this->dvCount = dvCount;
}

void FormStepMode::setSizeBuff(int sizeBuff){
    this->sizeBuff = sizeBuff;
}

void FormStepMode::on_pushButton_clicked()
{
    clik++;
    if(clik < int(Events.size())){
        initForm1(this->srCount, this->dvCount, clik);
        initForm2(this->sizeBuff, clik);
    }else{
        close();
    }
}

void FormStepMode::on_pushButton_2_clicked()
{
    clik--;
    initForm1(this->srCount, this->dvCount, clik);
    initForm2(this->sizeBuff, clik);
    if(clik == 0){
        close();
    }
}

void FormStepMode::on_pushButton_3_clicked()
{
    close();
}
