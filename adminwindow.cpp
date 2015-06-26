#include "adminwindow.h"


AdminWindow::AdminWindow(QWidget *parent, AdminController* adminController) : QWidget(parent){
    adminCtrl = adminController;
    utenteTrovato = 0;
    resultBox = 0;
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

    //SEZIONE FIND
    findBox = new QGroupBox("Ricerca");
    findLayout = new QGridLayout();

    //SEZIONE FIND PER USERNAME

    findForUsernameBox = new QGroupBox("Ricerca per username");
    findForUsernameLayout = new QGridLayout();

    findUsernameLabel = new QLabel("Username");
    findUsername = new QLineEdit();

    findUsernameButton = new QPushButton("Ricerca");

    findForUsernameLayout->addWidget(findUsernameLabel,0,0);
    findForUsernameLayout->addWidget(findUsername,0,1);
    findForUsernameLayout->addWidget(findUsernameButton,1,1);
    findForUsernameBox->setLayout(findForUsernameLayout);

    //SEZIONE FIND PER NOME E COGNOME
    findForNameBox = new QGroupBox("Ricerca per nome/cognome");
    findForNameLayout = new QGridLayout();

    findNameLabel = new QLabel("Nome");
    findName = new QLineEdit();
    findSurnameLabel = new QLabel("Cognome");
    findSurname = new QLineEdit();

    findNameButton = new QPushButton("Ricerca");

    findForNameLayout->addWidget(findNameLabel,0,0);
    findForNameLayout->addWidget(findName,0,1);
    findForNameLayout->addWidget(findSurnameLabel,1,0);
    findForNameLayout->addWidget(findSurname,1,1);
    findForNameLayout->addWidget(findNameButton,2,1);
    findForNameBox->setLayout(findForNameLayout);

    //-----------------------------------------------------//
    findLayout->addWidget(findForUsernameBox,0,0);
    findLayout->addWidget(findForNameBox,1,0);
    findBox->setLayout(findLayout);

    //RESULT
    resultBox = new QGroupBox("Risultati ricerca");
    resultLayout = new QGridLayout();
    nessunaRicerca = new QLabel("Nessuna ricerca effettuata");
    resultLayout->addWidget(nessunaRicerca,0,0);
    resultBox->setLayout(resultLayout);

    mainLayout->addWidget(editBox,0,0);
    mainLayout->addWidget(findBox,0,1);
    mainLayout->addWidget(resultBox,1,1);
    setLayout(mainLayout);

    connect(newUserButton, SIGNAL(clicked()), this, SLOT(dialogAddNewUser()));
    connect(deleteUserButton, SIGNAL(clicked()), this, SLOT(dialogEraseUser()));
    connect(findUsernameButton, SIGNAL(clicked()), this, SLOT(searchUsername()));
    connect(findNameButton, SIGNAL(clicked()), this, SLOT(searchName()));
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

void AdminWindow::updateWindow(){
    mainLayout->addWidget(resultBox,1,1);
    setLayout(mainLayout);
}

void AdminWindow::addNewUser(){
    //DA FARE
    QString nomeConferma = "L'utente " + usernameNewUser->text() + " è stato aggiunto";
    QMessageBox::information(this,"Conferma", nomeConferma);
}

void AdminWindow::deleteUser(){
    bool trovato;
    trovato = adminCtrl->searchUser(eraseUser->text());
    if(trovato)
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

void AdminWindow::searchUsername(){
    if(resultBox!=0)
    {
        mainLayout->removeWidget(resultBox);
        delete resultBox;
        resultBox = new QGroupBox("Risultati ricerca");
        resultLayout = new QGridLayout();
        bool trovato = adminCtrl->findUserForUsername(findUsername->text());
        if(trovato)
        {
            ResultWindow* result = new ResultWindow(adminCtrl->user,this);
            resultLayout->addWidget(result,0,0);
        }
        else
        {
            nessunUtenteTrovato = new QLabel("Nessun utente trovato");
            resultLayout->addWidget(nessunUtenteTrovato,0,0);
        }
    }
    resultBox->setLayout(resultLayout);
    mainLayout->addWidget(resultBox,1,1);
    setLayout(mainLayout);
}

void AdminWindow::searchName(){
    if(resultBox!=0)
    {
        mainLayout->removeWidget(resultBox);
        delete resultBox;
        resultBox = new QGroupBox("Risultati ricerca");
        resultLayout = new QGridLayout();
        bool trovato = adminCtrl->findUserForName(findName->text(),findSurname->text());
        if(trovato)
        {
            int i=0;
            for(std::map<QString,Utente*>::const_iterator it=adminCtrl->utentiTrovati.begin();it!=adminCtrl->utentiTrovati.end();++it)
            {
                ResultWindow* result = new ResultWindow((*it).second,this);
                resultLayout->addWidget(result,i,0);
                i++;
            }
        }
        else
        {
            nessunUtenteTrovato = new QLabel("Nessun utente trovato");
            resultLayout->addWidget(nessunUtenteTrovato,0,0);
        }
    }
    resultBox->setLayout(resultLayout);
    mainLayout->addWidget(resultBox,1,1);
    setLayout(mainLayout);
}

AdminWindow::~AdminWindow(){
}
