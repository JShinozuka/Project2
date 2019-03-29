#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "adminmembership.h"
#include "adminsales.h"
#include "admininventory.h"

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

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
    Ui::admin *ui;

    adminMembership adminMembershipWindow;
    adminSales adminSalesWindow;
    adminInventory adminInventoryWindow;
};

#endif // ADMIN_H
