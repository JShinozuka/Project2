#include "managersales.h"
#include "ui_managersales.h"

managerSales::managerSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerSales)
{
    ui->setupUi(this);
}

managerSales::~managerSales()
{
    delete ui;
}
