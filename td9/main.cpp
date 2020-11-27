#include "graph.h"
#include "timing.h"
#include "evenement.h"
#include<iostream>

using namespace std;
using namespace TIME;
int main(int argc, char *argv[])
{
    // EXO 31
//   try{
//        Graph G1("G1",5);
//        cout<<G1;
//        G1.addEdge(0,1);
//        G1.addEdge(0,2);
//        G1.addEdge(1,2);
//        G1.addEdge(1,3);
//        G1.addEdge(1,4);
//        G1.addEdge(3,0);
//        cout<<G1;
//    }catch(exception e)
//    {
//        std::cout<<e.what()<<"\n";
//    }

    Evt1j e1(Date(4,10,1957),"Spoutnik");
    Evt1j e2(Date(11,6,2013),"Shenzhou");
    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(0,10));
    e1.afficher();
    e2.afficher();
    e3.afficher();

    Rdv e(Date(11,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    std::cout<<"RDV:";
    e.afficher();

    return 0;
}
