/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QLabel *label;
    QGroupBox *pushButtonGroup;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *homeButton;
    QPushButton *membershipButton;
    QPushButton *salesButton;
    QPushButton *inventoryButton;
    QPushButton *convertMembershipButton;
    QPushButton *logoutButton;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QString::fromUtf8("admin"));
        admin->resize(1200, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(admin->sizePolicy().hasHeightForWidth());
        admin->setSizePolicy(sizePolicy);
        admin->setMinimumSize(QSize(1200, 700));
        admin->setMaximumSize(QSize(1200, 700));
        stackedWidget = new QStackedWidget(admin);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 1200, 640));
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        label = new QLabel(mainPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 180, 391, 171));
        stackedWidget->addWidget(mainPage);
        pushButtonGroup = new QGroupBox(admin);
        pushButtonGroup->setObjectName(QString::fromUtf8("pushButtonGroup"));
        pushButtonGroup->setGeometry(QRect(0, 0, 1201, 60));
        pushButtonGroup->setStyleSheet(QString::fromUtf8("background-color: #000080;"));
        widget = new QWidget(pushButtonGroup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 10, 1081, 31));
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

        membershipButton = new QPushButton(widget);
        membershipButton->setObjectName(QString::fromUtf8("membershipButton"));
        membershipButton->setMaximumSize(QSize(16777215, 16777215));
        membershipButton->setFont(font);
        membershipButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(membershipButton);

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

        inventoryButton = new QPushButton(widget);
        inventoryButton->setObjectName(QString::fromUtf8("inventoryButton"));
        inventoryButton->setMaximumSize(QSize(16777215, 16777215));
        inventoryButton->setFont(font);
        inventoryButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(inventoryButton);

        convertMembershipButton = new QPushButton(widget);
        convertMembershipButton->setObjectName(QString::fromUtf8("convertMembershipButton"));
        convertMembershipButton->setFont(font);
        convertMembershipButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(convertMembershipButton);

        logoutButton = new QPushButton(widget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setFont(font);
        logoutButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(logoutButton);


        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QApplication::translate("admin", "Admin Window", nullptr));
        label->setText(QApplication::translate("admin", "Admin Widget (main Page of stacked widget)", nullptr));
        pushButtonGroup->setTitle(QString());
        homeButton->setText(QApplication::translate("admin", "HOME", nullptr));
        membershipButton->setText(QApplication::translate("admin", "Edit Membership", nullptr));
        salesButton->setText(QApplication::translate("admin", "Edit Sales", nullptr));
        inventoryButton->setText(QApplication::translate("admin", "Edit Inventory", nullptr));
        convertMembershipButton->setText(QApplication::translate("admin", "Convert Membership", nullptr));
        logoutButton->setText(QApplication::translate("admin", "LOGOUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
