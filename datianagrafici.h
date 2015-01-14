#ifndef DATIANAGRAFICI_H
#define DATIANAGRAFICI_H

#include<iostream>
#include<QString>
#include<QDate>

class DatiAnagrafici
{
private:
    QString nome;
    QString cognome;
    QString email;
    QDate dataNascita;
    QString luogoNascita;
    QString residenza;
public:
    //Costruttore
    DatiAnagrafici();
    DatiAnagrafici(const QString&,const QString&,const QString&,const QDate&,const QString&,const QString&);
    //Controlli
    bool operator==(const DatiAnagrafici&) const;
    //Assegnazione
    DatiAnagrafici operator=(const DatiAnagrafici&);
    //bool operator!=(const DatiAnagrafici&) const;
    //Selettori
    QString getNome() const;
    QString getCognome() const;
    QString getEmail() const;
    QDate getDataNascita() const;
    QString getLuogoNascita() const;
    QString getResidenza() const;

    void setNome(const QString&);
    void setCognome(const QString&);
    void setEmail(const QString&);
    void setDataNascita(const QDate&);
    void setLuogoNascita(const QString&);
    void setResidenza(const QString&);
    //distruttore standard
};

#endif // DATIANAGRAFICI_H
