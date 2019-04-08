#ifndef ACONVERTMEMBERSHIP_H
#define ACONVERTMEMBERSHIP_H

#include <QWidget>

namespace Ui {
class aConvertMembership;
}

class aConvertMembership : public QWidget
{
    Q_OBJECT

public:
    explicit aConvertMembership(QWidget *parent = nullptr);
    ~aConvertMembership();

private:
    Ui::aConvertMembership *ui;
};

#endif // ACONVERTMEMBERSHIP_H
