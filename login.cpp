#include "QTimer"
#include "login.h"
#include "userpage.h"
#include "ui_login.h"
#include "adminpage.h"
#include "mainwindow.h"
#include "authentication.h"

using namespace std;

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}



void login::on_back_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}


void login::on_Login_clicked()
{
    string username = ui->loginname->text().toStdString();
    string password = ui->loginpass->text().toStdString();

    int error_code = log_in(username, password);

    if (error_code == 0){
        ui->logintext->setText("Logged in successfully!");
        QTimer::singleShot(1500, this, [this]() {
            this->hide();
            userpage *user = new userpage(this);
            user->show();
        });
    } else if (error_code == 1){
        ui->logintext->setText("Username not found.");
    } else if (error_code == 2){
        ui->logintext->setText("Incorrect password.");
    } else if (error_code == 3){
        ui->logintext->setText("Admin");
        QTimer::singleShot(1500, this, [this]() {
            this->hide();
            adminpage *admin = new adminpage(this);
            admin->show();
        });
    } else if (error_code == 4){
        ui->logintext->setText("No Data Entered.");
    }
}
