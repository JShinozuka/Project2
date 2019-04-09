/********************************************************************************
** Form generated from reading UI file 'mDailySales.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDAILYSALES_H
#define UI_MDAILYSALES_H

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

class Ui_mDailySales
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QTableView *salesReportTableView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QLabel *label_2;
    QTableView *tableView;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *mDailySales)
    {
        if (mDailySales->objectName().isEmpty())
            mDailySales->setObjectName(QString::fromUtf8("mDailySales"));
        mDailySales->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mDailySales->sizePolicy().hasHeightForWidth());
        mDailySales->setSizePolicy(sizePolicy);
        mDailySales->setMinimumSize(QSize(1200, 640));
        mDailySales->setMaximumSize(QSize(1200, 640));
        label = new QLabel(mDailySales);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 210, 391, 191));
        groupBox = new QGroupBox(mDailySales);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 741, 571));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 510, 271, 31));
        salesReportTableView = new QTableView(groupBox);
        salesReportTableView->setObjectName(QString::fromUtf8("salesReportTableView"));
        salesReportTableView->setGeometry(QRect(10, 70, 721, 361));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 510, 301, 31));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 30, 181, 31));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 30, 281, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 450, 111, 21));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(160, 440, 541, 41));
        label_3 = new QLabel(mDailySales);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 651, 31));
        QFont font;
        font.setPointSize(16);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: blue;"));
        label_4 = new QLabel(mDailySales);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(810, 80, 121, 21));

        retranslateUi(mDailySales);

        QMetaObject::connectSlotsByName(mDailySales);
    } // setupUi

    void retranslateUi(QWidget *mDailySales)
    {
        mDailySales->setWindowTitle(QApplication::translate("mDailySales", "Form", nullptr));
        label->setText(QApplication::translate("mDailySales", "Manager Inventory Widget", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("mDailySales", "Executive Members", nullptr));
        pushButton_2->setText(QApplication::translate("mDailySales", "Regular Members", nullptr));
        pushButton_3->setText(QApplication::translate("mDailySales", "PushButton", nullptr));
        label_2->setText(QApplication::translate("mDailySales", "Total Revuene: ", nullptr));
        label_3->setText(QApplication::translate("mDailySales", "Daily Sales Report", nullptr));
        label_4->setText(QApplication::translate("mDailySales", "This is story #10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mDailySales: public Ui_mDailySales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDAILYSALES_H
