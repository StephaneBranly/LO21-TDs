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
    Agenda(const Agenda&) = delete;
    Agenda& operator=(const Agenda&) = delete;

    Agenda() = default;
    virtual ~Agenda() = default;
    Agenda& operator<<(Evt& e);
    void afficher(std::ostream& f=std::cout) const;
};
}
#endif // AGENDA_H
