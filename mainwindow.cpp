#include "mainwindow.h"

QString MainWindow::adminPass = "admin";
QString MainWindow::adminUser = "admin";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Linqedin");
    setGeometry(0,0,400,300);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    layout = new QGridLayout(centralWidget);
    layout->setAlignment(Qt::AlignHCenter);
    //USER LOGIN
    userUsername = new QLineEdit(this);
    userUsername->setGeometry(QRect(QPoint(200, 200),
                                 QSize(200, 50)));
    userPassword= new QLineEdit (this);

    userSubmit = new QPushButton("user",this);
    userSubmit->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    //ADMIN LOGIN
    adminUsername = new QLineEdit(this);
    adminUsername->setGeometry(QRect(QPoint(200, 200),
                                 QSize(200, 50)));
    adminPassword= new QLineEdit (this);

    adminSubmit = new QPushButton("admin",this);
    adminSubmit->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));


    layout->addWidget(userUsername,0,0);
    layout->addWidget(userPassword,1,0);
    layout->addWidget(userSubmit,2,0);

    layout->addWidget(adminUsername,0,1);
    layout->addWidget(adminPassword,1,1);
    layout->addWidget(adminSubmit,2,1);
    setLayout(layout);

    connect(userSubmit, SIGNAL(clicked()),this, SLOT(readPassword()));
    connect(this, SIGNAL(signalPassword(QString)), this, SLOT(loginUser(const QString&)));

    connect(adminSubmit, SIGNAL(clicked()),this, SLOT(readCredentialAdmin()));
    connect(this, SIGNAL(signalPassword(QString,QString)), this, SLOT(loginAdmin(const QString&,const QString&)));

}

MainWindow::~MainWindow(){
}


//slot

void MainWindow::readCredentialAdmin() {
    emit signalPassword(adminUsername->text(),adminPassword->text());
}

void MainWindow::loginAdmin(const QString& u, const QString& p){
    if(u==adminUser && p==adminPass)
        statusBar->showMessage("Bella",1000);
    else
        statusBar->showMessage("eh no!",1000);
}
