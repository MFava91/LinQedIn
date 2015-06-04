#include "userwindow.h"
#include<QLineEdit>
#include<QRadioButton>
#include<QVBoxLayout>

UserWindow::UserWindow() {
    QRadioButton *userButton = new QRadioButton("Utente");
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(userButton);
    setLayout(layout);
};
