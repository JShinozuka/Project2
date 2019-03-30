#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>

#include "managermembership.h"
#include "managersales.h"
#include "managerinventory.h"

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
    /*!< POSTCONDITONS:  */

    void on_membershipButton_clicked();
    //!< Membership page is displayed in stackedWidget
    /*!< POSTCONDITONS:  */

    void on_salesButton_clicked();
    //!< Sales page is displayed in stackedWidget
    /*!< POSTCONDITONS:  */

    void on_inventoryButton_clicked();
    //!< Inventory page is displayed in stackedWidget
    /*!< POSTCONDITONS:  */

    void on_logoutButton_clicked();
    //!< Manager window closes
    /*!< POSTCONDITONS:  */

private:
    Ui::manager *ui;

    managerMembership managerMembershipWindow; // Membership window object
    managerSales      managerSalesWindow;      // Sales window object
    managerInventory  managerInventoryWindow;  // Inventory window object
};

#endif // MANAGER_H
