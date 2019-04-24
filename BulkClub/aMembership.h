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
     * \brief ui
     * \param ui
     */
    Ui::aMembership *ui;

    /*!
     * \brief myDB
     * \param myDB
     */
    QSqlDatabase myDB; // Database object for database connection
};

#endif // AMEMBERSHIP_H
