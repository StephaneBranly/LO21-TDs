#include "fonction.h"
#include <iostream>

using namespace b; // Indication du namespace que l'on veut utiliser

int main()
{	
	auto s = 123.123; // Le compilateur choisit de manière automatique le type de la variable
	bonjour();
	int a = 1, b = 2;
	std::cout << "a=" << a << " ; b=" << b << std::endl;
	inverse(&a, &b);
	std::cout << "a=" << a << " ; b=" << b << std::endl;
	int c = 1, d = 2;
	std::cout << "c=" << c << " ; d=" << d << std::endl;
	inverse(c, d);
	std::cout << "c=" << c << " ; d=" << d << std::endl;
	return 0;
}