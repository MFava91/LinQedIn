#include "adminwindow.h"


AdminWindow::AdminWindow(QWidget *parent, AdminController* adminController) : QWidget(parent){
    adminCtrl = adminController;
    p = new QPoint;
    p->setX(p->x() + 1);
    *p += QPoint(1, 0);
    p->rx()++;

    mainLayout = new QGridLayout();
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setAlignment(Qt::AlignTop);

    //SEZIONE EDIT
    editBox = new QGroupBox("Edit Utenti");
    editLayout = new QGridLayout();

    newUserButton = new QPushButton("Nuovo utente",this);
    deleteUserButton = new QPushButton("Elimina utente",this);
    modifyUserButton = new QPushButton ("Modifica utente",this);

    editLayout->addWidget(newUserButton,0,0);
    editLayout->addWidget(deleteUserButton,0,1);
    editLayout->addWidget(modifyUserButton,0,2);

    editBox->setLayout(editLayout);
    mainLayout->addWidget(editBox,0,0);
    setLayout(mainLayout);

    connect(newUserButton, SIGNAL(clicked()), this, SLOT(dialogAddNewUser()));
    connect(deleteUserButton, SIGNAL(clicked()), this, SLOT(dialogEraseUser()));

}

//DIALOG CREATE USER
void AdminWindow::dialogAddNewUser(){
    boxNewUser = new QDialog();
    newUserLayout = new QGridLayout(boxNewUser);
    usernameNewUserLabel = new QLabel("Username");
    nameNewUserLabel = new QLabel("Nome");
    surnameNewUserLabel = new QLabel("Congnome");

    usernameNewUser = new QLineEdit();
    nameNewUser = new QLineEdit();
    surnameNewUser = new QLineEdit();

    addNewUserButton = new QPushButton("Crea");
    cancelNewUserButton = new QPushButton("Annulla");

    newUserLayout->addWidget(usernameNewUserLabel,0,0);
    newUserLayout->addWidget(usernameNewUser,0,1);
    newUserLayout->addWidget(nameNewUserLabel,1,0);
    newUserLayout->addWidget(nameNewUser,1,1);
    newUserLayout->addWidget(surnameNewUserLabel,2,0);
    newUserLayout->addWidget(surnameNewUser,2,1);
    newUserLayout->addWidget(addNewUserButton,3,0);
    newUserLayout->addWidget(cancelNewUserButton,3,1);
    boxNewUser->setLayout(newUserLayout);

    connect(addNewUserButton, SIGNAL(clicked()), this, SLOT(addNewUser()));
    connect(cancelNewUserButton, SIGNAL(clicked()), boxNewUser, SLOT(close()));
    boxNewUser->exec();
}

void AdminWindow::dialogEraseUser(){
    boxEraseUser = new QDialog();
    eraseUserLayout = new QGridLayout(boxEraseUser);
    eraseUserLabel = new QLabel("Username");
    eraseUser = new QLineEdit();
    eraseUserButton = new QPushButton("Elimina");
    cancelEraseUserButton = new QPushButton("Annulla");

    eraseUserLayout->addWidget(eraseUserLabel,0,0);
    eraseUserLayout->addWidget(eraseUser,0,1);
    eraseUserLayout->addWidget(eraseUserButton,2,0);
    eraseUserLayout->addWidget(cancelEraseUserButton,2,1);
    boxEraseUser->setLayout(eraseUserLayout);

    connect(eraseUserButton, SIGNAL(clicked()), this, SLOT(deleteUser()));
    connect(cancelEraseUserButton, SIGNAL(clicked()), boxEraseUser , SLOT(close()));

    boxEraseUser->exec();
}

void AdminWindow::addNewUser(){
    //DA FARE
}

void AdminWindow::deleteUser(){
    bool trovato;
    trovato = adminCtrl->searchUser(eraseUser->text());
    if(trovato)
    {
        Username temp(eraseUser->text());
        adminCtrl->removeUser(temp);
        boxEraseUser->close();
    }
    else
        QToolTip::showText(eraseUser->mapToGlobal(QPoint()), "L'utente scelto non esiste");
}

AdminWindow::~AdminWindow(){
}
