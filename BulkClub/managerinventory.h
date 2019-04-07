#ifndef MANAGERINVENTORY_H
#define MANAGERINVENTORY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class managerInventory;
}

class managerInventory : public QWidget
{
    Q_OBJECT

public:
    explicit managerInventory(QWidget *parent = nullptr);
    ~managerInventory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::managerInventory *ui;
    QSqlDatabase myDB; // Database object for database connection
};

#endif // MANAGERINVENTORY_H
