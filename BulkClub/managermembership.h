#ifndef MANAGERMEMBERSHIP_H
#define MANAGERMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class managerMembership;
}

class managerMembership : public QWidget
{
    Q_OBJECT

public:

    explicit managerMembership(QWidget *parent = nullptr);
    ~managerMembership();

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

    void on_membershipExpirationTable_activated(const QModelIndex &index);

private:
    Ui::managerMembership *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif // MANAGERMEMBERSHIP_H
