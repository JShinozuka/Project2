#include "login.h"
#include "ui_login.h"

// Default Constructor
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

// Destructor
login::~login()
{
    delete ui;
}

/****************************************************************************
 * METHOD - connectToDB
 * --------------------------------------------------------------------------
 * This method creates and opens a database connection and displays a
 * qDebug message that the database access is open.  This method is used
 * with a valid login (manager or admin).  If database is already
 * connected and open, then only the qDebug message is displayed.
 * NOTE: Use with valid login username/password only (manager or admin)
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Creates and connects to SQLite database if not open
 ***************************************************************************/
void login::connectToDB()
{
    bool isOpen = false; // CALC - Set database open status to false

    // Create and open a database connection
    // Return if database opened successfully or not
    isOpen = myDB.openDB();

    // Display message if database connection was successful
    if(isOpen)
    {
        qDebug() << "Success: Able to access open database";
    }
}

/****************************************************************************
 * METHOD - on_loginManagerButton_clicked
 * --------------------------------------------------------------------------
 * On valid username/password for manager, the manager window is opened.
 * Connection to database is checked.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Manager Window on valid login/password
 ***************************************************************************/
void login::on_loginManagerButton_clicked()
{
/*
    //Creates a single manager username and password
    if(managerUsername == "manager" && managerPassword == "123")
    {
        // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
        connectToDB();

        // Create new manager object named managerWindow and show
        // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
        managerWindow = new manager();
        managerWindow->show();
    }
    else
    {
        qDebug() << "Unable to login as manager!";
    }
*/

    // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
    connectToDB();

    // Create new manager object named managerWindow and show
    // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
    managerWindow = new manager();
    managerWindow->show();

}

/****************************************************************************
 * METHOD - on_loginAdminButton_clicked
 * --------------------------------------------------------------------------
 * On valid username/password for admin, the admin window is opened.
 * Connection to database is checked.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Admin Window on valid login/password
 ***************************************************************************/
void login::on_loginAdminButton_clicked()
{
/*
    //Checks if the entered username/password is valid
    if(adminUsername == "admin" && adminPassword == "123")
    {
        // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
        connectToDB();

        // Create new admin object named adminWindow and show
        // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
        adminWindow = new admin();
        adminWindow->show();
    }
    else
    {
        qDebug() << "Unable to login as admin!";
    }
*/

    // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
    connectToDB();

    // Create new admin object named adminWindow and show
    // THIS SHOULD BE LOCATED IN VALID LOGIN ONLY
    adminWindow = new admin();
    adminWindow->show();

}

/****************************************************************************
 * METHOD - on_exitProgramButton_clicked
 * --------------------------------------------------------------------------
 * This method closes database and program when exit button is clicked
 * on the login window.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Closes database connection
 *      ==> Closes Login Window (closes program)
 ***************************************************************************/
void login::on_exitProgramButton_clicked()
{
    myDB.closeDB();
    this->close();
}

/****************************************************************************
 * METHOD - on_usernameLineEdit_textChanged
 * --------------------------------------------------------------------------
 * This method stores the users entry into two different class data members
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Stores username (admin)
 *      ==> Stores username (manager)
 ***************************************************************************/
void login::on_usernameLineEdit_textChanged(const QString &arg1)
{
    adminUsername = arg1;
    managerUsername = arg1;
}

/****************************************************************************
 * METHOD - on_passwordLineEdit_textChanged
 * --------------------------------------------------------------------------
 * This method stores the users entry into two different class data members
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Stores password (admin)
 *      ==> Stores password (manager)
 ***************************************************************************/
void login::on_passwordLineEdit_textChanged(const QString &arg1)
{
    adminPassword = arg1;
    managerPassword = arg1;
}
