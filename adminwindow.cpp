#include "adminwindow.h"
#include<QLineEdit>
#include<QRadioButton>
#include<QVBoxLayout>

AdminWindow::AdminWindow() {
    QRadioButton *userButton = new QRadioButton("Utente");
    QRadioButton *adminButton = new QRadioButton("Admin");
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(userButton);
    layout->addWidget(adminButton);
    setLayout(layout);
}
