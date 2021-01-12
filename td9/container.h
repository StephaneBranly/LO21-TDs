#ifndef CONTAINER_H
#define CONTAINER_H

#include<string>
#include<stdexcept>
namespace TD {
class ContainerException :public std::exception
{
protected:std::string info;
public:ContainerException(const std::string& i="") noexcept :info(i){}
    const char*what() const noexcept { return info.c_str(); }
    ~ContainerException() noexcept {}
};

template <class T>
class Container
{
protected:
    unsigned int nbEl;
public:
    Container(unsigned int n):nbEl(n){};
    unsigned int size() const { return nbEl; }
    bool empty() const { return nbEl==0; }
    virtual T & element(unsigned int i) = 0;
    virtual const T & element(unsigned int i) const = 0;
    virtual void push_back(const T & x) = 0;
    virtual void pop_back() = 0;

    virtual T & front();
    virtual const T & front() const;
    virtual T & back();
    virtual const T & back() const;
    virtual void clear();

    virtual ~Container() = default;
};


template <class T>
class Vector : public Container<T>
{
    T * tab;
    unsigned int cap; // nombre maximum d'elements que l'on peut stocker


public:
    Vector(unsigned int n=0, const T & x = T());
    ~Vector(){ delete[] tab; };
    Vector(const Vector<T> & v);
    Vector<T> & operator=(const Vector<T> & v);

    T & element(unsigned int i);
    const T & element(unsigned int i) const;
    void push_back(const T & x);
    void pop_back();
    void clear();
    T & operator[](unsigned int i){ return tab[i]; };
    const T & operator[](unsigned int i) const { return tab[i]; };

    class iterator{
        T* current;
        iterator(T* init): current(init){};
        friend class Vector<T>;
    public:

        T& operator*() const { return *current; };
        iterator& operator++(){ current++; return *this; };
        bool operator==(iterator it) const { return *it==current; };
        bool operator!=(iterator it) const { return *it!=current; };
    };
    iterator& begin(){ return iterator(tab[0]); }
    iterator& end(){ return iterator(tab[this->size()]); }
};


// Adaptateur de classe
template<class T, class CONT=Vector<T>>
class Stack1 : private CONT {
public:
    Stack1() : CONT(0){};
    using CONT::empty;
    void push(const T& x) { CONT::push_back(x); };
    void pop() { CONT::pop_back(); };
    using CONT::size;
    T& top() { return CONT::back(); };
    const T& top() const { return CONT::back(); };
    using CONT::clear;

    // iterator est un type qui depend d'un parametre de type
    using iterator = typename CONT::iterator;
    using CONT::begin;
    using CONT::end;
};

// Adaptateur d'objet
template<class T, class CONT=Vector<T>>
class Stack2{
    CONT cont;
public:
    Stack2(): cont(0){};
    bool empty() const { return cont.empty(); };
    void push(const T& x) { cont.push_back(x); };
    void pop() { cont.pop_back(); };
    unsigned int size() const { return cont.size(); };
    T& top() { return cont.front(); };
    const T& top() const { return cont.front(); };
    void clear() { cont.clear(); };

    // iterator est un type qui depend d'un parametre de type
    using iterator = typename CONT::iterator;
    iterator begin() { return cont.begin(); }
    iterator end() { return cont.end(); }
};
}






template<class T> T& TD::Container<T>::front(){
    if(this->empty())
        throw ContainerException("Conteneur vide");
    return element(0);
};

template<class T> const T& TD::Container<T>::front() const{
    if(this->empty())
        throw ContainerException("Conteneur vide");
    return element(0);
};

template<class T> T& TD::Container<T>::back(){
    if(empty())
        throw ContainerException("Conteneur vide");
    return element(nbEl-1);
};

template<class T> const T& TD::Container<T>::back() const{
    if(empty())
        throw ContainerException("Conteneur vide");
    return element(nbEl-1);
};

template<class T> void TD::Container<T>::clear(){
    while(!empty()) pop_back();
}


template<class T> TD::Vector<T>::Vector(unsigned int n, const T & x):
    Container<T>(n),
    tab(new T[n]),
    cap(n)
{
    for(unsigned int i=0; i<Container<T>::nbEl ;i++) tab[i]=x;
}

template<class T> T & TD::Vector<T>::element(unsigned int i){
    if(i<Container<T>::nbEl)
        throw ContainerException("Indice invalide");
    return tab[i];
}
template<class T> const T & TD::Vector<T>::element(unsigned int i) const{
    if(i<Container<T>::nbEl)
        throw ContainerException("Indice invalide");
    return tab[i];
}

template<class T> void TD::Vector<T>::push_back(const T & x)
{
    if(Container<T>::nbEl == cap)
    {
        T * newtab = new T[cap*2+1];
        for(unsigned int i=0;
            i<Container<T>::nbEl;
            i++)
            newtab[i]=tab[i];
        delete[] tab;
        tab = newtab;
        cap = cap*2+1;
    }
    tab[Container<T>::nbEl] = x;
    Container<T>::nbEl++;
}

template<class T> void TD::Vector<T>::pop_back()
{
    if(this->empty())
        throw ContainerException("Conteneur deja vide");
    Container<T>::nbEl--;
}

template<class T> void TD::Vector<T>::clear()
{
    Container<T>::nbEl=0;
}

template<class T> TD::Vector<T>::Vector(const TD::Vector<T> & v):
    Container<T>(v.size()),
    tab(new T[v.size()]),
    cap(v.size())
{
    for(unsigned int i = 0 ; i< Container<T>::nbEl; i++)
        tab[i] = v.tab[i];
}

template<class T> TD::Vector<T> & TD::Vector<T>::operator=(const TD::Vector<T> & v)
{
    if(this!= &v)
    {
        T * newtab = new T[v.nbEl];
        for(unsigned int i=0;
            i<Container<T>::nbEl;
            i++)
            newtab[i]=tab[i];
        delete[] tab;
        tab = newtab;
        cap = v.nbEl;
        Container<T>::nbEL = v.nbEl;
    }
    return *this;
}
#endif // CONTAINER_H



template<class IT> IT element_minimum(IT it1, IT it2)
{
    IT min = it1;
    while(it1!=it2)
    {
        if(*it1<*min) min=it1;
        ++it1;
    }
    return min;
}

template<class IT, class OP> IT element_minimum(IT it1, IT it2, OP op )
{
    IT min = it1;
    while(it1!=it2)
    {
        if(op(*it1,*min)) min=it1;
        ++it1;
    }
    return min;
}
