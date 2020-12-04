#include "iostream"

#include "agenda.h"
#include "evenement.h"
#include <vector>

TIME::Agenda& TIME::Agenda::operator<<(TIME::Evt1j& e)
{
     tab.push_back(e);
     return *this;
}


 void TIME::Agenda::afficher(std::ostream& f) const
 {
     for(std::vector<TIME::Evt1j>::const_iterator it = tab.begin();it != tab.end(); ++it)
     {
         it->afficher(f);
     }
 }
