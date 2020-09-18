void pointeurs()
{
	/*
		const : soit le pointeur ne pouvant pas �tre modifi�, soit la valeur point�e
		int const * p;
		const int * p;
		=> objet point� non modifiable par le pointeur ; voir en fonction de la position de l'�toile
		int * const p;
		=> poineur non modifiable (si const � droite de *)


		conversions implicites :
		T* => (const) T* (const)
		T* => void *
	*/
	double* pt0 = 0;  // Pr�f�rable d'utiliser nullptr (cpp 11)
	// double* pt1 = 4096;  // Impossible d'assigner un int � double*
	double* pt1 = (double*)4096; // On ne sait pas ce qui est contenu � l'adresse 4096
	void* pt3 = pt1;  
	// pt1 = pt3;  // Impossible d'assigner void* a un double*
	pt1 = (double*)pt3; 
	double d1 = 36; 
	const double d2 = 36; // d2 constante
	double* pt4 = &d1; 
	const double* pt5 = &d1; // d1 ne pourra pas �tre modifi� via pt5
	*pt4 = 2.1; 
	// *pt5 = 2.1; // pas le droit, pointeur sur object constant
	// pt4 = &d2; // le pointeur pt4 doit �tre typ� pour pointe un objet constant
	pt5 = &d2; 
	double* const pt6 = &d1; 
	// pt6 = &d1; // Pas le droit, on ne peut pas changer l'objet point�
	*pt6 = 2.78; 
	// double* const pt6b = &d2; // d2 est non modifiable, le pointeur doit donc pointer sur un objet constant
	const double* const pt7 = &d1; 
	// pt7 = &d1;  // on ne peut pas modifier l'adresse de 
	// *pt7 = 2.78; 
	double const* pt8 = &d1; 
	pt8 = &d2; 
	pt8 = &d1; 
	// *pt8 = 3.14; // on ne peut pas modifier la valeur de *pt8 qui est constant
}