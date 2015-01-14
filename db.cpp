#include "db.h"

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

void DB::save() {
    QString path("/home/mattia/Documenti/Linquedln/prova.xml");
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
    for(std::map<QString,Utente*>::iterator it=dbUtenti.begin();it!=dbUtenti.end();++it)
    {
        write.writeStartElement("Utente");
        write.writeStartElement("Profilo");
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
