#include "Bauer.h"

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

std::vector<std::string> Bauer::erlaubteFelderBerechnen(std::string)
{
	return {};
}

