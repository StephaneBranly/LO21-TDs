#include "computer.h"
#include <iostream>
#include <algorithm>

namespace COMPUTER
{
    void ExpressionManager::agrandissementCapacite()
    {
        // Agrandir le tableau
        // => En allouer un plus grand
        // => recopier les adresses dans le nouveau tableau
        // => désallouer l'ancien tableau
        // => le nouveau tableau devient le tableau courant
        nbMax = (nbMax + 1) * 2;

        auto newTab = new Expression * [nbMax];
        for (size_t i = 0; i < nb; i++)
        {
            newTab[i] = exps[i];
        }
        auto old = exps;
        exps = newTab;
        delete[] old;
    };

    ExpressionManager& ExpressionManager::getInstance()
    {
        if (hand.instance == nullptr)
            hand.instance = new ExpressionManager; // seul objet créé
        return *hand.instance;
        //static ExpressionManager singleton;
        //return singleton;
    };


    void ExpressionManager::libererInstance()
    {
        delete hand.instance; hand.instance = nullptr;
    };
    Expression& ExpressionManager::addExpression(int v)
    {
        if (nb == nbMax)
            agrandissementCapacite();
        exps[nb++] = new Expression(v);
        return *exps[nb - 1];
    };

    void ExpressionManager::removeExpression(Expression& e)
    {
        size_t i = 0;
        // retirer l'adresse &e du tableau
        while (i < nb && exps[i] != &e)
            i++;
        if (i == nb)
            throw ComputerException("Expression inexistante");

        delete exps[i]; // on désalloue l'objet expression pointé
        nb--;
        // suppression du pointer
        while (i < nb)
        {
            exps[i] = exps[i + 1];
            i++;
        }
    };

    ExpressionManager::~ExpressionManager()
    {
        for (size_t i = 0; i < nb; i++)
            delete exps[i]; // désallocation d'un objet
        delete[] exps;      // désallocation d'un tableau de pointeurs
    };

    /*ExpressionManager::ExpressionManager(const ExpressionManager& m) : nbMax(m.nb), nb(m.nb), exps(new Expression* [m.nb])
    {
        for (size_t i = 0; i < nb; i++)
            exps[i] = new Expression(*m.exps[i]); // utilisation du constructeur de recopie de Expression
    };
    */

   /* ExpressionManager& ExpressionManager::operator=(const ExpressionManager& m)
    {
        if (this != &m) // manager = manager ne s'auto détruira pas
        {
            this->~ExpressionManager();
            exps = new Expression * [m.nbMax];
            nbMax = m.nbMax;
            nb = m.nb;

            for (size_t i = 0; i < nb; i++)
                exps[i] = new Expression(*m.exps[i]);
        }
        return *this;
    };
    */

    void Pile::agrandissementCapacite()
    {
        Item* newtab = new Item[(nbMax + 1) * 2];
        for (size_t i = 0; i < nb; i++) newtab[i] = items[i];
        Item* old = items;
        items = newtab;
        nbMax = (nbMax + 1) * 2;
        delete[] old; // il vaut mieux faire le delete en dernier sur une copie de pointeur afin d'éviter une exception
    };

    void Pile::affiche() const
    {
        using namespace std;
        cout << "**********************\n";
        cout << "*>" << message << "\n";

        // Indice du 1er element affiche
        size_t i = min(nbAffiche, nb);
        while (i > 0)
        {
            
            cout << items[nb - i].getExpression().toString() << "\n";
            i--;
        }
        cout << "**********************\n";


    };


    void Controleur::executer()
    {
        using namespace std;
        std::string c; // commande courante a executer
        do
        {
            expAff.affiche();
            std::cout << "?-";
            std::cin >> c;
            if (c != "Q" && c != "q") commande(c);
        } while (c != "Q" && c != "q");
        std::cout << "\n Controleur quitte";
    };

    void Controleur::commande(const std::string& c)
    {
        bool unNb = true;
        int nb;
        try {
            nb = stoi(c);
        }
        catch (...) {
            unNb = false; // ce n'est pas un nombre si stoi renvoie une exception
        }
        if (unNb) // cas ou on a un nombre
        {
            expAff.push(expMng.addExpression(nb));
        }
        else // cas ou c'est un p-e opérateur
        {
            if (c == "+" || c == "-" || c == "*" || c == "/") // cas ou on a un opérateur
            {
                if (expAff.taille() >= 2)
                {
                    int v2 = expAff.top().getValue();
                    expAff.pop();
                    int v1 = expAff.top().getValue();
                    expAff.pop();

                    int res = 0;
                    if (c == "+") res = v1 + v2;
                    if (c == "-") res = v1 - v2;
                    if (c == "*") res = v1 * v2;
                    if (c == "/") res= v1 / v2;
                    expAff.push(expMng.addExpression(res));
                }
                else
                {
                    expAff.setMessage("Erreur : pas assez d'arguments sur la pile");
                }
            }
            else
            {
                expAff.setMessage("Erreur : commande inconnue");
            }
        }
    };
} // namespace COMPUTER


