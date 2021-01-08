#ifndef GRAPH2_H
#define GRAPH2_H


#include<map>
#include<set>
#include<string>
#include <iostream>

using namespace std;
template<class Vertex>
class GraphG {
    map<Vertex,set<Vertex> > adj;
    string name;
public:
    GraphG(const string& n):name(n){};
    const string& getName() const { return name; };
    size_t getNbVertices()const { return adj.size(); };
    size_t getNbEdges()const {
        size_t n = 0;
        for(auto& v: adj) n+=v.second.size();
        return n;
    };
    void addVertex(const Vertex& i) { adj[i]; };
    void addEdge(const Vertex& i,const Vertex& j) { adj[i].insert(j); adj[j]; };
    void removeEdge(const Vertex& i,const Vertex& j)
    {
        auto it = adj.find(i);
        if (it==adj.end() || it->erase(j)==0) throw "erreur";
    }

    void removeVertex(const Vertex& i);
    void print(ostream& f)const;


};

template<class V> ostream&operator<<(ostream& f,const GraphG<V>& G);



template<class Vertex>
void GraphG<Vertex>::removeVertex(const Vertex& i)
{
    adj.erase(i); // elimine i est son ensemble de successeurs
    for(auto& ve : adj) ve.second.erase(i);
}

template<class Vertex>
void GraphG<Vertex>::print(ostream& f)const{
    f << getName() << "\n";
    for(auto& ve : adj){
        f<<ve.first<<" : ";
        for(auto& su : ve.second)
            f<<su<<" ; ";

        f << "\n";
    }
}

#endif // GRAPH2_H
