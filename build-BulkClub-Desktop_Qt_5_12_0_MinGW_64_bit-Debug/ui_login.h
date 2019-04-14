/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *exitProgramButton;
    QLabel *nameLabel;
    QGroupBox *loginGroupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginManagerButton;
    QPushButton *loginAdminButton;
    QLabel *sandShrewPic;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setMinimumSize(QSize(600, 400));
        login->setMaximumSize(QSize(600, 400));
        exitProgramButton = new QPushButton(login);
        exitProgramButton->setObjectName(QString::fromUtf8("exitProgramButton"));
        exitProgramButton->setGeometry(QRect(480, 345, 104, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        exitProgramButton->setFont(font);
        exitProgramButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: white;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));
        nameLabel = new QLabel(login);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(20, 110, 191, 121));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);
        nameLabel->setWordWrap(true);
        loginGroupBox = new QGroupBox(login);
        loginGroupBox->setObjectName(QString::fromUtf8("loginGroupBox"));
        loginGroupBox->setGeometry(QRect(20, 245, 300, 141));
        loginGroupBox->setStyleSheet(QString::fromUtf8("background: rgba(255, 255, 255, 0.7)"));
        layoutWidget = new QWidget(loginGroupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 281, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        sizePolicy.setHeightForWidth(usernameLabel->sizePolicy().hasHeightForWidth());
        usernameLabel->setSizePolicy(sizePolicy);
        usernameLabel->setMinimumSize(QSize(32, 32));
        usernameLabel->setMaximumSize(QSize(32, 32));
        usernameLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/usernameIcon.png")));
        usernameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameLineEdit = new QLineEdit(layoutWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        QFont font2;
        font2.setPointSize(12);
        usernameLineEdit->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        sizePolicy.setHeightForWidth(passwordLabel->sizePolicy().hasHeightForWidth());
        passwordLabel->setSizePolicy(sizePolicy);
        passwordLabel->setMinimumSize(QSize(32, 32));
        passwordLabel->setMaximumSize(QSize(32, 32));
        passwordLabel->setFont(font2);
        passwordLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/passwordIcon.png")));
        passwordLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setFont(font2);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginManagerButton = new QPushButton(layoutWidget);
        loginManagerButton->setObjectName(QString::fromUtf8("loginManagerButton"));
        sizePolicy.setHeightForWidth(loginManagerButton->sizePolicy().hasHeightForWidth());
        loginManagerButton->setSizePolicy(sizePolicy);
        loginManagerButton->setMinimumSize(QSize(135, 30));
        loginManagerButton->setMaximumSize(QSize(135, 30));
        loginManagerButton->setFont(font);
        loginManagerButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));
        loginManagerButton->setFlat(false);

        horizontalLayout->addWidget(loginManagerButton);

        loginAdminButton = new QPushButton(layoutWidget);
        loginAdminButton->setObjectName(QString::fromUtf8("loginAdminButton"));
        sizePolicy.setHeightForWidth(loginAdminButton->sizePolicy().hasHeightForWidth());
        loginAdminButton->setSizePolicy(sizePolicy);
        loginAdminButton->setMinimumSize(QSize(125, 30));
        loginAdminButton->setMaximumSize(QSize(125, 30));
        loginAdminButton->setFont(font);
        loginAdminButton->setStyleSheet(QString::fromUtf8("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));
        loginAdminButton->setFlat(false);

        horizontalLayout->addWidget(loginAdminButton);


        verticalLayout->addLayout(horizontalLayout);

        sandShrewPic = new QLabel(login);
        sandShrewPic->setObjectName(QString::fromUtf8("sandShrewPic"));
        sandShrewPic->setGeometry(QRect(0, 0, 601, 401));
        sandShrewPic->setFont(font2);
        sandShrewPic->setPixmap(QPixmap(QString::fromUtf8(":/images/bluesandshrew.png")));
        sandShrewPic->raise();
        exitProgramButton->raise();
        nameLabel->raise();
        loginGroupBox->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Login Window", nullptr));
        exitProgramButton->setText(QApplication::translate("login", "Exit", nullptr));
        nameLabel->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#00007f;\">BLUE</span></p><p><span style=\" color:#00007f;\">SANDSHREW'S</span></p><p>BULK CLUB</p></body></html>", nullptr));
        loginGroupBox->setTitle(QString());
        usernameLabel->setText(QString());
        usernameLineEdit->setPlaceholderText(QApplication::translate("login", "Username", nullptr));
        passwordLabel->setText(QString());
        passwordLineEdit->setPlaceholderText(QApplication::translate("login", "Password", nullptr));
#ifndef QT_NO_TOOLTIP
        loginManagerButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        loginManagerButton->setText(QApplication::translate("login", "Manager Login", nullptr));
#ifndef QT_NO_TOOLTIP
        loginAdminButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        loginAdminButton->setText(QApplication::translate("login", "Admin Login", nullptr));
        sandShrewPic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
