#include "userwindow.h"

UserWindow::UserWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
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

    works = new QPushButton("Lavori",this);
    works->setGeometry(QRect(QPoint(100, 100),
                                 QSize(200, 50)));

    userInfo = new UserInfoWindow(this,userCtrl);

    menuLayout->addWidget(info,0,0);
    menuLayout->addWidget(school,1,0);
    menuLayout->addWidget(works,2,0);

    selectLayout->addWidget(userInfo,0,0);

    mainLayout->addLayout(menuLayout,0,0);
    mainLayout->addLayout(selectLayout,0,1);

    userInfo->setVisible(false);
    setLayout(mainLayout);

    connect(info, SIGNAL(clicked()), SLOT(loadUserInfo()));
//    connect(school, SIGNAL(clicked()), SLOT(loadUserSchool()));
//    connect(works, SIGNAL(clicked()), SLOT(loadUserWorks()));

}

void UserWindow::loadUserInfo() {
    userInfo->setVisible(true);
}

UserWindow::~UserWindow(){

}
