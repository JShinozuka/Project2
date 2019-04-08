#include "aInventory.h"
#include "ui_aInventory.h"

aInventory::aInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aInventory)
{
    ui->setupUi(this);
}

aInventory::~aInventory()
{
    delete ui;
}
