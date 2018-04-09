#include "tablestepmode.h"
#include "ui_tablestepmode.h"

tableStepMode::tableStepMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableStepMode)
{
    ui->setupUi(this);
    model = new QStandardItemModel(5,2, this);

    ui->tableStepMode_2->setModel(model);
}

tableStepMode::~tableStepMode()
{
    delete ui;
}


