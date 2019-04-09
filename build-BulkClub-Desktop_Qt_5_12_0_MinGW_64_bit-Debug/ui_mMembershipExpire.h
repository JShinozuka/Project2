/********************************************************************************
** Form generated from reading UI file 'mMembershipExpire.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMEMBERSHIPEXPIRE_H
#define UI_MMEMBERSHIPEXPIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mMembershipExpire
{
public:
    QLabel *label;
    QGroupBox *membershipExpirationGroup;
    QTableView *membershipExpirationTable;
    QLabel *sortByLabel;
    QComboBox *selectMonthBox;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *mMembershipExpire)
    {
        if (mMembershipExpire->objectName().isEmpty())
            mMembershipExpire->setObjectName(QString::fromUtf8("mMembershipExpire"));
        mMembershipExpire->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mMembershipExpire->sizePolicy().hasHeightForWidth());
        mMembershipExpire->setSizePolicy(sizePolicy);
        mMembershipExpire->setMinimumSize(QSize(1200, 640));
        mMembershipExpire->setMaximumSize(QSize(1200, 640));
        label = new QLabel(mMembershipExpire);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 371, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: blue;"));
        membershipExpirationGroup = new QGroupBox(mMembershipExpire);
        membershipExpirationGroup->setObjectName(QString::fromUtf8("membershipExpirationGroup"));
        membershipExpirationGroup->setGeometry(QRect(40, 110, 591, 351));
        QFont font1;
        font1.setPointSize(10);
        membershipExpirationGroup->setFont(font1);
        membershipExpirationTable = new QTableView(membershipExpirationGroup);
        membershipExpirationTable->setObjectName(QString::fromUtf8("membershipExpirationTable"));
        membershipExpirationTable->setGeometry(QRect(10, 50, 571, 291));
        sortByLabel = new QLabel(membershipExpirationGroup);
        sortByLabel->setObjectName(QString::fromUtf8("sortByLabel"));
        sortByLabel->setGeometry(QRect(280, 20, 91, 20));
        sortByLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        selectMonthBox = new QComboBox(membershipExpirationGroup);
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->addItem(QString());
        selectMonthBox->setObjectName(QString::fromUtf8("selectMonthBox"));
        selectMonthBox->setGeometry(QRect(400, 20, 201, 22));
        label_2 = new QLabel(mMembershipExpire);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 490, 611, 16));
        label_3 = new QLabel(mMembershipExpire);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(820, 40, 121, 16));

        retranslateUi(mMembershipExpire);

        QMetaObject::connectSlotsByName(mMembershipExpire);
    } // setupUi

    void retranslateUi(QWidget *mMembershipExpire)
    {
        mMembershipExpire->setWindowTitle(QApplication::translate("mMembershipExpire", "Form", nullptr));
        label->setText(QApplication::translate("mMembershipExpire", "Membership Expiration", nullptr));
        membershipExpirationGroup->setTitle(QString());
        sortByLabel->setText(QApplication::translate("mMembershipExpire", "Sort By:", nullptr));
        selectMonthBox->setItemText(0, QApplication::translate("mMembershipExpire", "All Months", nullptr));
        selectMonthBox->setItemText(1, QApplication::translate("mMembershipExpire", "January", nullptr));
        selectMonthBox->setItemText(2, QApplication::translate("mMembershipExpire", "February", nullptr));
        selectMonthBox->setItemText(3, QApplication::translate("mMembershipExpire", "March", nullptr));
        selectMonthBox->setItemText(4, QApplication::translate("mMembershipExpire", "April", nullptr));
        selectMonthBox->setItemText(5, QApplication::translate("mMembershipExpire", "May", nullptr));
        selectMonthBox->setItemText(6, QApplication::translate("mMembershipExpire", "June", nullptr));
        selectMonthBox->setItemText(7, QApplication::translate("mMembershipExpire", "July", nullptr));
        selectMonthBox->setItemText(8, QApplication::translate("mMembershipExpire", "August", nullptr));
        selectMonthBox->setItemText(9, QApplication::translate("mMembershipExpire", "September", nullptr));
        selectMonthBox->setItemText(10, QApplication::translate("mMembershipExpire", "October", nullptr));
        selectMonthBox->setItemText(11, QApplication::translate("mMembershipExpire", "Novembter", nullptr));
        selectMonthBox->setItemText(12, QApplication::translate("mMembershipExpire", "December", nullptr));

        label_2->setText(QApplication::translate("mMembershipExpire", "* Select a month to view memberships that expire that month.  Or select All Months to view all months.", nullptr));
        label_3->setText(QApplication::translate("mMembershipExpire", "This is Story #7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mMembershipExpire: public Ui_mMembershipExpire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMEMBERSHIPEXPIRE_H
