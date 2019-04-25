#include "aInventory.h"
#include "ui_aInventory.h"

aInventory::aInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aInventory)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

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
    // POPULATE TABLE with default
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
    //POPULATE THE COMBO BOXES with default
    QSqlQuery * qry = new QSqlQuery(myDB);
    QSqlQueryModel * combo = new QSqlQueryModel();

    qry->prepare("SELECT DISTINCT itemName "
                 "FROM InventoryDB ORDER BY itemName COLLATE NOCASE ASC");
    qry->exec();
    combo->setQuery(*qry);

    // Updating the EDIT item name combo box
    ui->currItemNameCombo->setModel(combo);
    ui->currItemNameCombo->setStyleSheet("QComboBox{background-color: LightBlue;}");

    // Updating the DELETE item name combo box
    ui->delNameComboBox->setModel(combo);
    ui->delNameComboBox->setStyleSheet("QComboBox{background-color: LightBlue;}");
}

void aInventory::on_addItemButton_clicked()
{
    // Initialize variables to insert into inventory database
    itemName  = ui->addItemNameLine->text();
    itemQty   = 0;
    itemTotal = 0.0;

    qDebug() << "Adding New Item Name: " << itemName;

    QSqlQuery query;
    query.prepare("INSERT INTO InventoryDB(itemName,itemQty,itemTotal) "
                  "VALUES (:itemName, :itemQty, :itemTotal)");

    query.bindValue(0,itemName);
    query.bindValue(1,itemQty);
    query.bindValue(2,itemTotal);

    if(query.exec())
        qDebug()<<("New item added to inventory database.");
    else
        qDebug()<<("Failed to add new item to inventory database.");

    ui->addItemNameLine->setText("");
    defaultTableView();
    defaultView();
}

void aInventory::on_editItemButton_clicked()
{
    QString currItemName;

    currItemName = ui->currItemNameCombo->currentText();
    itemName = ui->newItemNameLine->text();

    qDebug() << currItemName << " and " << itemName;

    QSqlQuery query;
    query.prepare("UPDATE InventoryDB "
                  "SET itemName = '"+itemName+"' "
                  "WHERE itemName = '"+currItemName+"'");

    if(query.exec())
        qDebug()<<("Item name edit successful.");
    else
        qDebug()<<("Item name edit failed.");

    // Reset to default
    ui->newItemNameLine->setText("");
    defaultTableView();
    defaultView();
}

void aInventory::on_deleteItemButton_clicked()
{
    // Create variable to store the reply from messagebox button click
    QMessageBox::StandardButton reply;

    // Prompt confirmation for delete
    reply = QMessageBox::question(this, "Delete Confirmation",
                                  "Are you sure you want to delete?",
                                  QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        // Get name of item to be deleted
        itemName = ui->delNameComboBox->currentText();

        qDebug() << "Item name: " << itemName;

        QSqlQuery query;
        query.prepare("DELETE FROM InventoryDB "
                      "WHERE itemName='"+itemName+"'");

        if(query.exec())
            qDebug()<<("Item name was successfully deleted.") << itemName;
        else
            qDebug()<<("Item failed to delete.") << itemName;
    }
    else
    {
        qDebug() << "Delete was cancelled.";
    }

    // Reset to default
    defaultTableView();
    defaultView();
}

void aInventory::on_delNameComboBox_currentIndexChanged()
{
    // Set to default in case empty
    ui->itemQtyLine->setText("");
    ui->itemTotalRevenueLine->setText("");

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
        qDebug() << ("Admin Inventory Widget Error: "
                     "Unable to update delete qty and revenue lines.");
    }
}
