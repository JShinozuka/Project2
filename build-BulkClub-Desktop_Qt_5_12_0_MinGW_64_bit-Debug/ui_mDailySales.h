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
#include <QtWidgets/QComboBox>
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
    QGroupBox *groupBox;
    QTableView *salesReportTableView;
    QLabel *dailySalesTitle;
    QLabel *numberOfExeuMem;
    QLabel *numberOfRegMem;
    QComboBox *monthBox;
    QComboBox *dateBox;
    QComboBox *yearBox;
    QPushButton *viewAllMembersButton;
    QLabel *totalRevenuelable;
    QPushButton *pushButton;
    QPushButton *regularMembersView;
    QTextEdit *totalRevenue;
    QTextEdit *regMemTextEdit;
    QTextEdit *execMemTextEdit;
    QPushButton *selectDateButton;

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
        groupBox = new QGroupBox(mDailySales);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 711, 571));
        salesReportTableView = new QTableView(groupBox);
        salesReportTableView->setObjectName(QString::fromUtf8("salesReportTableView"));
        salesReportTableView->setGeometry(QRect(10, 10, 701, 521));
        dailySalesTitle = new QLabel(mDailySales);
        dailySalesTitle->setObjectName(QString::fromUtf8("dailySalesTitle"));
        dailySalesTitle->setGeometry(QRect(20, 20, 651, 31));
        QFont font;
        font.setPointSize(16);
        dailySalesTitle->setFont(font);
        dailySalesTitle->setStyleSheet(QString::fromUtf8("color: blue;"));
        numberOfExeuMem = new QLabel(mDailySales);
        numberOfExeuMem->setObjectName(QString::fromUtf8("numberOfExeuMem"));
        numberOfExeuMem->setGeometry(QRect(790, 250, 151, 20));
        QFont font1;
        font1.setPointSize(12);
        numberOfExeuMem->setFont(font1);
        numberOfRegMem = new QLabel(mDailySales);
        numberOfRegMem->setObjectName(QString::fromUtf8("numberOfRegMem"));
        numberOfRegMem->setGeometry(QRect(800, 340, 121, 20));
        numberOfRegMem->setFont(font1);
        monthBox = new QComboBox(mDailySales);
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->addItem(QString());
        monthBox->setObjectName(QString::fromUtf8("monthBox"));
        monthBox->setGeometry(QRect(730, 120, 81, 41));
        monthBox->setFont(font1);
        dateBox = new QComboBox(mDailySales);
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->addItem(QString());
        dateBox->setObjectName(QString::fromUtf8("dateBox"));
        dateBox->setGeometry(QRect(820, 120, 71, 41));
        dateBox->setFont(font1);
        yearBox = new QComboBox(mDailySales);
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->addItem(QString());
        yearBox->setObjectName(QString::fromUtf8("yearBox"));
        yearBox->setGeometry(QRect(900, 120, 101, 41));
        yearBox->setFont(font1);
        viewAllMembersButton = new QPushButton(mDailySales);
        viewAllMembersButton->setObjectName(QString::fromUtf8("viewAllMembersButton"));
        viewAllMembersButton->setGeometry(QRect(730, 190, 111, 31));
        QFont font2;
        font2.setPointSize(10);
        viewAllMembersButton->setFont(font2);
        totalRevenuelable = new QLabel(mDailySales);
        totalRevenuelable->setObjectName(QString::fromUtf8("totalRevenuelable"));
        totalRevenuelable->setGeometry(QRect(800, 430, 121, 21));
        totalRevenuelable->setFont(font1);
        pushButton = new QPushButton(mDailySales);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(850, 190, 151, 31));
        pushButton->setFont(font2);
        regularMembersView = new QPushButton(mDailySales);
        regularMembersView->setObjectName(QString::fromUtf8("regularMembersView"));
        regularMembersView->setGeometry(QRect(1010, 190, 151, 31));
        regularMembersView->setFont(font2);
        totalRevenue = new QTextEdit(mDailySales);
        totalRevenue->setObjectName(QString::fromUtf8("totalRevenue"));
        totalRevenue->setGeometry(QRect(940, 420, 211, 64));
        regMemTextEdit = new QTextEdit(mDailySales);
        regMemTextEdit->setObjectName(QString::fromUtf8("regMemTextEdit"));
        regMemTextEdit->setGeometry(QRect(940, 320, 191, 64));
        execMemTextEdit = new QTextEdit(mDailySales);
        execMemTextEdit->setObjectName(QString::fromUtf8("execMemTextEdit"));
        execMemTextEdit->setGeometry(QRect(940, 240, 181, 64));
        selectDateButton = new QPushButton(mDailySales);
        selectDateButton->setObjectName(QString::fromUtf8("selectDateButton"));
        selectDateButton->setGeometry(QRect(1020, 120, 131, 41));
        selectDateButton->setFont(font1);

        retranslateUi(mDailySales);

        QMetaObject::connectSlotsByName(mDailySales);
    } // setupUi

    void retranslateUi(QWidget *mDailySales)
    {
        mDailySales->setWindowTitle(QApplication::translate("mDailySales", "Form", nullptr));
        groupBox->setTitle(QString());
        dailySalesTitle->setText(QApplication::translate("mDailySales", "Daily Sales Report", nullptr));
        numberOfExeuMem->setText(QApplication::translate("mDailySales", "Executive Member: ", nullptr));
        numberOfRegMem->setText(QApplication::translate("mDailySales", "Regular Member:", nullptr));
        monthBox->setItemText(0, QApplication::translate("mDailySales", "01", nullptr));
        monthBox->setItemText(1, QApplication::translate("mDailySales", "02", nullptr));
        monthBox->setItemText(2, QApplication::translate("mDailySales", "03", nullptr));
        monthBox->setItemText(3, QApplication::translate("mDailySales", "04", nullptr));
        monthBox->setItemText(4, QApplication::translate("mDailySales", "05", nullptr));
        monthBox->setItemText(5, QApplication::translate("mDailySales", "06", nullptr));
        monthBox->setItemText(6, QApplication::translate("mDailySales", "07", nullptr));
        monthBox->setItemText(7, QApplication::translate("mDailySales", "08", nullptr));
        monthBox->setItemText(8, QApplication::translate("mDailySales", "09", nullptr));
        monthBox->setItemText(9, QApplication::translate("mDailySales", "10", nullptr));
        monthBox->setItemText(10, QApplication::translate("mDailySales", "11", nullptr));
        monthBox->setItemText(11, QApplication::translate("mDailySales", "12", nullptr));
        monthBox->setItemText(12, QString());

        dateBox->setItemText(0, QApplication::translate("mDailySales", "01", nullptr));
        dateBox->setItemText(1, QApplication::translate("mDailySales", "02", nullptr));
        dateBox->setItemText(2, QApplication::translate("mDailySales", "03", nullptr));
        dateBox->setItemText(3, QApplication::translate("mDailySales", "04", nullptr));
        dateBox->setItemText(4, QApplication::translate("mDailySales", "05", nullptr));
        dateBox->setItemText(5, QApplication::translate("mDailySales", "06", nullptr));
        dateBox->setItemText(6, QApplication::translate("mDailySales", "07", nullptr));
        dateBox->setItemText(7, QApplication::translate("mDailySales", "08", nullptr));
        dateBox->setItemText(8, QApplication::translate("mDailySales", "09", nullptr));
        dateBox->setItemText(9, QApplication::translate("mDailySales", "10", nullptr));
        dateBox->setItemText(10, QApplication::translate("mDailySales", "11", nullptr));
        dateBox->setItemText(11, QApplication::translate("mDailySales", "12", nullptr));
        dateBox->setItemText(12, QApplication::translate("mDailySales", "13", nullptr));
        dateBox->setItemText(13, QApplication::translate("mDailySales", "14", nullptr));
        dateBox->setItemText(14, QApplication::translate("mDailySales", "15", nullptr));
        dateBox->setItemText(15, QApplication::translate("mDailySales", "16", nullptr));
        dateBox->setItemText(16, QApplication::translate("mDailySales", "17", nullptr));
        dateBox->setItemText(17, QApplication::translate("mDailySales", "18", nullptr));
        dateBox->setItemText(18, QApplication::translate("mDailySales", "19", nullptr));
        dateBox->setItemText(19, QApplication::translate("mDailySales", "20", nullptr));
        dateBox->setItemText(20, QApplication::translate("mDailySales", "21", nullptr));
        dateBox->setItemText(21, QApplication::translate("mDailySales", "22", nullptr));
        dateBox->setItemText(22, QApplication::translate("mDailySales", "23", nullptr));
        dateBox->setItemText(23, QApplication::translate("mDailySales", "24", nullptr));
        dateBox->setItemText(24, QApplication::translate("mDailySales", "25", nullptr));
        dateBox->setItemText(25, QApplication::translate("mDailySales", "26", nullptr));
        dateBox->setItemText(26, QApplication::translate("mDailySales", "27", nullptr));
        dateBox->setItemText(27, QApplication::translate("mDailySales", "28", nullptr));
        dateBox->setItemText(28, QApplication::translate("mDailySales", "29", nullptr));
        dateBox->setItemText(29, QApplication::translate("mDailySales", "30", nullptr));
        dateBox->setItemText(30, QApplication::translate("mDailySales", "31", nullptr));

        yearBox->setItemText(0, QApplication::translate("mDailySales", "2000", nullptr));
        yearBox->setItemText(1, QApplication::translate("mDailySales", "2001", nullptr));
        yearBox->setItemText(2, QApplication::translate("mDailySales", "2002", nullptr));
        yearBox->setItemText(3, QApplication::translate("mDailySales", "2003", nullptr));
        yearBox->setItemText(4, QApplication::translate("mDailySales", "2004", nullptr));
        yearBox->setItemText(5, QApplication::translate("mDailySales", "2005", nullptr));
        yearBox->setItemText(6, QApplication::translate("mDailySales", "2006", nullptr));
        yearBox->setItemText(7, QApplication::translate("mDailySales", "2007", nullptr));
        yearBox->setItemText(8, QApplication::translate("mDailySales", "2008", nullptr));
        yearBox->setItemText(9, QApplication::translate("mDailySales", "2009", nullptr));
        yearBox->setItemText(10, QApplication::translate("mDailySales", "2010", nullptr));
        yearBox->setItemText(11, QApplication::translate("mDailySales", "2011", nullptr));
        yearBox->setItemText(12, QApplication::translate("mDailySales", "2012", nullptr));
        yearBox->setItemText(13, QApplication::translate("mDailySales", "2013", nullptr));
        yearBox->setItemText(14, QApplication::translate("mDailySales", "2014", nullptr));
        yearBox->setItemText(15, QApplication::translate("mDailySales", "2015", nullptr));
        yearBox->setItemText(16, QApplication::translate("mDailySales", "2016", nullptr));
        yearBox->setItemText(17, QApplication::translate("mDailySales", "2017", nullptr));
        yearBox->setItemText(18, QApplication::translate("mDailySales", "2018", nullptr));
        yearBox->setItemText(19, QApplication::translate("mDailySales", "2019", nullptr));

        viewAllMembersButton->setText(QApplication::translate("mDailySales", "View all Members", nullptr));
        totalRevenuelable->setText(QApplication::translate("mDailySales", "Total Revuene: ", nullptr));
        pushButton->setText(QApplication::translate("mDailySales", "View Executive Members", nullptr));
        regularMembersView->setText(QApplication::translate("mDailySales", "View Regular Members", nullptr));
        selectDateButton->setText(QApplication::translate("mDailySales", "Select Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mDailySales: public Ui_mDailySales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDAILYSALES_H
