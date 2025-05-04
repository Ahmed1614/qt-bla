#include "QTimer"
#include "signup.h"
#include "userpage.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include "authentication.h"

using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_back_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}


void Dialog::on_sign_up_clicked()
{
    string username,password;
    username= ui->signup_name->text().toStdString();
    password= ui->signup_pass->text().toStdString();
    int error_code = sign_up(username,password,0);
    if (error_code == 0){
        ui->error->setText(QString::fromStdString("User Created"));
        QTimer::singleShot(1500, this, [this]() {
            this->hide();
            userpage *user = new userpage(this);
            user->show();
        });
    } else if (error_code == 1){
        ui->error->setText(QString::fromStdString("Username cannot contain commas. Please pick a different username."));
    } else if (error_code == 2){
        ui->error->setText(QString::fromStdString("Username already exists. Please choose another one."));
    } else if (error_code == 3){
        ui->error->setText(QString::fromStdString("Password can't contain commas, please pick a different password"));
    } else if (error_code == 4){
        ui->error->setText(QString::fromStdString("Password must be between 8 and 20"));
    } else if (error_code == 5){
        ui->error->setText(QString::fromStdString("Password can't contain the username."));
    } else if (error_code == 6){
        ui->error->setText(QString::fromStdString("Error: User limit reached."));
    }
}

