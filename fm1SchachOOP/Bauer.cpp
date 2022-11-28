#include "Bauer.h"

extern Spiel s;

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

vector<Feld> Bauer::erlaubteFelderBerechnen(string bezeichnung)
{
	vector<string> BauerV;
	string x	= "  ";
	switch (this->farbe) {
	case 0:
		
			// b l�uft runter
		if (bezeichnung.at(1) != 49)
		{
			
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) - 1;
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);
				break;
			}
			else
			{
				break;
			}
		}

		// doppelter Schritt zum Anfang
		if (bezeichnung.at(0) >= 'A' && bezeichnung.at(0) <= 'H' && bezeichnung.at(1) == '7') {
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) - 1;
			// Freeway : wenn ja : Feld hinzufuegen
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);

				// Zweiter Schritt
				x.at(1) = bezeichnung.at(1) - 2;
				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
				{
					BauerV.push_back(x);
				}
			}
		}
			// b schl�gt rechts runter
		if(bezeichnung.at(1) != 49 && bezeichnung.at(0) <72 )
		string x	= "  ";
		x.at(0)		= bezeichnung.at(0) + 1;
		x.at(1)		= bezeichnung.at(1) - 1;
		if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
		{
			BauerV.push_back(x);
			break;
		}	
		else
		{
			break;
		}
		
		// b schl�gt links runter
		if (bezeichnung.at(1) != 49 && bezeichnung.at(0) > 65 )
		x.at(0) = bezeichnung.at(0) - 1;
		x.at(1) = bezeichnung.at(1) - 1;
		if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
		{
			BauerV.push_back(x);
			break;
		}
		else
		{
			break;
		}

	case 1: // B l�uft hoch
		/*Geradeaus*/
		// einfacher Schritt ab linie 3
		if (bezeichnung.at(0) >= 'A' && bezeichnung.at(0) <= 'H' && bezeichnung.at(1) >= '3' && bezeichnung.at(1) <= '8')
		{
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) + 1;
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);
			}
		}

		// doppelter Schritt zum Anfang
		if (bezeichnung.at(0) >= 'A' && bezeichnung.at(0) <= 'H' && bezeichnung.at(1) == '2') {
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) + 1;
			// Freeway : wenn ja : Feld hinzufuegen
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);

				// Zweiter Schritt
				x.at(1) = bezeichnung.at(1) + 2;
				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
				{
					BauerV.push_back(x);
				}
			}
		}
		/*Diagonal Schlagen*/

		// Rechts Hoch
		bool erlaubnis = true;

		for (int i = 1; i < 8; i++)
		{
			if (erlaubnis == true)
			{
				for (int k = 1; k < 8; k++)
				{
					if (abs(bezeichnung.at(0) - bezeichnung.at(0) + i) == abs(bezeichnung.at(1) - bezeichnung.at(1) + k))
					{

						string x = "  ";
						x.at(0) = bezeichnung.at(0) + i;
						x.at(1) = bezeichnung.at(1) + k;

						if (x.at(0) >= 65 && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
						{
							if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
							{
								erlaubnis = false;
								break;
							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								erlaubnis = false;
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{

								BauerV.push_back(x);
								erlaubnis = false;
								break;
							}
						}
					}

				}
			}
			else
			{
				break;
			}

			// Links hoch
			erlaubnis = true;

			for (int i = 1; i < 8; i++)
			{
				if (erlaubnis == true) {
					for (int k = 1; k < 8; k++)
					{
						if (abs(bezeichnung.at(0) - bezeichnung.at(0) - i) == abs(bezeichnung.at(1) - bezeichnung.at(1) + k))
						{
							string x = "  ";
							x.at(0) = bezeichnung.at(0) - i;
							x.at(1) = bezeichnung.at(1) + k;

							if (x.at(0) >= 65 && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
							{
								if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
								{
									erlaubnis = false;
									break;
								}
								else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
								{
									erlaubnis = false;
									break;
								}
								else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
								{
									BauerV.push_back(x);
									erlaubnis = false;
									break;
								}
							}
						}
					}
				}
				else
				{
					break;
				}
			}
			break;
		}
	}

	// Convert vector<string> into vector<Feld>
	vector<Feld> felder;
	for (string& str : BauerV)
	{
		felder.push_back(s.get_Spielstand()[str]);
	}

	// Return
	return felder;
}

