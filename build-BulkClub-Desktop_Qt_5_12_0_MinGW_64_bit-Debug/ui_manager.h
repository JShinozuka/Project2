/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manager
{
public:
    QGroupBox *pushButtonGroup;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *homeButton;
    QPushButton *membershipExpireButton;
    QPushButton *dailySalesButton;
    QPushButton *memberPurchasesButton;
    QPushButton *rebateButton;
    QPushButton *inventoryButton;
    QPushButton *salesButton;
    QPushButton *logoutButton;
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QLabel *label;

    void setupUi(QWidget *manager)
    {
        if (manager->objectName().isEmpty())
            manager->setObjectName(QString::fromUtf8("manager"));
        manager->resize(1200, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(manager->sizePolicy().hasHeightForWidth());
        manager->setSizePolicy(sizePolicy);
        manager->setMinimumSize(QSize(1200, 700));
        manager->setMaximumSize(QSize(1200, 700));
        pushButtonGroup = new QGroupBox(manager);
        pushButtonGroup->setObjectName(QString::fromUtf8("pushButtonGroup"));
        pushButtonGroup->setGeometry(QRect(0, 0, 1200, 60));
        pushButtonGroup->setStyleSheet(QString::fromUtf8("background-color: #000080;"));
        widget = new QWidget(pushButtonGroup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 20, 1171, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        homeButton = new QPushButton(widget);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        homeButton->setFont(font);
        homeButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(homeButton);

        membershipExpireButton = new QPushButton(widget);
        membershipExpireButton->setObjectName(QString::fromUtf8("membershipExpireButton"));
        membershipExpireButton->setMaximumSize(QSize(16777215, 16777215));
        membershipExpireButton->setFont(font);
        membershipExpireButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(membershipExpireButton);

        dailySalesButton = new QPushButton(widget);
        dailySalesButton->setObjectName(QString::fromUtf8("dailySalesButton"));
        dailySalesButton->setMaximumSize(QSize(16777215, 16777215));
        dailySalesButton->setFont(font);
        dailySalesButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(dailySalesButton);

        memberPurchasesButton = new QPushButton(widget);
        memberPurchasesButton->setObjectName(QString::fromUtf8("memberPurchasesButton"));
        memberPurchasesButton->setFont(font);
        memberPurchasesButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(memberPurchasesButton);

        rebateButton = new QPushButton(widget);
        rebateButton->setObjectName(QString::fromUtf8("rebateButton"));
        rebateButton->setMaximumSize(QSize(16777215, 16777215));
        rebateButton->setFont(font);
        rebateButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(rebateButton);

        inventoryButton = new QPushButton(widget);
        inventoryButton->setObjectName(QString::fromUtf8("inventoryButton"));
        inventoryButton->setFont(font);
        inventoryButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(inventoryButton);

        salesButton = new QPushButton(widget);
        salesButton->setObjectName(QString::fromUtf8("salesButton"));
        salesButton->setMaximumSize(QSize(16777215, 16777215));
        salesButton->setFont(font);
        salesButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(salesButton);

        logoutButton = new QPushButton(widget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setFont(font);
        logoutButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(logoutButton);

        stackedWidget = new QStackedWidget(manager);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 1200, 640));
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        label = new QLabel(mainPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 180, 391, 171));
        stackedWidget->addWidget(mainPage);

        retranslateUi(manager);

        QMetaObject::connectSlotsByName(manager);
    } // setupUi

    void retranslateUi(QWidget *manager)
    {
        manager->setWindowTitle(QApplication::translate("manager", "Manager Window", nullptr));
        pushButtonGroup->setTitle(QString());
        homeButton->setText(QApplication::translate("manager", "HOME", nullptr));
        membershipExpireButton->setText(QApplication::translate("manager", "Membership Info", nullptr));
        dailySalesButton->setText(QApplication::translate("manager", "Daily Sales", nullptr));
        memberPurchasesButton->setText(QApplication::translate("manager", "Member Purchases", nullptr));
        rebateButton->setText(QApplication::translate("manager", "Rebate Info", nullptr));
        inventoryButton->setText(QApplication::translate("manager", "Inventory Info", nullptr));
        salesButton->setText(QApplication::translate("manager", "Duplicate?", nullptr));
        logoutButton->setText(QApplication::translate("manager", "LOGOUT", nullptr));
        label->setText(QApplication::translate("manager", "manager Widget (main Page of stacked widget)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manager: public Ui_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
