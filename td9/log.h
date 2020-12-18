#if !defined(LOG_H)
#define LOG_H
#include "timing.h"
#include "agenda.h"
#include "evenement.h"
#include<iostream>
#include <exception>

class Log {
public:
    virtual void addEvt(const TIME::Date& d,const TIME::Horaire& h,const std::string& s)=0;
    virtual void displayLog(std::ostream& f)const=0;
};

class LogError : public std::exception
{
    std::string message;
public:
    LogError(const std::string &m): message(m){}
    const char* what() const noexcept { return message.c_str(); }
};

namespace AO { // Adaptateur d'objet
class MyLog : public Log {
    TIME::Agenda a;
public:
    void addEvt(const TIME::Date& d,const TIME::Horaire& h,const std::string& s){
        TIME::Evt1jDur e(d,s,h,TIME::Duree(0));
        if(a.begin()==a.end()) a<<e;
        else {
            TIME::Evt& dernier = *(--a.end());
            if(e<dernier) throw LogError("Erreur enregistrement log");
        }
    }
    void displayLog(std::ostream& f)const {
        for(auto it=a.begin(); it!=a.end(); ++it)
        {
            TIME::Evt1jDur& e = dynamic_cast<TIME::Evt1jDur&>(*it);
            f<<e.getDate()<<" - "<<e.getHoraire()<<" - "<<e.getDescription();
        }
    }
};
}

namespace AC { // Adaptateur de classe
class MyLog : public Log, private TIME::Agenda {
public:
    void addEvt(const TIME::Date& d,const TIME::Horaire& h,const std::string& s){
        TIME::Evt1jDur e(d,s,h,TIME::Duree(0));
        if(Agenda::begin()==Agenda::end()) operator<<(e);
        else {
            TIME::Evt& dernier = *(--Agenda::end());
            if(e<dernier) throw LogError("Erreur enregistrement log");
        }
    }
    void displayLog(std::ostream& f)const {
        for(auto it=Agenda::begin(); it!=Agenda::end(); ++it)
        {
            TIME::Evt1jDur& e = dynamic_cast<TIME::Evt1jDur&>(*it);
            f<<e.getDate()<<" - "<<e.getHoraire()<<" - "<<e.getDescription();
        }
    }
};
}

#endif
