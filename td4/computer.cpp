#include "computer.h"
#include <iostream>

namespace COMPUTER
{
void ExpressionManager::agrandissementCapacite()
{
    // Agrandir le tableau
    // => En allouer un plus grand
    // => recopier les adresses dans le nouveau tableau
    // => désallouer l'ancien tableau
    // => le nouveau tableau devient le tableau courant
    nbMax++;

    Expression **newTab = new Expression *[nbMax];
    for (int i = 0; i < nbMax - 1; i++)
    {
        newTab[i] = exps[i];
    }

    delete exps;
    exps = newTab;
}

Expression &ExpressionManager::addExpression(int v)
{
    if (nb == nbMax)
        agrandissementCapacite();
    exps[nb++] = new Expression(v);
    return *exps[nb - 1];
}

void ExpressionManager::removeExpression(Expression &e)
{
    // retirer l'adresse &e du tableau
}

} // namespace COMPUTER
