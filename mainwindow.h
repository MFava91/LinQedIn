#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QStatusBar>
#include<QMenuBar>
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include<QGroupBox>
#include<QCloseEvent>
#include"db.h"
#include"adminwindow.h"
#include"userwindow.h"
#include"usercontroller.h"
#include"admincontroller.h"

class MainWindow: public QMainWindow {
    Q_OBJECT

private:
    QStatusBar *statusBar;
    QWidget *mainWidget;

    QAction *logoutAction;
    QGridLayout* layout;
    QGridLayout* userLoginLayout;
    QGridLayout* adminLoginLayout;
    QGroupBox* userLoginBox;
    QGroupBox* adminLoginBox;
    QPushButton *userSubmit;
    QPushButton *adminSubmit;
    QLineEdit *userUsername;
    QLineEdit *userPassword;
    QLineEdit *adminUsername;
    QLineEdit *adminPassword;
    static QString adminPass;
    static QString adminUser;
    QCloseEvent* close;

    userController* userCtrl;
    AdminController* adminCtrl;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signalPasswordUser(const QString&);
    void signalPasswordAdmin(const QString&);

public slots:
    void readCredentialUser();
    void readCredentialAdmin();
    void loginUser(const QString&);
    void loginAdmin(const QString&);
};



#endif // MAINWINDOW_H
