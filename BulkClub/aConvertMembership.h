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
     * \brief default constructor
     * It will check and see which regular members should be upgraded and which executive members should be downgraded
     * and display them in separate table views.
     * \param parent
     */
    explicit aConvertMembership(QWidget *parent = nullptr);

    /*!
     * \brief deconstructor
     */
    ~aConvertMembership();

    /*!
     * \brief displayUpGradeTable shows the regular members that should be upgraded
     */
    void displayUpGradeTable() const;

    /*!
     * \brief displayDownGradeTable shows the executive members that should be downgraded
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
