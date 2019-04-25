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
    //!< Prints the executive member sales report
    /*!< POST: Displays customer name, date, item purchase
    and quantity */

    void on_selectDateButton_clicked();
    //!< Prints the sales report for selected date
    /*!< POST: Displays customer name, date, item purchase
    and quantity */

    void on_viewAllMembersButton_clicked();
    //!< Prints the sales report for selected date
    /*!< POST: Displays customer name, date, item purchase
    and quantity */

    void on_regularMembersView_clicked();
    //!< Prints the regular member sales report
    /*!< POST: Displays customer name, date, item purchase
    and quantity */

private:
    /*!
     * \var ui
     */

    Ui::mDailySales *ui;
    /*!
     * \var myDB
     */
    QSqlDatabase myDB; // Database object for database connection

    /*!
     * \var year
     * \brief Qstring year variable
     */
    QString year;                   //IN&OUT- Qstring year variable
    /*!
     * \var month
     * \brief Qstring year variable
     */
    QString month;                  //IN&OUT- Qstring month variable

    /*!
     * \var day
     * \brief Qstring year variable
     */
    QString day;                    //IN&OUT- Qstring day variable
};

#endif // MDAILYSALES_H
