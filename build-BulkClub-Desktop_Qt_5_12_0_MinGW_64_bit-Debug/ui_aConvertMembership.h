/********************************************************************************
** Form generated from reading UI file 'aConvertMembership.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACONVERTMEMBERSHIP_H
#define UI_ACONVERTMEMBERSHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aConvertMembership
{
public:
    QLabel *label;

    void setupUi(QWidget *aConvertMembership)
    {
        if (aConvertMembership->objectName().isEmpty())
            aConvertMembership->setObjectName(QString::fromUtf8("aConvertMembership"));
        aConvertMembership->resize(1200, 640);
        aConvertMembership->setMinimumSize(QSize(1200, 640));
        aConvertMembership->setMaximumSize(QSize(1200, 640));
        label = new QLabel(aConvertMembership);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 521, 71));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(aConvertMembership);

        QMetaObject::connectSlotsByName(aConvertMembership);
    } // setupUi

    void retranslateUi(QWidget *aConvertMembership)
    {
        aConvertMembership->setWindowTitle(QApplication::translate("aConvertMembership", "Form", nullptr));
        label->setText(QApplication::translate("aConvertMembership", "Convert Membership", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aConvertMembership: public Ui_aConvertMembership {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACONVERTMEMBERSHIP_H
