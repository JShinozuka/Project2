#ifndef AINVENTORY_H
#define AINVENTORY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

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
    void defaultView();

private slots:
//    void on_delNameComboBox_currentIndexChanged();

   // void on_delNameComboBox_currentIndexChanged(int index);

private:
    Ui::aInventory *ui;
    QSqlDatabase myDB; // Database object for database connection

    QString itemName; //
};

#endif // AINVENTORY_H
