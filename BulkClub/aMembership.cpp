#include "aMembership.h"
#include "ui_aMembership.h"

aMembership::aMembership(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aMembership)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();
    displayDefaultTable();

    //populate the combo box
    QSqlQuery * query = new QSqlQuery(myDB);
    QSqlQueryModel * comboBox = new QSqlQueryModel();

    query->prepare("SELECT DISTINCT customerName "
                   "FROM MembershipDB "
                   "ORDER BY customerName COLLATE NOCASE ASC ");
    query->exec();

    comboBox->setQuery(*query);

    ui->customerNameBox->setModel(comboBox);
}

aMembership::~aMembership()
{
    delete ui;
}

void aMembership::on_addCustomer_clicked()
{
   QString name, num, type, date, totalAmount,rebateAmount, renewalCost;
   name = ui->name->toPlainText();
   num= ui->membershipNum->toPlainText();
   type = ui->membershipTypeBox->currentText();
   //date=  ui->expirationDate->toPlainText();
   totalAmount=  '0';
   rebateAmount = '0';
   QString year = ui->yearBox->currentText();
   QString month = ui->monthBox->currentText();
   QString day = ui->dayBox->currentText();
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
                 "expireDate, totalAmountSpent, rebateAmount, renewalCost) "
                 "VALUES ('"+name+"' , '"+num+"', '"+type+"', '"+date+"', '"+totalAmount+"', "
                         "'"+renewalCost+"') " );

   if(query.exec())
          qDebug()<<("added");
  else
      qDebug()<<("add failed");
}

void aMembership::on_deleteCustomer_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;

    QString name = ui->customerNameBox->currentText();

    model->setQuery("DELETE FROM MembershipDB "
                    "WHERE customerName  = '"+ name + "' ");

    displayDefaultTable();
}
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
