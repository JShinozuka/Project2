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

void aMembership::reset()
{
    displayDefaultTable();
    updateComboBox();
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
   name = ui->name->text();
   num= ui->membershipNum->text();
   type = ui->membershipTypeBox->currentText();
   totalAmount=  '0';
   rebateAmount= '0';

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

   QSqlQuery * qry5 = new QSqlQuery(myDB);

   qry5->prepare("INSERT INTO membershipDB(customerName, membershipNumber, membershipType, "
                 "expireDate, monthExpire, dayExpire, yearExpire, totalAmountSpent, rebateAmount, renewalCost) "
                 "VALUES (:name, :num, "
                 ":type,:date,:month, "
                 ":day,:year,:totalAmount, "
                 ":rebateAmount, :renewalCost)");
   qry5->bindValue(0, name);
   qry5->bindValue(1, num);
   qry5->bindValue(2, type);
   qry5->bindValue(3, date);
   qry5->bindValue(4,QString::number(month));
   qry5->bindValue(5,QString::number(day));
   qry5->bindValue(6,QString::number(year));
   qry5->bindValue(7, totalAmount);
   qry5->bindValue(8, rebateAmount);
   qry5->bindValue(9, renewalCost);


   if(qry5->exec())
   {
          qDebug()<<("added");
   }
   else
   {
      qDebug()<<("add failed");

      qDebug()<<("add failed");
      QMessageBox::information(this, "Error Add Failed",
                "Please make sure all fields are added and the member ID is unique!",
                QMessageBox::Ok);
    }


   displayDefaultTable();
   updateComboBox();
   ui->name->clear();
   ui->membershipNum->clear();

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
    //Deletion message
    QMessageBox::StandardButton message;
    message = QMessageBox::information(this, "Confirm action",
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
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Member ID#"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Expire Date"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total Spent"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Rebate Amt"));

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
