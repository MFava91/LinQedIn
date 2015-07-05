#include "userinfowindow.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"

UserInfoWindow::UserInfoWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    clientCtrl = userCtrl;
    datiBox = 0;
    profiloLayout = new QGridLayout();

    accountBox = new QGroupBox("Informazioni account");
    accountLayout = new QGridLayout();

    usernameLabel = new QLabel("Username:");
    username = new QLineEdit(clientCtrl->user->getLogin().getUsername());
    username->setReadOnly(true);

    tipoLabel = new QLabel("Tipo account:");
    if(typeid(*clientCtrl->user) == typeid(UtenteBasic))
        tipo = new QLineEdit("Basic");
    if(typeid(*clientCtrl->user) == typeid(UtenteBusiness))
        tipo = new QLineEdit("Business");
    if(typeid(*clientCtrl->user) == typeid(UtenteExecutive))
        tipo = new QLineEdit("Executive");

    tipo->setReadOnly(true);

    accountLayout->addWidget(usernameLabel,0,0);
    accountLayout->addWidget(username,0,1);
    accountLayout->addWidget(tipoLabel,0,2);
    accountLayout->addWidget(tipo,0,3);
    accountBox->setLayout(accountLayout);


    fetchDati();

    profiloLayout->addWidget(accountBox,0,0);
    setLayout(profiloLayout);

    connect(this, SIGNAL(signalSave()), parent, SLOT(saveDb()));
}

void UserInfoWindow::fetchDati(){
    //FETCH DATI PERSONALI
    if(datiBox!=0)
    {
        profiloLayout->removeWidget(datiBox);
        delete datiBox;
    }
    datiBox = new QGroupBox("Profilo");
    datiLayout = new QGridLayout();
    nomeLabel = new QLabel("Nome:");
    nome = new QLineEdit(clientCtrl->user->getInfo().getDati().getNome());
    nome->setReadOnly(true);

    cognomeLabel = new QLabel("Cognome:");
    cognome = new QLineEdit(clientCtrl->user->getInfo().getDati().getCognome());
    cognome->setReadOnly(true);

    emailLabel = new QLabel("Email:");
    email = new QLineEdit(clientCtrl->user->getInfo().getDati().getEmail());
    email->setReadOnly(true);

    dataLabel = new QLabel("Data di Nascita:");
    dataNascita = new QDateTimeEdit(clientCtrl->user->getInfo().getDati().getDataNascita());
    dataNascita->setReadOnly(true);
    dataNascita->setDisplayFormat("dd.MM.yyyy");

    luogoLabel = new QLabel("Luogo di Nascita:");
    luogoNascita = new QLineEdit(clientCtrl->user->getInfo().getDati().getLuogoNascita());
    luogoNascita->setReadOnly(true);

    residenzaLabel = new QLabel("Residenza:");
    residenza = new QLineEdit(clientCtrl->user->getInfo().getDati().getResidenza());
    residenza->setReadOnly(true);

    buttonLayout = new QGridLayout();
    modifyButton = new QPushButton("Modifica Dati",this);
    modifyButton->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));

    updateButton = new QPushButton("Aggiorna Dati",this);
    updateButton->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    updateButton->setVisible(false);

    deleteButton = new QPushButton("Annulla",this);
    deleteButton->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    deleteButton->setVisible(false);

    datiLayout->addWidget(nomeLabel,0,0);
    datiLayout->addWidget(nome,0,1);

    datiLayout->addWidget(cognomeLabel,1,0);
    datiLayout->addWidget(cognome,1,1);

    datiLayout->addWidget(emailLabel,2,0);
    datiLayout->addWidget(email,2,1);

    datiLayout->addWidget(dataLabel,3,0);
    datiLayout->addWidget(dataNascita,3,1);

    datiLayout->addWidget(luogoLabel,4,0);
    datiLayout->addWidget(luogoNascita,4,1);

    datiLayout->addWidget(residenzaLabel,5,0);
    datiLayout->addWidget(residenza,5,1);

    buttonLayout->addWidget(modifyButton,0,0);
    buttonLayout->addWidget(deleteButton,1,0);
    buttonLayout->addWidget(updateButton,1,1);
    datiLayout->addLayout(buttonLayout,6,1);

    datiBox->setLayout(datiLayout);
    profiloLayout->addWidget(datiBox,1,0);

    connect(modifyButton, SIGNAL(clicked()), this, SLOT(enableEdit()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(disableEdit()));
    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateInfo()));
}

void UserInfoWindow::enableEdit(){
    modifyButton->setVisible(false);
    deleteButton->setVisible(true);
    updateButton->setVisible(true);
    nome->setReadOnly(false);
    cognome->setReadOnly(false);
    email->setReadOnly(false);
    dataNascita->setReadOnly(false);
    luogoNascita->setReadOnly(false);
    residenza->setReadOnly(false);
}

void UserInfoWindow::disableEdit(){
    modifyButton->setVisible(true);
    deleteButton->setVisible(false);
    updateButton->setVisible(false);
    nome->setReadOnly(true);
    cognome->setReadOnly(true);
    email->setReadOnly(true);
    dataNascita->setReadOnly(true);
    luogoNascita->setReadOnly(true);
    residenza->setReadOnly(true);
    delete nome;
    delete cognome;
    delete email;
    delete dataNascita;
    delete luogoNascita;
    delete residenza;
    fetchDati();
}

void UserInfoWindow::updateInfo(){
    DatiAnagrafici x(nome->text(),cognome->text(),email->text(),dataNascita->date(),
                     luogoNascita->text(),residenza->text());
    clientCtrl->updateUserInfo(x);
    disableEdit();
    emit signalSave();
}

UserInfoWindow::~UserInfoWindow(){
}

