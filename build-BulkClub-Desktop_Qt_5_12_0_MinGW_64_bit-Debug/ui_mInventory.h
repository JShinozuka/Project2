/********************************************************************************
** Form generated from reading UI file 'mInventory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINVENTORY_H
#define UI_MINVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mInventory
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *mInventory)
    {
        if (mInventory->objectName().isEmpty())
            mInventory->setObjectName(QString::fromUtf8("mInventory"));
        mInventory->resize(1200, 640);
        mInventory->setMinimumSize(QSize(1200, 640));
        mInventory->setMaximumSize(QSize(1200, 640));
        label = new QLabel(mInventory);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 631, 51));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: blue;"));
        label_2 = new QLabel(mInventory);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(780, 250, 91, 16));

        retranslateUi(mInventory);

        QMetaObject::connectSlotsByName(mInventory);
    } // setupUi

    void retranslateUi(QWidget *mInventory)
    {
        mInventory->setWindowTitle(QApplication::translate("mInventory", "Form", nullptr));
        label->setText(QApplication::translate("mInventory", "Inventory Information Report", nullptr));
        label_2->setText(QApplication::translate("mInventory", "Story #12", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mInventory: public Ui_mInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINVENTORY_H
