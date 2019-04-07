#include "managerrebateinfo.h"
#include "ui_managerrebateinfo.h"

// Default Constructor
managerRebateInfo::managerRebateInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerRebateInfo)
{
    ui->setupUi(this);

    // Assign connection to object for use in managerMembership
    myDB = QSqlDatabase::database();

    // Displays all executive members rebate information
    displayDefaultRebateTable();


}

// Destructor
managerRebateInfo::~managerRebateInfo()
{
    delete ui;
}

/****************************************************************************
 * METHOD - displayDefaultRebateTable
 * --------------------------------------------------------------------------
 * Displays default view for executive member's rebate table.  Displays
 * customer name, membership id number, and rebate amount.
 * Table is ordered by rebate amount (ascending order).
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays default view of the member rebate table.
 ***************************************************************************/
void managerRebateInfo::displayDefaultRebateTable() const
{
    // Create query model
    QSqlQueryModel *model = new QSqlQueryModel;

    // Define query model
    model->setQuery("SELECT membershipNumber, customerName, "
                    "rebateAmount "
                    "FROM MembershipDB "
                    "WHERE membershipType = 'Executive' "
                    "ORDER BY membershipNumber ASC");

    // Display query error if exists
    if(model->lastError().isValid())
        qDebug() << model->lastError();

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Rebate Amount"));

    // Display table with query model
    ui->rebateTableView->setModel(model);
}

/****************************************************************************
 * METHOD - on_selectMonthBox_currentIndexChanged
 * --------------------------------------------------------------------------
 * Displays selected member's rebate information in specific order. Displays
 * customer name, membership id number,and rebate amount.
 * Table is ordered by rebate amount (ascending order).
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays selected sort of member's rebate amount.
 ***************************************************************************/
void managerRebateInfo::on_selectMonthBox_currentIndexChanged(int index)
{
    QString sortBy = QString::number(index); // CALC - expiration month
                                            //        selected for display

    // If index 0 (view rebate amounts, highest to lowest)
    if(sortBy == "0")
    {
       displayDefaultRebateTable();
    }
    // Display rebate amounts lowest to highest
    else if(sortBy == "1")
    {
        // Create query model
        QSqlQueryModel *model = new QSqlQueryModel;

        // Define query model
        model->setQuery("SELECT membershipNumber, customerName, "
                        "rebateAmount "
                        "FROM MembershipDB "
                        "WHERE membershipType = 'Executive' "
                        "ORDER BY rebateAmount DESC ");

        // Display query error if exists
        if(model->lastError().isValid())
            qDebug() << model->lastError();

        // Set Table Column Header Text
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Rebate Amount"));

        // Display table with query model
        ui->rebateTableView->setModel(model);
    }
    else if(sortBy == "2")
    {
        // Create query model
        QSqlQueryModel *model = new QSqlQueryModel;

        // Define query model
        model->setQuery("SELECT membershipNumber, customerName, "
                        "rebateAmount "
                        "FROM MembershipDB "
                        "WHERE membershipType = 'Executive' "
                        "ORDER BY rebateAmount ASC ");

        // Display query error if exists
        if(model->lastError().isValid())
            qDebug() << model->lastError();

        // Set Table Column Header Text
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Rebate Amount"));

        // Display table with query model
        ui->rebateTableView->setModel(model);
    }
}
