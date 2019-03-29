#ifndef ADMININVENTORY_H
#define ADMININVENTORY_H

#include <QWidget>

namespace Ui {
class adminInventory;
}

class adminInventory : public QWidget
{
    Q_OBJECT

public:
    explicit adminInventory(QWidget *parent = nullptr);
    ~adminInventory();

private:
    Ui::adminInventory *ui;
};

#endif // ADMININVENTORY_H
