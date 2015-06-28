#include "searchwindow.h"

SearchWindow::SearchWindow(QWidget *parent, Controller* control) : QWidget(parent){
    resultBox = 0;
    Ctrl = control;

    mainLayout = new QGridLayout();
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

    mainLayout->addWidget(findBox,0,0);
    mainLayout->addWidget(resultBox,1,0);
    setLayout(mainLayout);

    connect(findUsernameButton, SIGNAL(clicked()), this, SLOT(searchUsername()));
    connect(findNameButton, SIGNAL(clicked()), this, SLOT(searchName()));
}

void SearchWindow::searchUsername(){
    if(resultBox!=0)
    {
        mainLayout->removeWidget(resultBox);
        delete resultBox;
        resultBox = new QGroupBox("Risultati ricerca");
        resultLayout = new QGridLayout();
        if(Ctrl->findUserForUsername(findUsername->text()))
        {
            ResultWindow* result = new ResultWindow(Ctrl->findUserForUsername(findUsername->text()),this);
            resultLayout->addWidget(result,0,0);
        }
        else
        {
            nessunUtenteTrovato = new QLabel("Nessun utente trovato");
            resultLayout->addWidget(nessunUtenteTrovato,0,0);
        }
    }
    resultBox->setLayout(resultLayout);
    mainLayout->addWidget(resultBox,1,0);
    setLayout(mainLayout);
}

void SearchWindow::searchName(){
    if(resultBox!=0)
    {
        mainLayout->removeWidget(resultBox);
        delete resultBox;
        resultBox = new QGroupBox("Risultati ricerca");
        resultLayout = new QGridLayout();
        map<QString,Utente*> trovato = Ctrl->findUserForName(findName->text(),findSurname->text());
        if(!trovato.empty())
        {
            int i=0;
            for(std::map<QString,Utente*>::const_iterator it=trovato.begin();it!=trovato.end();++it)
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
    mainLayout->addWidget(resultBox,1,0);
    setLayout(mainLayout);
}
