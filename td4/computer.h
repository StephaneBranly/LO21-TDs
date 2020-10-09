#pragma once
#include <iostream>
#include <string>

namespace COMPUTER
{

class ComputerException
{
    std::string info;

public:
    ComputerException(const std::string &str) : info(str) {}
    std::string getInfo() const { return info; }
};

class Expression
{
    int value;

public:
    Expression(int v) : value(v){};
    int getValue() const { return value; };
    std::string toString() const { return std::to_string(value); }
};

class ExpressionManager
{
    Expression **exps;
    size_t nb = 0;    // Le nombre d'adresses stockées
    size_t nbMax = 0; // taille du tableau pointé par exps
    void agrandissementCapacite();

public:
    ExpressionManager() = default; // utilise les initialisateurs par défaut
    Expression &addExpression(int v);
    void removeExpression(Expression &e);
    ~ExpressionManager();
    ExpressionManager(const ExpressionManager &e);            // constructeur de recopie
    ExpressionManager &operator=(const ExpressionManager &e); // opérateur d'affectation
};

class Item
{
    Expression *exp = nullptr;

public:
    Item() = default;
    void setExpression(Expression &e) { exp = &e; }
    Expression &getExpression() { return *exp; };
    const Expression &getExpression() const { return *exp; };
    void raz() { exp = nullptr; };
};

class Pile
{
    Item *items = nullptr;
    size_t nb = 0;
    size_t nbMax = 0;
    size_t nbAffiche = 4;
    std::string message = "";
    void agrandissementCapacite();

public:
    Pile();
    void affiche() const;
    void push(Expression &e);
    void pop();
    bool estVide() const { return nb == 0; };
    size_t taille() const { return nb; };
    Expression &top() const;
    void setMessage(const std::string &m);
    std::string getMessage() const { return message; };
    void setNbItemsToAffiche(size_t n) { nbAffiche = n; };
};

} // namespace COMPUTER