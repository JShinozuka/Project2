#ifndef MANAGERREBATEINFO_H
#define MANAGERREBATEINFO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class managerRebateInfo;
}

class managerRebateInfo : public QWidget
{
    Q_OBJECT

public:
    explicit managerRebateInfo(QWidget *parent = nullptr);
    ~managerRebateInfo();

     void displayDefaultRebateTable() const;


private slots:
     void on_selectMonthBox_currentIndexChanged(int index);

private:
    Ui::managerRebateInfo *ui;
    QSqlDatabase myDB;
};

#endif // MANAGERREBATEINFO_H
