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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aSales
{
public:
    QLabel *label;

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
        label = new QLabel(aSales);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 200, 281, 161));

        retranslateUi(aSales);

        QMetaObject::connectSlotsByName(aSales);
    } // setupUi

    void retranslateUi(QWidget *aSales)
    {
        aSales->setWindowTitle(QApplication::translate("aSales", "Form", nullptr));
        label->setText(QApplication::translate("aSales", "Admin Sales Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aSales: public Ui_aSales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASALES_H
