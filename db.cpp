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
    QString path("/home/mattia/Documenti/Linquedln/info.xml");
    QFile file(path);
    QXmlStreamWriter xmlWriter(&file);
    std::map<QString,Utente*>::iterator it=dbUtenti.begin();
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
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
    for (vector<QString>::iterator itv = (*it).second->info.studi.getLaurea().begin(); itv != (*it).second->info.studi.getLaurea().end(); itv++) {
        xmlWriter.writeTextElement("Laurea",*itv);
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("Esperienze_Lavorative");
    for (vector<Lavoro>::iterator itl = (*it).second->info.curriculum.getEsperienze().begin(); itl != (*it).second->info.curriculum.getEsperienze().end(); itl++)
    {
        xmlWriter.writeStartElement("Lavoro");
        xmlWriter.writeTextElement("Azienda",(*itl).getAzienda());
        xmlWriter.writeTextElement("Titolo",(*itl).getTitolo());
        xmlWriter.writeTextElement("Citta",(*itl).getCitta());
        xmlWriter.writeTextElement("Inizio",(*itl).getInizio().toString());
        xmlWriter.writeTextElement("Fine",(*itl).getFine().toString());
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
}
