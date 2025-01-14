#include "Turm.h"

extern Spiel s;

Turm::Turm(bool symbol) {
	farbe =  symbol;
	bezeichnung = (symbol) ? 't' : 'T';
}

vector<Feld> Turm::erlaubteFelderBerechnen(string bezeichnung)
{
	//! Variablen
	vector<Feld> felder;
	vector<string> TurmV;

	//! Calculation
	for (int m = 0; m < 2; m++)  // wechselt zwischen Vertikal und horizontal // x.at(0) & x.at(1)
	{
		for (int n = 0; n < 3; n += 2) // Wechselt zwischen rechts & links || hoch und runter 
		{
			for (int i = 0; i < 8; i++)	// bestimmt die passende Rechnung f�r die Startposition & l�scht die Startposition aus TurmV
			{
				for (int k = 0; k < 8; k++) // ist jeder der bis zu 7 Schritte in jede Richtung
				{
					// Berechnung der erlaubten Felder 								
					if (bezeichnung.at(m) == (65 + i - (16 * m)))													// Feld auf dem man steht				| 65 + 0 = A 		
					{
						string x	 = "  ";
						x.at(m)		 = bezeichnung.at(m) + k - (k * n);												// Feld auf das man sich bewegen kann	| 65 + 0 = A 		
						x.at(1 - m)  = bezeichnung.at(1 - m);														// vertikale / horizontale bleibt unver�ndert		
						if (x.at(m) != (65 + i - (16 * m)) && x.at(m) >= 65 - (16 * m) && x.at(m) <= 72 - (16 * m)) // Felder auf dem man steht excludieren & nur on Board range erlauben		
						{
							if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')						// Wenn das Feld leer ist, ist es erlaubt -> pushback
							{
								TurmV.push_back(x);

							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())					// Wenn die Figur auf dem Feld die selbe Farbe hat als diese Figur kein pushback & break
							{
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())					// Wenn die Figur auf dem Feld eine andere Farbe hat als diese Figur, ist es erlaubt -> pushback & danach break
							{
								TurmV.push_back(x);
								break;
							}
						}
					}
				}
			}	
		}	
	}	
	
	//! Sort vector ascending
	sort(TurmV.begin(), TurmV.end());

	//! Convert vector<string> into vector<Feld>
	for (string& str : TurmV) {	felder.push_back(s.get_Spielstand()[str]);	}

	//! Return
	return felder;
}
