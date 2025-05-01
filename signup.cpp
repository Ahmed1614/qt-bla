#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"

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

void Dialog::on_pushButton_3_clicked()
{
    this->hide();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
}

