#ifndef ASALES_H
#define ASALES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

namespace Ui {
class aSales;
}

class aSales : public QWidget
{
    Q_OBJECT

public:
    explicit aSales(QWidget *parent = nullptr);
    ~aSales();
    void defaultSalesTable();
    void defaultAddSale(); // default sales form
    void addSaleToDB();

private slots:
    void on_addSalesButton_clicked();

    void on_salesFileButton_clicked();

private:
    Ui::aSales *ui;

    const double TAX_RATE_VAR = 0.0775;
    const double REBATE_RATE_VAR = 0.02;

    QSqlDatabase myDB; // Database object for database connection

    // Sales DB variables
    int monthVar, dayVar, yearVar; //month, day and year variables
    int membershipNumVar;          // membership number
    int qtyVar;                    // quantity
/****************** not recommended to initalize variables here *****/
    QString saleIDVar = ""; //
    QString itemPurchasedVar, dateVar;
    double salesPriceVar; //sales price
    double salesTotalVar; // sales price * quantity (no tax)
    double salesWithTaxVar; // salesTotalVar with tax

    // Membership DB variables
    double totalAmtSpentVar; // total amount member spent
    double rebateVar;        // rebate amount

    // Inventory DB variables
    int itemQty; // item quantity
    double itemTotal; // item total revenue
};

#endif // ASALES_H
