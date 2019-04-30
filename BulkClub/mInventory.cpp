#include "mInventory.h"
#include "ui_mInventory.h"

/****************************************************************************
 * CONSTRUCTOR
 * --------------------------------------------------------------------------
 * Displays Inventory Information Report Table and populates the item name
 * combo box.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      Database class created to connect to data base. Combo box & line edits
 * created.
 *
 * POST-CONDITIONS
 *      ==> Populates table view and combo box.
 ***************************************************************************/


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



    //POPULATE THE item name combo box
    QSqlQuery * qry = new QSqlQuery(myDB);

    QSqlQueryModel * combo = new QSqlQueryModel();


    qry->prepare("SELECT DISTINCT itemName "
                 "FROM InventoryDB ORDER BY itemName COLLATE NOCASE ASC");
    qry->exec();

    combo->setQuery(*qry);

    ui->InventoryComboBox->setModel(combo);

    ui->InventoryComboBox->setStyleSheet("QComboBox { background-color: LightBlue; }");

}

mInventory::~mInventory()
{
    delete ui;
}

/****************************************************************************
 * on_InventoryComboBox_currentIndexChanged()
 * --------------------------------------------------------------------------
 * Updates line edit fields (item quantity & item total)
 * based on inventory item name selected.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      line edit fields created, item name combo box created.
 *
 * POST-CONDITIONS
 *      ==> populates line edit fields (item quantity & item total).
 ***************************************************************************/

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
