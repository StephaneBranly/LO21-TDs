#include "iostream"

#include "agenda.h"
#include "evenement.h"
#include <vector>

std::ostream& operator<<(std::ostream& f, const TIME::Evt1j& e){
    e.afficher(f);  // appelle d'une methode polymorphique
    return f;
};

TIME::Agenda& TIME::Agenda::operator<<(TIME::Evt1j& e)
{
     tab.push_back(&e);
     return *this;
}


 void TIME::Agenda::afficher(std::ostream& f) const
 {
     for(std::vector<TIME::Evt1j*>::const_iterator it = tab.begin();it != tab.end(); ++it)
     {
         f<<(*it);
//         it->afficher(f);
     }
 }
