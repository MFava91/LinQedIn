#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include<QWidget>
#include<QGridLayout>
#include<QGroupBox>
#include<QDialog>
#include<QRadioButton>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QToolTip>
#include<QPoint>
#include<QMessageBox>

#include"resultwindow.h"
#include"controller.h"


class SearchWindow : public QWidget{
    Q_OBJECT
public:
    SearchWindow(QWidget *parent, Controller*);
    Controller* Ctrl;
    QGridLayout* mainLayout;
    QGridLayout* findLayout;
    QGridLayout* findForUsernameLayout;
    QGridLayout* findForNameLayout;
    QGridLayout* resultLayout;
    QGroupBox* findBox;
    QGroupBox* findForUsernameBox;
    QGroupBox* findForNameBox;
    QGroupBox* resultBox;

    QPushButton* findUsernameButton;
    QPushButton* findNameButton;

    //RICERCA
    QLabel* findUsernameLabel;
    QLabel* findNameLabel;
    QLabel* findSurnameLabel;
    QLineEdit* findUsername;
    QLineEdit* findName;
    QLineEdit* findSurname;

    //RISULTATI
    QLabel* nessunaRicerca;
    QLabel* nessunUtenteTrovato;

public slots:
    void searchUsername();
    void searchName();


};

#endif // SEARCHWINDOW_H
