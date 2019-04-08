#include "mInventory.h"
#include "ui_minventory.h"

mInventory::mInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mInventory)
{
    ui->setupUi(this);
}

mInventory::~mInventory()
{
    delete ui;
}
