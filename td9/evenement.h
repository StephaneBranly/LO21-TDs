#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H
#include<iostream>
#include<string>
#include"timing.h"

namespace TIME{
    class Evt{
    private:
        std::string sujet;
    public:
        Evt(const std::string& s) : sujet(s){};
        virtual ~Evt(){}
        const std::string& getDescription() const{ return sujet; }
        virtual void afficher(std::ostream& f= std::cout) const = 0;
    };


    class Evt1j : public Evt {
    private:
        Date date;

    public:
        Evt1j(const Date& d,const std::string& s):Evt(s),date(d){}
        ~Evt1j(){}
        const Date& getDate() const {return date; }
        void afficher(std::ostream& f= std::cout) const{
            f<<"Date="<<date<<" sujet="<<getDescription()<<"\n";
        }
    };

    class EvtPj : public Evt {
    private:
        Date debut;
        Date fin;

    public:
        EvtPj(const Date& d,const Date& f,const std::string& s):Evt(s),debut(d),fin(f){}
        ~EvtPj(){}
        const Date& getDateDebut() const {return debut; }
        const Date& getDateFin() const {return fin; }
        void afficher(std::ostream& f= std::cout) const{
            f<<"Debut="<<debut<<", fin="<<fin<<" | sujet="<<getDescription()<<"\n";
        }
    };

    class Evt1jDur : public Evt1j
    {
    private:
        Horaire debut;
        Duree duree;
    public:
        Evt1jDur(const Date& d, const std::string& s, const Horaire& h, const Duree& dur):Evt1j(d,s),debut(h),duree(dur){  };
        ~Evt1jDur(){ }
        const Horaire& getHoraire() const { return debut; }
        const Duree& getDuree() const { return duree; }
        void afficher(std::ostream& f= std::cout) const {
            f<<"Date:"<<getDate()<<" a "<<debut<<" duree="<<duree<<"  | sujet: "<<getDescription()<<"\n";
        }
    };

    class Rdv : public Evt1jDur
    {
        std::string lieu;
        std::string personnes;
    public:
        Rdv(const Date& d, const std::string& s, const Horaire& h, const Duree& dur, const std::string& l, const std::string& p ):Evt1jDur(d,s,h,dur),lieu(l),personnes(p)
        {
//            std::cout << "\nConstruction Rdv : " << this << "\n";
        };
        ~Rdv(){}
        const std::string& getPersonnes() const { return personnes ;}
        const std::string& getLieu() const { return lieu ; }
        void afficher(std::ostream& f= std::cout) const {
            f<<"Date:"<<getDate()<<" a "<<getHoraire()<<" duree="<<getDuree()<<" ("<<lieu<<") | sujet: "<<getDescription()<<"   Personnes presentes :"<<personnes<<"\n";
        }
    };
}


std::ostream& operator<<(std::ostream&, const TIME::Evt&);

#endif
