#include "userworkwindow.h"

UserWorkWindow::UserWorkWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    setWindowTitle("infoWork");
    scrollArea = 0;
    clientCtrl = userCtrl;
    workLayout = new QGridLayout();
    workLayout->setAlignment(Qt::AlignHCenter);
    fetchLavoro();
    addButtonLavoro = new QPushButton("Aggiungi lavoro",this);
    addButtonLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    titolo = new QLabel("Esperienze lavorative");
    workLayout->addWidget(titolo,0,0);
    workLayout->addWidget(addButtonLavoro,2,0);

    connect(addButtonLavoro, SIGNAL(clicked()), this, SLOT(dialogAddLavoro()));
}

void UserWorkWindow::fetchLavoro(){
    if(scrollArea!=0){
        workLayout->removeWidget(scrollArea);
        delete scrollArea;
    }
    scrollArea = new QScrollArea();
    widget = new QWidget(scrollArea);
    lavoriLayout = new QGridLayout();
    lavoriLayout->setAlignment(Qt::AlignTop);
    vector<Lavoro> lavori = clientCtrl->user->getInfo().getLavori().getEsperienze();
    int size = lavori.size();
    if(size){
        for(int i=0;i<size;i++){
            LavoroWindow* lavoro = new LavoroWindow(lavori[i].getAzienda(),lavori[i].getTitolo(),
                                                    lavori[i].getCitta(),lavori[i].getInizio(),
                                                    lavori[i].getFine(),this);
            lavoriLayout->addWidget(lavoro,i,0);
        }
    }
    else
    {
        noLavori = new QLabel("Non è presente nessun lavoro.");
        noLavori->setAlignment(Qt::AlignHCenter);
        lavoriLayout->addWidget(noLavori,0,0);
    }

    widget->setLayout(lavoriLayout);
    scrollArea->setWidget(widget);
    scrollArea->setWidgetResizable(true);
    workLayout->addWidget(scrollArea,1,0);


    setLayout(workLayout);
}

void UserWorkWindow::dialogAddLavoro(){
    boxAddLavoro = new QDialog();
    addLavoroLayout = new QGridLayout(boxAddLavoro);
    buttonLayout = new QGridLayout;
    addAziendaLabel = new QLabel("Nome azienda:");
    addTitoloLabel = new QLabel("Titolo:");
    addCittaLabel = new QLabel("Città:");
    addInizioLabel= new QLabel("Inizio lavoro:");
    addFineLabel= new QLabel("Fine lavoro:");

    addAzienda = new QLineEdit();
    addTitolo = new QLineEdit();
    addCitta = new QLineEdit();
    addInizio = new QDateEdit();
    addInizio->setMinimumDate(clientCtrl->user->getInfo().getDati().getDataNascita().addYears(14));
    addInizio->setDisplayFormat("dd.MM.yyyy");
    addFine = new QDateEdit();
    addFine->setMinimumDate(clientCtrl->user->getInfo().getDati().getDataNascita().addYears(14).addDays(1));
    addFine->setMaximumDate(QDate::currentDate());
    addFine->setDisplayFormat("dd.MM.yyyy");

    cancelButtonNewLavoro = new QPushButton("Annulla",this);
    cancelButtonNewLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));

    addButtonNewLavoro = new QPushButton("Aggiorna",this);
    addButtonNewLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));

    buttonLayout->addWidget(addButtonNewLavoro,0,0);
    buttonLayout->addWidget(cancelButtonNewLavoro,0,1);

    addLavoroLayout->addWidget(addAziendaLabel,0,0);
    addLavoroLayout->addWidget(addAzienda,0,1);
    addLavoroLayout->addWidget(addTitoloLabel,1,0);
    addLavoroLayout->addWidget(addTitolo,1,1);
    addLavoroLayout->addWidget(addCittaLabel,2,0);
    addLavoroLayout->addWidget(addCitta,2,1);
    addLavoroLayout->addWidget(addInizioLabel,3,0);
    addLavoroLayout->addWidget(addInizio,3,1);
    addLavoroLayout->addWidget(addFineLabel,4,0);
    addLavoroLayout->addWidget(addFine,4,1);
    addLavoroLayout->addLayout(buttonLayout,5,1);
    boxAddLavoro->setLayout(addLavoroLayout);

    connect(addButtonNewLavoro, SIGNAL(clicked()), this, SLOT(addLavoro()));
    connect(cancelButtonNewLavoro, SIGNAL(clicked()), boxAddLavoro, SLOT(close()));
    boxAddLavoro->exec();
}

void UserWorkWindow::addLavoro(){
    Lavoro temp(addAzienda->text(),addTitolo->text(),addCitta->text(),
                addInizio->date(),addFine->date());
    clientCtrl->user->getInfo().aggiungiLavoro(temp);
    boxAddLavoro->close();
    fetchLavoro();
    clientCtrl->saveDatabase();
}

void UserWorkWindow::removeLavoro(LavoroWindow* l){
    lavoriLayout->removeWidget(l);
    clientCtrl->user->getInfo().wiperLavoro(l->temp);
    fetchLavoro();
    clientCtrl->saveDatabase();
}

void UserWorkWindow::modificaLavoro(const Lavoro& temp, const Lavoro& l){
    clientCtrl->updateUserLavoro(temp,l);
    clientCtrl->saveDatabase();
}

UserWorkWindow::~UserWorkWindow(){
}
