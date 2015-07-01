#include "adminwindow.h"


AdminWindow::AdminWindow(QWidget *parent, AdminController* adminController) : QWidget(parent){
    adminCtrl = adminController;
    mainLayout = new QGridLayout();
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setAlignment(Qt::AlignTop);

    //SEZIONE EDIT
    editBox = new QGroupBox("Edit Utenti");
    editLayout = new QGridLayout();

    newUserButton = new QPushButton("Nuovo utente",this);
    newUserButton->setGeometry(QRect(QPoint(100, 100),
                                     QSize(200, 50)));

    deleteUserButton = new QPushButton("Elimina utente",this);
    deleteUserButton->setGeometry(QRect(QPoint(100, 100),
                                        QSize(200, 50)));

    modifyUserButton = new QPushButton ("Modifica utente",this);
    modifyUserButton->setGeometry(QRect(QPoint(100, 100),
                                        QSize(200, 50)));

    editLayout->addWidget(newUserButton,0,0);
    editLayout->addWidget(deleteUserButton,1,0);
    editLayout->addWidget(modifyUserButton,2,0);
    editBox->setLayout(editLayout);

    //RICERCA
    ricerca = new SearchWindow(this,adminCtrl);


    mainLayout->addWidget(editBox,0,0);
    mainLayout->addWidget(ricerca,0,1);



    setLayout(mainLayout);

    connect(newUserButton, SIGNAL(clicked()), this, SLOT(dialogAddNewUser()));
    connect(deleteUserButton, SIGNAL(clicked()), this, SLOT(dialogEraseUser()));
    connect(modifyUserButton, SIGNAL(clicked()), this, SLOT(dialogModifyUser()));

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

//DIALOG CANCELLA
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

//DIALOG MODIFICA
void AdminWindow::dialogModifyUser(){
    boxModifyUser = new QDialog();
    modifyLayout = new QGridLayout(boxModifyUser);
    modifyUsernameLabel = new QLabel("Username:");
    modifyUsername = new QLineEdit();

    confirmUserButton = new QPushButton("Modifica");

    boxType = new QGroupBox("Tipologia account");
    typeLayout = new QGridLayout();
    modifyInfo = new QLabel("Tipo:");
    basic = new QRadioButton("Basic");
    business = new QRadioButton("Business");
    executive = new QRadioButton("Executive");
    confirmModifyUserButton = new QPushButton("Conferma");
    cancelModifyUserButton = new QPushButton("Annulla");


    typeLayout->addWidget(modifyInfo,0,0);
    typeLayout->addWidget(basic,0,1);
    typeLayout->addWidget(business,1,0);
    typeLayout->addWidget(executive,1,1);
    typeLayout->addWidget(confirmModifyUserButton,2,0);
    typeLayout->addWidget(cancelModifyUserButton,2,1);
    boxType->setLayout(typeLayout);
    boxType->hide();


    modifyLayout->addWidget(modifyUsernameLabel,0,0);
    modifyLayout->addWidget(modifyUsername,0,1);
    modifyLayout->addWidget(confirmUserButton,1,1);
    modifyLayout->addWidget(boxType,2,1);
    boxModifyUser->setLayout(modifyLayout);

    connect(confirmUserButton, SIGNAL(clicked()), this, SLOT(searchModifyUser()));
    connect(confirmModifyUserButton, SIGNAL(clicked()), this, SLOT(updateAccountType()));
    connect(cancelModifyUserButton, SIGNAL(clicked()), boxModifyUser, SLOT(close()));
    boxModifyUser->exec();
}

void AdminWindow::searchModifyUser(){
//    if(adminCtrl->findUserForUsername(modifyUsername->text()))
//    {
//        boxType->show();
//        confirmUserButton->hide();
//        modifyUsername->setReadOnly(true);
//        QString tipo = adminCtrl->searchUserType(modifyUsername->text());
//        if(tipo == "Basic")
//            basic->setChecked(true);
//        if(tipo == "Business")
//            business->setChecked(true);
//        if(tipo == "Executive")
//            executive->setChecked(true);
//    }
//    else
//        QToolTip::showText(modifyUsername->mapToGlobal(QPoint()), "L'username scelto non esiste");
}

void AdminWindow::updateAccountType(){
    if(basic->isChecked())
        adminCtrl->modifyUserType(modifyUsername->text(),"Basic");
    if(business->isChecked())
        adminCtrl->modifyUserType(modifyUsername->text(),"Business");
    if(executive->isChecked())
        adminCtrl->modifyUserType(modifyUsername->text(),"Executive");
    QString nomeConferma = "La tipologia dell' account con username " + modifyUsername->text() + " è stata aggiornata";
    QMessageBox::information(this,"Conferma", nomeConferma);
    boxModifyUser->close();
}

void AdminWindow::addNewUser(){
    if(!adminCtrl->searchUser(usernameNewUser->text()))
    {
        adminCtrl->addUser(usernameNewUser->text(),nameNewUser->text(),surnameNewUser->text());
        QString nomeConferma = "L'utente " + usernameNewUser->text() + " è stato aggiunto";
        QMessageBox::information(this,"Conferma", nomeConferma);
        boxNewUser->close();
    }
    else
         QToolTip::showText(usernameNewUser->mapToGlobal(QPoint()), "L'username scelto già utilizzato");
}

void AdminWindow::deleteUser(){
    if(adminCtrl->searchUser(eraseUser->text()))
    {
        Username temp(eraseUser->text());
        adminCtrl->removeUser(temp);
        boxEraseUser->close();
        QString nomeRimosso = "L'utente " + eraseUser->text() + " è stato rimosso";
        QMessageBox::information(this,"Rimozione", nomeRimosso);
    }
    else
        QToolTip::showText(eraseUser->mapToGlobal(QPoint()), "L'utente scelto non esiste");
}



AdminWindow::~AdminWindow(){
}
