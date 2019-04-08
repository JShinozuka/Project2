#include "aConvertMembership.h"
#include "ui_aconvertmembership.h"

aConvertMembership::aConvertMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aConvertMembership)
{
    ui->setupUi(this);
}

aConvertMembership::~aConvertMembership()
{
    delete ui;
}
