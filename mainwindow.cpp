#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFont>
#include "signup.h"
#include "login.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Signup, SIGNAL(clicked()), this,SLOT(signup_clicked()));
    connect(ui->Exit, SIGNAL(clicked()), this,SLOT(exit_clicked()));
    connect(ui->Login, SIGNAL(clicked()), this,SLOT(login_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::login_bn()
// {

// }


void MainWindow::on_Login_clicked()
{
    this->hide();
    login *logind = new login(this);
    logind->show();
}


void MainWindow::on_Signup_clicked()
{
    this->hide();
    Dialog *signup = new Dialog(this);
    signup->show();
}


void MainWindow::on_Exit_clicked()
{
    this->close();
}

