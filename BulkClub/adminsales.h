#ifndef ADMINSALES_H
#define ADMINSALES_H

#include <QWidget>

namespace Ui {
class adminSales;
}

class adminSales : public QWidget
{
    Q_OBJECT

public:
    explicit adminSales(QWidget *parent = nullptr);
    ~adminSales();

private:
    Ui::adminSales *ui;
};

#endif // ADMINSALES_H
