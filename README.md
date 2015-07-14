#LinQedln
Progetto per il corso Programmazione ad Oggetti, Università degli studi di Padova, anno 2014/2015

**Compilazione**

Per la compilazione dell'applicativo con Qt5.3.2 eseguire i seguenti comandi:
```
  qmake-qt532 -project
```
Nel file .pro generato aggiungere nell'intestazione:
```
  QT += widgets
```
Dopo avere salvato le modifiche apportate, da terminale eseguite:
```
  qmake-qt532
  make
```  
Troverete così l'eseguibile del prodotto.
