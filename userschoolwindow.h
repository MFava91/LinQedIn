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

//    LaureaWindow* laurea;
    userController* clientCtrl;
    ~UserSchoolWindow();
public slots:
    void fetchDiploma();
    void enabledEditDiploma();
    void disableEditDiploma();
    void updateDiploma();

    void fetchLaurea();
//    void enabledEditLaurea();
//    void disableEditLaurea();
    void updateLaurea();
    void removeLaurea(LaureaWindow*);
};

#endif // USERSCHOOLWINDOW_H
