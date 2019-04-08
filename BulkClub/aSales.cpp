#include "aSales.h"
#include "ui_aSales.h"

aSales::aSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aSales)
{
    ui->setupUi(this);
}

aSales::~aSales()
{
    delete ui;
}
