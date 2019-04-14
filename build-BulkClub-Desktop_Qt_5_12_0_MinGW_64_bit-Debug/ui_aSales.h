/********************************************************************************
** Form generated from reading UI file 'aSales.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASALES_H
#define UI_ASALES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aSales
{
public:
    QTableView *aSalesTableView;
    QGroupBox *groupBox;
    QDateEdit *dateEdit;
    QLabel *label;
    QLabel *label_2;
    QComboBox *memberIDComboBox;
    QLabel *label_3;
    QComboBox *itemNameComboBox;
    QLabel *label_4;
    QSpinBox *qtySpinBox;
    QLabel *label_5;
    QLineEdit *salesPriceLineEdit;

    void setupUi(QWidget *aSales)
    {
        if (aSales->objectName().isEmpty())
            aSales->setObjectName(QString::fromUtf8("aSales"));
        aSales->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aSales->sizePolicy().hasHeightForWidth());
        aSales->setSizePolicy(sizePolicy);
        aSales->setMinimumSize(QSize(1200, 640));
        aSales->setMaximumSize(QSize(1200, 640));
        aSalesTableView = new QTableView(aSales);
        aSalesTableView->setObjectName(QString::fromUtf8("aSalesTableView"));
        aSalesTableView->setGeometry(QRect(10, 80, 691, 521));
        groupBox = new QGroupBox(aSales);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(710, 230, 271, 281));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(100, 80, 110, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 81, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 81, 31));
        memberIDComboBox = new QComboBox(groupBox);
        memberIDComboBox->setObjectName(QString::fromUtf8("memberIDComboBox"));
        memberIDComboBox->setGeometry(QRect(100, 110, 111, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 150, 81, 31));
        itemNameComboBox = new QComboBox(groupBox);
        itemNameComboBox->setObjectName(QString::fromUtf8("itemNameComboBox"));
        itemNameComboBox->setGeometry(QRect(100, 150, 111, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 81, 31));
        qtySpinBox = new QSpinBox(groupBox);
        qtySpinBox->setObjectName(QString::fromUtf8("qtySpinBox"));
        qtySpinBox->setGeometry(QRect(100, 190, 81, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 230, 81, 31));
        salesPriceLineEdit = new QLineEdit(groupBox);
        salesPriceLineEdit->setObjectName(QString::fromUtf8("salesPriceLineEdit"));
        salesPriceLineEdit->setGeometry(QRect(100, 230, 113, 20));

        retranslateUi(aSales);

        QMetaObject::connectSlotsByName(aSales);
    } // setupUi

    void retranslateUi(QWidget *aSales)
    {
        aSales->setWindowTitle(QApplication::translate("aSales", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("aSales", "Order Date", nullptr));
        label_2->setText(QApplication::translate("aSales", "Member ID", nullptr));
        label_3->setText(QApplication::translate("aSales", "Item Name", nullptr));
        label_4->setText(QApplication::translate("aSales", "Quantity", nullptr));
        label_5->setText(QApplication::translate("aSales", "Sales Price ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aSales: public Ui_aSales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASALES_H
