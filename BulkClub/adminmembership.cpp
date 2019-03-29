#include "adminmembership.h"
#include "ui_adminmembership.h"

adminMembership::adminMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminMembership)
{
    ui->setupUi(this);
}

adminMembership::~adminMembership()
{
    delete ui;
}
