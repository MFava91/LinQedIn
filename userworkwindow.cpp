#include "userworkwindow.h"

UserWorkWindow::UserWorkWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    boxLavori = 0;
    clientCtrl = userCtrl;
    workLayout = new QGridLayout();
    workLayout->setAlignment(Qt::AlignHCenter);
    fetchLavoro();
    addButtonLavoro = new QPushButton("Aggiungi lavoro",this);
    addButtonLavoro->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    workLayout->addWidget(addButtonLavoro,1,0);

}

void UserWorkWindow::fetchLavoro(){
    if(boxLavori!=0){
        workLayout->removeWidget(boxLavori);
        delete boxLavori;
    }
    boxLavori = new QGroupBox("Lavori");
    lavoriLayout = new QGridLayout();
    lavoriLayout->setAlignment(Qt::AlignHCenter);
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
    boxLavori->setLayout(lavoriLayout);
    workLayout->addWidget(boxLavori,0,0);
    setLayout(workLayout);
}

void UserWorkWindow::dialogAddLavoro(){
    boxAddLavoro = new QDialog();
    addLavoroLayout = new QGridLayout(boxAddLavoro);

}

void UserWorkWindow::removeLavoro(LavoroWindow* l){
    lavoriLayout->removeWidget(l);
    clientCtrl->user->getInfo();
}


UserWorkWindow::~UserWorkWindow(){
}
