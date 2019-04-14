#ifndef ASALES_H
#define ASALES_H

#include <QWidget>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class aSales;
}

class aSales : public QWidget
{
    Q_OBJECT

public:
    explicit aSales(QWidget *parent = nullptr);
    ~aSales();

private:
    Ui::aSales *ui;

    const double TAX_RATE_VAR = 0.0775;
    const double REBATE_RATE_VAR = 0.02;

    QSqlDatabase myDB; // Database object for database connection
    int monthVar, dayVar, yearVar, membershipNumVar, qtyVar;
    QString saleIDVar, itemPurchasedVar, dateVar;
    double salesPriceVar, itemTotalVar, totalAmtSpentVar, rebateVar;

};

#endif // ASALES_H
