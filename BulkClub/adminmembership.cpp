#include "adminmembership.h"
#include "ui_adminmembership.h"

adminMembership::adminMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminMembership)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT * FROM MembershipDB");
    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->memberDBTable->setModel(model);
}

adminMembership::~adminMembership()
{
    delete ui;
}
