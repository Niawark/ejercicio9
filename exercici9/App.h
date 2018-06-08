#pragma once
#include "Descarrega.h"
#include <string>
#include <fstream>
using namespace std;
const int MAX_DESCARREGUES = 100;

class App
{
public:
	App() { m_nom = ""; m_descripcio = ""; m_tamany = 0; m_descarrega = 0; }
	void setApp(const string &nom, const string &descripcio, int tamany)
	{
		int i = 0;
		m_nom = nom; m_descripcio = descripcio; m_tamany = tamany;
	}
	void afegeixDescarrega(string nom, string data, int temps);
	bool afegeixValoracio(string nomusuari, int valoracio);
	string getNom() const { return m_nom; }
	string getDescripcio() const { return m_descripcio; }
	int getTamany() const { return m_tamany; }
	Descarrega getDescarrega(/*string &usuari, string &data, int &temps, int &valoracio*/);
private:
	Descarrega m_descarregues[MAX_DESCARREGUES];
	string m_nom;
	string m_descripcio;
	int m_tamany;
	int m_descarrega;
};
