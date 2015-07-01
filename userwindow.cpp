#include "userwindow.h"

UserWindow::UserWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    clientCtrl = userCtrl;
    mainLayout = new QGridLayout();
    mainLayout->setAlignment(Qt::AlignTop);

    menuLayout = new QGridLayout();
    menuLayout->setAlignment(Qt::AlignCenter);

    selectLayout = new QGridLayout();
    menuLayout->setAlignment(Qt::AlignTop);


    info = new QPushButton("Info",this);
    info->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));
    info->setEnabled(false);

    school = new QPushButton("Istruzione",this);
    school->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    work = new QPushButton("Lavori",this);
    work->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    search = new QPushButton("Ricerca",this);
    search->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    userInfo = new UserInfoWindow(this,userCtrl);
    userSchool = new UserSchoolWindow(this,userCtrl);
    userWork = new UserWorkWindow(this,userCtrl);
    userSearch = new SearchWindow(this,userCtrl);

    menuLayout->addWidget(info,0,0);
    menuLayout->addWidget(school,1,0);
    menuLayout->addWidget(work,2,0);
    menuLayout->addWidget(search,3,0);

    selectLayout->addWidget(userInfo,0,0);
    selectLayout->addWidget(userSchool,1,0);
    selectLayout->addWidget(userWork,2,0);
    selectLayout->addWidget(userSearch,3,0);

    mainLayout->addLayout(menuLayout,0,0);
    mainLayout->addLayout(selectLayout,0,1);

    //hidden
    userInfo->setVisible(true);
    userSchool->setVisible(false);
    userWork->setVisible(false);
    userSearch->setVisible(false);

    setLayout(mainLayout);

    connect(info, SIGNAL(clicked()),this, SLOT(loadUserInfo()));
    connect(school, SIGNAL(clicked()),this, SLOT(loadUserSchool()));
    connect(work, SIGNAL(clicked()), SLOT(loadUserWork()));
    connect(search, SIGNAL(clicked()), SLOT(loadUserSearch()));

}

void UserWindow::loadUserInfo() {
    userInfo->setVisible(true);
    userSchool->setVisible(false);
    userWork->setVisible(false);
    userSearch->setVisible(false);
    info->setEnabled(false);
    school->setEnabled(true);
    work->setEnabled(true);
    search->setEnabled(true);
}

void UserWindow::loadUserSchool() {
    userInfo->setVisible(false);
    userSchool->setVisible(true);
    userWork->setVisible(false);
    userSearch->setVisible(false);
    info->setEnabled(true);
    school->setEnabled(false);
    work->setEnabled(true);
    search->setEnabled(true);
}

void UserWindow::loadUserWork(){
    userInfo->setVisible(false);
    userSchool->setVisible(false);
    userWork->setVisible(true);
    userSearch->setVisible(false);
    info->setEnabled(true);
    school->setEnabled(true);
    work->setEnabled(false);
    search->setEnabled(true);
}

void UserWindow::loadUserSearch(){
    userInfo->setVisible(false);
    userSchool->setVisible(false);
    userWork->setVisible(false);
    userSearch->setVisible(true);
    info->setEnabled(true);
    school->setEnabled(true);
    work->setEnabled(true);
    search->setEnabled(false);
}

void UserWindow::saveDb(){
    clientCtrl->saveDatabase();
}

UserWindow::~UserWindow(){

}
