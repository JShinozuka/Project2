#ifndef MMEMBERPURCHASES_H
#define MMEMBERPURCHASES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class mMemberPurchases;
}

class mMemberPurchases : public QWidget
{
    Q_OBJECT

public:
    explicit mMemberPurchases(QWidget *parent = nullptr);
    ~mMemberPurchases();

private slots:
    void on_memberIDcomboBox_currentIndexChanged();
    //!< Populates fields based on membership ID change including sale ID, date, item, price, qty
    /*!< POSTCONDITONS: updates sale ID, date, item, price and qty */

    void on_orderIDcomboBox_currentIndexChanged();
    //!< Populates fields based on saleID change including date, item, price, qty
    /*!< POSTCONDITONS: updates date, item, price and qty */


private:
    Ui::mMemberPurchases *ui;
    QSqlDatabase myDB; // Database object for database connection
};

#endif // MMEMBERPURCHASES_H
