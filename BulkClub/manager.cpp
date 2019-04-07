#include "manager.h"
#include "ui_manager.h"

// Default Constructor
manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);

    // Create a stacked widget index for seperate QWidget pages
    ui->stackedWidget->insertWidget(1, &managerMembershipWindow);
    ui->stackedWidget->insertWidget(2, &managerSalesWindow);
    ui->stackedWidget->insertWidget(3, &managerInventoryWindow);
    ui->stackedWidget->insertWidget(4, &managerMembershipPurchaseWindow);
}

// Destructor
manager::~manager()
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
 *      ==> Displays Manager Window Home Page
 ***************************************************************************/
void manager::on_homeButton_clicked()
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
void manager::on_membershipButton_clicked()
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
void manager::on_salesButton_clicked()
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
void manager::on_inventoryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

/****************************************************************************
 * METHOD - on_logoutButton_clicked
 * --------------------------------------------------------------------------
 * When the logout button is clicked, manager window closes.
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



void manager::on_membershipPurchasesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
