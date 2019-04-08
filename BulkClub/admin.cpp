#include "admin.h"
#include "ui_admin.h"

// Default Constructor
admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);

    // Create a stacked widget index for seperate QWidget pages
    ui->stackedWidget->insertWidget(1, &adminMembershipWindow);
    ui->stackedWidget->insertWidget(2, &aSalesWindow);
    ui->stackedWidget->insertWidget(3, &aInventoryWindow);
    ui->stackedWidget->insertWidget(4, &aConvertMemberWindow);
}

// Destructor
admin::~admin()
{
    delete ui;
}

/****************************************************************************
 * METHOD - on_homeButton_clicked
 * --------------------------------------------------------------------------
 * When the home button is clicked, the stackedWidget index changes to
 * display the home page.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Admin Window Home Page
 ***************************************************************************/
void admin::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/****************************************************************************
 * METHOD - on_membershipButton_clicked
 * --------------------------------------------------------------------------
 * When the membership button is clicked, the stackedWidget index changes to
 * display the membership page.
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
 * When the sales button is clicked, the stackedWidget index changes to
 * display the sales page.
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
 * When the inventory button is clicked, the stackedWidget index changes to
 * display the inventory page.
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

void admin::on_convertMembershipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

/****************************************************************************
 * METHOD - on_logoutButton_clicked
 * --------------------------------------------------------------------------
 * When the logout button is clicked, admin window closes.
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


