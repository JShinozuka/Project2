#include "aMembership.h"
#include "ui_aMembership.h"

//Default Constructor
aMembership::aMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aMembership)
{
    ui->setupUi(this);
    //Create database and display the table
    myDB = QSqlDatabase::database();
    displayDefaultTable();

    //populate the combo box
   updateComboBox();
}

//Destructor
aMembership::~aMembership()
{
    delete ui;
}

/****************************************************************************
 * METHOD - on_addCustomer_clicked()
 * --------------------------------------------------------------------------
 * This method creates a new member with data entered from an admin.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Updates database/table view
 *      ==> Updates and shows the correct name box for deleting afterwards
 ***************************************************************************/
void aMembership::on_addCustomer_clicked()
{
   QString name, num, type, date, totalAmount, renewalCost;
   int day, month, year;
   name = ui->name->toPlainText();
   num= ui->membershipNum->toPlainText();
   type = ui->membershipTypeBox->currentText();
   totalAmount=  '0';


   month = ui->dateEdit->date().month();
   day = ui->dateEdit->date().day();
   year = ui->dateEdit->date().year();

   date = ui->dateEdit->date().toString("MM/dd/yyyy");
   qDebug() << month << " " << day << " " << year;

   if (type == "Regular")
   {
       renewalCost = "65";
   }

   else {
   renewalCost = "120";
   }

   QSqlQuery query;

   query.prepare("INSERT INTO membershipDB (customerName, membershipNumber, membershipType, "
                 "expireDate, totalAmountSpent) "
                 "VALUES ('"+name+"' , '"+num+"', '"+type+"', '"+date+"', '"+totalAmount+"') " );

   if(query.exec())
          qDebug()<<("added");
  else
      qDebug()<<("add failed");
   displayDefaultTable();
   updateComboBox();

}

/****************************************************************************
 * METHOD - on_deleteCustomer_clicked
 * --------------------------------------------------------------------------
 * This method deletes a customer when an admin selects the correspoding name
 * clicks on the button.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Creates and connects to SQLite database if not open
 ***************************************************************************/
void aMembership::on_deleteCustomer_clicked()
{
    QMessageBox::StandardButton message;
    message = QMessageBox::information(this, "Are you sure?",
                  "You are about to delete a member!",
                  QMessageBox::Ok,QMessageBox::No);
    if(message == QMessageBox::Ok)
    {
        QSqlQueryModel *model = new QSqlQueryModel;

        QString name = ui->customerNameBox->currentText();

        model->setQuery("DELETE FROM MembershipDB "
                        "WHERE customerName  = '"+ name + "' ");


        displayDefaultTable();
        updateComboBox();
    }
    else if(message == QMessageBox::No)
    {
        displayDefaultTable();
        updateComboBox();
    }

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
 void aMembership::displayDefaultTable() const
 {
     QSqlQueryModel *model = new QSqlQueryModel;

     model->setQuery("SELECT customerName, membershipNumber, membershipType, "
                     "expireDate, totalAmountSpent, rebateAmount "
                     "FROM MembershipDB "
                     "ORDER BY customerName ");
     if(model->lastError().isValid())
         qDebug() << model->lastError();
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Membership Number"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Membership Type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Expiration Date"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total Amount spent"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Rebate Amount"));

    ui->memberDBTable->setModel(model);
 }

 /****************************************************************************
  * METHOD - updateComboBox
  * --------------------------------------------------------------------------
  * This function will update the combo box for the peoples names.
  * --------------------------------------------------------------------------
  * PRE-CONDITIONS
  *      No parameters are required.
  *
  * POST-CONDITIONS
  *      ==> Returns nothing.
  *      ==> Displays updated information for the combo box
  ***************************************************************************/
 void aMembership::updateComboBox() const
 {
     QSqlQuery * query2 = new QSqlQuery(myDB);
     QSqlQueryModel * comboBox = new QSqlQueryModel();

     query2->prepare("SELECT DISTINCT customerName "
                    "FROM MembershipDB "
                    "ORDER BY customerName COLLATE NOCASE ASC ");
     query2->exec();

     comboBox->setQuery(*query2);

     ui->customerNameBox->setModel(comboBox);
 }
