#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QStackedLayout>
#include <QDebug>
#include <QMessageBox>

#include "admin.h"
#include "manager.h"
#include "databasemanger.h"

/*!
 * \namespace Ui
 */
namespace Ui {
class login;
}

/*!
 * \class login
 * \brief a class to handle the login in buttons and logic
 */
class login : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief login constructor
     * \param parent
     */
    explicit login(QWidget *parent = nullptr);
    ~login();

    /*!
     * \brief connectToDB
     * Creates and opens database connection if not open
     */
    void connectToDB();

    /*!
     * \brief return QString UserName
     * returns the manager's username when called
     */
    QString returnName();

private slots:
    /*!
     * \brief on_loginManagerButton_clicked
     * On valid username/password for manager, open manager window
     * Checks if database is already open
     */
    void on_loginManagerButton_clicked();

    /*!
     * \brief on_loginAdminButton_clicked
     * On valid username/password for admin, open admin window
     * Checks if database is already open
     */
    void on_loginAdminButton_clicked();

    /*!
     * \brief on_exitProgramButton_clicked
     * Closes database and program when exit button is clicked
     */
    void on_exitProgramButton_clicked();

    /*!
     * \brief on_usernameLineEdit_textChanged
     * Saves user input as a username for both admin/manager
     * \param arg1
     */
    void on_usernameLineEdit_textChanged(const QString &arg1);

    /*!
     * \brief on_passwordLineEdit_textChanged
     * Saves user input as a password
     * \param arg1
     */
    void on_passwordLineEdit_textChanged(const QString &arg1);


private:
    /*!
     * \var ui
     */
    Ui::login *ui;

    /*!
     * \var managerPassword
     * \brief manager password variable
     */
    QString managerPassword;

    /*!
     * \var adminPassword
     * \brief admin password variable
     */
    QString adminPassword;

    /*!
     * \var adminUsername
     * \brief admin username variable
     */
    QString adminUsername;

    /*!
     * \var managerUsername
     * \brief manager username variable
     */
    QString managerUsername;

    /*!
     * \var managerWindow
     * \brief Manager window object
     */
    manager *managerWindow;

    /*!
     * \var adminWindow
     * \brief Admin window object
     */
    admin   *adminWindow;
    /*!
     * \var myDB
     * \brief Database object for database connection
     */
    databaseManger myDB;

 };

#endif // LOGIN_H
