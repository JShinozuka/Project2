#ifndef MMEMBERSHIPEXPIRE_H
#define MMEMBERSHIPEXPIRE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class mMembershipExpire;
}

class mMembershipExpire : public QWidget
{
    Q_OBJECT

public:

    explicit mMembershipExpire(QWidget *parent = nullptr);
    ~mMembershipExpire();

    void displayDefaultExpireTable() const;
    //!< Displays all membership expiration
    /*!< POST: Displays customer name, membership number, membership type,
               and expiration date */
    /*!< Additional Notes: Ordered by expiration date */

private slots:

    void on_selectMonthBox_currentIndexChanged(int index);
    //!< Displays selected month's membership expiration
    /*!< POST: Displays customer name, membership number, membership type,
               and expiration date */
    /*!< Additional Notes: Ordered by expiration date */

private:
    Ui::mMembershipExpire *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif // MMEMBERSHIPEXPIRE_H
