#ifndef MANAGERSALES_H
#define MANAGERSALES_H

#include <QWidget>

namespace Ui {
class managerSales;
}

class managerSales : public QWidget
{
    Q_OBJECT

public:
    explicit managerSales(QWidget *parent = nullptr);
    ~managerSales();

private:
    Ui::managerSales *ui;
};

#endif // MANAGERSALES_H
