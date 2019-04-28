#include "mDailySales.h"
#include "ui_mDailySales.h"

mDailySales::mDailySales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mDailySales)
{
    ui->setupUi(this);
    //displaySalesReport();
}

mDailySales::~mDailySales()
{
    delete ui;
}

/*****************************************************************
 * METHOD - on_pushButton_clicked
 * ---------------------------------------------------------------
 * This method printst the executive member daily sales report
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          year  : Qstring year variable
 *          month : Qstring month variable
 *          day   : Qstring day variable
 * POST-CONDITIONS
 *
 *****************************************************************/
void mDailySales::on_pushButton_clicked()
{
    year = ui->yearBox->currentText();
    month = ui->monthBox->currentText();
    day = ui->dateBox->currentText();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT MembershipDB.customerName, SalesDB.date, "
                    "SalesDB.itemPurchased, SalesDB.quantity "
                    "FROM MembershipDB "
                    "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                    "WHERE MembershipDB.membershipType = 'Executive' "
                    "AND SalesDB.month = '"+ month + "' "
                    "AND SalesDB.day = '"+ day + "' "
                    "AND SalesDB.year = '"+ year + "' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));

    // Display table with query model
    ui->salesReportTableView->setModel(model);
}

/*****************************************************************
 * METHOD - on_selectDateButton_clicked()
 * ---------------------------------------------------------------
 * This method prints the daily sales report for the selected
 * date
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          year  : Qstring year variable
 *          month : Qstring month variable
 *          day   : Qstring day variable
 * POST-CONDITIONS
 *
 *****************************************************************/
void mDailySales::on_selectDateButton_clicked()
{
    year = ui->yearBox->currentText();
    month = ui->monthBox->currentText();
    day = ui->dateBox->currentText();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery totalRevenueCalc;
    QSqlQuery numOfExecMembers;
    QSqlQuery numOfRegMembers;

    qDebug() << year << month << day;

    model->setQuery("SELECT MembershipDB.customerName, SalesDB.date, "
                    "SalesDB.itemPurchased, SalesDB.quantity, MembershipDB.membershipType "
                    "FROM SalesDB "
                    "INNER JOIN MembershipDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                    "WHERE SalesDB.month = '"+ month + "' "
                    "AND SalesDB.day = '"+ day + "' "
                    "AND SalesDB.year = '"+ year + "' ");

    totalRevenueCalc.exec("SELECT SUM(SalesDB.salePrice*SalesDB.quantity) "
                           "FROM SalesDB "
                           "WHERE SalesDB.month = '"+ month + "' "
                           "AND SalesDB.day = '"+ day + "' "
                           "AND SalesDB.year = '"+ year + "' ");

    //query that takes date from sales db and membership type from membership db
    numOfExecMembers.exec("SELECT COUNT(MembershipDB.customerName) "
                          "FROM MembershipDB "
                          "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                          "WHERE MembershipDB.membershipType = 'Executive' "
                          "AND SalesDB.month = '"+ month + "' "
                          "AND SalesDB.day = '"+ day + "' "
                          "AND SalesDB.year = '"+ year + "' ");

    //query that takes date from sales db and membership type from membership db
    numOfRegMembers.exec("SELECT COUNT(MembershipDB.customerName) "
                         "FROM MembershipDB "
                         "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                         "WHERE MembershipDB.membershipType = 'Regular' "
                         "AND SalesDB.month = '"+ month + "' "
                         "AND SalesDB.day = '"+ day + "' "
                         "AND SalesDB.year = '"+ year + "' ");

    //print the total revenue for the day
    while (totalRevenueCalc.next()) {
    QString printRevenue = totalRevenueCalc.value(0).toString();
    ui->totalRevenue->setText(printRevenue);
    qDebug() << printRevenue;
    }

    while (numOfExecMembers.next()) {
    QString printExecMembers = numOfExecMembers.value(0).toString();
    ui->execMemTextEdit->setText(printExecMembers);
    qDebug() << printExecMembers;
    }

    while (numOfRegMembers.next()) {
    QString printRegMembers = numOfRegMembers.value(0).toString();
    ui->regMemTextEdit->setText(printRegMembers);
    qDebug() << printRegMembers;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Membership Type"));

    // Display table with query model
    ui->salesReportTableView->setModel(model);
}

/*****************************************************************
 * METHOD - on_viewAllMembersButton_clicked()
 * ---------------------------------------------------------------
 * This method prints the daily sales report for the selected
 * date
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          year  : Qstring year variable
 *          month : Qstring month variable
 *          day   : Qstring day variable
 *          totalRevenueCalc : total revenue variable
 *          numOfExecMembers : number of exec members
 *          numOfRegMembers  : number of reg members
 * POST-CONDITIONS
 *
 *****************************************************************/
void mDailySales::on_viewAllMembersButton_clicked()
{
    //change to date edit later
    year = ui->yearBox->currentText();
    month = ui->monthBox->currentText();
    day = ui->dateBox->currentText();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery totalRevenueCalc;
    QSqlQuery numOfExecMembers;
    QSqlQuery numOfRegMembers;

    model->setQuery("SELECT MembershipDB.customerName, SalesDB.date, "
                    "SalesDB.itemPurchased, SalesDB.quantity, MembershipDB.membershipType "
                    "FROM SalesDB "
                    "INNER JOIN MembershipDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                    "WHERE SalesDB.month = '"+ month + "' "
                    "AND SalesDB.day = '"+ day + "' "
                    "AND SalesDB.year = '"+ year + "' ");

    totalRevenueCalc.exec("SELECT SUM(SalesDB.salePrice*SalesDB.quantity) "
                           "FROM SalesDB "
                           "WHERE SalesDB.month = '"+ month + "' "
                           "AND SalesDB.day = '"+ day + "' "
                           "AND SalesDB.year = '"+ year + "' ");

    //query that takes date from sales db and membership type from membership db
    numOfExecMembers.exec("SELECT COUNT(MembershipDB.customerName) "
                          "FROM MembershipDB "
                          "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                          "WHERE MembershipDB.membershipType = 'Executive' "
                          "AND SalesDB.month = '"+ month + "' "
                          "AND SalesDB.day = '"+ day + "' "
                          "AND SalesDB.year = '"+ year + "' ");

    //query that takes date from sales db and membership type from membership db
    numOfRegMembers.exec("SELECT COUNT(MembershipDB.customerName) "
                         "FROM MembershipDB "
                         "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                         "WHERE MembershipDB.membershipType = 'Regular' "
                         "AND SalesDB.month = '"+ month + "' "
                         "AND SalesDB.day = '"+ day + "' "
                         "AND SalesDB.year = '"+ year + "' ");

    //print the total revenue for the day
    while (totalRevenueCalc.next()) {
    QString printRevenue = totalRevenueCalc.value(0).toString();
    ui->totalRevenue->setText(printRevenue);
    qDebug() << printRevenue;
    }

    while (numOfExecMembers.next()) {
    QString printExecMembers = numOfExecMembers.value(0).toString();
    ui->execMemTextEdit->setText(printExecMembers);
    qDebug() << printExecMembers;
    }

    while (numOfRegMembers.next()) {
    QString printRegMembers = numOfRegMembers.value(0).toString();
    ui->regMemTextEdit->setText(printRegMembers);
    qDebug() << printRegMembers;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Membership Type"));

    // Display table with query model
    ui->salesReportTableView->setModel(model);
}

/*****************************************************************
 * METHOD - on_pushButton_clicked
 * ---------------------------------------------------------------
 * This method printst the executive member daily sales report
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          year  : Qstring year variable
 *          month : Qstring month variable
 *          day   : Qstring day variable
 * POST-CONDITIONS
 *
 *****************************************************************/
void mDailySales::on_regularMembersView_clicked()
{
    year = ui->yearBox->currentText();
    month = ui->monthBox->currentText();
    day = ui->dateBox->currentText();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT MembershipDB.customerName, SalesDB.date, "
                    "SalesDB.itemPurchased, SalesDB.quantity "
                    "FROM MembershipDB "
                    "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                    "WHERE MembershipDB.membershipType = 'Regular' "
                    "AND SalesDB.month = '"+ month + "' "
                    "AND SalesDB.day = '"+ day + "' "
                    "AND SalesDB.year = '"+ year + "' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));

    // Display table with query model
    ui->salesReportTableView->setModel(model);
}
