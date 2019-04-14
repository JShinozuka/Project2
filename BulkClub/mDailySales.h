#ifndef MDAILYSALES_H
#define MDAILYSALES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class mDailySales;
}

class mDailySales : public QWidget
{
    Q_OBJECT

public:
    explicit mDailySales(QWidget *parent = nullptr);
    ~mDailySales();

private slots:
    void on_pushButton_clicked();

    void on_selectDateButton_clicked();

    void on_viewAllMembersButton_clicked();

    void on_regularMembersView_clicked();

private:
    Ui::mDailySales *ui;
    QSqlDatabase myDB; // Database object for database connection
};

#endif // MDAILYSALES_H
