#ifndef USERSCHOOLWINDOW_H
#define USERSCHOOLWINDOW_H
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
#include"laureawindow.h"

class UserSchoolWindow : public QWidget{
    Q_OBJECT
public:
    UserSchoolWindow();
    UserSchoolWindow(QWidget *parent, userController*);
    QGridLayout* schoolLayout;
    QGridLayout* diplomaLayout;
    QGridLayout* laureeLayout;
    QLineEdit* diploma;
    QGroupBox* boxDiploma;
    QGroupBox* boxLauree;

    QLabel* diplomaLabel;

    QPushButton* modifyButtonDiploma;
    QPushButton* updateButtonDiploma;
    QPushButton* deleteButtonDiploma;
    QPushButton* addButtonLaurea;

    //DIALOG
    QDialog* boxAddLaurea;
    QGridLayout* addLaureaLayout;
    QLabel* addLaureaLabel;
    QLineEdit* newLaurea;
    QPushButton* addButtonNewLaurea;
    QPushButton* cancelButtonNewLaurea;


    userController* clientCtrl;
    ~UserSchoolWindow();
public slots:
    void fetchDiploma();
    void enabledEditDiploma();
    void disableEditDiploma();
    void updateDiploma();

    void fetchLaurea();
    void dialogAddLaurea();
    void addLaurea();
    void removeLaurea(LaureaWindow*);
    void updateLaurea(const QString&,const QString&);
};

#endif // USERSCHOOLWINDOW_H
