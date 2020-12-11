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
    class const_iterator : public std::vector<Evt*>::const_iterator
    {
        friend class Agenda;
        const_iterator (std::vector<Evt*>::const_iterator it) : std::vector<Evt*>::const_iterator(it){}
    public:
        Evt& operator*() const {return *std::vector<Evt*>::const_iterator::operator*();}
    };

    iterator begin(){ return iterator(tab.begin()); }
    iterator end(){ return iterator(tab.end()); }

    const_iterator begin() const { return const_iterator(tab.begin());}
    const_iterator end() const { return const_iterator(tab.end());}
    Agenda(const Agenda&) = delete;
    Agenda& operator=(const Agenda&) = delete;

    Agenda() = default;
    virtual ~Agenda() = default;
    Agenda& operator<<(Evt& e);
    void afficher(std::ostream& f=std::cout) const;
};
}
#endif // AGENDA_H
