/********************************************************************************
** Form generated from reading UI file 'managersales.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERSALES_H
#define UI_MANAGERSALES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_managerSales
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QTableView *salesTotalPurchaseTable;
    QPushButton *Search;
    QTextEdit *textEdit;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *managerSales)
    {
        if (managerSales->objectName().isEmpty())
            managerSales->setObjectName(QString::fromUtf8("managerSales"));
        managerSales->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(managerSales->sizePolicy().hasHeightForWidth());
        managerSales->setSizePolicy(sizePolicy);
        managerSales->setMinimumSize(QSize(1200, 640));
        managerSales->setMaximumSize(QSize(1200, 640));
        label = new QLabel(managerSales);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 261, 91));
        groupBox = new QGroupBox(managerSales);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 80, 791, 501));
        salesTotalPurchaseTable = new QTableView(groupBox);
        salesTotalPurchaseTable->setObjectName(QString::fromUtf8("salesTotalPurchaseTable"));
        salesTotalPurchaseTable->setGeometry(QRect(30, 80, 751, 381));
        Search = new QPushButton(groupBox);
        Search->setObjectName(QString::fromUtf8("Search"));
        Search->setGeometry(QRect(160, 50, 251, 21));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(160, 20, 511, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 141, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 50, 211, 21));

        retranslateUi(managerSales);

        QMetaObject::connectSlotsByName(managerSales);
    } // setupUi

    void retranslateUi(QWidget *managerSales)
    {
        managerSales->setWindowTitle(QApplication::translate("managerSales", "Form", nullptr));
        label->setText(QApplication::translate("managerSales", "Manager Sales Widget", nullptr));
        groupBox->setTitle(QString());
        Search->setText(QApplication::translate("managerSales", "Search Name", nullptr));
        label_2->setText(QApplication::translate("managerSales", "Enter Membership or Name", nullptr));
        pushButton->setText(QApplication::translate("managerSales", "Search Membership Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerSales: public Ui_managerSales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERSALES_H
