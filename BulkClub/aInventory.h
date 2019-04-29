#ifndef AINVENTORY_H
#define AINVENTORY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class aInventory;
}

class aInventory : public QWidget
{
    Q_OBJECT

public:
    explicit aInventory(QWidget *parent = nullptr);
    ~aInventory();

    void defaultTableView();
    //!< Displays default table
    void defaultView();
    //!< Displays default values in add and delete groups

private slots:
    void on_addItemButton_clicked();
    //!< Adds new item name to InventoryDB
    /*!< itemName  = ui->addItemNameLine->text(); */
    /*!< itemQty   = 0; itemTotal = 0.0 */

    void on_deleteItemButton_clicked();
    //!< Deletes an item from the InventoryDB

    void on_delNameComboBox_currentIndexChanged();
    //!< Updates information in the delete group when index is changed

private:
    Ui::aInventory *ui;
    QSqlDatabase myDB; // Database object for database connection

    QString itemName;  // IN&CALC - name of item
    int     itemQty;   // OUT     - quantity of the item
    double  itemTotal; // OUT     - revenue total of the item
};

#endif // AINVENTORY_H
