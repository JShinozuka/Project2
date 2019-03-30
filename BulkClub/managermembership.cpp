#include "managermembership.h"
#include "ui_managermembership.h"

// Default Constructor
managerMembership::managerMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerMembership)
{
    ui->setupUi(this);

    // Assign connection to object for use in managerMembership
    myDB = QSqlDatabase::database();

    // Displays all membership expiration ordered by expiration date
    displayDefaultExpireTable();
}

// Destructor
managerMembership::~managerMembership()
{
    delete ui;
}

/****************************************************************************
 * METHOD - displayDefaultExpireTable
 * --------------------------------------------------------------------------
 * Displays default view for membership expiration table.  Displays
 * customer name, membership id number, membership type, and
 * expiration date.  Table is ordered by expiration date (ascending order).
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays default view of membership expiration table.
 ***************************************************************************/
void managerMembership::displayDefaultExpireTable() const
{
    // Create query model
    QSqlQueryModel *model = new QSqlQueryModel;

    // Define query model
    model->setQuery("SELECT customerName, membershipNumber, "
                    "membershipType, expireDate "
                    "FROM MembershipDB "
                    "ORDER BY expireDate");

    // Display query error if exists
    if(model->lastError().isValid())
        qDebug() << model->lastError();

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Membership"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Expires"));

    // Display table with query model
    ui->membershipExpirationTable->setModel(model);
}

/****************************************************************************
 * METHOD - on_selectMonthBox_currentIndexChanged
 * --------------------------------------------------------------------------
 * Displays selected month's membership expiration.  Displays
 * customer name, membership id number, membership type, and
 * expiration date.  Table is ordered by expiration date (ascending order).
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays selected month's expiration to membership expiration
 *          table.
 ***************************************************************************/
void managerMembership::on_selectMonthBox_currentIndexChanged(int index)
{
    QString month = QString::number(index); // CALC - expiration month
                                            //        selected for display

    // If index 0 (view all months option), then display default table view
    if(month == "0")
    {
       displayDefaultExpireTable();
    }
    // Display expirations for selected month
    else
    {
        // Create query model
        QSqlQueryModel *model = new QSqlQueryModel;

        // Define query model
        model->setQuery("SELECT customerName, membershipNumber, "
                        "membershipType, expireDate "
                        "FROM MembershipDB "
                        "WHERE monthExpire ='"+ month + "' "
                        "ORDER BY expireDate");

        // Display query error if exists
        if(model->lastError().isValid())
            qDebug() << model->lastError();

        // Set Table Column Header Text
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Membership"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Expires"));

        // Display table with query model
        ui->membershipExpirationTable->setModel(model);
    }
}
