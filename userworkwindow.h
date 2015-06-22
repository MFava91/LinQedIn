#ifndef USERWORKWINDOW_H
#define USERWORKWINDOW_H
#include<QRadioButton>
#include<QPushButton>
#include<QGridLayout>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>
#include<QDialog>

#include"usercontroller.h"
#include"lavorowindow.h"

class UserWorkWindow : public QWidget{
    Q_OBJECT
public:
    UserWorkWindow();
    UserWorkWindow(QWidget *parent, userController*);
    QGridLayout* workLayout;
    QGridLayout* lavoriLayout;
    QGroupBox* boxLavori;
    QPushButton* addButtonLavoro;

    //DIALOG
    QDialog* boxAddLavoro;
    QGridLayout* addLavoroLayout;
    QPushButton* addButtonNewLavoro;
    QPushButton* cancelButtonNewLavoro;

    userController* clientCtrl;
    ~UserWorkWindow();

public slots:
    void fetchLavoro();
    void dialogAddLavoro();
//    void addLavoro();
    void removeLavoro(LavoroWindow*);

};

#endif // USERWORKWINDOW_H
