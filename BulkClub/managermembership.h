#ifndef MANAGERMEMBERSHIP_H
#define MANAGERMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class managerMembership;
}

class managerMembership : public QWidget
{
    Q_OBJECT

public:
    explicit managerMembership(QWidget *parent = nullptr);
    ~managerMembership();

    void closeDB();
    //!< Closes database connection if still open

private:
    Ui::managerMembership *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif // MANAGERMEMBERSHIP_H
