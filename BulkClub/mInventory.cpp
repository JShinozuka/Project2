#include "mInventory.h"
#include "ui_mInventory.h"

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
