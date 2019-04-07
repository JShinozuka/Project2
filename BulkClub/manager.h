#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>

#include "managermembership.h"
#include "managersales.h"
#include "managerinventory.h"
#include "managerrebateinfo.h"
#include "managermemberpurchases.h"

namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = nullptr);
    ~manager();

private slots:

    void on_homeButton_clicked();
    //!< Home page is displayed in stackedWidget

    void on_membershipButton_clicked();
    //!< Membership page is displayed in stackedWidget

    void on_salesButton_clicked();
    //!< Sales page is displayed in stackedWidget

    void on_inventoryButton_clicked();
    //!< Inventory page is displayed in stackedWidget

    void on_logoutButton_clicked();
    //!< Manager window closes

    void on_memberPurchasesButton_clicked();
    //!< Membership Purchase page is displayed in stacked Widget

    void on_salesButton_2_clicked();
      //!< Rebate page is displayed in stacked Widget




private:
    Ui::manager *ui;

    managerMembership managerMembershipWindow; // Membership window object
    managerSales      managerSalesWindow;      // Sales window object
    managerInventory  managerInventoryWindow;  // Inventory window object
    managerMemberPurchases managerMembershipPurchaseWindow; //Membership purchase window object
    managerRebateInfo managerRebateWindow;     // Rebate Information window object
};

#endif // MANAGER_H
