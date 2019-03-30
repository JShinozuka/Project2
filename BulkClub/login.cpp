
////////////////////////////    NEEDS DOCUMENTATION STILL

#include "login.h"
#include "ui_login.h"
#include "databasemanger.h"
//#include "bulkClubDB.h"

#include <QDebug>

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
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Creates and connects to SQLite database
 ***************************************************************************/
void login::connectToDB()
{
    bool isOpen = false; // CALC - Set database open status to false

    // Create and open a database connection
    // Return if database opened successfully or not
    isOpen = myDB.openDB();

    if(isOpen)
    {
        qDebug() << "Success: Able to access open database";
    }
}

/****************************************************************************
 * METHOD - on_loginManagerButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Manager Window
 ***************************************************************************/
void login::on_loginManagerButton_clicked()
{
// NEED CODE TO CHECK USERNAME AND PASSWORD
// IMPLEMENT LATER

    connectToDB();

    // Create new manager object named managerWindow and show
    managerWindow = new manager();
    managerWindow->show();
}

/****************************************************************************
 * METHOD - on_loginAdminButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Admin Window
 ***************************************************************************/
void login::on_loginAdminButton_clicked()
{
// NEED CODE TO CHECK USERNAME AND PASSWORD
// IMPLEMENT LATER

    connectToDB();

    // Create new admin object named adminWindow and show
    adminWindow = new admin();
    adminWindow->show();
}

/****************************************************************************
 * METHOD - on_exitProgramButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Closes Login Window (closes entire program)
 *      ==> Closes database connection
 ***************************************************************************/
void login::on_exitProgramButton_clicked()
{
    myDB.closeDB();
    this->close();
}
