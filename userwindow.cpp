#include "userwindow.h"

UserWindow::UserWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    datiLayout = new QGridLayout();
    datiLayout->setAlignment(Qt::AlignHCenter);

    //FETCH DATI PERSONALI
    usernameLabel=new QLabel("Username:");
    username = new QLineEdit(userCtrl->user->getLogin().getUsername());
    username->setReadOnly(true);

//    username = new QTextEdit(userCtrl->user->getLogin().getUsername());
//    username->setReadOnly(true);


    nomeLabel = new QLabel("Nome:");
    nome = new QLabel(userCtrl->user->getInfo().getDati().getNome());
//    nome = new QTextEdit(userCtrl->user->getInfo().getDati().getNome());
//    nome->setReadOnly(true);
    cognomeLabel = new QLabel("Cognome:");
    cognome = new QLineEdit(userCtrl->user->getInfo().getDati().getCognome());
    cognome->setReadOnly(true);

    emailLabel = new QLabel("Email:");
    email = new QLineEdit(userCtrl->user->getInfo().getDati().getEmail());
    email->setReadOnly(true);

//    dataLabel = new QLabel("Data di Nascita:");
//    dataNascita = new QDateTimeEdit(userCtrl->user->getInfo().getDati().getDataNascita());
    //dataNascita->setReadOnly(true);

    luogoLabel = new QLabel("Luogo di Nascita:");
    luogoNascita = new QLineEdit(userCtrl->user->getInfo().getDati().getLuogoNascita());
    luogoNascita->setReadOnly(true);

    residenzaLabel = new QLabel("Residenza:");
    residenza = new QLineEdit(userCtrl->user->getInfo().getDati().getResidenza());
    residenza->setReadOnly(true);

    datiLayout->addWidget(usernameLabel,0,0);
    datiLayout->addWidget(username,0,1);

    datiLayout->addWidget(nomeLabel,1,0);
    datiLayout->addWidget(nome,1,1);

    datiLayout->addWidget(cognomeLabel,2,0);
    datiLayout->addWidget(cognome,2,1);

    datiLayout->addWidget(emailLabel,3,0);
    datiLayout->addWidget(email,3,1);

//    datiLayout->addWidget(dataLabel,4,0);
//    datiLayout->addWidget(dataNascita,4,1);

    datiLayout->addWidget(luogoLabel,5,0);
    datiLayout->addWidget(luogoNascita,5,1);

    datiLayout->addWidget(residenzaLabel,6,0);
    datiLayout->addWidget(residenza,6,1);

    setLayout(datiLayout);
}

UserWindow::~UserWindow(){
    delete username;
    delete nome;
    delete cognome;
    delete email;
    delete luogoNascita;
    delete residenza;
    delete usernameLabel;
    delete nomeLabel;
    delete cognomeLabel;
    delete emailLabel;
//    delete dataLabel;
    delete luogoLabel;
    delete residenzaLabel;
    delete datiLayout;
}
