#include "aSales.h"
#include "ui_aSales.h"

aSales::aSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aSales)
{

    ui->setupUi(this);

    defaultAddSale();
}

aSales::~aSales()
{
    delete ui;
}

void aSales::defaultAddSale()
{
    //set default table:

    myDB = QSqlDatabase::database();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT SaleID, date, membershipNum, itemPurchased, quantity, salePrice "
                    "FROM SalesDB "
                    "ORDER BY SaleID COLLATE NOCASE ASC ");

    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->aSalesTableView->setModel(model);

    qDebug() << "MODEL ROW COUNT" << (model->rowCount());

    // Set Table Column Width
    ui->aSalesTableView->setColumnWidth(0,100);
    ui->aSalesTableView->setColumnWidth(1,120);
    ui->aSalesTableView->setColumnWidth(2,150);
    ui->aSalesTableView->setColumnWidth(3,150);
    ui->aSalesTableView->setColumnWidth(4,60);
    ui->aSalesTableView->setColumnWidth(5,80);

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Order ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Membership #"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Item Name"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Qty"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Price"));
    // Set default date

    ui->dateEdit->setDate(QDate(2019,01,01));


    //ui->dateEdit->;

    // POPULATE THE COMBO BOX for MEMBER ID

    QSqlQuery * qry = new QSqlQuery(myDB);

    QSqlQueryModel * combo = new QSqlQueryModel();


    qry->prepare("SELECT DISTINCT membershipNumber "
                 "FROM MembershipDB ORDER BY membershipNumber COLLATE NOCASE ASC");
    qry->exec();

    combo->setQuery(*qry);

    ui->memberIDComboBox->setModel(combo);

    ui->memberIDComboBox->setCurrentIndex(-1); //Set default value for member ID combo

    // POPULATE THE COMBO BOX for itemName

    QSqlQuery * qry2 = new QSqlQuery(myDB);

    QSqlQueryModel * combo2 = new QSqlQueryModel();

    qry2->prepare("SELECT itemName "
                 "FROM InventoryDB ORDER BY itemName COLLATE NOCASE ASC");
    qry2->exec();

    combo2->setQuery(*qry2);

    ui->itemNameComboBox->setModel(combo2);
    ui->itemNameComboBox->setCurrentIndex(-1); //Set default value for member ID combo

    //Set default quantity
    ui->qtySpinBox->setValue(0);

    //Set sales price quantity
    ui->salesPriceLineEdit->setText("");


}

void aSales::on_addSalesButton_clicked()
{

    QString temp5 = ui->salesPriceLineEdit->text();
    double temp6 = QVariant(temp5).toDouble();

    if (ui->memberIDComboBox->currentText() == "" || ui->itemNameComboBox->currentText() == "" || ui->qtySpinBox->value()== 0 || ui->salesPriceLineEdit->text() == "")
    {
        QMessageBox::information(this, "Empty Fields","Please enter all fields!",QMessageBox::Ok);
    }

    else if(temp6 <= 0)
    {
        QMessageBox::information(this, "Invalid entry","Sales Price must be a valid number greater than 0",QMessageBox::Ok);
    }

    else
    {
        QString memberType; //used to store executive or regular status

        monthVar = ui->dateEdit->date().month();
        dayVar = ui->dateEdit->date().day();
        yearVar = ui->dateEdit->date().year();

        dateVar = ui->dateEdit->date().toString("MM/dd/yyyy");

       qDebug() << monthVar << " " << dayVar << " " << yearVar;
       qDebug() << ui->dateEdit->date();
       qDebug()  << dateVar;

       QString temp = ui->memberIDComboBox->currentText();
       membershipNumVar = QVariant(temp).toInt();
       qDebug() << "testing temp: " << temp;


       itemPurchasedVar = ui->itemNameComboBox->currentText();
       qDebug() << "itemPurchasedVar: " << itemPurchasedVar;

       QString temp3 = ui->qtySpinBox->text();
       qtyVar = QVariant(temp3).toInt();
       qDebug() << "qty: " << qtyVar;

       QString temp2 = ui->salesPriceLineEdit->text();
       salesPriceVar = (QVariant(temp2).toDouble());
       qDebug() << "salesPriceVar: " << salesPriceVar;

       //Updating membership database total amount spent and rebate

       salesTotalVar = (salesPriceVar * qtyVar); // salesPrice * qty
       qDebug() << "salesTotalVar" << salesTotalVar;

       totalAmtSpentVar = (salesTotalVar*TAX_RATE_VAR)+salesTotalVar;
       qDebug() << "total amount spent var" << totalAmtSpentVar;


       //Clear fields after add sale
       defaultAddSale();

       //QSqlQuery * qry3 = new QSqlQuery(myDB);
       //QSqlQueryModel * model3 = new QSqlQueryModel();
       QSqlQuery qry3;


           qry3.prepare("SELECT * "
                         "FROM MembershipDB "
                         "WHERE membershipNumber = '"+temp+"' " );


           if(qry3.exec())

           {
                  while(qry3.next())
                  {

                      memberType = qry3.value(2).toString();
                      qDebug() << "memberType: " << memberType;

                  }
           }

           else
              {
                  qDebug() << ("query did not execute");
              }



           if (memberType == "Executive")
           {

                rebateVar = (qry3.value(8).toDouble()+(salesTotalVar*REBATE_RATE_VAR));
                qDebug() << "RebateVar: " << rebateVar;

           }


           // Create queryIndex object for query on order id in the
                     // 'orders' database table to find the last entry index
                     // so we can determine the order id for the new order.
                     int index = 0;
                     QString IDPreFix = "";
                     QSqlQuery queryIndex;

                     // Query the orderID from the 'orders' database table
                     queryIndex.exec("SELECT SaleID FROM SalesDB");

                     // Locate last index in orders database table
                     while (queryIndex.next())
                     {
                         index++;
                         qDebug() << "index: " << index;
                     }

                     qDebug() << "index TESTING: " << index;

           // Creating query to insert values into the database:

                       QSqlQuery * qry4 = new QSqlQuery(myDB);
                       //QSqlQuery query4;
                       qry4->prepare("INSERT INTO SalesDB(SaleID, month, "
                                     "day, year, date, "
                                     "membershipNum, itemPurchased, salePrice, "
                                     "quantity) "
                                     "VALUES (:saleIDVar, :monthVar, "
                                     ":dayVar,:yearVar,:dateVar, "
                                     ":membershipNumVar,:itemPurchasedVar,:salesPriceVar, "
                                     ":qtyVar)");

                       // Format the orderID with padded 0s as needed
                       if (index<=10)
                       {
                           IDPreFix = "00-000";
                       }
                       else if(index<=100)
                       {
                           IDPreFix = "00-00";
                       }
                       else if (index<=1000)
                       {
                           IDPreFix = "00-0";
                       }
                       else
                       {
                           IDPreFix = "00-";
                       }

                       // Store the new formatted orderID value as a string
                       saleIDVar = IDPreFix +  (QString::number(++index));

                       // Save input values from the form into the orders database
                       // Convert int and doubles into strings to be saved up to
                       // two decimal places
                       qry4->bindValue(0,saleIDVar);
                       qry4->bindValue(1,QString::number(monthVar));
                       qry4->bindValue(2,QString::number(dayVar));
                       qry4->bindValue(3,QString::number(yearVar));
                       qry4->bindValue(4,dateVar);
                       qry4->bindValue(5,QString::number(membershipNumVar));
                       qry4->bindValue(6,itemPurchasedVar);
                       qry4->bindValue(7,QString::number(salesPriceVar, 'f', 2));
                       qry4->bindValue(8,QString::number(qtyVar));

                       //query.bindValue(9,QString::number(robotBSubtotal, 'f', 2));


                       // qDebug to for programmer to verify values were saved
                       if(qry4->exec())
                       {
                           qDebug() << ("added");

                           // Open and display order confirmation message box
                           QMessageBox::information(this, "Success",
                               "Add completed", QMessageBox::Ok);
                       }
                       else
                       {
                           qDebug() << ("add failed");

                           QMessageBox::information(this, "Failed",
                               "Add Failed", QMessageBox::Ok);
                       }

                       // Shows value of variables that should be saved
                       qDebug() << "Variables that were saved: \n";
                       qDebug() << "Sale ID: "    << saleIDVar;
                       qDebug() << "month: " << monthVar;
                       qDebug() << "day: "    << dayVar;
                       qDebug() << "year: " << yearVar;
                       qDebug() << "date:  "    << dateVar;
                       qDebug() << "membership number: " << membershipNumVar;
                       qDebug() << "item purchased: "  << itemPurchasedVar;
                       qDebug() << "sales price: "  << salesPriceVar;
                       qDebug() << "quantity: " << qtyVar;


                       defaultAddSale(); // reset the views



     }




  }
