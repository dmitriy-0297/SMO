#ifndef TABLESTEPMODE_H
#define TABLESTEPMODE_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class tableStepMode;
}

class tableStepMode : public QWidget
{
    Q_OBJECT

public:
    explicit tableStepMode(QWidget *parent = 0);
    ~tableStepMode();
    QStandardItemModel *model;

private:
    Ui::tableStepMode *ui;
};

#endif // TABLESTEPMODE_H
