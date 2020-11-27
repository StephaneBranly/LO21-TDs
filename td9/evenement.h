#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H
#include<iostream>
#include<string>
#include"timing.h"

namespace TIME{
    class Evt1j {
    private:
        Date date;
        std::string sujet;
    public:
        Evt1j(const Date& d,const std::string& s):date(d),sujet(s){}
        const std::string& getDescription() const{return sujet; }
        const Date& getDate() const {return date; }
        void afficher(std::ostream& f= std::cout) const{
            f<<"*****Evt********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
        }
    };

    class Evt1jDur : public Evt1j
    {
    private:
        Horaire debut;
        Duree duree;
    public:
        Evt1jDur(const Date& d, const std::string& s, const Horaire& h, const Duree& dur):Evt1j(d,s),debut(h),duree(dur){};
        const Horaire& getHoraire() const { return debut; }
        const Duree& getDuree() const { return duree; }
        void afficher(std::ostream& f= std::cout) const {
            f<<"*****Evt********"<<"\n"<<"Date:"<<getDate()<<" a "<<debut<<" duree="<<duree<<"  | sujet: "<<getDescription()<<"\n\n";
        }
    };

    class Rdv : public Evt1jDur
    {
        std::string lieu;
        std::string personnes;
    public:
        Rdv(const Date& d, const std::string& s, const Horaire& h, const Duree& dur, const std::string& l, const std::string& p ):Evt1jDur(d,s,h,dur),lieu(l),personnes(p){};
        const std::string& getPersonnes() const { return personnes ;}
        const std::string& getLieu() const { return lieu ; }
        void afficher(std::ostream& f= std::cout) const {
            f<<"*****Evt********"<<"\n"<<"Date:"<<getDate()<<" a "<<getHoraire()<<" duree="<<getDuree()<<" ("<<lieu<<") | sujet: "<<getDescription()<<"   Personnes presentes :"<<personnes<<"\n\n";
        }
    };
}
#endif
