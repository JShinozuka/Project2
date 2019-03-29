#ifndef MANAGERMEMBERSHIP_H
#define MANAGERMEMBERSHIP_H

#include <QWidget>

namespace Ui {
class managerMembership;
}

class managerMembership : public QWidget
{
    Q_OBJECT

public:
    explicit managerMembership(QWidget *parent = nullptr);
    ~managerMembership();

private:
    Ui::managerMembership *ui;
};

#endif // MANAGERMEMBERSHIP_H
