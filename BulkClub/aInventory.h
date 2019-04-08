#ifndef AINVENTORY_H
#define AINVENTORY_H

#include <QWidget>

namespace Ui {
class aInventory;
}

class aInventory : public QWidget
{
    Q_OBJECT

public:
    explicit aInventory(QWidget *parent = nullptr);
    ~aInventory();

private:
    Ui::aInventory *ui;
};

#endif // AINVENTORY_H
