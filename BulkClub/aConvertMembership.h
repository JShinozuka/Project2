#ifndef ACONVERTMEMBERSHIP_H
#define ACONVERTMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

/*!
 *\namespace ui
 * \brief class aConvertMembership is contained within this namespace
 */
namespace Ui {
class aConvertMembership;
}

/*!
 * \brief The aConvertMembership class with public inheritance to QWidget
 * \class aConvertMembership
 */
class aConvertMembership : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief aConvertMembership
     * \param parent
     */
    explicit aConvertMembership(QWidget *parent = nullptr);

    /*!
     * \brief deconstructor
     */
    ~aConvertMembership();

    /*!
     * \brief displayUpGradeTable
     */
    void displayUpGradeTable() const;

    /*!
     * \brief displayDownGradeTable
     */
    void displayDownGradeTable() const;


private:
    /*!
     * \var ui
     */
    Ui::aConvertMembership *ui;

    /*!
     * \var myDB
     * \brief type QSqlDatabase
     */
    QSqlDatabase myDB;
};

#endif // ACONVERTMEMBERSHIP_H
