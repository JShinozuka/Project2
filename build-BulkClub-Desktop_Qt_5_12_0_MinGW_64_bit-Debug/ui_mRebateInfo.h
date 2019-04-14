/********************************************************************************
** Form generated from reading UI file 'mRebateInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MREBATEINFO_H
#define UI_MREBATEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mRebateInfo
{
public:
    QGroupBox *groupBox;
    QTableView *rebateTableView;
    QComboBox *selectMonthBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *mRebateInfo)
    {
        if (mRebateInfo->objectName().isEmpty())
            mRebateInfo->setObjectName(QString::fromUtf8("mRebateInfo"));
        mRebateInfo->resize(1200, 640);
        groupBox = new QGroupBox(mRebateInfo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 681, 471));
        rebateTableView = new QTableView(groupBox);
        rebateTableView->setObjectName(QString::fromUtf8("rebateTableView"));
        rebateTableView->setGeometry(QRect(10, 50, 661, 411));
        selectMonthBox = new QComboBox(groupBox);
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->setObjectName(QString::fromUtf8("selectMonthBox"));
        selectMonthBox->setGeometry(QRect(470, 20, 201, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 20, 71, 21));
        label_2 = new QLabel(mRebateInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 451, 31));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: blue;"));
        label_3 = new QLabel(mRebateInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(780, 100, 55, 16));

        retranslateUi(mRebateInfo);

        QMetaObject::connectSlotsByName(mRebateInfo);
    } // setupUi

    void retranslateUi(QWidget *mRebateInfo)
    {
        mRebateInfo->setWindowTitle(QApplication::translate("mRebateInfo", "Form", nullptr));
        groupBox->setTitle(QString());
        selectMonthBox->setItemText(0, QApplication::translate("mRebateInfo", "Member ID", nullptr));
        selectMonthBox->setItemText(1, QApplication::translate("mRebateInfo", "Highest Rebate Amount", nullptr));
        selectMonthBox->setItemText(2, QApplication::translate("mRebateInfo", "Lowest Rebate Amount", nullptr));

        label->setText(QApplication::translate("mRebateInfo", "Sort By:", nullptr));
        label_2->setText(QApplication::translate("mRebateInfo", "Membership Rebate Information", nullptr));
        label_3->setText(QApplication::translate("mRebateInfo", "Story #6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mRebateInfo: public Ui_mRebateInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MREBATEINFO_H
