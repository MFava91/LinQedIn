#include "laureawindow.h"

LaureaWindow::LaureaWindow(const QString& name, QWidget *parent) : QWidget(parent){
     laureaLayout = new QGridLayout(this);
     laureaLabel = new QLabel("Titolo:");
     laurea = new QLineEdit(name);
     laurea->setReadOnly(true);


     laureaLayout->addWidget(laureaLabel,0,0);
     laureaLayout->addWidget(laurea,0,1);


     if(parent->windowTitle()=="infoSchool"){
         displayButton();
         laureaLayout->addLayout(buttonsLayout,1,1);
         connect(modifyButtonLaurea, SIGNAL(clicked()), this, SLOT(enableEditLaurea()));
         connect(cancelButtonLaurea, SIGNAL(clicked()), this, SLOT(disableEditLaurea()));
         connect(cancelButtonLaurea, SIGNAL(clicked()), parent, SLOT(fetchLaurea()));
         connect(deleteButtonLaurea, SIGNAL(clicked()), this, SLOT(deleteLaurea()));
         connect(this, SIGNAL(signalDeleteLaurea(LaureaWindow*)), parent, SLOT(removeLaurea(LaureaWindow*)));
         connect(updateButtonLaurea, SIGNAL(clicked()), this, SLOT(modifyLaurea()));
         connect(this, SIGNAL(signalUpdateLaurea(const QString&, const QString&)), parent, SLOT(updateLaurea(const QString&, const QString&)));
     }

     setLayout(laureaLayout);
}

void LaureaWindow::displayButton(){
    buttonsLayout = new QGridLayout();
    modifyButtonLaurea = new QPushButton("Modifica Laurea",this);
    modifyButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));

    cancelButtonLaurea = new QPushButton("Annulla Modifiche",this);
    cancelButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    cancelButtonLaurea->setVisible(false);

    updateButtonLaurea = new QPushButton("Aggiorna Laurea",this);
    updateButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    updateButtonLaurea->setVisible(false);

    deleteButtonLaurea = new QPushButton("Cancella Laurea",this);
    deleteButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    deleteButtonLaurea->setVisible(false);
    buttonsLayout->addWidget(modifyButtonLaurea,0,1);
    buttonsLayout->addWidget(cancelButtonLaurea,1,0);
    buttonsLayout->addWidget(deleteButtonLaurea,1,1);
    buttonsLayout->addWidget(updateButtonLaurea,1,2);

}

void LaureaWindow::enableEditLaurea(){
    modifyButtonLaurea->setVisible(false);
    deleteButtonLaurea->setVisible(true);
    updateButtonLaurea->setVisible(true);
    cancelButtonLaurea->setVisible(true);
    laurea->setReadOnly(false);
    temp = laurea->text();
}

void LaureaWindow::disableEditLaurea(){
    modifyButtonLaurea->setVisible(true);
    deleteButtonLaurea->setVisible(false);
    updateButtonLaurea->setVisible(false);
    cancelButtonLaurea->setVisible(false);
    laurea->setReadOnly(true);
}

void LaureaWindow::modifyLaurea(){
    disableEditLaurea();
    QString x=laurea->text();
    emit signalUpdateLaurea(temp,x);
}


void LaureaWindow::deleteLaurea(){
    emit signalDeleteLaurea(this);
}

LaureaWindow::~LaureaWindow(){
}
