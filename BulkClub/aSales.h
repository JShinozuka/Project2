#ifndef ASALES_H
#define ASALES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>


namespace Ui {
class aSales;
}

class aSales : public QWidget
{
    Q_OBJECT

public:
    explicit aSales(QWidget *parent = nullptr);
    ~aSales();
    void defaultAddSale(); // default sales form

private slots:
    void on_addSalesButton_clicked();

private:
    Ui::aSales *ui;

    const double TAX_RATE_VAR = 0.0775;
    const double REBATE_RATE_VAR = 0.02;

    QSqlDatabase myDB; // Database object for database connection
    int monthVar, dayVar, yearVar; //month, day and year variables
    int membershipNumVar; // membership number
    int qtyVar; // quantity
    QString saleIDVar = "";
    QString itemPurchasedVar, dateVar;
    double salesPriceVar; //sales price
    double salesTotalVar; // sales price * quantity + tax
    double totalAmtSpentVar; // total amount member spent
    double rebateVar;        // rebate amount

};

#endif // ASALES_H
