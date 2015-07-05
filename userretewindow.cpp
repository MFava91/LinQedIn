#include "userretewindow.h"

UserReteWindow::UserReteWindow(){}

UserReteWindow::UserReteWindow(QWidget *parent, userController* userCtrl) : QWidget(parent){
    setWindowTitle("UserReteWindow");
    setMinimumWidth(700);
    reteBox = new QGroupBox("Rete di contatti");
    reteLayout = new QGridLayout();
    connectLayout = new QGridLayout();
    set<QString> rete = userCtrl->user->getRete().getFollow();
    int i = 0;
    for(set<QString>::const_iterator it=rete.begin();it!=rete.end();++it){
        ResultWindow* result = new ResultWindow(userCtrl->returnUtenteFromUsername(*it),userCtrl,this);
        reteLayout->addWidget(result,i,0);
        i++;
    }
    reteBox->setLayout(reteLayout);
    connectLayout->addWidget(reteBox,0,0);
    setLayout(connectLayout);
}

UserReteWindow::~UserReteWindow(){}
