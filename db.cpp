#include "db.h"
#include<iostream>
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"

using std::cout;
using std::endl;
using std::set;

DB::DB()
{
}

map<QString,Utente*>* DB::getDb(){
    return &dbUtenti;
}

void DB::addUtente(Username u,Utente* p){
    dbUtenti.insert(map<QString,Utente*>::value_type(u.getUsername(),p));
    save();
}

void DB::addNewUtente(const QString &u, const QString &n, const QString &c){
    Username x(u);
    Utente *temp = new UtenteBasic(u);
    temp->getInfo().setNomeDatiPersonali(n);
    temp->getInfo().setCognomeDatiPersonali(c);
    addUtente(x,temp);
    save();
}

void DB::removeUtete(const QString& u){
    Utente* user = find(u);
    set<QString> followati = user->getRete().getFollow();
    for(set<QString>::iterator it=followati.begin();it!=followati.end();++it)
    {
        for(map<QString,Utente*>::iterator itf=dbUtenti.begin();itf!=dbUtenti.end();++itf)
        {
            if((*itf).first==(*it))
                (*itf).second->rimuoviUteteRete(u);
        }
    }
    dbUtenti.erase(u);
    save();
}

void DB::updateUtente(Utente* u){
    QString user = u->getLogin().getUsername();
    map<QString,Utente*>::iterator it=dbUtenti.begin();
    for(;it!=dbUtenti.end();++it)
    {
        if(((*it).first)==user)
        {
            (*it).second = u;
            return;
        }
    }
}

void DB::upgradeUtente(const QString &u, const QString &t){
    Utente* user = find(u);
    Utente* temp;
    if(t=="Basic"){
        temp = new UtenteBasic(u);
        *temp = *user;
    }
    if(t=="Business"){
        temp = new UtenteBusiness(u);
        *temp = *user;
    }
    if(t=="Executive"){
        temp = new UtenteExecutive(u);
        *temp = *user;
    }
    removeUtete(u);
    addUtente(u,temp);
}

void DB::updateReteFollower(const QString &follow, const QString &follower){
    for(std::map<QString,Utente*>::iterator it=dbUtenti.begin();it!=dbUtenti.end();++it){
        if((*it).second->getLogin().getUsername() == follower)
        {
            (*it).second->aggiungiUtenteRete(follow);
            return;
        }
    }
}


void DB::removeReteFollower(const QString &follow,const QString &follower){
    for(std::map<QString,Utente*>::iterator it=dbUtenti.begin();it!=dbUtenti.end();++it){
        if((*it).second->getLogin().getUsername() == follower)
        {
            (*it).second->rimuoviUteteRete(follow);
            return;
        }
    }
}

bool DB::search(const QString &u){
    map<QString,Utente*>::const_iterator it=dbUtenti.begin();
    for(;it!=dbUtenti.end();++it){
        if(((*it).first)==u){
            return true;
        }
    }
    return false;
}

Utente* DB::find(const QString& u) const{
    //Utente* temp = new Utente();
    map<QString,Utente*>::const_iterator it=dbUtenti.begin();
    for(;it!=dbUtenti.end();++it){
        if(((*it).first)==u){
            return (*it).second;
        }
    }
    return 0;
}

map<QString,Utente*> DB::findUsername(const InfoSearch& info) const {
    map<QString,Utente*> trovati;
    for(map<QString,Utente*>::const_iterator it=dbUtenti.begin(); it!=dbUtenti.end();++it)
    {
        if(info.getUsername()!="" && (*it).first != info.getUsername())
            continue;
        if(info.getNome()!="" && (*it).second->getInfo().getDati().getNome() != info.getNome())
            continue;
        if(info.getCognome()!="" && (*it).second->getInfo().getDati().getCognome() != info.getCognome())
            continue;
        trovati.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
    }
    return trovati;
}

void DB::load() {
    path = ("/home/mattia/Documenti/LinQuedln/input.xml");
    QFile file(path);
    while(!file.open(QIODevice::ReadOnly)){
        QMessageBox box;
        box.setWindowTitle("Attenzione");
        box.setText("Database non trovato. Seleziona un database.");
        box.setIcon(QMessageBox::Warning);
        box.setStandardButtons(QMessageBox::Ok);
        int choose = box.exec();
        switch(choose){
            case QMessageBox::Ok:
                path = QFileDialog::getOpenFileName(0,"Open File","/home","Xml (*.xml)");
                file.setFileName(path);
        }
    }
    bool trovato=false;
    QString key,nome,cognome,email,lnascita,lresidenza,diploma,laur,type;
    QDate dnascita;
    vector<QString> lauree;
    vector<Lavoro> vlavoro;
    set<QString> rete;
    QXmlStreamReader read(&file);
    QXmlStreamReader lines(&file);
    while (!read.atEnd())
    {
        if(read.name()=="Username" && read.tokenType() != QXmlStreamReader::EndElement)
        {
            key=read.readElementText();
            read.readNextStartElement();
        }
        if(read.name()=="TipoAccount" && read.tokenType() != QXmlStreamReader::EndElement)
        {
            type=read.readElementText();
            read.readNextStartElement();
        }
        if(read.name()=="DatiAnagrafici" && read.tokenType() != QXmlStreamReader::EndElement)
        {
            read.readNextStartElement();

            nome=read.readElementText();
            read.readNextStartElement();
            cognome=read.readElementText();
            read.readNextStartElement();
            email=read.readElementText();
            read.readNextStartElement();
            dnascita=QDate::fromString(read.readElementText());
            read.readNextStartElement();
            lnascita=read.readElementText();
            read.readNextStartElement();
            lresidenza=read.readElementText();
            read.readNextStartElement();
            //std::cout<<std::endl;
            //std::cout<<nome.toStdString()<<cognome.toStdString()<<" "<<email.toStdString()<<" "<<dnascita.toString().toStdString()<<" "<<lnascita.toStdString()<<" "<<lresidenza.toStdString()<<std::endl;

        }
        if(read.name()=="Titoli_Studio" && read.tokenType() != QXmlStreamReader::EndElement)
        {
            read.readNextStartElement();
            diploma=read.readElementText();
            read.readNextStartElement();
            while(read.name()=="Laurea")
            {
                laur=read.readElementText();
                lauree.push_back(laur);
                read.readNextStartElement();
            }
            //std::cout<<std::endl;
            //std::cout<<diploma.toStdString()<<" "<<lauree.toStdString()<<endl;
        }
        if(read.name()=="Esperienze_Lavorative" && read.tokenType() != QXmlStreamReader::EndElement)
        {
            read.readNextStartElement();
            while(read.name()=="Lavoro")
            {
                read.readNextStartElement();
                QString azienda,titolo,citta;
                QDate inizio,fine;
                azienda=read.readElementText();
                read.readNextStartElement();
                titolo=read.readElementText();
                read.readNextStartElement();
                citta=read.readElementText();
                read.readNextStartElement();
                inizio=QDate::fromString(read.readElementText());
                read.readNextStartElement();
                fine=QDate::fromString(read.readElementText());

                //std::cout<<"---------"<<std::endl;
                //std::cout<<azienda.toStdString()<<" "<<titolo.toStdString()<<" "<<citta.toStdString()<<" "<<inizio.toString().toStdString()<<" "<<fine.toString().toStdString()<<endl;
                Lavoro c(azienda,titolo,citta,inizio,fine);
                vlavoro.push_back(c);
            }

        }
        if(read.name()=="Rete_Follow" && read.tokenType() != QXmlStreamReader::EndElement)
        {
            read.readNextStartElement();
            while(read.name()=="Follow")
            {
                QString follow=read.readElementText();
                rete.insert(follow);
                read.readNextStartElement();
            }
            trovato=true;
        }
        if(trovato)
        {
            DatiAnagrafici a(nome,cognome,email,dnascita,lnascita,lresidenza);
            TitoliStudio b(diploma,lauree);
            CompetenzeLavorative c(vlavoro);
            Profilo p(a,b,c);
            Rete r(rete);
            if(type=="Basic"){
                UtenteBasic* u = new UtenteBasic(key,p,r);
            addUtente(u->getLogin(),u);
            }
            if(type=="Business"){
                UtenteBusiness* u = new UtenteBusiness(key,p,r);
                addUtente(u->getLogin(),u);
            }
            if(type=="Executive"){
                UtenteExecutive* u = new UtenteExecutive(key,p,r);
                addUtente(u->getLogin(),u);
            }
            trovato=false;
            lauree.clear(); //pulire il vector
            vlavoro.clear();
            rete.clear();
        }
        read.readNextStartElement();
    }
    file.close();
}


void DB::save() {
    QFile file(path);
    file.open(QFile::WriteOnly);

    QXmlStreamWriter write(&file);
    write.setAutoFormatting(true);
    write.writeStartDocument();
    write.writeStartElement("db");
    for(std::map<QString,Utente*>::const_iterator it=dbUtenti.begin();it!=dbUtenti.end();++it)
    {
        write.writeStartElement("Utente");
        write.writeStartElement("Profilo");
        write.writeTextElement("Username",(*it).second->getLogin().getUsername());
        if(typeid(*(*it).second) == typeid(UtenteBasic))
            write.writeTextElement("TipoAccount","Basic");
        if(typeid(*(*it).second) == typeid(UtenteBusiness))
            write.writeTextElement("TipoAccount","Business");
        if(typeid(*(*it).second) == typeid(UtenteExecutive))
            write.writeTextElement("TipoAccount","Executive");
        write.writeStartElement("DatiAnagrafici");
        write.writeTextElement("Nome",(*it).second->getInfo().getDati().getNome());
        write.writeTextElement("Cognome",(*it).second->getInfo().getDati().getCognome());
        write.writeTextElement("Email",(*it).second->getInfo().getDati().getEmail());
        write.writeTextElement("Data",(*it).second->getInfo().getDati().getDataNascita().toString());
        write.writeTextElement("Luogo_Nascita",(*it).second->getInfo().getDati().getLuogoNascita());
        write.writeTextElement("Residenza",(*it).second->getInfo().getDati().getResidenza());
        write.writeEndElement();
        write.writeStartElement("Titoli_Studio");
        write.writeTextElement("Diploma",(*it).second->getInfo().getStudi().getDiploma());

        int sizeStudi=(*it).second->getInfo().getStudi().getLaurea().size();
        for (int i=0;i<sizeStudi;i++) {
            write.writeTextElement("Laurea",(*it).second->getInfo().getStudi().getLaurea()[i]);
        }
        write.writeEndElement();

        write.writeStartElement("Esperienze_Lavorative");
        int sizeLavori=(*it).second->getInfo().getLavori().getEsperienze().size();
        //OLD  for (vector<Lavoro>::iterator itl = (*it).second->info.getLavori().getEsperienze().begin(); itl != (*it).second->info.getLavori().getEsperienze().end(); itl++)
        for(int i=0;i<sizeLavori;i++)
        {
            write.writeStartElement("Lavoro");
            write.writeTextElement("Azienda",(*it).second->getInfo().getLavori().getEsperienze()[i].getAzienda());
            write.writeTextElement("Titolo",(*it).second->getInfo().getLavori().getEsperienze()[i].getTitolo());
            write.writeTextElement("Citta",(*it).second->getInfo().getLavori().getEsperienze()[i].getCitta());
            write.writeTextElement("Inizio",(*it).second->getInfo().getLavori().getEsperienze()[i].getInizio().toString());
            write.writeTextElement("Fine",(*it).second->getInfo().getLavori().getEsperienze()[i].getFine().toString());
            write.writeEndElement();
        }
        write.writeEndElement();
        write.writeEndElement();
        write.writeStartElement("Rete_Follow");


        set<QString> fol=((*it).second->getRete().getFollow());
        set<QString>::const_iterator itfollow=fol.begin();
        for(;itfollow!=fol.end();++itfollow)
            write.writeTextElement("Follow",*itfollow);

        write.writeEndElement();
        write.writeEndElement();
    }
    write.writeEndDocument();
    file.close();
}




DB::~DB() {

}
