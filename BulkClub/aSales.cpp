#include "aSales.h"
#include "ui_aSales.h"

aSales::aSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aSales)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    // Set default view
    defaultSalesTable();
    defaultAddSale();
}

aSales::~aSales()
{
    delete ui;
}

void aSales::defaultSalesTable()
{
    //Set Default Table
    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery("SELECT SaleID, date, membershipNum, itemPurchased, quantity, salePrice "
                    "FROM SalesDB "
                    "ORDER BY SaleID COLLATE NOCASE ASC ");

    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->aSalesTableView->setModel(model);

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
}

void aSales::defaultAddSale()
{
    // Set Default Date
    ui->dateEdit->setDate(QDate(2019,01,01));

    // POPULATE THE COMBO BOX for MEMBER ID
    QSqlQuery * qry = new QSqlQuery(myDB);
    QSqlQueryModel * combo = new QSqlQueryModel();

    qry->prepare("SELECT DISTINCT membershipNumber "
                 "FROM MembershipDB ORDER BY membershipNumber COLLATE NOCASE ASC");
    qry->exec();
    combo->setQuery(*qry);

    ui->memberIDComboBox->setModel(combo);     // Populate combo box
    ui->memberIDComboBox->setCurrentIndex(-1); // Show first entry blank

    // POPULATE THE COMBO BOX for itemName
    QSqlQuery * qry2 = new QSqlQuery(myDB);
    QSqlQueryModel * combo2 = new QSqlQueryModel();

    qry2->prepare("SELECT itemName "
                 "FROM InventoryDB ORDER BY itemName COLLATE NOCASE ASC");
    qry2->exec();
    combo2->setQuery(*qry2);

    ui->itemNameComboBox->setModel(combo2);    // Populate combo box
    ui->itemNameComboBox->setCurrentIndex(-1); // Show first entry blank

    //Set default quantity
    ui->qtySpinBox->setValue(0);

    //Set sales price quantity
    ui->salesPriceLineEdit->setText("");
}

void aSales::on_addSalesButton_clicked()
{
    QString salePriceAsTxt = ui->salesPriceLineEdit->text();
    double salePriceAsDouble = QVariant(salePriceAsTxt).toDouble();

    // Checks for empty fields
    if (ui->memberIDComboBox->currentText() == "" || ui->itemNameComboBox->currentText() == "" || ui->qtySpinBox->value()== 0 || ui->salesPriceLineEdit->text() == "")
    {
        QMessageBox::information(this, "Empty Fields","Please enter all fields!",QMessageBox::Ok);
    }
    // Checks if sale price is 0.00
    else if(salePriceAsDouble <= 0)
    {
        QMessageBox::information(this, "Invalid entry","Sales Price must be greater than 0.00",QMessageBox::Ok);
    }
    // Continues with adding sale if input fields are valid
    else
    {
        /********************************************************************
         * UPDATE SALES DB - all fields
         *******************************************************************/
        monthVar = ui->dateEdit->date().month();
        dayVar   = ui->dateEdit->date().day();
        yearVar  = ui->dateEdit->date().year();
        dateVar  = ui->dateEdit->date().toString("MM/dd/yyyy");

        qDebug() << monthVar << " " << dayVar << " " << yearVar << " is: "
                 << dateVar;

        // Get and convert membership number from field to int
        QString memNumAsTxt = ui->memberIDComboBox->currentText();
        membershipNumVar = QVariant(memNumAsTxt).toInt();
        qDebug() << "membershipNumVar: " << membershipNumVar;

        // Get item name
        itemPurchasedVar = ui->itemNameComboBox->currentText();
        qDebug() << "itemPurchasedVar: " << itemPurchasedVar;

        // Get and convert item quantity from spinbox to int
        QString qtyAsTxt = ui->qtySpinBox->text();
        qtyVar = QVariant(qtyAsTxt).toInt();
        qDebug() << "qtyVar: " << qtyVar;

        // Get and convert sale price from line edit to double
        QString salePriceAsTxt = ui->salesPriceLineEdit->text();
        salesPriceVar = (QVariant(salePriceAsTxt).toDouble());
        qDebug() << "salesPriceVar: " << salesPriceVar;

        int index = 0; // used to store last index in database
        QString IDPreFix = ""; // used to create unique sale id

        QSqlQuery queryIndex;
        queryIndex.exec("SELECT SaleID FROM SalesDB");

        // Locate last index in orders database table and increment
        while (queryIndex.next())
        {
            index++;
        }

        qDebug() << "New sale index: " << index;

        // ADD NEW SALE to sales database
        QSqlQuery * saleQry = new QSqlQuery(myDB);
        saleQry->prepare("INSERT INTO SalesDB(SaleID, month, "
                         "day, year, date, "
                         "membershipNum, itemPurchased, salePrice, "
                         "quantity) "
                         "VALUES (:saleIDVar, :monthVar, "
                         ":dayVar, :yearVar, :dateVar, "
                         ":membershipNumVar, :itemPurchasedVar, "
                         ":salesPriceVar, :qtyVar)");

        // Format the sale id with padded 0s as needed
        if(index<=10)
        {
            IDPreFix = "00-00";
        }
        else if(index<=100)
        {
            IDPreFix = "00-0";
        }
        else
        {
            IDPreFix = "00-";
        }

        // Get sale id string
        saleIDVar = IDPreFix + (QString::number(index));

        // STORE variables into SalesDB
        saleQry->bindValue(0,saleIDVar);
        saleQry->bindValue(1,QString::number(monthVar));
        saleQry->bindValue(2,QString::number(dayVar));
        saleQry->bindValue(3,QString::number(yearVar));
        saleQry->bindValue(4,dateVar);
        saleQry->bindValue(5,QString::number(membershipNumVar));
        saleQry->bindValue(6,itemPurchasedVar);
        saleQry->bindValue(7,QString::number(salesPriceVar, 'f', 2));
        saleQry->bindValue(8,QString::number(qtyVar));

// IS THIS STILL NEEDED?
        //query.bindValue(9,QString::number(robotBSubtotal, 'f', 2));

        // Verify if storing to database is successful
        if(saleQry->exec())
        {
            // Display sales update confirmation
            QMessageBox::information(this, "Sales Database",
                                     "Sales was added.", QMessageBox::Ok);

            // Shows value of variables that should be saved
            qDebug() << "Variables that were successfully saved: \n";
            qDebug() << "Sale ID: "    << saleIDVar;
            qDebug() << "month: " << monthVar;
            qDebug() << "day: "    << dayVar;
            qDebug() << "year: " << yearVar;
            qDebug() << "date:  "    << dateVar;
            qDebug() << "membership number: " << membershipNumVar;
            qDebug() << "item purchased: "  << itemPurchasedVar;
            qDebug() << "sales price: "  << salesPriceVar;
            qDebug() << "quantity: " << qtyVar;
        }
        else
        {
            qDebug() << ("Sales Database Error: Unable to add sales.");
            QMessageBox::information(this, "Sales Database Error",
                                     "Unable to add sales.",
                                     QMessageBox::Ok);
        }

        /********************************************************************
         * UPDATE MEMBERSHIP DB - total spent and rebate
         *******************************************************************/
        QString memberType; //used to store executive or regular status

        // CALCULATE and UPDATE sales total in membership datebase
        // Item sale price * qty (for the new sale)
        salesTotalVar = (salesPriceVar * qtyVar);
        qDebug() << "salesTotalVar" << salesTotalVar;

        totalAmtSpentVar = (salesTotalVar*TAX_RATE_VAR)+salesTotalVar;
        qDebug() << "total amount spent var" << totalAmtSpentVar;

// STILL NEED THIS?
        //QSqlQuery * qry3 = new QSqlQuery(myDB);
        //QSqlQueryModel * model3 = new QSqlQueryModel();

        // Locate member in membership database
        QSqlQuery qry;
        qry.prepare("SELECT * "
                    "FROM MembershipDB "
                    "WHERE membershipNumber = '"+memNumAsTxt+"'");

        if(qry.exec())
        {
            while(qry.next())
            {
                // Get memberhsip type
                memberType = qry.value(2).toString();
                qDebug() << "memberType: " << memberType;
            }
        }
        else
        {
            qDebug() << ("Membership id search failed.");
        }

        // CALCULATE rebate if member is of Executive membership type
        if (memberType == "Executive")
        {
            // rebate = current rebate value + (sale total * rebate rate)
            rebateVar = (qry.value(8).toDouble()+(salesTotalVar*REBATE_RATE_VAR));
            qDebug() << "RebateVar: " << rebateVar;
        }

        // Convert variables to be stored into database
        QString totalAmountAsString;
        QString rebateAsString;
        totalAmountAsString = (QVariant(totalAmtSpentVar).toString());
        rebateAsString = (QVariant(rebateVar).toString());


        // UPDATE membership database total amount spent and rebate fields
        QSqlQuery memberQry;
        memberQry.prepare("UPDATE MembershipDB "
                          "SET totalAmountSpent = '"+totalAmountAsString+"', "
                          "rebateAmount = '"+rebateAsString+"' "
                          "WHERE membershipNumber = '"+memNumAsTxt+"'");

        // STORE totalAmountSpent and rebateAmount into MembershipDB
        if(memberQry.exec())
            qDebug()<<("Item name edit successful.");
        else
            qDebug()<<("Item name edit failed.");

        /********************************************************************
         * UPDATE INVENTORY DB - ?????
         *******************************************************************/

// ADD STUFF HERE

// WHERE DOES THE RESET GO?
        // Update sales table and reset add sale fields
        defaultSalesTable();
        defaultAddSale();
    }


}
