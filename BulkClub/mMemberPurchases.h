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

    void defaultReset();

private slots:
    void on_memberIDcomboBox_currentIndexChanged();
    //!< Populates fields based on membership ID change including sale ID, date, item, price, qty
    /*!< POSTCONDITONS: updates sale ID, date, item, price and qty */

    void on_orderIDcomboBox_currentIndexChanged();
    //!< Populates fields based on saleID change including date, item, price, qty
    /*!< POSTCONDITONS: updates date, item, price and qty */


    void on_memberNameComboBox_currentIndexChanged();
    //!< Populates fields based on membership name change including date, item, price, qty
    /*!< POSTCONDITONS: updates date, item, price and qty */

    void on_resetButton_clicked();

private:
    Ui::mMemberPurchases *ui;
    bool flag = false; //bool variable to control when index functions change..
    bool flagName = false;
    bool flagID = false;
    QSqlDatabase myDB; // Database object for database connection
};

#endif // MMEMBERPURCHASES_H
