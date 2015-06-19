#include "userschoolwindow.h"

UserSchoolWindow::UserSchoolWindow(QWidget *parent,userController* userCtrl) : QWidget(parent){
    schoolLayout = new QGridLayout();
    schoolLayout->setAlignment(Qt::AlignHCenter);
    schoolLayout->setColumnMinimumWidth(0,200);
    schoolLayout->setColumnMinimumWidth(1,400);


    diplomaLabel = new QLabel("Diploma:");

    laureaLabel = new QLabel("Laurea:");

    schoolLayout->addWidget(diplomaLabel,0,0);
    schoolLayout->addWidget(laureaLabel,0,1);
    setLayout(schoolLayout);
}

UserSchoolWindow::~UserSchoolWindow(){

}
