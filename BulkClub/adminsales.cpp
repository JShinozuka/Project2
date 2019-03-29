#include "adminsales.h"
#include "ui_adminsales.h"

adminSales::adminSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminSales)
{
    ui->setupUi(this);
}

adminSales::~adminSales()
{
    delete ui;
}
