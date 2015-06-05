#include "mainwindow.h"

QString MainWindow::adminUser = "admin";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Linqedin");
    setGeometry(0,0,400,300);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);

    layout = new QGridLayout(mainWidget);
    layout->setAlignment(Qt::AlignHCenter);
    //USER LOGIN
    userUsername = new QLineEdit(this);
    userUsername->setGeometry(QRect(QPoint(200, 200),
                                 QSize(200, 50)));

    userSubmit = new QPushButton("user",this);
    userSubmit->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));


    //ADMIN LOGIN
    adminUsername = new QLineEdit(this);
    adminUsername->setGeometry(QRect(QPoint(200, 200),
                                 QSize(200, 50)));

    adminSubmit = new QPushButton("admin",this);
    adminSubmit->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));


    layout->addWidget(userUsername,0,0);
    layout->addWidget(userSubmit,2,0);

    layout->addWidget(adminUsername,0,1);
    layout->addWidget(adminSubmit,2,1);
    setLayout(layout);

    connect(userSubmit, SIGNAL(clicked()),this, SLOT(readCredentialUser()));
    connect(this, SIGNAL(signalPasswordUser(QString)), this, SLOT(loginUser(const QString&)));

    connect(adminSubmit, SIGNAL(clicked()),this, SLOT(readCredentialAdmin()));
    connect(this, SIGNAL(signalPasswordAdmin(QString)), this, SLOT(loginAdmin(const QString&)));

}

MainWindow::~MainWindow(){
}


//slot

void MainWindow::readCredentialUser() {
    emit signalPasswordUser(userUsername->text());
}

void MainWindow::readCredentialAdmin() {
    emit signalPasswordAdmin(adminUsername->text());
}

void MainWindow::loginUser(const QString& u){
    userCtrl = new userController(u);
    if(userCtrl->user->getLogin().getUsername() != "")
    {
        mainWidget = new UserWindow(this);
        setCentralWidget(mainWidget);
        statusBar->showMessage("Autenticato",1000);
    }
    else
        statusBar->showMessage("Errore!",1000);
}

void MainWindow::loginAdmin(const QString& u){
    if(u==adminUser)
    {
        mainWidget = new AdminWindow(this);
        setCentralWidget(mainWidget);
        statusBar->showMessage("Autenticato! Bentornato Admin",1000);
    }
    else
        statusBar->showMessage("Errore!",1000);
}
