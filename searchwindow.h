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
    QGridLayout* resultLayout;
    QGroupBox* findBox;
    QGroupBox* resultBox;

    QPushButton* findButton;

    //RICERCA
    QLabel* findUsernameLabel;
    QLabel* findNameLabel;
    QLabel* findSurnameLabel;
    QLabel* findLuogoNascitaLabel;
    QLabel* findResidenzaLabel;
    QLabel* findDiplomaLabel;
    QLabel* findLaureaLabel;
    QLabel* findAziendaLabel;
    QLabel* findTitoloLabel;
    QLineEdit* findUsername;
    QLineEdit* findName;
    QLineEdit* findSurname;
    QLineEdit* findLuogoNascita;
    QLineEdit* findResidenza;
    QLineEdit* findDiploma;
    QLineEdit* findLaurea;
    QLineEdit* findAzienda;
    QLineEdit* findTitolo;

    //RISULTATI
    QLabel* nessunaRicerca;
    QLabel* nessunUtenteTrovato;

public slots:
    void search();
};

#endif // SEARCHWINDOW_H
