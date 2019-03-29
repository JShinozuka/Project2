#ifndef MANAGERMEMBERSHIP_H
#define MANAGERMEMBERSHIP_H

#include <QWidget>
#include <QSqlDatabase>

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
    QSqlDatabase db;

};

#endif // MANAGERMEMBERSHIP_H
