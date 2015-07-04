#include "resultwindow.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"
#include"usercontroller.h"

ResultWindow::ResultWindow(Utente* u, Controller* c,QWidget* parent){
    setWindowTitle("resultSearch");
    showProfileLayout = 0;
    user = u;
    ctrl = c;

    resultLayout = new QGridLayout();
    usernameRicercaLabel = new QLabel("Username:");
    nameRicercaLabel = new QLabel("Nome:");
    surnameRicercaLabel = new QLabel("Cognome:");
    usernameRicerca = new QLabel(user->getLogin().getUsername());
    nameRicerca = new QLabel(user->getInfo().getDati().getNome());
    surnameRicerca = new QLabel(user->getInfo().getDati().getCognome());
    showProfileButton = new QPushButton("Visualizza profilo");
    addReteButton = new QPushButton("Aggiungi amico");
    removeReteButton = new QPushButton("Rimuovi amico");
    if(ctrl->checkUtenteRete(user->getLogin().getUsername()) == true){
        addReteButton->setVisible(false);
        removeReteButton->setVisible(true);
    }
    else{
        addReteButton->setVisible(true);
        removeReteButton->setVisible(false);
    }
    resultLayout->addWidget(usernameRicercaLabel,0,0);
    resultLayout->addWidget(usernameRicerca,0,1);
    resultLayout->addWidget(nameRicercaLabel,0,2);
    resultLayout->addWidget(nameRicerca,0,3);
    resultLayout->addWidget(surnameRicercaLabel,0,4);
    resultLayout->addWidget(surnameRicerca,0,5);
    resultLayout->addWidget(addReteButton,0,6);
    resultLayout->addWidget(removeReteButton,0,7);
    resultLayout->addWidget(showProfileButton,0,8);
    setLayout(resultLayout);

    connect(showProfileButton, SIGNAL(clicked()), this, SLOT(showProfile()));
    connect(addReteButton, SIGNAL(clicked()), this, SLOT(addRete()));
    connect(removeReteButton, SIGNAL(clicked()), this, SLOT(removeRete()));
    connect(this, SIGNAL(signalFetchResult()), parent, SLOT(search()));
}

void ResultWindow::showProfile(){
    showProfileDialog = new QDialog();
    if(showProfileLayout!=0)
        delete showProfileLayout;
    showProfileLayout = new QGridLayout();
    profileLayout = new QGridLayout();
    topLayout = new QGridLayout();
    usernameLayout = new QGridLayout();
    infoBox = new QGroupBox("Informazioni utente");
    infoLayout = new QGridLayout();


    if(ctrl->tipoUtente() == "Basic" || ctrl->tipoUtente() == "Business" || ctrl->tipoUtente() == "Executive"){
        usernameLabel = new QLabel("Username:");
        nomeLabel = new QLabel("Nome:");
        cognomeLabel = new QLabel("Cognome:");
        username = new QLineEdit(user->getLogin().getUsername());
        username->setReadOnly(true);
        nome = new QLineEdit(user->getInfo().getDati().getNome());
        nome->setReadOnly(true);
        cognome = new QLineEdit(user->getInfo().getDati().getCognome());
        cognome->setReadOnly(true);
        usernameLayout->addWidget(usernameLabel,0,0);
        usernameLayout->addWidget(username,0,1);
        usernameLayout->addWidget(nomeLabel,1,0);
        usernameLayout->addWidget(nome,1,1);
        usernameLayout->addWidget(cognomeLabel,2,0);
        usernameLayout->addWidget(cognome,2,1);
        profileLayout->addLayout(usernameLayout,0,0);
        if(ctrl->tipoUtente() == "Basic"){
            infoBox->setLayout(profileLayout);
            topLayout->addWidget(infoBox,0,1);
        }
    }


    if(ctrl->tipoUtente() == "Business" || ctrl->tipoUtente() == "Executive"){
        dataLabel = new QLabel("Data di Nascita:");
        luogoLabel = new QLabel("Luogo di nascita:");
        residenzaLabel = new QLabel("Residenza:");
        emailLabel = new QLabel("Email:");

        email = new QLineEdit(user->getInfo().getDati().getEmail());
        email->setReadOnly(true);
        dataNascita = new QLineEdit(user->getInfo().getDati().getDataNascita().toString());
        dataNascita->setReadOnly(true);
        luogoNascita = new QLineEdit(user->getInfo().getDati().getLuogoNascita());
        luogoNascita->setReadOnly(true);
        residenza = new QLineEdit(user->getInfo().getDati().getResidenza());
        residenza->setReadOnly(true);
        infoLayout->addWidget(dataLabel,0,0);
        infoLayout->addWidget(dataNascita,0,1);
        infoLayout->addWidget(luogoLabel,1,0);
        infoLayout->addWidget(luogoNascita,1,1);
        infoLayout->addWidget(residenzaLabel,2,0);
        infoLayout->addWidget(residenza,2,1);

        schoolBox = new QGroupBox("Percorso scolastico");
        schoolLayout = new QGridLayout();
        diplomaLayout = new QGridLayout();
        diplomaLabel = new QLabel("Titolo diploma:");
        diploma = new QLineEdit(user->getInfo().getStudi().getDiploma());
        diploma->setReadOnly(true);
        diplomaLayout->addWidget(diplomaLabel,0,0);
        diplomaLayout->addWidget(diploma,0,1);
        schoolLayout->addLayout(diplomaLayout,0,0);
        vector<QString> lauree =
                user->getInfo().getStudi().getLaurea();
        int count = lauree.size();
        if(count){
            for(int i=0;i<count;i++){
                LaureaWindow* laurea = new LaureaWindow(lauree[i],this);
                schoolLayout->addWidget(laurea,i+1,0);
            }
        }
        profileLayout->addLayout(infoLayout,0,1);
        infoBox->setLayout(profileLayout);
        schoolBox->setLayout(schoolLayout);
        topLayout->addWidget(infoBox,0,1);
        topLayout->addWidget(schoolBox,0,2);
    }

    if(ctrl->tipoUtente() == "Executive"){
        titoloLavori = new QLabel("Esperienze lavorative");
        scrollArea = new QScrollArea();
        widget = new QWidget(scrollArea);

        workLayout = new QGridLayout();
        workLayout->setAlignment(Qt::AlignTop);
        vector<Lavoro> lavori = user->getInfo().getLavori().getEsperienze();
        int size = lavori.size();
        if(size){
            for(int i=0;i<size;i++){
                LavoroWindow* lavoro = new LavoroWindow(lavori[i].getAzienda(),lavori[i].getTitolo(),
                                                        lavori[i].getCitta(),lavori[i].getInizio(),
                                                        lavori[i].getFine(),this);
                workLayout->addWidget(lavoro,i,0);
            }
        }
        widget->setLayout(workLayout);
        scrollArea->setWidget(widget);
        scrollArea->setWidgetResizable(true);
        showProfileLayout->addWidget(titoloLavori,1,0);
        showProfileLayout->addWidget(scrollArea,2,0);

    }
    showProfileLayout->addLayout(topLayout,0,0);
    showProfileDialog->setLayout(showProfileLayout);
    showProfileDialog->exec();
}

void ResultWindow::addRete(){
    ctrl->updateReteContatti(user->getLogin().getUsername());
    emit signalFetchResult();
}

void ResultWindow::removeRete(){
    ctrl->removeReteContatti(user->getLogin().getUsername());
    emit signalFetchResult();
}

ResultWindow::~ResultWindow(){

}

