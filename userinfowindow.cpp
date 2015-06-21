#include "userinfowindow.h"

UserInfoWindow::UserInfoWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    clientCtrl = userCtrl;
    datiLayout = new QGridLayout();
    datiLayout->setAlignment(Qt::AlignHCenter);

    usernameLabel=new QLabel("Username:");
    username = new QLineEdit(clientCtrl->user->getLogin().getUsername());
    username->setReadOnly(true);

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

    datiLayout->addWidget(usernameLabel,0,0);
    datiLayout->addWidget(username,0,1);
    datiLayout->addWidget(modifyButton,7,1);
    datiLayout->addWidget(deleteButton,8,0);
    datiLayout->addWidget(updateButton,8,1);

    fetchDati();

    connect(modifyButton, SIGNAL(clicked()), this, SLOT(enableEdit()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(disableEdit()));
    connect(updateButton, SIGNAL(clicked()), this, SLOT(updateInfo()));
}

void UserInfoWindow::fetchDati(){
    //FETCH DATI PERSONALI

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

    luogoLabel = new QLabel("Luogo di Nascita:");
    luogoNascita = new QLineEdit(clientCtrl->user->getInfo().getDati().getLuogoNascita());
    luogoNascita->setReadOnly(true);

    residenzaLabel = new QLabel("Residenza:");
    residenza = new QLineEdit(clientCtrl->user->getInfo().getDati().getResidenza());
    residenza->setReadOnly(true);

    datiLayout->addWidget(nomeLabel,1,0);
    datiLayout->addWidget(nome,1,1);

    datiLayout->addWidget(cognomeLabel,2,0);
    datiLayout->addWidget(cognome,2,1);

    datiLayout->addWidget(emailLabel,3,0);
    datiLayout->addWidget(email,3,1);

    datiLayout->addWidget(dataLabel,4,0);
    datiLayout->addWidget(dataNascita,4,1);

    datiLayout->addWidget(luogoLabel,5,0);
    datiLayout->addWidget(luogoNascita,5,1);

    datiLayout->addWidget(residenzaLabel,6,0);
    datiLayout->addWidget(residenza,6,1);

    setLayout(datiLayout);
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
}

UserInfoWindow::~UserInfoWindow(){
//    delete username;
//    delete nome;
//    delete cognome;
//    delete email;
//    delete luogoNascita;
//    delete residenza;
//    delete usernameLabel;
//    delete nomeLabel;
//    delete cognomeLabel;
//    delete emailLabel;
//    delete dataLabel;
//    delete luogoLabel;
//    delete residenzaLabel;
//    delete datiLayout;
}

