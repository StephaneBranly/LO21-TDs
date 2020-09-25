#include <iostream>
#include "fonction.h"
#include <string>

int fct(int x);
int fct(float y);
int fct(int x, float y);
float fct(float x, int y);

// On peut encapsuler des namespaces A::C::hello();
namespace a // Cr�ation de namespace
{
void bonjour()
{
	std::cout << "nichao\n";
}
} // namespace a
namespace b
{
void bonjour()
{
	std::cout << "hello\n";
}
} // namespace b

void exercice_surcharge()
{
	int i = 3, j = 15;
	float x = 3.14159, y = 1.414;
	char c = 'A';
	double z = 3.14159265;
	fct(i);						   //appel 1 // A
	fct(x);						   //appel 2 // B
	fct(i, y);					   //appel 3 // C
	fct(x, j);					   //appel 4 // D
	fct(c);						   //appel 5 // A
	fct(i, (float)j);			   //appel 6 , changement du type pour que cela corresponde aux types des param�tres des fonctions
	fct(i, static_cast<float>(c)); //appel 7
	fct(i, z);					   //appel 8 // C
	fct(z, (int)z);				   //appel 9
}

void inverse(int *a, int *b)
{
	const auto tmp = *a;
	*a = *b;
	*b = tmp;
}
void inverse(int &a, int &b)
{
	const auto tmp = a;
	a = b;
	b = tmp;
}

void essai::raz()
{
	n = 0;
	x = 0;
}
void raz(essai *e) // Par pointeur
{
	e->n = 0;
	e->x = 0;
}
void raz(essai &e) // Par r�f�rence
{
	e.n = 0;
	e.x = 0;
}
void essai::afficher()
{
	std::cout << "n=" << this->n << " ; x=" << this->x << std::endl;
}

void init(point &ref, int _x, int _y, int _z)
{
	ref.x = _x;
	ref.y = _y;
	ref.z = _z;
}

void essai_alloc()
{
	int *pt_int;
	double *pt_double;
	pt_int = new int;
	pt_double = new double[100];
	delete pt_int;
	delete[] pt_double;
}

void essai_init()
{
	point p;
	init(p);
	init(p, 1);
	init(p, 1, 2);
	init(p, 1, 2, 3);
}

#include <array>
using namespace std;
constexpr int calcul(int x) { return 2 * x + 1; }
constexpr int getNumber() { return 3; }
int mainconstexpr()
{
	constexpr int N = getNumber();
	array<int, calcul(N)> tableau;
	return 0;
}

void raz(personne *p)
{
	p->age = 0;
	p->nom = "";
	// ou p->nom.clear();

	// Si nom de type char[] :
	// ou strcpy(p->nom, "");
	// p->nom = ""; affectation IMPOSSIBLE
}

void affiche_struct(const personne *p)
{
	std::cout << p->nom << " age = "
			  << "\n";
}

void affiche_tab(const personne *tab, size_t n)
{
	for (size_t i = 0; i < n; i++)
		affiche_struct(tab + i);
}
void init_struct(personne *p, const string &n, unsigned int a)
{
	p->age = a;
	size_t i = 0;
	p->nom = n;
	// while (*n)
	// 	p->nom[i++] = *(n++);
	// p->nom[i] = '\0';
}

void copy_struct(personne *p, const personne *s)
{
	*p = *s; // recopie des attributs de s dans les attributs de p
}
void copy_tab(personne *tdest, const personne *ts, unsigned int n)
{
	for (size_t i = 0; i < n; i++)
		tdest[i] = ts[i];
}

int &operation(compte *tab, std::string id)
{
	size_t i = 0;
	while (tab[i].id != id) // opérateur != dispo pour comparer des types strings
		i++;

	return tab[i].solde;
}
void essai_comptes()
{
	compte tab[4] = {{"courant", 0}, {"codevi", 1500}, {"epargne", 200}, {"cel", 300}};
	operation(tab, "courant") = 100;
	operation(tab, "codevi") += 100;
	operation(tab, "cel") -= 50;
	for (int i = 0; i < 4; i++)
		cout << tab[i].id << " : " << tab[i].solde << "\n";
}
