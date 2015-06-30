#include "resultwindow.h"

ResultWindow::ResultWindow(Utente* u, QWidget* parent){
    setWindowTitle("resultSearch");
    showProfileLayout = 0;
    user=u;
    resultLayout = new QGridLayout();
    usernameRicercaLabel = new QLabel("Username:");
    nameRicercaLabel = new QLabel("Nome:");
    surnameRicercaLabel = new QLabel("Cognome:");
    usernameRicerca = new QLabel(user->getLogin().getUsername());
    nameRicerca = new QLabel(user->getInfo().getDati().getNome());
    surnameRicerca = new QLabel(user->getInfo().getDati().getCognome());
    showProfileButton = new QPushButton("Visualizza profilo");

    resultLayout->addWidget(usernameRicercaLabel,0,0);
    resultLayout->addWidget(usernameRicerca,0,1);
    resultLayout->addWidget(nameRicercaLabel,0,2);
    resultLayout->addWidget(nameRicerca,0,3);
    resultLayout->addWidget(surnameRicercaLabel,0,4);
    resultLayout->addWidget(surnameRicerca,0,5);
    resultLayout->addWidget(showProfileButton,0,6);

    setLayout(resultLayout);

    connect(showProfileButton, SIGNAL(clicked()), this, SLOT(showProfile()));
}

void ResultWindow::showProfile(){
    showProfileDialog = new QDialog();
    if(showProfileLayout!=0)
        delete showProfileLayout;
    showProfileLayout = new QGridLayout();
    infoBox = new QGroupBox("Informazioni utente");
    infoLayout = new QGridLayout();
    usernameLabel = new QLabel("Username:");
    nomeLabel = new QLabel("Nome:");
    cognomeLabel = new QLabel("Cognome:");
    emailLabel = new QLabel("Email:");
    dataLabel = new QLabel("Data di Nascita:");
    luogoLabel = new QLabel("Luogo di nascita:");
    residenzaLabel = new QLabel("Residenza:");

    username = new QLineEdit(user->getLogin().getUsername());
    username->setReadOnly(true);
    nome = new QLineEdit(user->getInfo().getDati().getNome());
    nome->setReadOnly(true);
    cognome = new QLineEdit(user->getInfo().getDati().getCognome());
    cognome->setReadOnly(true);
    email = new QLineEdit(user->getInfo().getDati().getEmail());
    email->setReadOnly(true);
    dataNascita = new QLineEdit(user->getInfo().getDati().getDataNascita().toString());
    dataNascita->setReadOnly(true);
    luogoNascita = new QLineEdit(user->getInfo().getDati().getLuogoNascita());
    luogoNascita->setReadOnly(true);
    residenza = new QLineEdit(user->getInfo().getDati().getResidenza());
    residenza->setReadOnly(true);


    infoLayout->addWidget(usernameLabel,0,0);
    infoLayout->addWidget(username,0,1);
    infoLayout->addWidget(dataLabel,0,2);
    infoLayout->addWidget(dataNascita,0,3);
    infoLayout->addWidget(nomeLabel,1,0);
    infoLayout->addWidget(nome,1,1);
    infoLayout->addWidget(luogoLabel,1,2);
    infoLayout->addWidget(luogoNascita,1,3);
    infoLayout->addWidget(residenzaLabel,2,2);
    infoLayout->addWidget(residenza,2,3);
    infoLayout->addWidget(cognomeLabel,2,0);
    infoLayout->addWidget(cognome,2,1);
    infoLayout->addWidget(username,3,0);
    infoLayout->addWidget(usernameLabel,3,1);
    infoBox->setLayout(infoLayout);

    schoolBox = new QGroupBox("Percorso scolastico");
    schoolLayout = new QGridLayout();

    diplomaLabel = new QLabel("Titolo diploma:");
    diploma = new QLineEdit(user->getInfo().getStudi().getDiploma());
    diploma->setReadOnly(true);
    schoolLayout->addWidget(diplomaLabel,0,0);
    schoolLayout->addWidget(diploma,0,1);
    vector<QString> lauree =
            user->getInfo().getStudi().getLaurea();
    int count = lauree.size();
    if(count){
        for(int i=0;i<count;i++){
            LaureaWindow* laurea = new LaureaWindow(lauree[i],this);
            schoolLayout->addWidget(laurea,i+1,0);
        }
    }
    schoolBox->setLayout(schoolLayout);

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
    topLayout = new QGridLayout();
    topLayout->addWidget(infoBox,0,0);
    topLayout->addWidget(schoolBox,0,1);
    titoloLavori = new QLabel("Esperienze lavorative");
    showProfileLayout->addLayout(topLayout,0,0);
    showProfileLayout->addWidget(titoloLavori,1,0);
    showProfileLayout->addWidget(scrollArea,2,0);
    showProfileDialog->setLayout(showProfileLayout);
    showProfileDialog->exec();
}

ResultWindow::~ResultWindow(){

}

