#ifndef ADMINMEMBERSHIP_H
#define ADMINMEMBERSHIP_H

#include <QWidget>

namespace Ui {
class adminMembership;
}

class adminMembership : public QWidget
{
    Q_OBJECT

public:
    explicit adminMembership(QWidget *parent = nullptr);
    ~adminMembership();

private:
    Ui::adminMembership *ui;
};

#endif // ADMINMEMBERSHIP_H
