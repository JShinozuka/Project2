#ifndef MREBATEINFO_H
#define MREBATEINFO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class mRebateInfo;
}

class mRebateInfo : public QWidget
{
    Q_OBJECT

public:
    explicit mRebateInfo(QWidget *parent = nullptr);
    ~mRebateInfo();

     void displayDefaultRebateTable() const;


private slots:
     void on_selectMonthBox_currentIndexChanged(int index);

private:
    Ui::mRebateInfo *ui;
    QSqlDatabase myDB;
};

#endif // MREBATEINFO_H
