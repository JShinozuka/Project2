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
    //!< Brief Description
    /*!< POSTCONDITONS:  */

    void on_membershipButton_clicked();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

    void on_salesButton_clicked();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

    void on_inventoryButton_clicked();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

    void on_logoutButton_clicked();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

private:
    Ui::manager *ui;

    managerMembership managerMembershipWindow;
    managerSales managerSalesWindow;
    managerInventory managerInventoryWindow;
};

#endif // MANAGER_H
