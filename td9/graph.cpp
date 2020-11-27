#include "graph.h"
#include<list>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

size_t Graph::getNbVertices() const
{
    return adj.size();
};
size_t Graph::getNbEdges() const
{
    size_t nb = 0;
    for(vector<list<unsigned int>>::const_iterator it = adj.begin(); it != adj.end(); ++it)
        nb += it->size();

//    for(auto& l : adj) nb += l.size();

    return nb;
};
void Graph::addEdge(unsigned int i,unsigned int j)
{
    if(i>=adj.size() || j>=adj.size()) throw GraphException("Un des edges est non defini.");

    if(find(adj[i].begin(),adj[i].end(),j)==adj[i].end())
        adj[i].push_back(j);
    else
        throw GraphException("Arc deja existant.");
}
void Graph::removeEdge(unsigned int i,unsigned int j)
{
    if(i>=adj.size() || j>=adj.size()) throw GraphException("Un des edges est non defini.");

   /* if(find(adj.begin(),adj.end(),j)!=adj.end())
        adj[i].remove(j);
    else
        throw GraphException("Arc non existant.")*/;
    auto it = find(adj[i].begin(),adj[i].end(),j);
    if(it!=adj[i].end()) adj[i].erase(it);
    else throw GraphException("Arc non existant/");
}
const list<unsigned int>& Graph::getSuccessors(unsigned int i) const
{
    if(i>=adj.size()) throw GraphException("Edge non defini.");
    return adj[i];
}
const list<unsigned int> Graph::getPredecessors(unsigned int i) const
{
    if(i>=adj.size()) throw GraphException("Edge non defini.");
    list<unsigned int> pred;
    for(size_t j=0; j < adj.size(); j++)
            if(find(adj[j].begin(),adj[j].end(),i) != adj[j].end()) pred.push_back(j);

    return pred;
}


ostream&operator<<(ostream& f,const Graph& G)
{
    f<< "graphe" << G.getName() << "\n";
    for(size_t i = 0; i < G.getNbVertices(); i++)
    {
        f << i << ":";
        for(auto& j : G.getSuccessors(i)) f << j << " ";
        f << "\n";
    }
    return f;
}
