#pragma once

#include <list>
using namespace std;

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	~Zbior() { zwolnij(); }

	//kopiujace
	Zbior(const Zbior& org) {}
	Zbior& operator=(const Zbior& org) = delete;

	//przenoszace
	Zbior(Zbior&& org) = delete;
	Zbior& operator=(Zbior&& org)noexcept {
		return *this;
	}

	operator double() {
		double srednia = 0;
		for (int i = 0; i < m_liczbaElementow; i++) {
			srednia += m_elementy[i];
		}
		srednia = srednia / m_liczbaElementow;
		return srednia;
	}
};

class Funktor {
private:
	double tolerancja;

public:
	//Konstruktor
	Funktor(double tol)
	{
		tolerancja = tol;
	}

	bool operator()(list<double>::iterator tol) {
		if (*tol > (tolerancja - 1e-6) && *tol < (tolerancja + 1e-6)) {
			return true;
		}
		else {
			return false;
		}
	}
};

