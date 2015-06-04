#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"adminwindow.h"
#include<QMainWindow>
#include<QStatusBar>
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>

#include"db.h"
#include"usercontroller.h"

class MainWindow: public QMainWindow {
    Q_OBJECT

private:
    QStatusBar *statusBar;
    QWidget *centralWidget;

    QGridLayout* layout;
    QPushButton *userSubmit;
    QPushButton *adminSubmit;
    QLineEdit *userUsername;
    QLineEdit *userPassword;
    QLineEdit *adminUsername;
    QLineEdit *adminPassword;
    DB* dataBase;
    static QString adminPass;
    static QString adminUser;

    userController* userCtrl;

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
