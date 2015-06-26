#include "db.h"
#include<iostream>

using std::cout;
using std::endl;
using std::set;

DB::DB()
{
}

void DB::addUtente(Username u,Utente* p){
    dbUtenti.insert(map<QString,Utente*>::value_type(u.getUsername(),p));
}

void DB::removeUtete(Username u){
    for(std::map<QString,Utente*>::iterator it=dbUtenti.begin();it!=dbUtenti.end();++it)
    {
        for(std::set<QString>::iterator itf=(*it).second->getRete().getFollow().begin();itf!=(*it).second->getRete().getFollow().end();++itf)
        {
            if((*itf)==u.getUsername())
                (*it).second->getRete().removeFollow(u);
        }
    }
    dbUtenti.erase(u.getUsername());

    //eliminare utete dalla rete amici.
}

void DB::updateUtente(Utente* u){
    QString user = u->getLogin().getUsername();
    bool trovato=false;
    map<QString,Utente*>::iterator it=dbUtenti.begin();
    for(;it!=dbUtenti.end() && !trovato ;++it)
    {
        if(((*it).first)==user)
        {
            (*it).second = u;
            trovato=true;
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
    Utente* temp = new Utente();
    map<QString,Utente*>::const_iterator it=dbUtenti.begin();
    for(;it!=dbUtenti.end();++it){
        if(((*it).first)==u){
            temp=(*it).second;
            return temp;
        }
    }
    return 0;
}

void DB::load() {
    QString path("/home/mattia/Documenti/LinQuedln/input.xml");
    QFile file(path);
    bool trovato=false;
    file.open(QIODevice::ReadOnly);
    QString key,nome,cognome,email,lnascita,lresidenza,diploma,laur;
    QDate dnascita;
    vector<QString> lauree;
    vector<Lavoro> vlavoro;
    set<QString> rete;
    QXmlStreamReader read(&file);
    QXmlStreamReader lines(&file);
    /*
    while (!lines.isEndDocument() && !lines.hasError())
    {
        cout<<lines.lineNumber()<<" ";
        lines.readNext();
        lines.readNext();
    }
    */
    //std::map<QString,Utente*>::iterator it=dbUtenti.begin();
    while (!read.atEnd() /*&& !read.hasError()*/)
    {
        if(read.name()=="Username" && read.tokenType() != QXmlStreamReader::EndElement)
        {
            key=read.readElementText();
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
            Utente* u=new Utente(key,p,r);
            //cout<<u->login.getUsername().toStdString();
            addUtente(u->getLogin(),u);
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
    QString path("/home/mattia/Documenti/LinQuedln/input.xml");
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
