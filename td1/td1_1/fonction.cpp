#include <iostream>
#include "fonction.h"

int fct(int x); 
int fct(float y); 
int fct(int x, float y); 
float fct(float x, int y);

// On peut encapsuler des namespaces A::C::hello();
namespace a // Création de namespace
{
	void bonjour() {
		std::cout << "nichao\n";
	}
}
namespace b
{
	void bonjour() {
		std::cout << "hello\n";
	}
}




void exercice_surcharge() {
	int i = 3, j = 15; 
	float x = 3.14159, y = 1.414; 
	char c = 'A'; 
	double z = 3.14159265; 
	fct(i); //appel 1 // A
	fct(x); //appel 2 // B
	fct(i,y); //appel 3 // C
	fct(x,j); //appel 4 // D
	fct(c); //appel 5 // A
	fct(i,(float)j); //appel 6 , changement du type pour que cela corresponde aux types des paramètres des fonctions
	fct(i,static_cast<float>(c)); //appel 7 
	fct(i,z); //appel 8 // C
	fct(z,(int)z); //appel 9 
}

void inverse(int* a, int* b)
{
	const auto tmp = *a;
	*a = *b;
	*b = tmp;
}
void inverse(int& a, int& b)
{
	const auto tmp = a;
	a = b;
	b = tmp;
}

void raz(essai* e) // Par pointeur
{
	e->n = 0;
	e->x = 0;
}
void raz(essai& e) // Par référence
{
	e.n = 0;
	e.x = 0;
}
void essai::afficher() {
	std::cout << "n=" << this->n << " ; x=" << this->x << std::endl;
}