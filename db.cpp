#include "db.h"
#include<iostream>

using std::cout;
using std::endl;

DB::DB()
{
}

void DB::addUtente(Username u,Utente* p){
    dbUtenti.insert(map<QString,Utente*>::value_type(u.getUsername(),p));
}

void DB::removeUtete(Username u){
    for(std::map<QString,Utente*>::iterator it=dbUtenti.begin();it!=dbUtenti.end();++it)
    {
        for(std::set<QString>::iterator itf=(*it).second->rete.getFollow().begin();itf!=(*it).second->rete.getFollow().end();++itf)
        {
            if((*itf)==u.getUsername())
                (*it).second->rete.removeFollow(u);
        }
    }
    dbUtenti.erase(u.getUsername());

    //eliminare utete dalla rete amici.
}

void DB::load() {
    QString path("/home/mattia/Documenti/Linquedln/prova.xml");
    QFile file(path);
    bool trovato=false;
    file.open(QIODevice::ReadOnly);
    QString key,nome,cognome,email,lnascita,lresidenza,diploma,laur;
    QDate dnascita;
    vector<QString> lauree;
    vector<Lavoro> vlavoro;
    QXmlStreamReader read(&file);
    //QXmlStreamReader lines(&file);
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
            trovato=true;
        }
        if(trovato)
        {
            DatiAnagrafici a(nome,cognome,email,dnascita,lnascita,lresidenza);
            TitoliStudio b(diploma,lauree);
            CompetenzeLavorative c(vlavoro);
            Profilo p;
            p.datiPersonali=a;
            p.studi=b;
            p.curriculum=c;
            Utente* u=new Utente();
            u->login=key;
            u->info=p;
            //cout<<u->login.getUsername().toStdString();
            addUtente(u->login,u);
            trovato=false;
            lauree.clear(); //pulire il vector
            vlavoro.clear();
        }
        read.readNextStartElement();
    }
    file.close();
    //++it;
}


void DB::save() {
    QString path("/home/mattia/Documenti/Linquedln/output.xml");
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
        write.writeTextElement("Username",(*it).second->login.getUsername());
        write.writeStartElement("DatiAnagrafici");
        write.writeTextElement("Nome",(*it).second->info.datiPersonali.getNome());
        write.writeTextElement("Cognome",(*it).second->info.datiPersonali.getCognome());
        write.writeTextElement("Email",(*it).second->info.datiPersonali.getEmail());
        write.writeTextElement("Data",(*it).second->info.datiPersonali.getDataNascita().toString());
        write.writeTextElement("Luogo_Nascita",(*it).second->info.datiPersonali.getLuogoNascita());
        write.writeTextElement("Residenza",(*it).second->info.datiPersonali.getResidenza());
        write.writeEndElement();
        write.writeStartElement("Titoli_Studio");
        write.writeTextElement("Diploma",(*it).second->info.studi.getDiploma());

        int sizeStudi=(*it).second->info.studi.getLaurea().size();
        for (int i=0;i<sizeStudi;i++) {
            write.writeTextElement("Laurea",(*it).second->info.studi.getLaurea()[i]);
        }
        write.writeEndElement();

        write.writeStartElement("Esperienze_Lavorative");
        int sizeLavori=(*it).second->info.curriculum.getEsperienze().size();
        //OLD  for (vector<Lavoro>::iterator itl = (*it).second->info.curriculum.getEsperienze().begin(); itl != (*it).second->info.curriculum.getEsperienze().end(); itl++)
        for(int i=0;i<sizeLavori;i++)
        {
            write.writeStartElement("Lavoro");
            write.writeTextElement("Azienda",(*it).second->info.curriculum.getEsperienze()[i].getAzienda());
            write.writeTextElement("Titolo",(*it).second->info.curriculum.getEsperienze()[i].getTitolo());
            write.writeTextElement("Citta",(*it).second->info.curriculum.getEsperienze()[i].getCitta());
            write.writeTextElement("Inizio",(*it).second->info.curriculum.getEsperienze()[i].getInizio().toString());
            write.writeTextElement("Fine",(*it).second->info.curriculum.getEsperienze()[i].getFine().toString());
            write.writeEndElement();
        }
        write.writeEndElement();
        write.writeEndElement();
        /*
        write.writeStartElement("RetiFollow");
        QString temp,tempp;
        for(std::set<QString>::iterator itfollow=(*it).second->rete.getFollow().begin();itfollow!=(*it).second->rete.getFollow().end();++itfollow)
        {
            temp=(*itfollow);
            std::cout<<temp.toStdString()<<" ";
            //write.writeTextElement("Follow",temp);

        }
        write.writeTextElement("Follow",temp);
        write.writeEndElement();
        */
    }
    write.writeEndElement();
    write.writeEndDocument();
    file.close();
}




DB::~DB() {

}
