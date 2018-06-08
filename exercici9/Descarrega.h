#pragma once
#include <string>
#include <fstream>
using namespace std;

class Descarrega
{
public:
	Descarrega() { m_usuari = ""; m_data = ""; m_temps = 0; m_valoracio = -1; }
	void setDescarrega(const string &usuari, const string &data, int temps)
	{
		m_usuari = usuari; m_data = data; m_temps = temps;
	}
	void setValoracio(int valoracio) { m_valoracio = valoracio; }
	string getUsuari() const { return m_usuari; }
	string getData() const { return m_data; }
	int getTemps() const { return m_temps; }
	int getValoracio() const { return m_valoracio; }
private:
	string m_usuari;
	string m_data;
	int m_temps;
	int m_valoracio;
};
