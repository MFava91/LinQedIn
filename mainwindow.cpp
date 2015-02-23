#include "mainwindow.h"
#include <QStackedWidget>
#include<QWidget>
#include<QLineEdit>
#include<QRadioButton>
#include<QPushButton>
#include<QVBoxLayout>
#include<QApplication>
#include<iostream>

MainWindow::MainWindow(QWidget *parent){
    QLineEdit* username=new QLineEdit();
    QRadioButton *userButton = new QRadioButton("Utente");
    QRadioButton *adminButton = new QRadioButton("Admin");
    QPushButton* loginButton = new QPushButton(tr("Login"));
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(username);
    layout->addWidget(userButton);
    layout->addWidget(adminButton);
    layout->addWidget(loginButton);
    setLayout(layout);
    //login* loginpage = new login();
    connect(loginButton, SIGNAL(clicked()),this, SLOT(change_stack()));
}

void MainWindow::change_stack(){
    this->hide();
    AdminWindow *a=new AdminWindow();
    a->show();

}

/*ui(new Ui::MainWindow)
{
    ui->setupUi(this);}

MainWindow::~MainWindow()
{
    delete ui;
}
*/

/*
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    setObjectName("Main Window");
    setWindowTitle("LinQdl");
};
*/
