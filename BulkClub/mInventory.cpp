#include "mInventory.h"
#include "ui_mInventory.h"

mInventory::mInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mInventory)
{

    //DISPLAY THE TABLE
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT itemName, itemQty, itemTotal "
                    "FROM InventoryDB "
                    "ORDER BY itemName COLLATE NOCASE ASC ");

    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->inventoryTableView->setModel(model);

    qDebug() << "MODEL ROW COUNT" << (model->rowCount());

    // Set Table Column Width
    ui->inventoryTableView->setColumnWidth(0,200);
    ui->inventoryTableView->setColumnWidth(1,100);
    ui->inventoryTableView->setColumnWidth(2,150);


    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Item Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Item Qty"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Total"));



    //POPULATE THE COMBO BOXES

    QSqlQuery * qry = new QSqlQuery(myDB);

    QSqlQueryModel * combo = new QSqlQueryModel();


    qry->prepare("SELECT DISTINCT itemName "
                 "FROM InventoryDB ORDER BY itemName COLLATE NOCASE ASC");
    qry->exec();

    combo->setQuery(*qry);

    ui->InventoryComboBox->setModel(combo);

    ui->InventoryComboBox->setStyleSheet("QComboBox { background-color: LightBlue; }");

    /*
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

mInventory::~mInventory()
{
    delete ui;
}



void mInventory::on_InventoryComboBox_currentIndexChanged()
{
    QString name = ui->InventoryComboBox->currentText();

    qDebug() << name;

    QSqlQuery qry;

    qry.prepare("SELECT itemQty, itemTotal "
                " FROM InventoryDB WHERE itemName='"+ name + "' ");

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

            sale = qry.value(1).toDouble();

            ui->itemQuantityLineEdit->setText(qry.value(0).toString());
            ui->itemTotalLineEdit->setText(QString::number(sale,'f',2));

         }
    }
    else
    {
        qDebug() << ("qry not work");
    }


}
