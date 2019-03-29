#include "manager.h"
#include "ui_manager.h"

manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);

    // Create a stacked widget index for seperate QWidget pages
    ui->stackedWidget->insertWidget(1, &managerMembershipWindow);
    ui->stackedWidget->insertWidget(2, &managerSalesWindow);
    ui->stackedWidget->insertWidget(3, &managerInventoryWindow);
}

manager::~manager()
{
    delete ui;
}

/****************************************************************************
 * METHOD - on_homeButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Manager Window Home Page
 ***************************************************************************/
void manager::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/****************************************************************************
 * METHOD - on_membershipButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Membership QWidget
 ***************************************************************************/
void manager::on_membershipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/****************************************************************************
 * METHOD - on_salesButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Sales QWidget
 ***************************************************************************/
void manager::on_salesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

/****************************************************************************
 * METHOD - on_inventoryButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Inventory QWidget
 ***************************************************************************/
void manager::on_inventoryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

/****************************************************************************
 * METHOD - on_logoutButton_clicked
 * --------------------------------------------------------------------------
 * This method ...
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Closes Manager Window (returns control to login window)
 ***************************************************************************/
void manager::on_logoutButton_clicked()
{
    this->close();
}


