#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>

#include "aMembership.h"
#include "aSales.h"
#include "aInventory.h"
#include "aConvertMembership.h"

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
    //!< Home page is displayed in stackedWidget

    void on_membershipButton_clicked();
    //!< Membership page is displayed in stackedWidget

    void on_salesButton_clicked();
    //!< Sales page is displayed in stackedWidget

    void on_inventoryButton_clicked();
    //!< Inventory page is displayed in stackedWidget

    void on_convertMembershipButton_clicked();
    //!< Convert Membership page is displayed in stackedWidget

    void on_logoutButton_clicked();
    //!< Admin window closes

private:
    Ui::admin *ui;

    aMembership adminMembershipWindow; // Membership window object
    aSales      aSalesWindow;      // Sales window object
    aInventory  aInventoryWindow;  // Inventory window object
    aConvertMembership aConvertMemberWindow; // Convert Membership window object
};

#endif // ADMIN_H
