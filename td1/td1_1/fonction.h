#ifndef _FONCTION_H // sécurité double inclusion du même fichier
#define _FONCTION_H
#include <iostream>

namespace a
{
	void bonjour();
}
namespace b
{
	void bonjour();
}


int fct(int x) // Fonctions 'en ligne'
{
	std::cout << "1:" << x << "\n";
	return 0;
}

int fct(float y)
{
	std::cout << "2:" << y << "\n";
	return 0;
}

int fct(int x, float y)
{
	std::cout << "3:" << x << y << "\n";
	return 0;
}

float fct(float x, int y)
{
	std::cout << "4:" << x << y << "\n";
	return 3.14;
}


void inverse(int* a, int* b);
void inverse(int& a, int& b);


struct essai { 
	int n; 
	float x; 
	void afficher(); // Création d'une méthode
};

void raz(essai* e);
void raz(essai& e);

struct point { 
	int x; 
	int y; 
	int z; 
}:

#endif // !_FONCTION_H