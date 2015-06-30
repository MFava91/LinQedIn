#include "userschoolwindow.h"

UserSchoolWindow::UserSchoolWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    setWindowTitle("infoSchool");
    boxDiploma = 0;
    boxLauree = 0;
    clientCtrl = userCtrl;
    schoolLayout = new QGridLayout();
    schoolLayout->setAlignment(Qt::AlignHCenter);

    //DIPLOMA
    fetchDiploma();
    //LAUREE

    fetchLaurea();
    addButtonLaurea = new QPushButton("Aggiungi laurea",this);
    addButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    schoolLayout->addWidget(addButtonLaurea,3,0);
    //INTERFACCIA GLOBALE

    connect(addButtonLaurea, SIGNAL(clicked()), this, SLOT(dialogAddLaurea()));

}

void UserSchoolWindow::fetchDiploma()
{
    if(boxDiploma!=0){
        schoolLayout->removeWidget(boxDiploma);
        delete boxDiploma;
    }
    boxDiploma = new QGroupBox("Diploma");
    diplomaLayout = new QGridLayout();
    diplomaLayout->setAlignment(Qt::AlignHCenter);

    diplomaLabel = new QLabel("Titolo:");
    diploma = new QLineEdit(clientCtrl->user->getInfo().getStudi().getDiploma());
    diploma->setReadOnly(true);

    buttonLayout = new QGridLayout();
    modifyButtonDiploma = new QPushButton("Aggiorna Diploma",this);
    modifyButtonDiploma->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));

    updateButtonDiploma = new QPushButton("Aggiorna Dati",this);
    updateButtonDiploma->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    updateButtonDiploma->setVisible(false);

    deleteButtonDiploma = new QPushButton("Annulla",this);
    deleteButtonDiploma->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    deleteButtonDiploma->setVisible(false);

    buttonLayout->addWidget(modifyButtonDiploma,0,0);
    buttonLayout->addWidget(deleteButtonDiploma,1,0);
    buttonLayout->addWidget(updateButtonDiploma,1,1);

    diplomaLayout->addWidget(diplomaLabel,0,0);
    diplomaLayout->addWidget(diploma,0,1);
    diplomaLayout->addLayout(buttonLayout,1,1);
    boxDiploma->setLayout(diplomaLayout);
    schoolLayout->addWidget(boxDiploma,0,0);

    connect(modifyButtonDiploma, SIGNAL(clicked()), this, SLOT(enabledEditDiploma()));
    connect(deleteButtonDiploma, SIGNAL(clicked()), this, SLOT(disableEditDiploma()));
    connect(updateButtonDiploma, SIGNAL(clicked()), this, SLOT(updateDiploma()));
}

void UserSchoolWindow::enabledEditDiploma(){
    modifyButtonDiploma->setVisible(false);
    deleteButtonDiploma->setVisible(true);
    updateButtonDiploma->setVisible(true);
    diploma->setReadOnly(false);
}

void UserSchoolWindow::disableEditDiploma(){
    deleteButtonDiploma->setVisible(false);
    updateButtonDiploma->setVisible(false);
    modifyButtonDiploma->setVisible(true);
    diploma->setReadOnly(true);
    delete diploma;
    fetchDiploma();
}

void UserSchoolWindow::updateDiploma(){
    TitoliStudio x(diploma->text());
    clientCtrl->updateUserDiploma(x);
    disableEditDiploma();
    //manca scrittura sul database
}

void UserSchoolWindow::fetchLaurea(){
    if(boxLauree!=0){
        schoolLayout->removeWidget(boxLauree);
        delete boxLauree;
    }
    boxLauree = new QGroupBox("Lauree");
    laureeLayout = new QGridLayout();
    laureeLayout->setAlignment(Qt::AlignHCenter);
    vector<QString> lauree =
            clientCtrl->user->getInfo().getStudi().getLaurea();
    int size = lauree.size();
    if(size){
        for(int i=0;i<size;i++){
            LaureaWindow* laurea = new LaureaWindow(lauree[i],this);
            laureeLayout->addWidget(laurea,i,0);
        }
    }
    else{
        noLauree = new QLabel("Non è presente nessuna laurea.");
        laureeLayout->addWidget(noLauree,0,0);
    }
    boxLauree->setLayout(laureeLayout);
    schoolLayout->addWidget(boxLauree,1,0);
    setLayout(schoolLayout);

}

void UserSchoolWindow::dialogAddLaurea(){
    boxAddLaurea = new QDialog();
    addLaureaLayout = new QGridLayout(boxAddLaurea);
    addLaureaLabel = new QLabel("Titolo:");
    newLaurea = new QLineEdit();
    addButtonNewLaurea = new QPushButton("Aggiungi");
    cancelButtonNewLaurea = new QPushButton("Annulla");
    addLaureaLayout->addWidget(addLaureaLabel,0,0);
    addLaureaLayout->addWidget(newLaurea,0,1);
    addLaureaLayout->addWidget(addButtonNewLaurea,1,0);
    addLaureaLayout->addWidget(cancelButtonNewLaurea,1,1);
    boxAddLaurea->setLayout(addLaureaLayout);

    connect(addButtonNewLaurea, SIGNAL(clicked()), this, SLOT(addLaurea()));
    connect(cancelButtonNewLaurea, SIGNAL(clicked()), boxAddLaurea, SLOT(close()));
    boxAddLaurea->exec();
}

void UserSchoolWindow::addLaurea(){
    if(!clientCtrl->searchLaurea(newLaurea->text()))
    {
        clientCtrl->user->getInfo().aggiungiLaurea(newLaurea->text());
        boxAddLaurea->close();
        fetchLaurea();
    }
    else
        QToolTip::showText(newLaurea->mapToGlobal(QPoint()), "La laurea che si vuole inserire è già presente");
}


void UserSchoolWindow::removeLaurea(LaureaWindow *l){
    laureeLayout->removeWidget(l);
    clientCtrl->user->getInfo().wipeLaurea(l->laurea->text());
    delete l;
    fetchLaurea();
}

void UserSchoolWindow::updateLaurea(const QString& temp, const QString& laurea){
    clientCtrl->updateUserLaurea(temp,laurea);
}

UserSchoolWindow::~UserSchoolWindow(){
}
