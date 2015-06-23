#include "userwindow.h"

UserWindow::UserWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    clientCtrl = userCtrl;
    mainLayout = new QGridLayout();
    mainLayout->setAlignment(Qt::AlignTop);

    menuLayout = new QGridLayout();
    menuLayout->setAlignment(Qt::AlignCenter);

    selectLayout = new QGridLayout();
    menuLayout->setAlignment(Qt::AlignCenter);


    info = new QPushButton("Info",this);
    info->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    school = new QPushButton("Istruzione",this);
    school->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    work = new QPushButton("Lavori",this);
    work->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    userInfo = new UserInfoWindow(this,userCtrl);
    userSchool = new UserSchoolWindow(this,userCtrl);
    userWork = new UserWorkWindow(this,userCtrl);

    menuLayout->addWidget(info,0,0);
    menuLayout->addWidget(school,1,0);
    menuLayout->addWidget(work,2,0);

    selectLayout->addWidget(userInfo,0,0);
    selectLayout->addWidget(userSchool,1,0);
    selectLayout->addWidget(userWork,2,0);

    mainLayout->addLayout(menuLayout,0,0);
    mainLayout->addLayout(selectLayout,0,1);

    //hidden
    userInfo->setVisible(true);
    userSchool->setVisible(false);
    userWork->setVisible(false);
    setLayout(mainLayout);

    connect(info, SIGNAL(clicked()),this, SLOT(loadUserInfo()));
    connect(school, SIGNAL(clicked()),this, SLOT(loadUserSchool()));
    connect(work, SIGNAL(clicked()), SLOT(loadUserWork()));

}

void UserWindow::loadUserInfo() {
    userInfo->setVisible(true);
    userSchool->setVisible(false);
    userWork->setVisible(false);
}

void UserWindow::loadUserSchool() {
    userInfo->setVisible(false);
    userSchool->setVisible(true);
    userWork->setVisible(false);
}

void UserWindow::loadUserWork(){
    userInfo->setVisible(false);
    userSchool->setVisible(false);
    userWork->setVisible(true);
}

void UserWindow::saveDb(){
    clientCtrl->saveDatabase();
}

UserWindow::~UserWindow(){

}
