#include "aConvertMembership.h"
#include "ui_aConvertMembership.h"

//Default Constructor
aConvertMembership::aConvertMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aConvertMembership)
{
    ui->setupUi(this);

    // Assign connection to object for use in managerMembership
    myDB = QSqlDatabase::database();

    // Displays all regular members that would benefit from an upgrade
    displayUpGradeTable();

    // Displays all inactive executive members that should downgrade
    displayDownGradeTable();
}

// Destructor
aConvertMembership::~aConvertMembership()
{
    delete ui;
}

/****************************************************************************
 * METHOD - displayUpGradeTable
 * --------------------------------------------------------------------------
 * Displays table view for regular member's that should upgrade membership type.
 * Displays customer name, membership id number, and rebate amount.
 * Table is ordered by membershipNumber and sorted to only show the regular
 * members that benefit from an upgrade to executive status.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays view of the regular member's rebate information in a table.
 ***************************************************************************/
void aConvertMembership::displayUpGradeTable() const
{
    // Create query model
    QSqlQueryModel *model = new QSqlQueryModel;

    // Define query model
    model->setQuery("SELECT customerName, membershipNumber, "
                    "rebateAmount "
                    "FROM MembershipDB "
                    "WHERE rebateAmount >= 55 AND membershipType = 'Regular' "
                    "ORDER BY membershipNumber ASC");

    // Display query error if exists
    if(model->lastError().isValid())
        qDebug() << model->lastError();

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Rebate Amount"));

    // Display table with query model
    ui->upGradeTable->setModel(model);
}

/****************************************************************************
 * METHOD - displayDownGradeTable
 * --------------------------------------------------------------------------
 * Displays table view for executive member's that should downgrade membership type.
 * Displays customer name, membership id number, and rebate amount.
 * Table is ordered by membershipNumber and sorted to only show the executive
 * members that benefit from downgrading to regular status.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays view of the executive member's rebate information in a table.
 ***************************************************************************/
void aConvertMembership::displayDownGradeTable() const
{
    // Create query model
    QSqlQueryModel *model = new QSqlQueryModel;

    // Define query model
    model->setQuery("SELECT customerName, membershipNumber, "
                    "rebateAmount "
                    "FROM MembershipDB "
                    "WHERE rebateAmount < 55 AND membershipType = 'Executive' "
                    "ORDER BY membershipNumber ASC");

    // Display query error if exists
    if(model->lastError().isValid())
        qDebug() << model->lastError();

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Rebate Amount"));

    // Display table with query model
    ui->downGradeTable->setModel(model);
}
