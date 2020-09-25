#ifndef _FONCTION_H // s�curit� double inclusion du m�me fichier
#define _FONCTION_H
#include <iostream>
#include <string>

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

void inverse(int *a, int *b);
void inverse(int &a, int &b);

struct essai
{
	int n;
	float x;
	void raz();
	void afficher(); // Cr�ation d'une m�thode
};

void raz(essai *e);
void raz(essai &e);

struct point
{
	int x;
	int y;
	int z;
};

void init(point &ref, int _x = 0, int _y = 0, int _z = 0);
void essai_init();

constexpr int intcalcul(int x);
constexpr int getNumber();
int mainconstexpr();

struct personne
{
	//char nom[30];
	std::string nom;
	unsigned int age;
};

void raz(personne *p);
void affiche_struct(const personne *p);
void affiche_tab(const personne *p, size_t n); // size_t permet d'indiquer la taille du tableau
// void init_struct(personne *p, const char *n, unsigned int a);
void init_struct(personne *p, const std::string &, unsigned int a);
void copy_struct(personne *p, const personne *s);
void copy_tab(personne *tdest, const personne *ts, unsigned int n);

struct compte
{
	std::string id;
	int solde;
};

void essai_comptes();
int &operation(compte *tab, std::string id);

#endif // !_FONCTION_H