#ifndef AGENDA_H
#define AGENDA_H
#include "evenement.h"
#include <vector>

namespace TIME{
class Agenda
{
private:
    std::vector<Evt*> tab;
public:

    class iterator{
    private:
        std::vector<Evt*>::iterator e;
        iterator(std::vector<Evt*>::iterator it): e(it){}
        friend class Agenda;
    public:
        iterator& operator++(){ ++e; return *this; }
        iterator operator++(int){ iterator old = *this; e++; return old; }
        iterator& operator--(){ --e; return *this; }
        iterator operator--(int){ iterator old = *this; e--; return old; }
        bool operator!=(const iterator it) const { return e != it.e; }
        bool operator==(const iterator it) const { return e == it.e; }
        Evt& operator*(){ return **e; }
    };

    iterator begin(){ return iterator(tab.begin()); }
    iterator end(){ return iterator(tab.end()); }

    Agenda(const Agenda&) = delete;
    Agenda& operator=(const Agenda&) = delete;

    Agenda() = default;
    virtual ~Agenda() = default;
    Agenda& operator<<(Evt& e);
    void afficher(std::ostream& f=std::cout) const;
};
}
#endif // AGENDA_H
