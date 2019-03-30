#ifndef LOGIN_H
#define LOGIN_H

///////////////////////// NEEDS DOCUMENTATION STILL

#include <QDialog>
#include <QStackedLayout>

#include "admin.h"
#include "manager.h"
#include "databasemanger.h"
//#include "bulkClubDB.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    void connectToDB();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

private slots:

    void on_loginManagerButton_clicked();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

    void on_loginAdminButton_clicked();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

    void on_exitProgramButton_clicked();
    //!< Brief Description
    /*!< POSTCONDITONS:  */

private:
    Ui::login *ui;

    manager *managerWindow; //
    admin   *adminWindow;   //

    databaseManger myDB;  //
};

#endif // LOGIN_H
