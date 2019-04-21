#ifndef ACONVERTMEMBERSHIP_H
#define ACONVERTMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class aConvertMembership;
}

class aConvertMembership : public QWidget
{
    Q_OBJECT

public:
    explicit aConvertMembership(QWidget *parent = nullptr);
    ~aConvertMembership();
    void displayUpGradeTable() const;
    void displayDownGradeTable() const;


private:
    Ui::aConvertMembership *ui;
    QSqlDatabase myDB;
};

#endif // ACONVERTMEMBERSHIP_H
