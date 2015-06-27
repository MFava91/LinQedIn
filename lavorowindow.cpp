#include "lavorowindow.h"

LavoroWindow::LavoroWindow(const QString& nomeAzienda, const QString& mansione ,
                           const QString& luogo, const QDate& inizioLavoro,
                           const QDate& fineLavoro, QWidget *parent) : QWidget(parent){
    lavoroLayout = new QGridLayout(this);

    aziendaLabel = new QLabel("Nome azienda:");
    titoloLabel = new QLabel("Titolo:");
    cittaLabel = new QLabel("Città:");
    inizioLabel= new QLabel("Inizio lavoro:");
    fineLabel= new QLabel("Fine lavoro:");

    azienda = new QLineEdit(nomeAzienda);
    azienda->setReadOnly(true);
    titolo = new QLineEdit(mansione);
    titolo->setReadOnly(true);
    citta = new QLineEdit(luogo);
    citta->setReadOnly(true);
    inizio = new QDateEdit(inizioLavoro);
    inizio->setReadOnly(true);
    fine = new QDateEdit(fineLavoro);
    fine->setReadOnly(true);

    modifyButtonLavoro = new QPushButton("Modifica",this);
    modifyButtonLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));

    cancelButtonLavoro = new QPushButton("Annulla",this);
    cancelButtonLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    cancelButtonLavoro->setVisible(false);

    updateButtonLavoro = new QPushButton("Aggiorna",this);
    updateButtonLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    updateButtonLavoro->setVisible(false);

    deleteButtonLavoro = new QPushButton("Cancella",this);
    deleteButtonLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    deleteButtonLavoro->setVisible(false);

    lavoroLayout->addWidget(aziendaLabel,0,0);
    lavoroLayout->addWidget(azienda,0,1);
    lavoroLayout->addWidget(titoloLabel,1,0);
    lavoroLayout->addWidget(titolo,1,1);
    lavoroLayout->addWidget(cittaLabel,2,0);
    lavoroLayout->addWidget(citta,2,1);
    lavoroLayout->addWidget(inizioLabel,3,0);
    lavoroLayout->addWidget(inizio,3,1);
    lavoroLayout->addWidget(fineLabel,4,0);
    lavoroLayout->addWidget(fine,4,1);
    lavoroLayout->addWidget(modifyButtonLavoro,5,1);
    lavoroLayout->addWidget(cancelButtonLavoro,6,0);
    lavoroLayout->addWidget(deleteButtonLavoro,6,1);
    lavoroLayout->addWidget(updateButtonLavoro,6,2);

    setLayout(lavoroLayout);

    connect(modifyButtonLavoro, SIGNAL(clicked()), this, SLOT(enableEditLavoro()));
    connect(cancelButtonLavoro, SIGNAL(clicked()), this, SLOT(disableEditLavoro()));
    connect(cancelButtonLavoro, SIGNAL(clicked()), parent, SLOT(fetchLavoro()));
    connect(deleteButtonLavoro,SIGNAL(clicked()),this, SLOT(deleteLavoro()));
    connect(this, SIGNAL(signalDeleteLavoro(LavoroWindow*)), parent, SLOT(removeLavoro(LavoroWindow*)));
    connect(updateButtonLavoro, SIGNAL(clicked()), this, SLOT(updateLavoro()));
    connect(this, SIGNAL(signalUpdateLavoro(const Lavoro&, const Lavoro&)), parent, SLOT(modificaLavoro(const Lavoro&, const Lavoro&)));
}

void LavoroWindow::enableEditLavoro(){
    modifyButtonLavoro->setVisible(false);
    cancelButtonLavoro->setVisible(true);
    updateButtonLavoro->setVisible(true);
    deleteButtonLavoro->setVisible(true);
    azienda->setReadOnly(false);
    titolo->setReadOnly(false);
    citta->setReadOnly(false);
    inizio->setReadOnly(false);
    fine->setReadOnly(false);
    Lavoro x(azienda->text(),titolo->text(),citta->text(),inizio->date(),fine->date());
    temp=x;
}

void LavoroWindow::disableEditLavoro(){
    modifyButtonLavoro->setVisible(true);
    cancelButtonLavoro->setVisible(false);
    updateButtonLavoro->setVisible(false);
    deleteButtonLavoro->setVisible(false);
    azienda->setReadOnly(true);
    titolo->setReadOnly(true);
    citta->setReadOnly(true);
    inizio->setReadOnly(true);
    fine->setReadOnly(true);
}

void LavoroWindow::deleteLavoro(){
    emit signalDeleteLavoro(this);
}

void LavoroWindow::updateLavoro(){
    Lavoro x(azienda->text(),titolo->text(),citta->text(),inizio->date(),fine->date());
    emit signalUpdateLavoro(temp,x);
    disableEditLavoro();
}

LavoroWindow::~LavoroWindow(){
}
