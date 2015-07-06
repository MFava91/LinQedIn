#ifndef INFOSEARCH_H
#define INFOSEARCH_H
#include <QString>

class InfoSearch
{
private:
    QString username;
    QString nome;
    QString cognome;
    QString luogoNascita;
    QString residenza;
    QString diploma;
    QString laurea;
    QString lavoro;
    QString titolo;
public:
    InfoSearch(const QString& = "",const QString& = "",const QString& = "",
               const QString& = "",const QString& = "",const QString& = "",
               const QString& = "",const QString& = "",const QString& = "");
    void setUsername(const QString&);
    void setNome(const QString&);
    void setCognome(const QString&);
    void setLuogoNascita(const QString&);
    void setResidenza(const QString&);
    void setDiploma(const QString&);
    void setLaurea(const QString&);
    void setAzienda(const QString&);
    void setTitolo(const QString&);
    QString getUsername() const;
    QString getNome() const;
    QString getCognome() const;
    QString getLuogoNascita() const;
    QString getResidenza() const;
    QString getDiploma() const;
    QString getLauree() const;
    QString getAzienda() const;
    QString getTitolo() const;
};

#endif // INFOSEARCH_H
