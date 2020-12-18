#include "evenement.h"

TIME::Date TIME::getDate(const TIME::Evt& e){

    using namespace TIME;
    if(const Evt1j* pt = dynamic_cast<const Evt1j*>(&e)) return pt->getDate();
    if(const EvtPj* pt = dynamic_cast<const EvtPj*>(&e)) return pt->getDateDebut();
}

bool TIME::operator<(const Evt& e1, const Evt& e2)
{
    if(getDate(e1)<getDate(e2)) return true;
    if(getDate(e2)<getDate(e1)) return false;

    const Evt1jDur* pt1 = dynamic_cast<const Evt1jDur*>(&e1);
    const Evt1jDur* pt2 = dynamic_cast<const Evt1jDur*>(&e2);
    if(pt1!=nullptr && pt2!=nullptr) return pt1->getHoraire()<pt2->getHoraire();

    return false;
}

