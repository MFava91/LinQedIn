#include "usercontroller.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"

userController::userController(const QString& username){
//    if(db==0){  //DA RIVEDERE QUESTO IF
//        db = new DB();
//        db->load();
//    }
//    else
//        //db = database;
//        db->load();
//    //db->save();
//    loadUser(username);
    db = new DB();
    db->load();
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

void userController::updateUserLaurea(const QString& temp, const QString& l){
    user->getInfo().setLaurea(temp,l);
}

bool userController::searchLaurea(const QString& l){
    vector<QString> laurea = user->getInfo().getStudi().getLaurea();
    for(int i=0;i<laurea.size();i++){
        if(laurea[i]==l)
            return true;
    }
    return false;
}

void userController::updateUserLavoro(const Lavoro &temp, const Lavoro & lavoro){
    user->getInfo().setCurriculum(temp,lavoro);
}

void userController::saveDatabase(){
    db->updateUtente(user);
    db->save();
}

bool userController::searchUser(const QString &u){
    bool trovato;
    trovato=db->search(u);
    return trovato;
}

map<QString,Utente*> userController::findUser(const InfoSearch &info ){
    return user->find(info,db->getDb());
}

QString userController::tipoUtente() const{
    if(typeid(*user)==typeid(UtenteBasic))
        return "Basic";
    if(typeid(*user)==typeid(UtenteBusiness))
        return "Business";
    if(typeid(*user)==typeid(UtenteExecutive))
        return "Executive";
}

void userController::updateReteContatti(const QString &u){
    user->aggiungiUtenteRete(u);
    db->updateReteFollower(user->getLogin().getUsername(),u);
}

void userController::removeReteContatti(const QString &u){
    user->rimuoviUteteRete(u);
    db->removeReteFollower(user->getLogin().getUsername(),u);
}

bool userController::checkUtenteRete(const QString &u){
    set<QString> rete = user->getRete().getFollow();
    for(set<QString>::iterator it=rete.begin(); it!=rete.end(); ++it){
        if(*it == u)
            return true;
    }
    return false;
}

userController::~userController(){
}
