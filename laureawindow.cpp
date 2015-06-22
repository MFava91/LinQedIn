#include "laureawindow.h"

LaureaWindow::LaureaWindow(const QString& name, QWidget *parent) : QWidget(parent){
    laureaLayout = new QGridLayout(this);

    laureaLabel = new QLabel("Titolo:");
     laurea = new QLineEdit(name);
     laurea->setReadOnly(true);

     modifyButtonLaurea = new QPushButton("Modifica",this);
     modifyButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                               QSize(200, 50)));

     cancelButtonLaurea = new QPushButton("Annulla",this);
     cancelButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                               QSize(200, 50)));
     cancelButtonLaurea->setVisible(false);

     updateButtonLaurea = new QPushButton("Aggiorna",this);
     updateButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                               QSize(200, 50)));
     updateButtonLaurea->setVisible(false);

     deleteButtonLaurea = new QPushButton("Cancella",this);
     deleteButtonLaurea->setGeometry(QRect(QPoint(100, 100),
                               QSize(200, 50)));
     deleteButtonLaurea->setVisible(false);

     laureaLayout->addWidget(laureaLabel,0,0);
     laureaLayout->addWidget(laurea,0,1);
     laureaLayout->addWidget(modifyButtonLaurea,1,1);
     laureaLayout->addWidget(cancelButtonLaurea,2,0);
     laureaLayout->addWidget(deleteButtonLaurea,2,1);
     laureaLayout->addWidget(updateButtonLaurea,2,2);

     setLayout(laureaLayout);

     connect(modifyButtonLaurea, SIGNAL(clicked()), this, SLOT(enableEditLaurea()));
     connect(cancelButtonLaurea, SIGNAL(clicked()), this, SLOT(disableEditLaurea()));
     connect(cancelButtonLaurea, SIGNAL(clicked()), parent, SLOT(fetchLaurea()));
     connect(deleteButtonLaurea, SIGNAL(clicked()), this, SLOT(deleteLaurea()));
     connect(this, SIGNAL(signalDeleteLaurea(LaureaWindow*)), parent, SLOT(removeLaurea(LaureaWindow*)));
}

void LaureaWindow::enableEditLaurea(){
    modifyButtonLaurea->setVisible(false);
    deleteButtonLaurea->setVisible(true);
    updateButtonLaurea->setVisible(true);
    cancelButtonLaurea->setVisible(true);
    laurea->setReadOnly(false);
}

void LaureaWindow::disableEditLaurea(){
    modifyButtonLaurea->setVisible(true);
    deleteButtonLaurea->setVisible(false);
    updateButtonLaurea->setVisible(false);
    cancelButtonLaurea->setVisible(false);
    laurea->setReadOnly(true);
}

//manca salvataggio modifiche

void LaureaWindow::deleteLaurea(){
    emit signalDeleteLaurea(this);
}

LaureaWindow::~LaureaWindow(){
}
