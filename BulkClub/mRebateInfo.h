#ifndef MREBATEINFO_H
#define MREBATEINFO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

/*!
 *\namespace Ui
 */
namespace Ui {
class mRebateInfo;
}

/*!
 * \class mRebateInfo
 */
class mRebateInfo : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief mRebateInfo Default constructor
     * \param parent
     */
    explicit mRebateInfo(QWidget *parent = nullptr);
    /*!
     * \brief destructor
     */
    ~mRebateInfo();

    /*!
      * \brief displayDefaultRebateTable
      */
     void displayDefaultRebateTable() const;


private slots:
     /*!
      * \brief on_selectMonthBox_currentIndexChanged Filters the displayed table
      * \param index
      */
     void on_selectMonthBox_currentIndexChanged(int index);

private:
     /*!
     * \var sortBy
     * \brief index counter that is used for rebate information sorting
     */
    QString sortBy;

    /*!
     * \var ui
     */
    Ui::mRebateInfo *ui;

    /*!
     * \var myDB
     * \brief variable that is used to create the database
     */
    QSqlDatabase myDB;
};

#endif // MREBATEINFO_H
