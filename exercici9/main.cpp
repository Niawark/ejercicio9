// HistNotes.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "Store.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

float testStore()
{
	float reduccio = 0.0;

	Store s;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la classe Store" << endl;
	cout << "Comment :=>> ================================" << endl;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------" << endl;
	cout << "Comment :=>> Afegint aplicacions" << endl;
	cout << "Comment :=>> -------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_APP = 6;

	string nomApp[N_PROVES_APP] = {"APP_NOM_1", "APP_NOM_2" , "APP_NOM_3" , "APP_NOM_4" , "APP_NOM_5" , "APP_NOM_6" };
	string descripcioApp[N_PROVES_APP] = { "APP_DESC_1", "APP_DESC_2" , "APP_DESC_3" , "APP_DESC_4" , "APP_DESC_5" , "APP_DESC_6" };
	int tamany[N_PROVES_APP] = { 10, 20, 30, 40, 50, 60 };
	bool resultatAfegeixApp[N_PROVES_APP] = { true, true, true, true, true, false};
	for (int i = 0; i < N_PROVES_APP; i++)
	{
		cout << "Comment :=>> Afegint App: " << nomApp[i] << ", " << descripcioApp[i] << ", " << tamany[i] << endl;

		bool resultat = s.afegeixApp(nomApp[i], descripcioApp[i], tamany[i]);
		cout << "Comment :=>> Resultat: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat == resultatAfegeixApp[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Afegint usuaris des del fitxer usuaris.txt" << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_USUARI = 7;
	const int N_USUARIS_FITXER = 4;
	string nomUsuari[N_PROVES_USUARI] = { "USUARI_NOM_1", "USUARI_NOM_2" , "USUARI_NOM_3" , "USUARI_NOM_4" , "USUARI_NOM_3" ,"USUARI_NOM_5" , "USUARI_NOM_6" };
	string mailUsuari[N_PROVES_USUARI] = { "USUARI_MAIL_1", "USUARI_MAIL_2" , "USUARI_MAIL_3" , "USUARI_MAIL_4" , "USUARI_MAIL_3" ,"USUARI_MAIL_5" , "USUARI_MAIL_6" };
	string contrassenyaUsuari[N_PROVES_USUARI] = { "USUARI_CONTRASSENYA_1", "USUARI_CONTRASSENYA_2" , "USUARI_CONTRASSENYA_3" , "USUARI_CONTRASSENYA_4" , "USUARI_CONTRASSENYA_3" ,"USUARI_CONTRASSENYA_5" , "USUARI_CONTRASSENYA_6" };
	bool resultatAfegeixUsuari[N_PROVES_USUARI - N_USUARIS_FITXER] = { false, true, false };

	s.llegeixUsuaris("usuaris.txt");

	for (int i = 0; i < N_USUARIS_FITXER; i++)
	{
		cout << "Comment :=>> Usuari: " << nomUsuari[i] << ", " << mailUsuari[i] << ", " << contrassenyaUsuari[i] << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------" << endl;
	cout << "Comment :=>> Afegint usuaris amb el metode afegeixUsuari" << endl;
	cout << "Comment :=>> -------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = N_USUARIS_FITXER; i < N_PROVES_USUARI; i++)
	{
		cout << "Comment :=>> Afegint Usuari: " << nomUsuari[i] << ", " << mailUsuari[i] << ", " << contrassenyaUsuari[i] << endl;

		bool resultat = s.afegeixUsuari(nomUsuari[i], mailUsuari[i], contrassenyaUsuari[i]);
		cout << "Comment :=>> Resultat: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat == resultatAfegeixUsuari[i - N_USUARIS_FITXER])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	const int N_PROVES_DESCARREGA = 4;
	string nomAppDesc[N_PROVES_DESCARREGA] = { "APP_NOM_1", "APP_NOM_1" , "APP_NOM_1" , "APP_NOM_6" };
	string nomUsuariDesc[N_PROVES_DESCARREGA] = { "USUARI_NOM_1", "USUARI_NOM_2" , "USUARI_NOM_6" , "USUARI_NOM_4" };
	string dataDescarrega[N_PROVES_DESCARREGA] = { "DATA_1", "DATA_2" , "DATA_3" , "DATA_4" };
	int tempsDescarrega[N_PROVES_DESCARREGA] = { 10, 20, 30, 40};
	int valoracioDescarrega[N_PROVES_DESCARREGA] = { 1, 2, 3, 4};
	bool resultatAfegeixDescarrega[N_PROVES_DESCARREGA] = { true, true, false, false };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------" << endl;
	cout << "Comment :=>> Afegint descarregues" << endl;
	cout << "Comment :=>> --------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < N_PROVES_DESCARREGA; i++)
	{
		cout << "Comment :=>> Afegint Descarrega: " << nomAppDesc[i] << ", " << nomUsuariDesc[i] << ", " << dataDescarrega[i] << ", " << tempsDescarrega[i] << ", " << valoracioDescarrega[i] << endl;

		bool resultat = s.afegeixDescarrega(nomAppDesc[i], nomUsuariDesc[i], dataDescarrega[i], tempsDescarrega[i], valoracioDescarrega[i]);
		cout << "Comment :=>> Resultat: ";
		mostraBool(resultat);
		cout << endl;
		if (resultat == resultatAfegeixDescarrega[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------" << endl;
	cout << "Comment :=>> Guardant descarregues a fitxer" << endl;
	cout << "Comment :=>> ------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	const int N_PROVES_FITXER = 2;
	string nomAppFitxer = "APP_NOM_1";
	string descripcioAppFitxer = "APP_DESC_1";
	int tamanyAppFitxer = 10;
	int nDescarreguesAppFitxer = 2;


	string nomUsuariFitxer[N_PROVES_FITXER] = { "USUARI_NOM_1", "USUARI_NOM_2"};
	string dataDescarregaFitxer[N_PROVES_FITXER] = { "DATA_1", "DATA_2"};
	int tempsDescarregaFitxer[N_PROVES_FITXER] = { 10, 20};
	int valoracioDescarregaFitxer[N_PROVES_FITXER] = { 1, 2 };

	s.escriuDescarregues("descarregues.txt", nomAppFitxer);

	cout << "Comment :=>> Contingut del fitxer" << endl;
	cout << "Comment :=>> --------------------" << endl;

	ifstream fitxer;
	bool correcte = true;
	string nomAppResultat, descripcioResultat;
	int tamanyResultat, nDescarreguesResultat;
	string nomUsuariResultat, dataResultat;
	int tempsResultat, valoracioResultat;
	fitxer.open("descarregues.txt");
	if (fitxer.is_open())
	{
		fitxer >> nomAppResultat >> descripcioResultat >> tamanyResultat >> nDescarreguesResultat;
		if (!fitxer.eof())
		{
			cout << "Comment :=>> " << nomAppResultat << endl;
			cout << "Comment :=>> " << descripcioResultat << endl;
			cout << "Comment :=>> " << tamanyResultat << endl;
			cout << "Comment :=>> " << nDescarreguesResultat << endl;
		}
		if ((nomAppResultat != nomAppFitxer) || (descripcioResultat != descripcioAppFitxer) || (tamanyResultat != tamanyAppFitxer) || (nDescarreguesResultat != nDescarreguesAppFitxer))
			correcte = false;
		fitxer >> nomUsuariResultat >> dataResultat >> tempsResultat >> valoracioResultat;
		int i = 0;
		while (!fitxer.eof())
		{
			cout << "Comment :=>> " << nomUsuariResultat << endl;
			cout << "Comment :=>> " << dataResultat << endl;
			cout << "Comment :=>> " << tempsResultat << endl;
			cout << "Comment :=>> " << valoracioResultat << endl;
			if (i < N_PROVES_FITXER)
			{
				if ((nomUsuariResultat != nomUsuariFitxer[i]) || (dataResultat != dataDescarregaFitxer[i]) || (tempsResultat != tempsDescarregaFitxer[i]) || (valoracioResultat != valoracioDescarregaFitxer[i]))
					correcte = false;
			}
			i++;
			fitxer >> nomUsuariResultat >> dataResultat >> tempsResultat >> valoracioResultat;
		}
		if (i != N_PROVES_FITXER)
			correcte = false;
		fitxer.close();
	}
	else
		correcte = false;

	cout << "Comment :=>> FINAL DE FITXER" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> " << endl;
	if (correcte)
		cout << "Comment :=>> ESCRITURA CORRECTA" << endl;
	else
	{
		cout << "Comment :=>> ERROR D'ESCRIPTURA" << endl;
		reduccio += 4;
	}
	return reduccio;

}


int main()
{
	float grade = 10;

	grade -= testStore();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	system("pause");
	return 0;
}

