#include "aInventory.h"
#include "ui_aInventory.h"

// Default constructor
aInventory::aInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aInventory)
{
    ui->setupUi(this);

    // Set connection to database
    myDB = QSqlDatabase::database();

    // Populate table with defaultTableView()
    defaultTableView();
    defaultView();
}

// Destructor
aInventory::~aInventory()
{
    delete ui;
}

/****************************************************************************
 * METHOD - defaultTableView
 * --------------------------------------------------------------------------
 * Displays the default table for the inventory database.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
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
    ui->inventoryTableView->setColumnWidth(0,225);
    ui->inventoryTableView->setColumnWidth(1,100);
    ui->inventoryTableView->setColumnWidth(2,125);

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Item Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Item Qty"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Item Total"));
}

/****************************************************************************
 * METHOD - defaultView
 * --------------------------------------------------------------------------
 * Displays the default values in elements for Edit and Delete fields.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void aInventory::defaultView()
{
    //POPULATE THE COMBO BOXES with default
    QSqlQuery * qry = new QSqlQuery(myDB);
    QSqlQueryModel * combo = new QSqlQueryModel();

    qry->prepare("SELECT DISTINCT itemName "
                 "FROM InventoryDB ORDER BY itemName COLLATE NOCASE ASC");
    qry->exec();
    combo->setQuery(*qry);

    // Updating the DELETE item name combo box
    ui->delNameComboBox->setModel(combo);
    ui->delNameComboBox->setStyleSheet("QComboBox{background-color: LightBlue;}");
}

/****************************************************************************
 * METHOD - on_addItemButton_clicked
 * --------------------------------------------------------------------------
 * Adds a new item to inventory database.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
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

    // Stores new record into database
    query.bindValue(0,itemName);
    query.bindValue(1,itemQty);
    query.bindValue(2,itemTotal);

    if(query.exec())
    {
        qDebug()<<("New item added to inventory database.");
    }
    else
    {
        qDebug()<<("Failed to add new item to inventory database.");
        if(query.lastError().isValid())
        {
            QMessageBox::warning(this, "Unable to Add Item",
                                       "Please enter a unique item name.",
                                          QMessageBox::Ok);
        }
//        qDebug() << query.lastError();
    }

    // Reset default
    ui->addItemNameLine->setText("");
    defaultTableView();
    defaultView();
}

/****************************************************************************
 * METHOD - on_deleteItemButton_clicked
 * --------------------------------------------------------------------------
 * Deletes a selected item from database after confirmation.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void aInventory::on_deleteItemButton_clicked()
{
    // Create variable to store the reply from messagebox button click
    QMessageBox::StandardButton reply;

    // Prompt confirmation for delete
    reply = QMessageBox::question(this, "Delete Confirmation",
                                  "Are you sure you want to delete?",
                                  QMessageBox::Yes|QMessageBox::No);

    // Only deletes if "Yes" is selected from message confirmation
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
    // Exits delete process if "No" was selected in confirmation
    else
    {
        qDebug() << "Delete was cancelled.";
    }

    // Reset to default
    defaultTableView();
    defaultView();
}

/****************************************************************************
 * METHOD - on_delNameComboBox_currentIndexChanged
 * --------------------------------------------------------------------------
 * Displays default values for the delete item section
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void aInventory::on_delNameComboBox_currentIndexChanged()
{
    // Set to default in case empty
    ui->itemQtyLine->setText("");
    ui->itemTotalRevenueLine->setText("");

    // Get name of current item selected in delete section
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
