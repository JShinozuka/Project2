/********************************************************************************
** Form generated from reading UI file 'aMembership.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMEMBERSHIP_H
#define UI_AMEMBERSHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aMembership
{
public:
    QLabel *label;
    QTableView *memberDBTable;

    void setupUi(QWidget *aMembership)
    {
        if (aMembership->objectName().isEmpty())
            aMembership->setObjectName(QString::fromUtf8("aMembership"));
        aMembership->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aMembership->sizePolicy().hasHeightForWidth());
        aMembership->setSizePolicy(sizePolicy);
        aMembership->setMinimumSize(QSize(1200, 640));
        aMembership->setMaximumSize(QSize(1200, 640));
        label = new QLabel(aMembership);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 510, 481, 91));
        memberDBTable = new QTableView(aMembership);
        memberDBTable->setObjectName(QString::fromUtf8("memberDBTable"));
        memberDBTable->setGeometry(QRect(10, 10, 1181, 421));

        retranslateUi(aMembership);

        QMetaObject::connectSlotsByName(aMembership);
    } // setupUi

    void retranslateUi(QWidget *aMembership)
    {
        aMembership->setWindowTitle(QApplication::translate("aMembership", "Form", nullptr));
        label->setText(QApplication::translate("aMembership", "Admin Membership Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aMembership: public Ui_aMembership {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMEMBERSHIP_H
