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

void userController::updateUserInfo(const DatiAnagrafici & dati){
    user->getInfo().setDatiPersonali(dati);
}

void userController::updateUserDiploma(const TitoliStudio & diploma){
    user->getInfo().setTitoliStudio(diploma);
}

void userController::updateUserLavoro(const Lavoro &temp, const Lavoro & lavoro){
    user->getInfo().setCurriculum(temp,lavoro);
}
