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

    public:
        Expression(int v) : value(v) {};
        int getValue() const { return value; };
        std::string toString() const { return std::to_string(value); }
    };

    class ExpressionManager
    {
        Expression** exps;
        size_t nb = 0;    // Le nombre d'adresses stockées
        size_t nbMax = 0; // taille du tableau pointé par exps
        void agrandissementCapacite();

    public:
        ExpressionManager() = default; // utilise les initialisateurs par défaut
        Expression& addExpression(int v);
        void removeExpression(Expression& e);
        ~ExpressionManager();
        ExpressionManager(const ExpressionManager& e);            // constructeur de recopie
        ExpressionManager& operator=(const ExpressionManager& e); // opérateur d'affectation
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