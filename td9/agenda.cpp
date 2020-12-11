#include "iostream"

#include "agenda.h"
#include "evenement.h"
#include <vector>

std::ostream& operator<<(std::ostream& f, const TIME::Evt& e){
    e.afficher(f);  // appelle d'une methode polymorphique
    return f;
};

TIME::Agenda& TIME::Agenda::operator<<(TIME::Evt& e)
{
     tab.push_back(&e);
     return *this;
}


 void TIME::Agenda::afficher(std::ostream& f) const
 {
//     for(std::vector<TIME::Evt*>::const_iterator it = tab.begin();it != tab.end(); ++it)
//         f<<(**it);
    for(auto e : tab) f<<*e;
 }
