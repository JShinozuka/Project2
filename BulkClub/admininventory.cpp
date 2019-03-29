#include "admininventory.h"
#include "ui_admininventory.h"

adminInventory::adminInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminInventory)
{
    ui->setupUi(this);
}

adminInventory::~adminInventory()
{
    delete ui;
}
