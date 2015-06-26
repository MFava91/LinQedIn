#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H
#include<QWidget>
#include<QGridLayout>
#include<QGroupBox>
#include<QDialog>
#include<QRadioButton>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>

#include"admincontroller.h"

class ResultWindow : public QWidget{
    Q_OBJECT
public:
    ResultWindow(AdminController*, QWidget* = 0);
    ~ResultWindow();
    QGridLayout* resultLayout;
    QLabel* usernameRicercaLabel;
    QLabel* nameRicercaLabel;
    QLabel* surnameRicercaLabel;
    QLabel* usernameRicerca;
    QLabel* nameRicerca;
    QLabel* surnameRicerca;
};

#endif // RESULTWINDOW_H
