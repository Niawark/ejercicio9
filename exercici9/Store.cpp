#include"Store.h"

Store::Store()
{
	for (int i = 0; i < MAX; i++)
	{
		m_usuaris[i].setUsuari("", "", "");
		m_aplicacions[i].setApp("", "", 0);
	}
	m_nAplicacions = 0;
	m_nUsuarisExistents = 0;
}

bool Store::afegeixApp(const string &nom, const string &descripcio, int tamany)
{
	if (m_nAplicacions < MAX)
	{
		m_aplicacions[m_nAplicacions].setApp(nom, descripcio, tamany);
		m_nAplicacions++;
		return true;
	}
	return false;
}

bool Store::afegeixUsuari(const string &nom, const string &email, const string &contrassenya)
{
	bool trobat = false;
	int i = 0;

	if (m_nUsuarisExistents < MAX)
	{
		while (!trobat && i < MAX)
		{
			if (m_usuaris[i].getNom() == nom)
			{
				trobat = true;
			}
			i++;
		}

		if (!trobat)
		{
			m_usuaris[m_nUsuarisExistents].setUsuari(nom, email, contrassenya);
			m_nUsuarisExistents++;
			return true;
		}
	}
	return false;
}

bool Store::afegeixDescarrega(const string &nomApp, const string &nomUsuari, const string &data, int temps, int valoracio)
{
	bool trobat = false;
    int i= 0;

		while (!trobat&&i<MAX)
		{
			if ((m_aplicacions[i].getNom() == nomApp)&&(m_aplicacions[i].getTamany()<MAX_DESCARREGUES))
			{

					m_aplicacions[i].afegeixDescarrega(nomApp, data, temps);
					m_aplicacions[i].afegeixValoracio(nomUsuari, valoracio);
					return true;
			}
			i++;
		}
		
	return false;
}

void Store::llegeixUsuaris(const string &nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		string nom, email, contrassenya;
		fitxer >> nom >> email >> contrassenya;
		while (!fitxer.eof())
		{
			m_usuaris[m_nUsuarisExistents].setUsuari(nom, email, contrassenya);
			m_nUsuarisExistents++;
			fitxer >> nom >> email >> contrassenya;
		}
		fitxer.close();
	}
}

void Store::escriuDescarregues(const string &nomFitxer, const string &nomApp)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	bool trobat = false;
	int i = 0;
	string nomusuari, data,nomapp,descripcioapp;
	int temps,valoracio,tamanyapp;

	while (!trobat && i<MAX)
	{
		if (m_aplicacions[i].getNom() == nomApp)
		{
			trobat = true;
			if (fitxer.is_open())
			{
				nomapp = m_aplicacions[i].getNom();
				descripcioapp = m_aplicacions[i].getDescripcio();
				tamanyapp = m_aplicacions[i].getTamany();

				fitxer << nomapp << " " << descripcioapp << " " << tamanyapp << " " << tamanyapp <<"\n";

				for (int x = 0; x < m_aplicacions[i].getTamany(); x++)
				{
					
					m_aplicacions[i].getDescarrega(nomusuari, data, temps, valoracio);
					fitxer << nomusuari << "\n" << data << "\n" << temps << "\n" << valoracio << "\n";
				}
				
				fitxer.close();
			}
		}
		i++;
	}
}