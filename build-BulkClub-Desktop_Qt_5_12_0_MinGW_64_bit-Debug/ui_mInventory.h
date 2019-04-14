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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mInventory
{
public:
    QLabel *headerLabel;
    QTableView *inventoryTableView;
    QGroupBox *groupBox;
    QComboBox *InventoryComboBox;
    QLineEdit *itemQuantityLineEdit;
    QLineEdit *itemTotalLineEdit;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *sandshrewLabel;

    void setupUi(QWidget *mInventory)
    {
        if (mInventory->objectName().isEmpty())
            mInventory->setObjectName(QString::fromUtf8("mInventory"));
        mInventory->resize(1200, 640);
        mInventory->setMinimumSize(QSize(1200, 640));
        mInventory->setMaximumSize(QSize(1200, 640));
        headerLabel = new QLabel(mInventory);
        headerLabel->setObjectName(QString::fromUtf8("headerLabel"));
        headerLabel->setGeometry(QRect(0, 0, 1201, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        headerLabel->setFont(font);
        headerLabel->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 75 18pt \"Consolas\";\n"
"background: LightBlue"));
        inventoryTableView = new QTableView(mInventory);
        inventoryTableView->setObjectName(QString::fromUtf8("inventoryTableView"));
        inventoryTableView->setGeometry(QRect(0, 60, 621, 601));
        inventoryTableView->setStyleSheet(QString::fromUtf8(""));
        inventoryTableView->setDragDropOverwriteMode(false);
        inventoryTableView->setAlternatingRowColors(true);
        groupBox = new QGroupBox(mInventory);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(680, 50, 371, 141));
        groupBox->setStyleSheet(QString::fromUtf8("background: rgba(255, 255, 255, 0.2)"));
        InventoryComboBox = new QComboBox(groupBox);
        InventoryComboBox->setObjectName(QString::fromUtf8("InventoryComboBox"));
        InventoryComboBox->setGeometry(QRect(160, 20, 190, 25));
        InventoryComboBox->setAutoFillBackground(true);
        InventoryComboBox->setFrame(true);
        itemQuantityLineEdit = new QLineEdit(groupBox);
        itemQuantityLineEdit->setObjectName(QString::fromUtf8("itemQuantityLineEdit"));
        itemQuantityLineEdit->setGeometry(QRect(160, 60, 190, 25));
        itemQuantityLineEdit->setReadOnly(true);
        itemTotalLineEdit = new QLineEdit(groupBox);
        itemTotalLineEdit->setObjectName(QString::fromUtf8("itemTotalLineEdit"));
        itemTotalLineEdit->setGeometry(QRect(160, 100, 190, 25));
        itemTotalLineEdit->setReadOnly(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 141, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 100, 141, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 12pt \"MS Shell Dlg 2\";"));
        sandshrewLabel = new QLabel(mInventory);
        sandshrewLabel->setObjectName(QString::fromUtf8("sandshrewLabel"));
        sandshrewLabel->setGeometry(QRect(0, 49, 1221, 951));
        sandshrewLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/sandshrewInverted3.jpg);"));
        sandshrewLabel->raise();
        inventoryTableView->raise();
        headerLabel->raise();
        groupBox->raise();

        retranslateUi(mInventory);

        QMetaObject::connectSlotsByName(mInventory);
    } // setupUi

    void retranslateUi(QWidget *mInventory)
    {
        mInventory->setWindowTitle(QApplication::translate("mInventory", "Form", nullptr));
        headerLabel->setText(QApplication::translate("mInventory", "Inventory Information Report", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("mInventory", "Item Name", nullptr));
        label_5->setText(QApplication::translate("mInventory", "Item Quantity", nullptr));
        label_6->setText(QApplication::translate("mInventory", "Item Total", nullptr));
        sandshrewLabel->setText(QApplication::translate("mInventory", "SANDSHREW LABEL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mInventory: public Ui_mInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINVENTORY_H
