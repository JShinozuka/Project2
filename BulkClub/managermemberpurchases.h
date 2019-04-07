#ifndef MANAGERMEMBERPURCHASES_H
#define MANAGERMEMBERPURCHASES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class managerMemberPurchases;
}

class managerMemberPurchases : public QWidget
{
    Q_OBJECT

public:
    explicit managerMemberPurchases(QWidget *parent = nullptr);
    ~managerMemberPurchases();

private slots:
    void on_memberIDcomboBox_currentIndexChanged();
    //!< Populates fields based on membership ID change including sale ID, date, item, price, qty
    /*!< POSTCONDITONS: updates sale ID, date, item, price and qty */

    void on_orderIDcomboBox_currentIndexChanged();
    //!< Populates fields based on saleID change including date, item, price, qty
    /*!< POSTCONDITONS: updates date, item, price and qty */


private:
    Ui::managerMemberPurchases *ui;
    QSqlDatabase myDB; // Database object for database connection
};

#endif // MANAGERMEMBERPURCHASES_H
