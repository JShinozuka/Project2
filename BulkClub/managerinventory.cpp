#include "managerinventory.h"
#include "ui_managerinventory.h"

managerInventory::managerInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerInventory)
{
    ui->setupUi(this);
    //displaySalesReport();
}

managerInventory::~managerInventory()
{
    delete ui;
}

//print the excecutive members daily sales report
void managerInventory::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT MembershipDB.customerName, SalesDB.date, "
                    "SalesDB.itemPurchased, SalesDB.quantity "
                    "FROM MembershipDB "
                    "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                    "WHERE MembershipDB.membershipType = 'Executive' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));

    // Display table with query model
    ui->salesReportTableView->setModel(model);
}

//print the regular members daily sales report
void managerInventory::on_pushButton_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT MembershipDB.customerName, SalesDB.date, "
                    "SalesDB.itemPurchased, SalesDB.quantity "
                    "FROM MembershipDB "
                    "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                    "WHERE MembershipDB.membershipType = 'Regular' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));

    // Display table with query model
    ui->salesReportTableView->setModel(model);
}

//prints the sales daily report for the entered date
void managerInventory::on_pushButton_3_clicked()
{
    QString texttmp = ui->textEdit->toPlainText();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQueryModel *totalRevenue = new QSqlQueryModel;

    model->setQuery("SELECT MembershipDB.customerName, SalesDB.date, "
                    "SalesDB.itemPurchased, SalesDB.quantity "
                    "FROM SalesDB "
                    "INNER JOIN MembershipDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                     "WHERE SalesDB.date = '"+ texttmp + "' ");

    totalRevenue->setQuery("SELECT SUM(SalesDB.salePrice*SalesDB.quantity) "
                           "FROM SalesDB "
                           "WHERE date = '"+ texttmp + "' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));

    // Display table with query model
    ui->salesReportTableView->setModel(model);
    ui->tableView->setModel(totalRevenue);
}
