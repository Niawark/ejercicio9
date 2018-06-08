#include "App.h"

void App::afegeixDescarrega(string nom, string data, int temps)
{
	int i = m_tamany;
	if (m_tamany < MAX_DESCARREGUES)
	{
		m_descarregues[i].setDescarrega(nom, data, temps);
		m_tamany++;
	}
}

bool App::afegeixValoracio(string nomusuari, int valoracio)
{
	int i = 0;
	bool trobat = false;
	while (!trobat&&i<MAX_DESCARREGUES)
	{
		if (m_descarregues[i].getUsuari() == nomusuari)
		{
			m_descarregues[i].setValoracio(valoracio);
			if (m_descarregues[i].getData() == "")
			{
				return true;
			}
			trobat = true;
		}
		i++;
	}
	return false;
}

Descarrega App::getDescarrega(/*string &usuari,string &data, int &temps,int &valoracio*/)
{
	/* 
	if (m_descarrega < MAX_DESCARREGUES)
	{
		usuari = m_descarregues[m_descarrega].getUsuari();
		data = m_descarregues[m_descarrega].getData();
		temps = m_descarregues[m_descarrega].getTemps();
		valoracio = m_descarregues[m_descarrega].getValoracio();

		m_descarrega++;
	}	
	*/
	return m_descarregues[MAX_DESCARREGUES];
}

