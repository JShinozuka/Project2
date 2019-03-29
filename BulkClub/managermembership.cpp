#include "managermembership.h"
#include "ui_managermembership.h"
#include "manager.h"

managerMembership::managerMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerMembership)
{
    ui->setupUi(this);

    db = QSqlDatabase::database();

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(db);

    qry->prepare("SELECT * "
                 "FROM MembershipDB"); //From Table
    qry->exec();
    modal->setQuery(*qry);

    ui->memberDBTable->setModel(modal);

}

managerMembership::~managerMembership()
{
    delete ui;
}
