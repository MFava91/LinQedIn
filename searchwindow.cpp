#include "searchwindow.h"
#include"usercontroller.h"
#include"admincontroller.h"
#include"utentebasic.h"

SearchWindow::SearchWindow(QWidget *parent, Controller* control) : QWidget(parent){
    resultBox = 0;
    Ctrl = control;
    setWindowTitle("SearchWindow");
    mainLayout = new QGridLayout();
    //SEZIONE FIND
    findBox = new QGroupBox("Ricerca");
    findLayout = new QGridLayout();

    //SEZIONE FIND PER USERNAME

    findUsernameLabel = new QLabel("Username");
    findUsername = new QLineEdit();    
    findNameLabel = new QLabel("Nome");
    findName = new QLineEdit();
    findSurnameLabel = new QLabel("Cognome");
    findSurname = new QLineEdit();
    findLuogoNascitaLabel = new QLabel("Luogo di Nascita");
    findLuogoNascita = new QLineEdit();
    findResidenzaLabel = new QLabel("Residenza");
    findResidenza = new QLineEdit();
    findDiplomaLabel = new QLabel("Diploma");
    findDiploma = new QLineEdit();
    findLaureaLabel = new QLabel("Laurea");
    findLaurea = new QLineEdit();
    findAziendaLabel = new QLabel("Nome azienda");
    findAzienda = new QLineEdit();
    findTitoloLabel = new QLabel("Titolo ricoperto");
    findTitolo = new QLineEdit();

    findButton = new QPushButton("Ricerca");

    if(Ctrl->tipoUtente() == "Basic" || Ctrl->tipoUtente() == "Business"
            || Ctrl->tipoUtente() == "Executive" || Ctrl->tipoUtente() == "Admin"){
        findLayout->addWidget(findUsernameLabel,0,0);
        findLayout->addWidget(findUsername,0,1);
        findLayout->addWidget(findNameLabel,1,0);
        findLayout->addWidget(findName,1,1);
        findLayout->addWidget(findSurnameLabel,1,2);
        findLayout->addWidget(findSurname,1,3);
    }
    if(Ctrl->tipoUtente() == "Business"
            || Ctrl->tipoUtente() == "Executive"){
         findLayout->addWidget(findLuogoNascitaLabel,2,0);
         findLayout->addWidget(findLuogoNascita,2,1);
         findLayout->addWidget(findResidenzaLabel,2,2);
         findLayout->addWidget(findResidenza,2,3);
         findLayout->addWidget(findDiplomaLabel,3,0);
         findLayout->addWidget(findDiploma,3,1);
         findLayout->addWidget(findLaureaLabel,3,2);
         findLayout->addWidget(findLaurea,3,3);
    }
    if(Ctrl->tipoUtente() == "Executive"){
        findLayout->addWidget(findAziendaLabel,4,0);
        findLayout->addWidget(findAzienda,4,1);
        findLayout->addWidget(findTitoloLabel,4,2);
        findLayout->addWidget(findTitolo,4,3);
    }
    findLayout->addWidget(findButton,5,3);
    findBox->setLayout(findLayout);

    //RESULT
    resultBox = new QGroupBox("Risultati ricerca");
    resultLayout = new QGridLayout();
    nessunaRicerca = new QLabel("Nessuna ricerca effettuata");
    resultLayout->addWidget(nessunaRicerca,0,0);
    resultBox->setLayout(resultLayout);

    mainLayout->addWidget(findBox,0,0);
    mainLayout->addWidget(resultBox,1,0);
    setLayout(mainLayout);

    connect(findButton, SIGNAL(clicked()), this, SLOT(search()));
}

void SearchWindow::search(){
    mainLayout->removeWidget(resultBox);
    delete resultBox;
    resultBox = new QGroupBox("Risultati ricerca");
    resultLayout = new QGridLayout();
    InfoSearch info(findUsername->text(),findName->text(),findSurname->text(),
                    findLuogoNascita->text(),findResidenza->text(),findDiploma->text(),
                    findLaurea->text(),findAzienda->text(),findTitolo->text());
    if(Ctrl->findUser(info).size())
    {
        map<QString,Utente*> trovati = Ctrl->findUser(info);
        int i = 0;
        for(std::map<QString,Utente*>::iterator it=trovati.begin();it!=trovati.end();++it)
        {
            if(Ctrl->getUsername()!=(*it).first){
                ResultWindow* result = new ResultWindow((*it).second,Ctrl,this);
                resultLayout->addWidget(result,i,0);
                i++;
            }
        }
    }
    else
    {
        nessunUtenteTrovato = new QLabel("Nessun utente trovato");
        resultLayout->addWidget(nessunUtenteTrovato,0,0);
    }
    resultBox->setLayout(resultLayout);
    mainLayout->addWidget(resultBox,1,0);
    setLayout(mainLayout);
}

