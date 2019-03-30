
////////////////////////////// DOCUMENTATION STILL NEEDED

#include "managermembership.h"
#include "ui_managermembership.h"

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>

managerMembership::managerMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerMembership)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();
    QSqlQuery * qry = new QSqlQuery(myDB);

    qry->prepare("SELECT * "
                 "FROM MembershipDB"); //From Table
    qry->exec();

    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery(*qry);

    ui->memberDBTable->setModel(modal);
}

managerMembership::~managerMembership()
{
    delete ui;
}
