#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>

#include "mMembershipExpire.h"
#include "mDailySales.h"
#include "mInventory.h"
#include "mMemberPurchases.h"
#include "mRebateInfo.h"
#include "username.h"

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

    void on_logoutButton_clicked();
    //!< Manager window closes

    void on_inventoryButton_clicked();

private:
    Ui::manager *ui;
    /*!
     * \var mMembershipExpireWindow
     * \brief Membership Expiration window object
     */
    mMembershipExpire mMembershipExpireWindow;  //IN/OUT- Membership Expiration window object
    /*!
     * \var mDailySalesWindow
     * \brief Daily Sales window object
     */
    mDailySales       mDailySalesWindow;  //IN/OUT- Daily Sales window object
    /*!
     * \var mMemberPurchaseWindow
     * \brief Membership purchase window object
     */
    mMemberPurchases  mMemberPurchaseWindow; //IN/OUT- Membership purchase window object
    /*!
     * \var mRebateWindow
     * \brief Rebate Information window object
     */
    mRebateInfo       mRebateWindow;     //IN/OUT- Rebate Information window object
    /*!
     * \var mInventoryWindow
     * \brief Inventory window object
     */
    mInventory        mInventoryWindow; // IN/OUT- Inventory window object

    /*!
     * \var namePtr
     * \brief pointer to point to userName object (to demonstrate copy constructor)
     */
    userName * namePtr;
};

#endif // MANAGER_H
