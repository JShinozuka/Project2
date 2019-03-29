#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);

    // Create a stacked widget index for seperate QWidget pages
    ui->stackedWidget->insertWidget(1, &adminMembershipWindow);
    ui->stackedWidget->insertWidget(2, &adminSalesWindow);
    ui->stackedWidget->insertWidget(3, &adminInventoryWindow);
}

admin::~admin()
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
void admin::on_homeButton_clicked()
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
void admin::on_membershipButton_clicked()
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
void admin::on_salesButton_clicked()
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
void admin::on_inventoryButton_clicked()
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
 *      ==> Closes Admin Window (returns control to login window)
 ***************************************************************************/
void admin::on_logoutButton_clicked()
{
    this->close();
}
