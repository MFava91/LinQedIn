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

class UserSchoolWindow : public QWidget{
    Q_OBJECT
public:
    UserSchoolWindow();
    UserSchoolWindow(QWidget *parent, userController*);  
    QGridLayout* schoolLayout;
    QGridLayout* diplomaLayout;
    QLineEdit* diploma;
    QLineEdit* laurea;
    QGroupBox* boxDiploma;

    QLabel* diplomaLabel;
    QLabel* laureaLabel;
    QPushButton* modifyButtonDiploma;
    QPushButton* updateButtonDiploma;
    QPushButton* deleteButtonDiploma;

    userController* clientCtrl;
    ~UserSchoolWindow();
public slots:
    void fetchDiploma();
    void enabledEditDiploma();
    void disableEditDiploma();
    void updateDiploma();
};

#endif // USERSCHOOLWINDOW_H
