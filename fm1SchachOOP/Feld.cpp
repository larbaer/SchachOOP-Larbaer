#include "Feld.h"
#include "Bauer.h"
#include "Dame.h"
#include "Koenig.h"
#include "Laeufer.h"
#include "Leer.h"
#include "Springer.h"
#include "Turm.h"
#include <iostream>
using namespace std;

Feld::Feld()
{
}

Feld::Feld(std::string bez)
{
	bezeichnung = bez;
}

Feld::Feld(std::string bez, char symbol)
{
	// Bezeichnung von Feld
	bezeichnung = bez;

	// Figur* auf Feld setzen
	switch (symbol)
	{
	case 'B': case 'b':
		figur = new Bauer(isupper(symbol));
		break;
	case 'T': case 't':
		figur = new Turm(isupper(symbol));
		break;
	case 'L': case 'l':
		figur = new Laeufer(isupper(symbol));
		break;
	case 'S': case 's':
		figur = new Springer(isupper(symbol));	
		break;
	case 'D': case 'd':
		figur = (Laeufer*) new Dame(isupper(symbol));			// Bridge-Pointer in cause of Mehrfachvererbung
		break;
	case 'K': case 'k':
		figur = new Koenig(isupper(symbol));
		break;
	default:
		figur = new Leer(bez);
		break;
	}
}

string Feld::get_Bezeichnung()
{
	return bezeichnung;
}

Figur* Feld::get_Figur()
{
	return figur;
}

void Feld::set_ErlaubteFelder(string bezeichnung)
{
	// Output
	cout << endl << "void Feld::set_ErlaubteFelder(string bezeichnung)" << endl;

	erlaubteFelder = figur->erlaubteFelderBerechnen(bezeichnung);
}