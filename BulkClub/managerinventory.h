#ifndef MANAGERINVENTORY_H
#define MANAGERINVENTORY_H

#include <QWidget>

namespace Ui {
class managerInventory;
}

class managerInventory : public QWidget
{
    Q_OBJECT

public:
    explicit managerInventory(QWidget *parent = nullptr);
    ~managerInventory();

private:
    Ui::managerInventory *ui;
};

#endif // MANAGERINVENTORY_H
