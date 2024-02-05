#include <iostream>
#include "zbior.h"
#include <random>
#include <list>
#include <algorithm>

using namespace std;

int main() 
{
	int minZakres = 10;
	int maxZakres = 20;

	random_device inicjalizujLosowe; 
	mt19937 generujLosowe;
	generujLosowe.seed(inicjalizujLosowe());
	uniform_int_distribution<int> uniDistInt(minZakres, maxZakres);
	uniform_real_distribution<double> uniDistReal(minZakres, maxZakres);

	list<double> LiczbyLosowe = {};

	int LiczbaElementowListy = uniDistInt(generujLosowe);
	int LiczbaElementowZbioru;

	for (int i = 0; i < LiczbaElementowListy; ++i) 
	{
		LiczbaElementowZbioru = uniDistInt(generujLosowe);

		//Zbior z losowymi wartosciami
		Zbior ZbiorDoDouble(LiczbaElementowZbioru, uniDistReal(generujLosowe), uniDistReal(generujLosowe));

		//Konwersja do double
		LiczbyLosowe.push_back(static_cast<double>(ZbiorDoDouble));
	}
	list<double> ListaFunktora = { 1.5,1.9,2.9,0.6,1.1 };
	list<double>::iterator IteratorListyFunktora=ListaFunktora.begin();

	Funktor FunktorListy(0.6);
	auto znajdz = find_if(ListaFunktora.begin(), ListaFunktora.end(), FunktorListy);

	if (znajdz != ListaFunktora.end())
		cout << "Wartosc znaleziona" << endl;
	else
		cout << "Wartosc nie znaleziona" << endl;
	
	
}