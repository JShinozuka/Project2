#include "managersales.h"
#include "ui_managersales.h"

managerSales::managerSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerSales)
{
    ui->setupUi(this);

    // Assign connection to object for use in managerMembership
    myDB = QSqlDatabase::database();

    displaySalesPerMember();
}

managerSales::~managerSales()
{
    delete ui;
}

 void managerSales::displaySalesPerMember() const
 {
     // Create query model
     QSqlQueryModel *model = new QSqlQueryModel;

     model->setQuery("SELECT customerName, membershipNumber, totalAmountSpent "
                     "FROM MembershipDB "
                     "ORDER BY customerName ");

     // Display query error if exists
     if(model->lastError().isValid())
         qDebug() << model->lastError();

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total Amount Spent"));

     // Display table with query model
     ui->salesTotalPurchaseTable->setModel(model);
 }

void managerSales::on_Search_clicked()
{
     QString texttmp = ui->textEdit->toPlainText();

     QSqlQueryModel *model = new QSqlQueryModel;

     model->setQuery("SELECT customerName, membershipNumber, totalAmountSpent "
                     "FROM MembershipDB "
                     "WHERE customerName ='"+ texttmp + "' "
                     "ORDER BY customerName");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total Amount Spent"));

     // Display table with query model
     ui->salesTotalPurchaseTable->setModel(model);
}

void managerSales::on_pushButton_clicked()
{
    QString texttmp = ui->textEdit->toPlainText();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT customerName, membershipNumber, totalAmountSpent "
                    "FROM MembershipDB "
                    "WHERE membershipNumber ='"+ texttmp + "' "
                    "ORDER BY customerName");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total Amount Spent"));

    // Display table with query model
    ui->salesTotalPurchaseTable->setModel(model);
}
