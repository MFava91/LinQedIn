#include "userschoolwindow.h"

UserSchoolWindow::UserSchoolWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    clientCtrl = userCtrl;
    schoolLayout = new QGridLayout();
    schoolLayout->setAlignment(Qt::AlignHCenter);
    schoolLayout->setColumnMinimumWidth(0,100);
    schoolLayout->setColumnMinimumWidth(1,400);

    //DIPLOMA
    diplomaLayout = new QGridLayout();
    diplomaLayout->setAlignment(Qt::AlignHCenter);

    boxDiploma = new QGroupBox("Diploma");
    fetchDiploma();

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


    diplomaLayout->addWidget(modifyButtonDiploma,1,1);
    diplomaLayout->addWidget(deleteButtonDiploma,2,0);
    diplomaLayout->addWidget(updateButtonDiploma,2,1);
    boxDiploma->setLayout(diplomaLayout);




    //LAUREE
    laureaLabel = new QLabel("Laurea:");

    diplomaLayout->addWidget(diplomaLabel,0,0);
    diplomaLayout->addWidget(diploma,0,1);
    boxDiploma->setLayout(diplomaLayout);

    schoolLayout->addWidget(boxDiploma,0,0);
    schoolLayout->addWidget(laureaLabel,1,0);
    setLayout(schoolLayout);

    connect(modifyButtonDiploma, SIGNAL(clicked()), this, SLOT(enabledEditDiploma()));
    connect(deleteButtonDiploma, SIGNAL(clicked()), this, SLOT(disableEditDiploma()));
    connect(updateButtonDiploma, SIGNAL(clicked()), this, SLOT(updateDiploma()));
}

void UserSchoolWindow::fetchDiploma(){
    diplomaLabel = new QLabel("Titolo:");
    diploma = new QLineEdit(clientCtrl->user->getInfo().getStudi().getDiploma());
    diploma->setReadOnly(true);
    diplomaLayout->addWidget(diplomaLabel,0,0);
    diplomaLayout->addWidget(diploma,0,1);
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


UserSchoolWindow::~UserSchoolWindow(){
}
