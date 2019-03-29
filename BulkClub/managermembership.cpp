#include "managermembership.h"
#include "ui_managermembership.h"

managerMembership::managerMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerMembership)
{
    ui->setupUi(this);
}

managerMembership::~managerMembership()
{
    delete ui;
}
