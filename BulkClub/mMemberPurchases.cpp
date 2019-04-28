#include "mMemberPurchases.h"
#include "ui_mMemberPurchases.h"

/****************************************************************************
 * CONSTRUCTOR
 * --------------------------------------------------------------------------
 * Displays Manager Member Purchase Table and populates the line edit fields for
 * membership number, saleID, date, item purchased, quantity ordered by
 * Membership number.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      Database class created to connect to data base.
 *
 * POST-CONDITIONS
 *      ==> Populates line edit fields
 ***************************************************************************/
mMemberPurchases::mMemberPurchases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mMemberPurchases)
{
    //DISPLAY THE TABLE

    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    QSqlQueryModel *model = new QSqlQueryModel;


    model->setQuery("SELECT MembershipDB.customerName, SalesDB.membershipNum, SalesDB.SaleID, SalesDB.date, SalesDB.itemPurchased, "
                    "SalesDB.quantity "
                    "FROM MembershipDB "
                    "INNER JOIN SalesDB ON SalesDB.membershipNum = MembershipDB.membershipNumber ");


    if(model->lastError().isValid())
        qDebug() << model->lastError();

    ui->membershipPurchaseTableView->setModel(model);

    qDebug() << "MODEL ROW COUNT" << (model->rowCount());

    // Set Table Column Width
    ui->membershipPurchaseTableView->setColumnWidth(0,170);
    ui->membershipPurchaseTableView->setColumnWidth(1,70);
    ui->membershipPurchaseTableView->setColumnWidth(2,80);
    ui->membershipPurchaseTableView->setColumnWidth(3,100);
    ui->membershipPurchaseTableView->setColumnWidth(4,180);
    ui->membershipPurchaseTableView->setColumnWidth(5,50);

    // Set Table Column Header Text
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID#"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Order ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Item Purchased"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Qty"));


    defaultReset();


   }

/****************************************************************************
 * DESTRUCTOR
 * --------------------------------------------------------------------------
 * DELETES ui
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      ui exists
 *
 * POST-CONDITIONS
 *      ==> Deletes ui
 ***************************************************************************/
mMemberPurchases::~mMemberPurchases()
{
    delete ui;
}


void mMemberPurchases::defaultReset()
{

    flag = false; // when it first executes flag should be false so other index changing functions do not get called.

    //POPULATE THE COMBO BOXES

    //populate member ID Combo boxes
    QSqlQuery * qry = new QSqlQuery(myDB);
    QSqlQueryModel * combo = new QSqlQueryModel();


    qry->prepare("SELECT DISTINCT membershipNum "
                 "FROM salesDB "
                 "ORDER BY membershipNum COLLATE NOCASE ASC" );
    qry->exec();

    combo->setQuery(*qry);

    ui->memberIDcomboBox->setModel(combo);
    ui->memberIDcomboBox->setCurrentIndex(-1); // Show first entry blank

    //Populate order id combo boxes
    //QSqlQuery * qry2 = new QSqlQuery(myDB);
    QSqlQueryModel * combo2 = new QSqlQueryModel();
    QString membID = ui->memberIDcomboBox->currentText();
    qDebug() << "membID: " << membID;
    qry->prepare("SELECT saleID "
                  "FROM SalesDB "
                  "WHERE membershipNum = '"+membID+"' "
                  "ORDER BY saleID COLLATE NOCASE ASC" );
    qry->exec();

    combo2->setQuery(*qry);

    ui->orderIDcomboBox->setModel(combo2);
    ui->orderIDcomboBox->setCurrentIndex(-1); // Show first entry blank

    //populate member name combo boxes

    QSqlQuery * qry3 = new QSqlQuery(myDB);
    QSqlQueryModel * combo3 = new QSqlQueryModel();
    qry3->prepare("SELECT DISTINCT customerName "
                  "FROM MembershipDB "
                  "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                  "ORDER BY MembershipDB.customerName ASC ");

    qry3->exec();

    combo3->setQuery(*qry3);

    ui->memberNameComboBox->setModel(combo3);
    ui->memberNameComboBox->setCurrentIndex(-1); // Show first entry blank

    ui->quantityLineEdit->setText("");
    ui->salePriceLineEdit->setText("");
    ui->grandTotalLineEdit->setText("");
    ui->itemPurchasedLineEdit->setText("");
    ui->dateLineEdit->setText("");

    flag = true; // only true once constructor or reset has finished.

}


/****************************************************************************
 * on_memberIDcomboBox_currentIndexChanged()
 * --------------------------------------------------------------------------
 * Changes line edit fields (salesID, item purchased, salePrice, quantity
 * based on memberID selected)
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      line edit fields created, salesID combo created.
 *
 * POST-CONDITIONS
 *      ==> populates line edit fields (salesID, item purchased, salePrice, quantity
 * based on memberID selected)
 ***************************************************************************/
void mMemberPurchases::on_memberIDcomboBox_currentIndexChanged()
{
    flagID = true; //change flag while function works.

    if (flag == true) //only executes if constructor completed once
    {
        if(flagName == false) //will execute only if flagName is false, it's only true when membername fn runs.
        {

            QString id = ui->memberIDcomboBox->currentText();

            qDebug() << id;

            QSqlQuery qry,qry2;

            qry.prepare("SELECT date,itemPurchased, salePrice, quantity "
                        " FROM salesDB WHERE membershipNum='"+ id + "' ");

            if(qry.exec())
            {
                while(qry.next())
                {
                    //double salesTax, totalPrice;
                    double sale;

                    /************************************************************
                     * PROCESSING - Update all line edits boxes with data from
                     *              the sales database for selected memberID
                     ************************************************************/

                    sale = qry.value(2).toDouble();

                    ui->dateLineEdit->setText(qry.value(0).toString());
                    ui->itemPurchasedLineEdit->setText(qry.value(1).toString());
                    ui->salePriceLineEdit->setText(QString::number(sale,'f',2));
                    ui->quantityLineEdit->setText(qry.value(3).toString());
                }
            }
            else
            {
                qDebug() << ("qry not work");
            }

            qry2.prepare("SELECT totalAmountSpent "
                         " FROM MembershipDB WHERE membershipNumber= '"+ id + "'");

            if(qry2.exec())
            {
                while(qry2.next())
                {

                    double total;

                    /************************************************************
                     * PROCESSING - Update grand total line edit with data from
                     *              the membership database for selected memberID
                     ************************************************************/

                    total = qry2.value(0).toDouble();


                    ui->grandTotalLineEdit->setText(QString::number(total,'f',2));

                }
            }
            else
            {
                qDebug() << ("qry2 did not work");
            }

            //changing order ID to match member ID
            QSqlQuery * qry3 = new QSqlQuery(myDB);
            QSqlQueryModel * combo2 = new QSqlQueryModel();


            QString membID = ui->memberIDcomboBox->currentText();
            qDebug() << "membID: " << membID;
            qry3->prepare("SELECT saleID "
                          "FROM SalesDB "
                          "WHERE membershipNum = '"+membID+"' "
                          "ORDER BY saleID COLLATE NOCASE DESC" );

            qry3->exec();

            combo2->setQuery(*qry3);

            //changing member name to match memberID

            ui->orderIDcomboBox->setModel(combo2);

            //extra crap added today 4/26/19

            QSqlQuery * qry4 = new QSqlQuery(myDB);
            QSqlQueryModel * combo4 = new QSqlQueryModel();


            qry4->prepare("SELECT DISTINCT customerName "
                          "FROM MembershipDB "
                          "INNER JOIN SalesDB ON SalesDB.membershipNum= MembershipDB.membershipNumber "
                          "WHERE SalesDB.membershipNum = '"+membID+"' ");

            qry4->exec();

            combo4->setQuery(*qry4);

             ui->memberNameComboBox->setModel(combo4);
        }



    }

    flagID = false; //change flag  back to false to exit.

}

/****************************************************************************
 * on_orderIDcomboBox_currentIndexChanged()
 * --------------------------------------------------------------------------
 * Changes line edit fields (salesID, item purchased, salePrice, quantity
 * based on orderID selected)
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      line edit fields created, memberID & salesID combo boxes created.
 *
 * POST-CONDITIONS
 *      ==> populates line edit fields (item purchased, salePrice, quantity
 * based on orderID selected)
 ***************************************************************************/

void mMemberPurchases::on_orderIDcomboBox_currentIndexChanged()
{

    qDebug() << "orderIDcombo index changed";
    QString salesID = ui->orderIDcomboBox->currentText();

    qDebug() << salesID;

    QSqlQuery qry,qry2;

    qry.prepare("SELECT date,itemPurchased, salePrice, quantity, membershipNum "
                " FROM SalesDB WHERE saleID='"+ salesID + "'");

    if(qry.exec())
    {
        while(qry.next())
        {
            //double salesTax, totalPrice;
            double sale;

            /************************************************************
             * PROCESSING - Update all line edits boxes with data from
             *              the sales database for selected memberID
             ************************************************************/

            sale = qry.value(2).toDouble();

            ui->dateLineEdit->setText(qry.value(0).toString());
            ui->itemPurchasedLineEdit->setText(qry.value(1).toString());
            ui->salePriceLineEdit->setText(QString::number(sale,'f',2));
            ui->quantityLineEdit->setText(qry.value(3).toString());


        }

    }
    else
    {
        qDebug() << ("qry not work");
    }

    QString id2 = ui->memberIDcomboBox->currentText();

    qry2.prepare("SELECT totalAmountSpent "
                 " FROM MembershipDB WHERE membershipNumber= '"+ id2 + "'");

    if(qry2.exec())
    {
        while(qry2.next())
        {

            double total;

            /************************************************************
             * PROCESSING - Update grand total line edit with data from
             *              the membership database for selected memberID
             ************************************************************/

            total = qry2.value(0).toDouble();
            ui->grandTotalLineEdit->setText(QString::number(total,'f',2));

        }
    }

    else
    {
        qDebug() << ("qry2 did not work");
    }
}


void mMemberPurchases::on_memberNameComboBox_currentIndexChanged()
{

    flagName = true; //flip flagName to true once entering name function so it won't trigger the member id index change function.

    if (flag == true)
    {
        if(flagID == false)
        {

            qDebug() << ("memberName index change");
               QSqlQuery * qry5 = new QSqlQuery(myDB);
               QSqlQueryModel * combo5 = new QSqlQueryModel();

               QString name = ui->memberNameComboBox->currentText();

               qDebug() << "THE NAME: " <<  name;


               qry5->prepare("SELECT DISTINCT membershipNumber "
                             "FROM MembershipDB "
                             "WHERE customerName = '"+ name + "'");

               qry5->exec();

               combo5->setQuery(*qry5);

                ui->memberIDcomboBox->setModel(combo5);


                //untested stuff as of 5:42 pm

                QString id = ui->memberIDcomboBox->currentText();

                qDebug() << id;

                QSqlQuery qry,qry2;

                qry.prepare("SELECT date,itemPurchased, salePrice, quantity "
                            " FROM salesDB WHERE membershipNum='"+ id + "' ");

                if(qry.exec())
                {
                    while(qry.next())
                    {
                        //double salesTax, totalPrice;
                        double sale;

                        /************************************************************
                         * PROCESSING - Update all line edits boxes with data from
                         *              the sales database for selected memberID
                         ************************************************************/

                        sale = qry.value(2).toDouble();

                        ui->dateLineEdit->setText(qry.value(0).toString());
                        ui->itemPurchasedLineEdit->setText(qry.value(1).toString());
                        ui->salePriceLineEdit->setText(QString::number(sale,'f',2));
                        ui->quantityLineEdit->setText(qry.value(3).toString());
                    }
                }
                else
                {
                    qDebug() << ("qry not work");
                }

                qry2.prepare("SELECT totalAmountSpent "
                             " FROM MembershipDB WHERE membershipNumber= '"+ id + "'");

                if(qry2.exec())
                {
                    while(qry2.next())
                    {

                        double total;

                        /************************************************************
                         * PROCESSING - Update grand total line edit with data from
                         *              the membership database for selected memberID
                         ************************************************************/

                        total = qry2.value(0).toDouble();


                        ui->grandTotalLineEdit->setText(QString::number(total,'f',2));

                    }
                }
                else
                {
                    qDebug() << ("qry2 did not work");
                }

                //changing order ID to match member ID
                QSqlQuery * qry3 = new QSqlQuery(myDB);
                QSqlQueryModel * combo2 = new QSqlQueryModel();


                qry3->prepare("SELECT saleID "
                              "FROM SalesDB "
                              "WHERE membershipNum = '"+id+"' "
                              "ORDER BY saleID COLLATE NOCASE DESC" );

                qry3->exec();

                combo2->setQuery(*qry3);

                ui->orderIDcomboBox->setModel(combo2);
        }

    }

    flagName = false; //assign flagName back to false so id index change can still change the index of customerName.

}

void mMemberPurchases::on_resetButton_clicked()
{
    defaultReset();
}
