#pragma once
#include <iostream>
#include <string>

namespace COMPUTER
{

    class ComputerException
    {
        std::string info;

    public:
        ComputerException(const std::string& str) : info(str) {}
        std::string getInfo() const { return info; }
    };

    class Expression
    {
        int value;
        ~Expression() = default;
        Expression(const Expression&) = delete;
        Expression(int v) : value(v) {};
        Expression& operator=(const Expression&) = default;
        friend class ExpressionManager;
    public:
        int getValue() const { return value; };
        std::string toString() const { return std::to_string(value); }
    };

    class ExpressionManager
    {
        Expression** exps;
        size_t nb = 0;    // Le nombre d'adresses stockées
        size_t nbMax = 0; // taille du tableau pointé par exps
        void agrandissementCapacite();

        ExpressionManager() = default; // utilise les initialisateurs par défaut
        ~ExpressionManager();
        ExpressionManager(const ExpressionManager& e)=delete;            // constructeur de recopie
        ExpressionManager& operator=(const ExpressionManager& e)=delete; // opérateur d'affectation

        class Handler
        {
            ExpressionManager* instance = nullptr;
            Handler() = default;
            ~Handler() { delete instance; }
        };
        static Handler hand;

       
    public:
        class const_iterator {
            Expression** cur = nullptr;
            Expression** fin = nullptr;
            const_iterator(Expression** c, Expression** f) : cur(c), fin(f) {};
            friend class ExpressionManager; // pour que ExpressionManager puisse avoir accès à la partie privée de Itérator
        public:
            const_iterator() = default;
            const Expression& operator*() const  { return **cur; }
            const_iterator& operator++() {
                if (cur == fin)
                    throw ComputerException("Incrementation pointeur non valide");
                cur++;
                return *this;
            }
            bool operator!=(const const_iterator& i) const {  return cur != i.cur; }
        };
        const_iterator cbegin() { return const_iterator(exps, exps + nb); }
        const_iterator cend() { return const_iterator(exps + nb, exps + nb); }

        class iterator {
            Expression** cur = nullptr;
            Expression** fin = nullptr;
            iterator(Expression** c, Expression** f) : cur(c), fin(f) {};
            friend class ExpressionManager; // pour que ExpressionManager puisse avoir accès à la partie privée de Itérator
        public:
            iterator() = default;
            Expression& operator*() { return **cur;  }
             iterator& operator++() { 
                 if (cur == fin) 
                     throw ComputerException("Incrementation pointeur non valide");
                 cur++;
                 return *this;
             }
             bool operator!=(const iterator& i) { return cur != i.cur; }
        };
        iterator begin() { return iterator(exps, exps + nb); }
        iterator end() { return iterator(exps + nb, exps + nb); }
    

        class Iterator {
            Expression** cur = nullptr; // adresse de l'objet courant
            Expression** fin = nullptr; // adresse de fin
            Iterator(Expression** c, Expression** f) : cur(c), fin(f) {};
            friend class ExpressionManager; // pour que ExpressionManager puisse avoir accès à la partie privée de Itérator
            public:
                Iterator() = default;
                Expression& current() { return **cur; };  // méthode const car ne modifie pas les attributs
                void next() {
                    if (cur == fin)
                        throw ComputerException("Incrementation pointeur non valide");
                    cur++;
                };
                bool isDone() const { // méthode const car ne modifie pas les attributs
                    return cur == fin;
                } ;
        };

        Iterator getIterator() { return Iterator(exps, exps + nb); };
        iterator getIterator2() { return iterator(exps, exps + nb); };
        const_iterator cgetIterator() { return const_iterator(exps, exps + nb); };
        void removeExpression(Expression& e);
        Expression& addExpression(int v);
        static ExpressionManager& getInstance();
        static void libererInstance();
    };

    class Item
    {
        Expression* exp = nullptr;

    public:
        Item() = default;
        void setExpression(Expression& e) { exp = &e; }
        Expression& getExpression() { return *exp; };
        const Expression& getExpression() const { return *exp; };
        void raz() { exp = nullptr; };
    };

    class Pile
    {
        Item* items = nullptr;
        size_t nb = 0;
        size_t nbMax = 0;
        size_t nbAffiche = 4;
        std::string message = "";
        void agrandissementCapacite();

    public:
        Pile() = default;
        void affiche() const;
        void push(Expression& e)
        {
            if (nb == nbMax)agrandissementCapacite();
            items[nb++].setExpression(e);
        };
        void pop()
        {
            if (nb == 0) ComputerException("Pop sur une pile vide");
            items[--nb].raz();
        };
        bool estVide() const { return nb == 0; };
        size_t taille() const { return nb; };
        Expression& top() const {
            if (nb == 0) ComputerException("Pile vide");
            return items[nb - 1].getExpression();
        };
        void setMessage(const std::string& m) { message = m; }
        std::string getMessage() const { return message; };
        void setNbItemsToAffiche(size_t n) { nbAffiche = n; };

        ~Pile()
        {
            delete[] items; // désallocation du tableau d'objets
            // ce n'est pas à la pile de gérer le cycle de vie des expressions pointées par des items
        }
    };

    class Controleur
    {
        ExpressionManager& expMng;
        Pile& expAff;
    public:
        Controleur(ExpressionManager& m, Pile& v) :expMng(m), expAff(v) {}
        void commande(const std::string& c);
        void executer();
    };

} // namespace COMPUTER