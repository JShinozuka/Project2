#include "aSales.h"
#include "ui_aSales.h"

aSales::aSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aSales)
{

    //DISPLAY THE TABLE
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT SaleID, date, membershipNum, itemPurchased, quantity, salePrice "
                    "FROM SalesDB "
                    "ORDER BY SaleID COLLATE NOCASE ASC ");

    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->aSalesTableView->setModel(model);

    qDebug() << "MODEL ROW COUNT" << (model->rowCount());

    // Set Table Column Width
    ui->aSalesTableView->setColumnWidth(0,100);
    ui->aSalesTableView->setColumnWidth(1,120);
    ui->aSalesTableView->setColumnWidth(2,150);
    ui->aSalesTableView->setColumnWidth(3,150);
    ui->aSalesTableView->setColumnWidth(4,60);
    ui->aSalesTableView->setColumnWidth(5,80);

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Order ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Membership #"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Item Name"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Qty"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Price"));

    /*

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

    */
}

aSales::~aSales()
{
    delete ui;
}
