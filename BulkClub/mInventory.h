#ifndef MINVENTORY_H
#define MINVENTORY_H

#include <QWidget>

namespace Ui {
class mInventory;
}

class mInventory : public QWidget
{
    Q_OBJECT

public:
    explicit mInventory(QWidget *parent = nullptr);
    ~mInventory();

private:
    Ui::mInventory *ui;
};

#endif // MINVENTORY_H
