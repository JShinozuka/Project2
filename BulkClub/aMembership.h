#ifndef AMEMBERSHIP_H
#define AMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class aMembership;
}

class aMembership : public QWidget
{
    Q_OBJECT

public:
    explicit aMembership(QWidget *parent = nullptr);
    ~aMembership();

private:
    Ui::aMembership *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif // AMEMBERSHIP_H
