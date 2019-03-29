#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
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

    // Hide current window
//    this->hide();

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

    // Hide current window
//    this->hide();

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
 ***************************************************************************/
void login::on_exitProgramButton_clicked()
{
    this->close();
}
