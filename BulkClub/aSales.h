#ifndef ASALES_H
#define ASALES_H

#include <QWidget>

namespace Ui {
class aSales;
}

class aSales : public QWidget
{
    Q_OBJECT

public:
    explicit aSales(QWidget *parent = nullptr);
    ~aSales();

private:
    Ui::aSales *ui;
};

#endif // ASALES_H
