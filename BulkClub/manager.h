#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>

#include "mMembershipExpire.h"
#include "mDailySales.h"
#include "mInventory.h"
#include "mMemberPurchases.h"
#include "mRebateInfo.h"

#include "managersales.h"

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

    void on_membershipExpireButton_clicked();
    //!< Membership Expiration page is displayed in stackedWidget

    void on_dailySalesButton_clicked();
    //!< Daily Sales page is displayed in stackedWidget

    void on_memberPurchasesButton_clicked();
    //!< Member Purchases page is displayed in stacked Widget

    void on_rebateButton_clicked();
    //!< Rebate page is displayed in stacked Widget

    void on_salesButton_clicked();
    //!< Sales page is displayed in stackedWidget

    void on_logoutButton_clicked();
    //!< Manager window closes

    void on_inventoryButton_clicked();

private:
    Ui::manager *ui;

    mMembershipExpire mMembershipExpireWindow; // Membership Expiration window object
    mDailySales       mDailySalesWindow;  // Daily Sales window object
    mMemberPurchases  mMemberPurchaseWindow; //Membership purchase window object
    mRebateInfo       mRebateWindow;     // Rebate Information window object
    mInventory        mInventoryWindow; // Inventory window object
    managerSales      managerSalesWindow;      // Sales window object
};

#endif // MANAGER_H
