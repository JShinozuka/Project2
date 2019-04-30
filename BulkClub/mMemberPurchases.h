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
    //!< Populates table view and combo boxes
    /*!< POSTCONDITONS:Table view is updated with the following fields:
    *< customer name, membership #, order ID, date, item purchased & qty and is ordered by member ID.
    *< Combo boxes are updated with member name, id and order id */

private slots:
    void on_memberIDcomboBox_currentIndexChanged();
    //!< Populates fields based on membership ID change including sale ID, date, item, price, qty & updates the membership name to match
    /*!< POSTCONDITONS: updates sale ID, date, item, price, qty & membership name */

    void on_orderIDcomboBox_currentIndexChanged();
    //!< Populates fields based on saleID change including date, item, price, qty
    /*!< POSTCONDITONS: updates date, item, price and qty */


    void on_memberNameComboBox_currentIndexChanged();
    //!< Populates fields based on membership name change including date, item, price, qty & updates member ID to match
    /*!< POSTCONDITONS: updates date, item, price and qty & member ID */

    void on_resetButton_clicked();
    //!< Calls defaultReset() function and resets combo

private:
    Ui::mMemberPurchases *ui;

    //bool variables are used to prevent index change functions from being called unintentionally
    bool flag = false;       //flag is only turned on when constructor or default reset function called and turned off when constructor/default reset finishes execution
    bool flagName = false;   //flagName is only turned on when on_memberNameComboBox_currentIndexChanged() executes and turned off when it's finished executing.
    bool flagID = false;     //flagID is only turned on when on_memberIDcomboBox_currentIndexChanged() executes and turned off when it's finished executing.
    QSqlDatabase myDB; // Database object for database connection
};

#endif // MMEMBERPURCHASES_H
