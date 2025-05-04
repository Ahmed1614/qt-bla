#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFont>
#include "signup.h"
#include "login.h"
#include "settings.h"
#include "teams.h"
#include "player.h"
#include "userpage.h"
#include "adminpage.h"
#include "matches.h"
#include "teamstats.h"
#include "authentication.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
    load_user_db();
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(signup_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this,SLOT(exit_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this,SLOT(login_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

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
    save();
    this->close();
}



void MainWindow::on_pushButton_4_clicked()
{
    this->hide();
    settings *setting = new settings(this);
    setting->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    this->hide();
    teams *team = new teams(this);
    team->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    this->hide();
    player *players = new player(this);
    players->show();
}


void MainWindow::on_userbutton_clicked()
{
    this->hide();
    userpage *user = new userpage(this);
    user->show();
}


void MainWindow::on_userbutton_2_clicked()
{
    this->hide();
    adminpage *admin = new adminpage(this);
    admin->show();
}


void MainWindow::on_pushButton_7_clicked()
{
    this->hide();
    matches *match = new matches(this);
    match->show();
}


void MainWindow::on_pushButton_8_clicked()
{
    this->hide();
    TeamStats *league = new TeamStats(this);
    league->show();
}

