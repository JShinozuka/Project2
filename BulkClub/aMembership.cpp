#include "aMembership.h"
#include "ui_aMembership.h"

aMembership::aMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aMembership)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT * FROM MembershipDB");
    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->memberDBTable->setModel(model);
}

aMembership::~aMembership()
{
    delete ui;
}
