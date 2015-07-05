#include "mainwindow.h"

QString MainWindow::adminUser = "admin";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Linqedin");
    setGeometry(0,0,800,600);
    adminCtrl = 0;
    userCtrl = 0;

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);

    layout = new QGridLayout(mainWidget);
    layout->setAlignment(Qt::AlignCenter);
    //USER LOGIN
    userLoginBox = new QGroupBox("User");
    userLoginLayout = new QGridLayout();
    userUsername = new QLineEdit(this);
    userSubmit = new QPushButton("login",this);

    userLoginLayout->addWidget(userUsername,0,0);
    userLoginLayout->addWidget(userSubmit,1,0);
    userLoginBox->setLayout(userLoginLayout);
    //ADMIN LOGIN
    adminLoginBox = new QGroupBox("Admin");
    adminLoginLayout = new QGridLayout();
    adminUsername = new QLineEdit(this);
    adminSubmit = new QPushButton("login",this);

    adminLoginLayout->addWidget(adminUsername,0,0);
    adminLoginLayout->addWidget(adminSubmit,1,0);
    adminLoginBox->setLayout(adminLoginLayout);

    layout->addWidget(userLoginBox,0,0);
    layout->addWidget(adminLoginBox,0,1);
    mainWidget->setLayout(layout);

    connect(userSubmit, SIGNAL(clicked()),this, SLOT(readCredentialUser()));
    connect(this, SIGNAL(signalPasswordUser(QString)), this, SLOT(loginUser(const QString&)));

    connect(adminSubmit, SIGNAL(clicked()),this, SLOT(readCredentialAdmin()));
    connect(this, SIGNAL(signalPasswordAdmin(QString)), this, SLOT(loginAdmin(const QString&)));
}

MainWindow::~MainWindow(){
    delete mainWidget;
    if(userCtrl!=0)
        delete userCtrl;
    if(adminCtrl!=0)
        delete adminCtrl;
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
    if(userCtrl->searchUser(u))
    {
        mainWidget = new UserWindow(this,userCtrl);
        setCentralWidget(mainWidget);
        statusBar->showMessage("Autenticato",1000);
    }
    else
    {
        delete userCtrl;
        statusBar->showMessage("Errore!",1000);
    }
}

void MainWindow::loginAdmin(const QString& u){
    if(u==adminUser)
    {
        adminCtrl = new AdminController();
        mainWidget = new AdminWindow(this,adminCtrl);
        setCentralWidget(mainWidget);
        statusBar->showMessage("Autenticato! Bentornato Admin",1000);
    }
    else
        statusBar->showMessage("Errore!",1000);
}
