#include "userwindow.h"
#include<QLineEdit>
#include<QRadioButton>
#include<QVBoxLayout>

UserWindow::UserWindow(QWidget *parent) : QWidget(parent){
    setWindowTitle("madonna");
    out = new QGridLayout();
    out->setAlignment(Qt::AlignHCenter);
    prova = new QRadioButton(this);
    out->addWidget(prova,0,0);
    test = new QPushButton("eheheh",this);
    test->setGeometry(QRect(QPoint(100, 100),
                              QSize(200, 50)));
    out->addWidget(test,0,1);
    setLayout(out);

}

UserWindow::~UserWindow(){
}
