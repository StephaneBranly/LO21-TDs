#include "fonction.h"
#include<iostream> 
using namespace std;

// void bonjour(); // Première manière d'indiquer qu'une fonction existe dans un autre fichier


int main() 
{ 
	double pi = 3.14;
	double y = 5;
	pi = y;
	cout << "pi=" << pi << "\n";

	// bonjour(); 
	exerciceA();
	return 0; 
}
