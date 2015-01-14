#include "db.h"
#include<iostream>
DB::DB()
{
}

void DB::addUtente(Username u,Utente* p){
    dbUtenti.insert(map<QString,Utente*>::value_type(u.getUsername(),p));
}

void DB::removeUtete(Username u){
    dbUtenti.erase(u.getUsername());
    //eliminare utete dalla rete amici.
}

void DB::load() {
    QString path("/home/mattia/Documenti/Linquedln/prova.xml");
    QFile file(path);
    /*bool open = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!open) {
        std::cout << "Couldn't open file" << std::endl;
        return;
    }
    else
        std::cout << "File opened OK" << std::endl;
    */
    file.open(QFile::ReadOnly);
    QXmlStreamReader read(&file);
    read.readNext();
    QString key;
    DatiAnagrafici a;
    TitoliStudio b;
    Lavoro c;
    std::map<QString,Utente*>::iterator it=dbUtenti.begin();
    //while (!read.isEndDocument())
    //{
    read.readNext();
        if (read.isStartElement())
        {
            std::cout<<read.name().toString().toStdString()<<std::endl;
            read.readNext();
            read.readNext();
            std::cout<<read.name().toString().toStdString()<<std::endl;
            read.readNext();
            read.readNext();
            std::cout<<read.name().toString().toStdString()<<std::endl;
            if(read.name()=="Username")
            {
                key=read.readElementText();
                std::cout<<key.toStdString()<<std::endl;
                //(*it).second->login.setUsername(read.readElementText());
            }
            read.readNext();
            read.readNext();
            std::cout<<read.name().toString().toStdString()<<std::endl;

            if(read.name()=="DatiAnagrafici")
            {

                read.readNext();
                read.readNext();
                QString nome,cognome,email,lnascita,lresidenza;
                QDate dnascita;
                std::cout<<read.name().toString().toStdString()<<std::endl;
                nome=read.readElementText();
                std::cout<<nome.toStdString()<<std::endl;
                read.readNext();
                read.readNext();
                std::cout<<read.name().toString().toStdString()<<std::endl;
                cognome=read.readElementText();
                std::cout<<cognome.toStdString()<<std::endl;
                read.readNext();
                read.readNext();
                std::cout<<read.name().toString().toStdString()<<std::endl;
                email=read.readElementText();
                std::cout<<email.toStdString()<<std::endl;
                read.readNext();
                read.readNext();
                std::cout<<read.name().toString().toStdString()<<std::endl;
                dnascita=QDate::fromString(read.readElementText());
                std::cout<<dnascita.toString().toStdString()<<std::endl;
                read.readNext();
                read.readNext();
                std::cout<<read.name().toString().toStdString()<<std::endl;
                lnascita=read.readElementText();
                std::cout<<lnascita.toStdString()<<std::endl;
                read.readNext();
                read.readNext();
                std::cout<<read.name().toString().toStdString()<<std::endl;
                lresidenza=read.readElementText();
                std::cout<<lresidenza.toStdString()<<std::endl;
                read.readNext();
                read.readNext();
                read.readNext();
                read.readNext();
                std::cout<<read.name().toString().toStdString()<<std::endl;
                DatiAnagrafici a1(nome,cognome,email,dnascita,lnascita,lresidenza);
                a=a1;
            }
            if(read.name()=="Titoli_Studio")
            {
                read.readNext();
                read.readNext();

                QString diploma;
                QString lauree;
                std::cout<<read.name().toString().toStdString()<<std::endl;

                diploma=read.readElementText();
                std::cout<<diploma.toStdString()<<std::endl;
                read.readNext();
                read.readNext();
                std::cout<<read.name().toString().toStdString()<<std::endl;

                while(!read.isEndElement())
                {
                    lauree=read.readElementText();
                    std::cout<<lauree.toStdString()<<std::endl;
                    read.readNext();
                    read.readNext();
                }
                TitoliStudio b1(diploma,lauree);
                b=b1;
            }
            read.readNext();
            read.readNext();
            //std::cout<<read.name().toString().toStdString()<<std::endl;

            if(read.name()=="Esperienze_Lavorative")
            {
                //while(!read.isEndElement())
                //{
                    read.readNext();
                    read.readNext();
                     std::cout<<read.name().toString().toStdString()<<std::endl;

                    if(read.name()=="Lavoro")
                    {
                        read.readNext();
                        read.readNext();
                        std::cout<<read.name().toString().toStdString()<<std::endl;
                        QString azienda,titolo,citta;
                        QDate inizio,fine;
                        azienda=read.readElementText();
                        std::cout<<azienda.toStdString()<<std::endl;
                        read.readNext();
                        read.readNext();
                        std::cout<<read.name().toString().toStdString()<<std::endl;
                        titolo=read.readElementText();
                        std::cout<<titolo.toStdString()<<std::endl;
                        read.readNext();
                        read.readNext();
                        std::cout<<read.name().toString().toStdString()<<std::endl;
                        citta=read.readElementText();
                        std::cout<<citta.toStdString()<<std::endl;
                        read.readNext();
                        read.readNext();
                        std::cout<<read.name().toString().toStdString()<<std::endl;
                        inizio=QDate::fromString(read.readElementText());

                        std::cout<<read.lineNumber()<<std::endl;


                        std::cout<<inizio.toString().toStdString()<<std::endl;
                        std::cout<<read.name().toString().toStdString()<<std::endl;

                        std::cout<<read.lineNumber()<<std::endl;
                        read.readNext();
                        std::cout<<read.lineNumber()<<std::endl;

                        fine=QDate::fromString(read.readElementText());
                        std::cout<<fine.toString().toStdString();
                        Lavoro l2(azienda,titolo,citta,inizio,fine);
                        c=l2;
                    }

                //}

            }
        }
        //else
        /*if (read.isEndElement())
        {
            read.readNext();
        }
        */
        CompetenzeLavorative d(c);
        Profilo p;
        p.datiPersonali=a;
        p.studi=b;
        p.curriculum=d;
        Utente u;
        u.login=key;
        u.info=p;
        Utente *punt=&u;
        std::cout<<"ciao"<<u.login.getUsername().toStdString();
        //addUtente(u.login,punt);
        ++it;
    }



void DB::save() const {
    QString path("/home/mattia/Documenti/Linquedln/output.xml");
    QFile file(path);
    qint64 s = file.size();
    if (s > 0) {
        file.open(QFile::ReadWrite);
        if (file.seek(s))
            Q_ASSERT(file.pos() == s);
    }
    else
        file.open(QFile::WriteOnly);
    /*bool open = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!open)
    {
        std::cout << "Couldn't open file" << std::endl;
        return;
    }
    else
    {
        std::cout << "File opened OK" << std::endl;
    }
    */
    QXmlStreamWriter write(&file);
    write.setAutoFormatting(true);
    if (s == 0) {
        write.writeStartDocument();
    }
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

        /*OLD
        for (vector<QString>::iterator itv = (*it).second->info.studi.getLaurea().begin(); itv != (*it).second->info.studi.getLaurea().end(); ++itv) {
            write.writeTextElement("Laurea",*itv);
        }
        */
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
        write.writeEndElement();
        if (s == 0) {
            write.writeEndDocument();
        }
    }
}

DB::~DB() {

}
