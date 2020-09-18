#include<iostream> 
#include<string> 

using namespace std;

void bonjour() {
	cout << "Entrez votre prenom :";
	string prenom;
	cin >> prenom;
	cout << "Bonjour " << prenom << "\n";
}

const double pi = 3.14159;

void exerciceA(){ 
	int r; 
	double p, s; 
	cout << "Donnez le rayon entier d un cercle: "; 
	cin >> r; 
	p=2*pi*r; 
	s=pi*r*r; 
	cout << "\nLe cercle de rayon " << r ; 
	cout << " a un perimetre de " << p << " et une surface de " << s; 
} 
