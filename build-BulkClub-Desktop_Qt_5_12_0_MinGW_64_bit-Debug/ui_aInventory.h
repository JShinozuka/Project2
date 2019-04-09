/********************************************************************************
** Form generated from reading UI file 'aInventory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AINVENTORY_H
#define UI_AINVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aInventory
{
public:
    QLabel *label;

    void setupUi(QWidget *aInventory)
    {
        if (aInventory->objectName().isEmpty())
            aInventory->setObjectName(QString::fromUtf8("aInventory"));
        aInventory->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aInventory->sizePolicy().hasHeightForWidth());
        aInventory->setSizePolicy(sizePolicy);
        aInventory->setMinimumSize(QSize(1200, 640));
        aInventory->setMaximumSize(QSize(1200, 640));
        label = new QLabel(aInventory);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 200, 501, 201));

        retranslateUi(aInventory);

        QMetaObject::connectSlotsByName(aInventory);
    } // setupUi

    void retranslateUi(QWidget *aInventory)
    {
        aInventory->setWindowTitle(QApplication::translate("aInventory", "Form", nullptr));
        label->setText(QApplication::translate("aInventory", "Admin Inventory Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aInventory: public Ui_aInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AINVENTORY_H
