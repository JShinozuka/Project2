#ifndef ADMINMEMBERSHIP_H
#define ADMINMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class adminMembership;
}

class adminMembership : public QWidget
{
    Q_OBJECT

public:
    explicit adminMembership(QWidget *parent = nullptr);
    ~adminMembership();

private:
    Ui::adminMembership *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif // ADMINMEMBERSHIP_H
