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
    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(signup_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this,SLOT(exit_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this,SLOT(login_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::login_bn()
// {

// }
void MainWindow::signup_clicked()
{
    this->hide();
    Dialog *signup = new Dialog(this);
    signup->show();
}
void MainWindow::login_clicked()
{
    this->hide();
    login *logind = new login(this);
    logind->show();
}

void MainWindow::exit_clicked()
{
    this->close();
}
