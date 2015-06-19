#include "usercontroller.h"

userController::userController(const QString& username, DB* database){
    if(database==0){  //DA RIVEDERE QUESTO IF
        db = new DB();
        db->load();
    }
    else
        //db = database;
        db->load();
    db->save();
    loadUser(username);
}

void userController::loadUser(const QString& username){
    user = db->find(username);
}
