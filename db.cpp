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
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    if (s == 0) {
        xmlWriter.writeStartDocument();
    }
    for(std::map<QString,Utente*>::iterator it=dbUtenti.begin();it!=dbUtenti.end();++it)
    {
        xmlWriter.writeStartElement("Utente");
        xmlWriter.writeStartElement("Profilo");
        xmlWriter.writeStartElement("DatiAnagrafici");
        xmlWriter.writeTextElement("Nome",(*it).second->info.datiPersonali.getNome());
        xmlWriter.writeTextElement("Cognome",(*it).second->info.datiPersonali.getCognome());
        xmlWriter.writeTextElement("Email",(*it).second->info.datiPersonali.getEmail());
        xmlWriter.writeTextElement("Data",(*it).second->info.datiPersonali.getDataNascita().toString());
        xmlWriter.writeTextElement("Luogo_Nascita",(*it).second->info.datiPersonali.getLuogoNascita());
        xmlWriter.writeTextElement("Residenza",(*it).second->info.datiPersonali.getResidenza());
        xmlWriter.writeEndElement();
        xmlWriter.writeStartElement("Titoli_Studio");
        xmlWriter.writeTextElement("Diploma",(*it).second->info.studi.getDiploma());

        int sizeStudi=(*it).second->info.studi.getLaurea().size();
        for (int i=0;i<sizeStudi;i++) {
            xmlWriter.writeTextElement("Laurea",(*it).second->info.studi.getLaurea()[i]);
        }

        /*OLD
        for (vector<QString>::iterator itv = (*it).second->info.studi.getLaurea().begin(); itv != (*it).second->info.studi.getLaurea().end(); ++itv) {
            xmlWriter.writeTextElement("Laurea",*itv);
        }
        */
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("Esperienze_Lavorative");
        int sizeLavori=(*it).second->info.curriculum.getEsperienze().size();

        //OLD  for (vector<Lavoro>::iterator itl = (*it).second->info.curriculum.getEsperienze().begin(); itl != (*it).second->info.curriculum.getEsperienze().end(); itl++)
        for(int i=0;i<sizeLavori;i++)
        {

            xmlWriter.writeStartElement("Lavoro");
            xmlWriter.writeTextElement("Azienda",(*it).second->info.curriculum.getEsperienze()[i].getAzienda());
            xmlWriter.writeTextElement("Titolo",(*it).second->info.curriculum.getEsperienze()[i].getTitolo());
            xmlWriter.writeTextElement("Citta",(*it).second->info.curriculum.getEsperienze()[i].getCitta());
            xmlWriter.writeTextElement("Inizio",(*it).second->info.curriculum.getEsperienze()[i].getInizio().toString());
            xmlWriter.writeTextElement("Fine",(*it).second->info.curriculum.getEsperienze()[i].getFine().toString());
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
        if (s == 0) {
            xmlWriter.writeEndDocument();
        }
    }
}
