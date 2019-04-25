#ifndef AMEMBERSHIP_H
#define AMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

/*!
 *\namespace Ui
 */
namespace Ui {
class aMembership;
}

/*!
 * \brief The aMembership class
 * \class aMembership
 */
class aMembership : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief aMembership
     * \param parent
     */
    explicit aMembership(QWidget *parent = nullptr);

    ~aMembership();

private slots:
    /*!
     * \brief on_addCustomer_clicked
     */
    void on_addCustomer_clicked();

    /*!
     * \brief on_deleteCustomer_clicked
     */
    void on_deleteCustomer_clicked();

    /*!
     * \brief displayDefaultTable
     */
    void displayDefaultTable() const;

    /*!
     * \brief updateComboBox
     */
    void updateComboBox() const;

private:
    /*!
     * \var ui
     * \brief type: QString
     */
    Ui::aMembership *ui;

    /*!
     * \var myDB
     * \brief type: QString
     */
    QSqlDatabase myDB; // Database object for database connection

    /*!
     * \var name
     * \brief type: QString
     */
    QString name;

    /*!
     * \var num
     * \brief type: QString
     */
    QString num;

    /*!
     * \var type
     * \brief type: QString
     */
    QString type;

    /*!
     * \var date
     * \brief type: QString
     */
    QString date;

    /*!
     * \var totalAmount
     * \brief type: QString
     */
    QString totalAmount;

    /*!
     * \var rebateAmount
     * \brief type: QString
     */
    QString rebateAmount;

    /*!
     * \var renewalCost
     * \brief type: QString
     */
    QString renewalCost;

    /*!
     * \var day
     * \brief type: Integer
     */
    int day;

    /*!
     * \var month
     * \brief type: Integer
     */
    int month;

    /*!
     * \var year
     * \brief type: Integer
     */
    int year;
};

#endif // AMEMBERSHIP_H
