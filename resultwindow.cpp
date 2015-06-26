#include "resultwindow.h"

ResultWindow::ResultWindow(Utente* user, QWidget* parent){
    resultLayout = new QGridLayout();
    usernameRicercaLabel = new QLabel("Username:");
    nameRicercaLabel = new QLabel("Nome:");
    surnameRicercaLabel = new QLabel("Cognome:");
    usernameRicerca = new QLabel(user->getLogin().getUsername());
    nameRicerca = new QLabel(user->getInfo().getDati().getNome());
    surnameRicerca = new QLabel(user->getInfo().getDati().getCognome());

    resultLayout->addWidget(usernameRicercaLabel,0,0);
    resultLayout->addWidget(usernameRicerca,0,1);
    resultLayout->addWidget(nameRicercaLabel,1,0);
    resultLayout->addWidget(nameRicerca,1,1);
    resultLayout->addWidget(surnameRicercaLabel,2,0);
    resultLayout->addWidget(surnameRicerca,2,1);

    setLayout(resultLayout);
}

ResultWindow::~ResultWindow(){

}

