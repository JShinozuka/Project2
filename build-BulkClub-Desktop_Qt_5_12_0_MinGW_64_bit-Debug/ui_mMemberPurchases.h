/********************************************************************************
** Form generated from reading UI file 'mMemberPurchases.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMEMBERPURCHASES_H
#define UI_MMEMBERPURCHASES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mMemberPurchases
{
public:
    QTableView *membershipPurchaseTableView;
    QGroupBox *groupBox;
    QComboBox *memberIDcomboBox;
    QLabel *MemberIDlabel;
    QLabel *grandTotalLabel;
    QLineEdit *grandTotalLineEdit;
    QLineEdit *dateLineEdit;
    QLabel *MemberIDlabel_2;
    QLineEdit *itemPurchasedLineEdit;
    QLabel *MemberIDlabel_3;
    QLineEdit *salePriceLineEdit;
    QLabel *MemberIDlabel_4;
    QLineEdit *quantityLineEdit;
    QLabel *MemberIDlabel_5;
    QComboBox *orderIDcomboBox;
    QLabel *MemberIDlabel_6;
    QTextEdit *textEdit;

    void setupUi(QWidget *mMemberPurchases)
    {
        if (mMemberPurchases->objectName().isEmpty())
            mMemberPurchases->setObjectName(QString::fromUtf8("mMemberPurchases"));
        mMemberPurchases->resize(1200, 640);
        membershipPurchaseTableView = new QTableView(mMemberPurchases);
        membershipPurchaseTableView->setObjectName(QString::fromUtf8("membershipPurchaseTableView"));
        membershipPurchaseTableView->setGeometry(QRect(0, 80, 731, 771));
        membershipPurchaseTableView->setAlternatingRowColors(true);
        groupBox = new QGroupBox(mMemberPurchases);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(730, 70, 481, 571));
        groupBox->setStyleSheet(QString::fromUtf8("background-image: url(:/images/poke.png);"));
        memberIDcomboBox = new QComboBox(groupBox);
        memberIDcomboBox->setObjectName(QString::fromUtf8("memberIDcomboBox"));
        memberIDcomboBox->setGeometry(QRect(130, 40, 150, 25));
        memberIDcomboBox->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        memberIDcomboBox->setEditable(false);
        MemberIDlabel = new QLabel(groupBox);
        MemberIDlabel->setObjectName(QString::fromUtf8("MemberIDlabel"));
        MemberIDlabel->setGeometry(QRect(10, 40, 100, 25));
        MemberIDlabel->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        grandTotalLabel = new QLabel(groupBox);
        grandTotalLabel->setObjectName(QString::fromUtf8("grandTotalLabel"));
        grandTotalLabel->setGeometry(QRect(10, 280, 100, 25));
        grandTotalLabel->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        grandTotalLineEdit = new QLineEdit(groupBox);
        grandTotalLineEdit->setObjectName(QString::fromUtf8("grandTotalLineEdit"));
        grandTotalLineEdit->setGeometry(QRect(130, 280, 150, 25));
        grandTotalLineEdit->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        grandTotalLineEdit->setReadOnly(true);
        dateLineEdit = new QLineEdit(groupBox);
        dateLineEdit->setObjectName(QString::fromUtf8("dateLineEdit"));
        dateLineEdit->setGeometry(QRect(130, 120, 150, 25));
        dateLineEdit->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        dateLineEdit->setReadOnly(true);
        MemberIDlabel_2 = new QLabel(groupBox);
        MemberIDlabel_2->setObjectName(QString::fromUtf8("MemberIDlabel_2"));
        MemberIDlabel_2->setGeometry(QRect(10, 120, 100, 25));
        MemberIDlabel_2->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        itemPurchasedLineEdit = new QLineEdit(groupBox);
        itemPurchasedLineEdit->setObjectName(QString::fromUtf8("itemPurchasedLineEdit"));
        itemPurchasedLineEdit->setGeometry(QRect(130, 160, 150, 25));
        itemPurchasedLineEdit->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        itemPurchasedLineEdit->setReadOnly(true);
        MemberIDlabel_3 = new QLabel(groupBox);
        MemberIDlabel_3->setObjectName(QString::fromUtf8("MemberIDlabel_3"));
        MemberIDlabel_3->setGeometry(QRect(10, 160, 100, 25));
        MemberIDlabel_3->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        salePriceLineEdit = new QLineEdit(groupBox);
        salePriceLineEdit->setObjectName(QString::fromUtf8("salePriceLineEdit"));
        salePriceLineEdit->setGeometry(QRect(130, 200, 150, 25));
        salePriceLineEdit->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        salePriceLineEdit->setReadOnly(true);
        MemberIDlabel_4 = new QLabel(groupBox);
        MemberIDlabel_4->setObjectName(QString::fromUtf8("MemberIDlabel_4"));
        MemberIDlabel_4->setGeometry(QRect(10, 200, 100, 25));
        MemberIDlabel_4->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        quantityLineEdit = new QLineEdit(groupBox);
        quantityLineEdit->setObjectName(QString::fromUtf8("quantityLineEdit"));
        quantityLineEdit->setGeometry(QRect(130, 240, 150, 25));
        quantityLineEdit->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        quantityLineEdit->setReadOnly(true);
        MemberIDlabel_5 = new QLabel(groupBox);
        MemberIDlabel_5->setObjectName(QString::fromUtf8("MemberIDlabel_5"));
        MemberIDlabel_5->setGeometry(QRect(10, 240, 100, 25));
        MemberIDlabel_5->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        orderIDcomboBox = new QComboBox(groupBox);
        orderIDcomboBox->setObjectName(QString::fromUtf8("orderIDcomboBox"));
        orderIDcomboBox->setGeometry(QRect(130, 80, 150, 25));
        orderIDcomboBox->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        MemberIDlabel_6 = new QLabel(groupBox);
        MemberIDlabel_6->setObjectName(QString::fromUtf8("MemberIDlabel_6"));
        MemberIDlabel_6->setGeometry(QRect(10, 80, 100, 25));
        MemberIDlabel_6->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";"));
        textEdit = new QTextEdit(mMemberPurchases);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 10, 731, 61));
        textEdit->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;"));
        textEdit->setReadOnly(true);

        retranslateUi(mMemberPurchases);

        QMetaObject::connectSlotsByName(mMemberPurchases);
    } // setupUi

    void retranslateUi(QWidget *mMemberPurchases)
    {
        mMemberPurchases->setWindowTitle(QApplication::translate("mMemberPurchases", "Form", nullptr));
        groupBox->setTitle(QString());
        MemberIDlabel->setText(QApplication::translate("mMemberPurchases", "Member ID", nullptr));
        grandTotalLabel->setText(QApplication::translate("mMemberPurchases", "Grand Total", nullptr));
        MemberIDlabel_2->setText(QApplication::translate("mMemberPurchases", "Date", nullptr));
        MemberIDlabel_3->setText(QApplication::translate("mMemberPurchases", "Item purchased", nullptr));
        MemberIDlabel_4->setText(QApplication::translate("mMemberPurchases", "Sale price", nullptr));
        MemberIDlabel_5->setText(QApplication::translate("mMemberPurchases", "Quantity", nullptr));
        MemberIDlabel_6->setText(QApplication::translate("mMemberPurchases", "Order ID", nullptr));
        textEdit->setHtml(QApplication::translate("mMemberPurchases", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#5555ff;\">Membership Purchases</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mMemberPurchases: public Ui_mMemberPurchases {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMEMBERPURCHASES_H
