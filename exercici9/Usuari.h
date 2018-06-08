#pragma once
#include <string>
#include <fstream>
using namespace std;

class Usuari
{
public:
	Usuari()
	{
		m_usuari = ""; m_email = ""; m_contrassenya = "";
	}
	void setUsuari(const string &nom, const string &email, const string &contrassenya)
	{
		m_usuari = nom; m_email = email; m_contrassenya = contrassenya;
	}
	string getNom() const { return m_usuari; }
	string getEmail() const { return m_email; }
	string getContrassenya() const { return m_contrassenya; }
private:
	string m_usuari;
	string m_email;
	string m_contrassenya;
};
