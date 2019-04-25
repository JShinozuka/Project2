#include "aInventory.h"
#include "ui_aInventory.h"

aInventory::aInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aInventory)
{
    ui->setupUi(this);

    // Populate table with defaultTableView()
    defaultTableView();
    defaultView();
}

aInventory::~aInventory()
{
    delete ui;
}

void aInventory::defaultTableView()
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

    // Set Table Column Width
    ui->inventoryTableView->setColumnWidth(0,200);
    ui->inventoryTableView->setColumnWidth(1,100);
    ui->inventoryTableView->setColumnWidth(2,125);

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Item Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Item Qty"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Total"));
}

void aInventory::defaultView()
{
    //POPULATE THE COMBO BOXES
    QSqlQuery * qry = new QSqlQuery(myDB);
    QSqlQueryModel * combo = new QSqlQueryModel();

    qry->prepare("SELECT DISTINCT itemName "
                 "FROM InventoryDB ORDER BY itemName COLLATE NOCASE ASC");
    qry->exec();
    combo->setQuery(*qry);

    // Updating the EDIT item name combo box
    ui->currItemNameCombo->setModel(combo);
    ui->currItemNameCombo->setStyleSheet("QComboBox { background-color: LightBlue; }");

    // Updating the DELETE item name combo box
    ui->delNameComboBox->setModel(combo);
    ui->delNameComboBox->setStyleSheet("QComboBox { background-color: LightBlue; }");
}
/*
void aInventory::on_delNameComboBox_currentIndexChanged()
{
    qDebug() << "Your changed it.";
    // Get name of current item selected in delete secion
    itemName = ui->delNameComboBox->currentText();

    qDebug() << "Current item name: " << itemName;

    QSqlQuery qry2;
    qry2.prepare("SELECT * "
                 "FROM InventoryDB "
                 "WHERE itemName='"+itemName+"'");

    if(qry2.exec())
    {
        while(qry2.next())
        {
            ui->itemQtyLine->setText(qry2.value(1).toString());
            ui->itemTotalRevenueLine->setText(qry2.value(2).toString());
        }
    }
    else
    {
        qDebug() << ("Admin Inventory Widget Error: Unable to update delete qty and revenue lines.");
    }
}*/

