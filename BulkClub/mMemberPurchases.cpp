#include "mMemberPurchases.h"
#include "ui_mMemberpurchases.h"

/****************************************************************************
 * CONSTRUCTOR
 * --------------------------------------------------------------------------
 * Displays Manager Member Purchase Table and populates the line edit fields for
 * membership number, saleID, date, item purchased, quantity ordered by
 * Membership number.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      Database class created to connect to data base.
 *
 * POST-CONDITIONS
 *      ==> Populates line edit fields
 ***************************************************************************/
mMemberPurchases::mMemberPurchases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mMemberPurchases)
{
    //DISPLAY THE TABLE
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT membershipNum, saleID, date, itemPurchased, quantity "
                    "FROM SalesDB "
                    "ORDER BY membershipNum COLLATE NOCASE ASC ");

    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->membershipPurchaseTableView->setModel(model);

    qDebug() << "MODEL ROW COUNT" << (model->rowCount());

    // Set Table Column Width
    ui->membershipPurchaseTableView->setColumnWidth(0,150);
    ui->membershipPurchaseTableView->setColumnWidth(1,200);
    ui->membershipPurchaseTableView->setColumnWidth(2,150);
    ui->membershipPurchaseTableView->setColumnWidth(3,150);
    ui->membershipPurchaseTableView->setColumnWidth(4,80);

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Membership #"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Order ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Qty"));

    //POPULATE THE COMBO BOXES

    QSqlQuery * qry = new QSqlQuery(myDB);

    QSqlQueryModel * combo = new QSqlQueryModel();


    qry->prepare("SELECT DISTINCT membershipNum "
                 "FROM salesDB ORDER BY membershipNum COLLATE NOCASE ASC");
    qry->exec();

    combo->setQuery(*qry);

    ui->memberIDcomboBox->setModel(combo);

    //QSqlQuery * qry2 = new QSqlQuery(myDB);
    QSqlQueryModel * combo2 = new QSqlQueryModel();

    //changed today 4/7/19 - CL
    QString membID = ui->memberIDcomboBox->currentText();
    qDebug() << "membID: " << membID;
    qry->prepare("SELECT saleID "
                  "FROM SalesDB "
                  "WHERE membershipNum = '"+membID+"' "
                  "ORDER BY saleID COLLATE NOCASE ASC" );
    qry->exec();

    combo2->setQuery(*qry);

    ui->orderIDcomboBox->setModel(combo2);

}

/****************************************************************************
 * DESTRUCTOR
 * --------------------------------------------------------------------------
 * DELETES ui
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      ui exists
 *
 * POST-CONDITIONS
 *      ==> Deletes ui
 ***************************************************************************/
mMemberPurchases::~mMemberPurchases()
{
    delete ui;
}

/****************************************************************************
 * on_memberIDcomboBox_currentIndexChanged()
 * --------------------------------------------------------------------------
 * Changes line edit fields (salesID, item purchased, salePrice, quantity
 * based on memberID selected)
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      line edit fields created, salesID combo created.
 *
 * POST-CONDITIONS
 *      ==> populates line edit fields (salesID, item purchased, salePrice, quantity
 * based on memberID selected)
 ***************************************************************************/
void mMemberPurchases::on_memberIDcomboBox_currentIndexChanged()
{

    QString id = ui->memberIDcomboBox->currentText();

    qDebug() << id;

    QSqlQuery qry,qry2;

    qry.prepare("SELECT date,itemPurchased, salePrice, quantity "
                " FROM salesDB WHERE membershipNum='"+ id + "' ");

    if(qry.exec())
    {
        while(qry.next())
        {
            //double salesTax, totalPrice;
            double sale;

            /************************************************************
             * PROCESSING - Update all line edits boxes with data from
             *              the sales database for selected memberID
             ************************************************************/

            sale = qry.value(2).toDouble();

            ui->dateLineEdit->setText(qry.value(0).toString());
            ui->itemPurchasedLineEdit->setText(qry.value(1).toString());
            ui->salePriceLineEdit->setText(QString::number(sale,'f',2));
            ui->quantityLineEdit->setText(qry.value(3).toString());
        }
    }
    else
    {
        qDebug() << ("qry not work");
    }

    qry2.prepare("SELECT totalAmountSpent "
                 " FROM MembershipDB WHERE membershipNumber= '"+ id + "'");

    if(qry2.exec())
    {
        while(qry2.next())
        {

            double total;

            /************************************************************
             * PROCESSING - Update grand total line edit with data from
             *              the membership database for selected memberID
             ************************************************************/

            total = qry2.value(0).toDouble();


            ui->grandTotalLineEdit->setText(QString::number(total,'f',2));

        }
    }
    else
    {
        qDebug() << ("qry2 did not work");
    }

    QSqlQuery * qry3 = new QSqlQuery(myDB);
    QSqlQueryModel * combo2 = new QSqlQueryModel();


    QString membID = ui->memberIDcomboBox->currentText();
    qDebug() << "membID: " << membID;
    qry3->prepare("SELECT saleID "
                  "FROM SalesDB "
                  "WHERE membershipNum = '"+membID+"' "
                  "ORDER BY saleID COLLATE NOCASE DESC" );

    qry3->exec();

    combo2->setQuery(*qry3);

    ui->orderIDcomboBox->setModel(combo2);

}

/****************************************************************************
 * on_orderIDcomboBox_currentIndexChanged()
 * --------------------------------------------------------------------------
 * Changes line edit fields (salesID, item purchased, salePrice, quantity
 * based on orderID selected)
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      line edit fields created, memberID & salesID combo boxes created.
 *
 * POST-CONDITIONS
 *      ==> populates line edit fields (item purchased, salePrice, quantity
 * based on orderID selected)
 ***************************************************************************/

void mMemberPurchases::on_orderIDcomboBox_currentIndexChanged()
{

    QString salesID = ui->orderIDcomboBox->currentText();

    qDebug() << salesID;

    QSqlQuery qry,qry2;

    qry.prepare("SELECT date,itemPurchased, salePrice, quantity, membershipNum "
                " FROM SalesDB WHERE saleID='"+ salesID + "'");

    if(qry.exec())
    {
        while(qry.next())
        {
            //double salesTax, totalPrice;
            double sale;

            /************************************************************
             * PROCESSING - Update all line edits boxes with data from
             *              the sales database for selected memberID
             ************************************************************/

            sale = qry.value(2).toDouble();

            ui->dateLineEdit->setText(qry.value(0).toString());
            ui->itemPurchasedLineEdit->setText(qry.value(1).toString());
            ui->salePriceLineEdit->setText(QString::number(sale,'f',2));
            ui->quantityLineEdit->setText(qry.value(3).toString());


        }

    }
    else
    {
        qDebug() << ("qry not work");
    }

    QString id2 = ui->memberIDcomboBox->currentText();

    qry2.prepare("SELECT totalAmountSpent "
                 " FROM MembershipDB WHERE membershipNumber= '"+ id2 + "'");

    if(qry2.exec())
    {
        while(qry2.next())
        {

            double total;

            /************************************************************
             * PROCESSING - Update grand total line edit with data from
             *              the membership database for selected memberID
             ************************************************************/

            total = qry2.value(0).toDouble();
            ui->grandTotalLineEdit->setText(QString::number(total,'f',2));

        }
    }

    else
    {
        qDebug() << ("qry2 did not work");
    }
}
