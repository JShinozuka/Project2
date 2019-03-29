#include "managerinventory.h"
#include "ui_managerinventory.h"

managerInventory::managerInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerInventory)
{
    ui->setupUi(this);
}

managerInventory::~managerInventory()
{
    delete ui;
}
