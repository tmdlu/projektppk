#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>  
#include <string>
#include <string.h>

#include <stdio.h>
#include "funkcje.h"

void odczytajTab(tablica*& pHead, string nazwaW, string nazwS)
{
	tablica* tempHead = pHead;

	tablica* pNowy = new tablica;
	pNowy->sesja = nazwS;
	pNowy->wyk = nazwaW;
	pNowy->nastT = nullptr;

	if (tempHead != nullptr) {
		while (tempHead->nastT != nullptr)
			tempHead = tempHead->nastT;
		tempHead->nastT = pNowy;
	}
	else
		pHead = pNowy;
}
void sortowanieTab(tablica*& pHead)
{
	string b, c;
	tablica* tempHead = pHead;
	while (tempHead->nastT)
	{
		if (tempHead->wyk > tempHead->nastT->wyk)
		{
			b = tempHead->wyk;
			tempHead->wyk = tempHead->nastT->wyk;
			tempHead->nastT->wyk = b;


			c = tempHead->sesja;
			tempHead->sesja = tempHead->nastT->sesja;
			tempHead->nastT->sesja = c;

		}
		tempHead = tempHead->nastT;
	}
}
void usunTab(tablica*& pHead)
{

	while (pHead)
	{

		auto p = pHead->nastT;
		delete pHead;
		pHead = p;
	}
}
void WypiszSesjeBezPowtarzania(tablica* pHead)
{
	tablica* tempHead = pHead;

	while (tempHead)
	{
		auto s = tempHead->sesja;
		tablica* tempHead2 = tempHead;
		while (tempHead2->nastT)
		{
			if (tempHead2->nastT->sesja.compare(s) == 0)
			{


				tablica* us = tempHead2->nastT;
				tempHead2->nastT = us->nastT;
				delete us;


			}
			else
				tempHead2 = tempHead2->nastT;
		}
		tempHead = tempHead->nastT;
	}
	while (pHead)
	{
		cout << pHead->sesja << " ";
		pHead = pHead->nastT;
	}

}
void WypiszWykonawcowBezPowtarzania(tablica* pHead)
{
	tablica* tempHead = pHead;

	while (tempHead->nastT)
	{


		if (tempHead->wyk.compare(tempHead->nastT->wyk) == 0)
		{


			tablica* us = tempHead->nastT;
			tempHead->nastT = us->nastT;
			delete us;


		}
		else
			tempHead = tempHead->nastT;

	}
	while (pHead)
	{
		cout << pHead->wyk << " ";
		pHead = pHead->nastT;
	}
}












void odczytajSesje(sesja*& pSesja, string Sesja)
{
	sesja* tempSesja = pSesja;

	sesja* pNowy = new sesja;
	(*pNowy).nazwaSesji = Sesja;
	pNowy->nastS = nullptr;
	pNowy->utwory = nullptr;

	if (tempSesja != nullptr) {
		while (tempSesja->nastS != nullptr)
			tempSesja = tempSesja->nastS;
		tempSesja->nastS = pNowy;
	}
	else
		pSesja = pNowy;



}


void odczytajUtwory(sesja*& pSesja, string nazwaUtworu, string nazwaWykonawcy, int czas)
{
	sesja* tempSesja = pSesja;


	while (tempSesja->nastS != nullptr)
		tempSesja = tempSesja->nastS;

	utwor* pNowyU = new utwor;
	(*pNowyU).nazwaUtworu = nazwaUtworu;
	(*pNowyU).wyk = nazwaWykonawcy;
	(*pNowyU).czas = czas;
	pNowyU->nastU = nullptr;



	if (tempSesja->utwory == nullptr)
	{
		tempSesja->utwory = pNowyU;
	}

	else
	{
		auto pUtwor = tempSesja->utwory;
		while (pUtwor->nastU != nullptr)
			pUtwor = pUtwor->nastU;
		pUtwor->nastU = pNowyU;
	}
}


sesja* ZnajdzSesje(sesja* pSesja, string nazwS) 
{

	while (pSesja)
	{
		if (pSesja->nazwaSesji.compare(nazwS) == 0)
			return pSesja;
		pSesja = pSesja->nastS;
	}
	return nullptr;

}

int CzasCal(sesja* pSesja, string nazwS)
{


	auto p = ZnajdzSesje(pSesja, nazwS)->utwory;


	int sumaCzasu = 0;

	while (p != nullptr)
	{
		sumaCzasu += p->czas;

		p = p->nastU;
	}
	return sumaCzasu;

}

int IloscUtworow(sesja* pSesja, string nazwS)
{

	auto p = ZnajdzSesje(pSesja, nazwS)->utwory;

	int sumaUtworow = 0;

	while (p != nullptr)
	{

		sumaUtworow++;
		p = p->nastU;
	}
	return sumaUtworow;

}
bool czyIstniejeSesja(sesja* pSesja, string nazwS)
{



	int sumaUtworow = 0;

	while (pSesja != nullptr)
	{

		if (pSesja->nazwaSesji.compare(nazwS) == 0)
			return true;
		pSesja = pSesja->nastS;
	}
	return false;


}
bool sczyIstniejeSesja(sesja* pSesja, string nazwS)
{

	auto tempSesja = pSesja;

	int sumaUtworow = 0;

	while (tempSesja != nullptr)
	{

		if (tempSesja->nazwaSesji.compare(nazwS) == 0)
			return true;
		tempSesja = tempSesja->nastS;
	}
	return false;


}


void usunListy(sesja*& pSesja)
{

	while (pSesja)
	{
		while (pSesja->utwory)
		{
			auto l = pSesja->utwory->nastU;
			delete pSesja->utwory;
			pSesja->utwory = l;
		}

		auto p = pSesja->nastS;
		delete pSesja;
		pSesja = p;
	}
}





void WypiszInformacjeOSesji(sesja* pSesja, string nazwS)
{
	if (czyIstniejeSesja(pSesja, nazwS))
	{
		auto p = ZnajdzSesje(pSesja, nazwS);
		auto utwor = p->utwory;
		cout << "Informacje o sesji \"" << p->nazwaSesji << "\": Liczba utworow: " << IloscUtworow(pSesja, nazwS) << ", Calkowity czas trwania: " << CzasCal(pSesja, nazwS) << " sekund, Utwory: ";//
		if (utwor)
		{
			for (int i = 0; i < IloscUtworow(pSesja, nazwS); i++)
			{
				cout << utwor->nazwaUtworu << " ";

				utwor = utwor->nastU;
			}
			cout << endl;
		}
	}
	else
		cout << "Brak informacji o sesji, poniewaz podana sesja nie istnieje" << endl;
}


int IloscWykonanU(sesja* pSesja, string nazwU)
{

	int s = 0;
	while (pSesja)
	{
		auto utwor = pSesja->utwory;
		while (utwor)
		{
			if (utwor->nazwaUtworu == nazwU)
				s++;

			utwor = utwor->nastU;


		}




		pSesja = pSesja->nastS;
	}
	return s;

}

int IloscWykonanWyk(sesja* pSesja, string wykonawca)
{

	int s = 0;
	while (pSesja)
	{
		auto utwor = pSesja->utwory;
		while (utwor)
		{
			if (utwor->wyk.compare(wykonawca) == 0)
				s++;

			utwor = utwor->nastU;


		}




		pSesja = pSesja->nastS;
	}
	return s;
}



void WypisywanieWykonawcowISesje(sesja* pSesja, string nazwU)
{




	tablica* tab = nullptr;
	tablica* tab2 = nullptr;


	while (pSesja)
	{
		auto utwor = pSesja->utwory;
		while (utwor)
		{
			if (utwor->nazwaUtworu.compare(nazwU) == 0)
			{
				odczytajTab(tab, utwor->wyk, pSesja->nazwaSesji);
				odczytajTab(tab2, utwor->wyk, pSesja->nazwaSesji);
			}
			utwor = utwor->nastU;
		}




		pSesja = pSesja->nastS;
	}
	sortowanieTab(tab);
	sortowanieTab(tab2);
	cout << "Wykonawcy: ";
	WypiszWykonawcowBezPowtarzania(tab);
	cout << " Sesje: ";
	WypiszSesjeBezPowtarzania(tab2);
	usunTab(tab);
	usunTab(tab2);

}
void WypiszRaportOUtworze(sesja* pSesja, string nazwaU)
{

	
	if (IloscWykonanU(pSesja, nazwaU) != 0)
	{
		if (pSesja)
		{
			cout << "Raport o utworze  \"" << nazwaU << "\" liczba wykonan: " << IloscWykonanU(pSesja, nazwaU) << " ";//
			WypisywanieWykonawcowISesje(pSesja, nazwaU);
			cout << endl;


		}
	}
	else
		cout << "Brak raportu, poniewaz nie ma podanego utworu w sesjach." << endl;


}

void usuwanieWystapien(sesja*& pSesja, string wykonawca)
{
	
	int b = 1;
	sesja* tempSesja = pSesja;
	int ile = IloscWykonanWyk(tempSesja, wykonawca);
	if (ile != 0)
	{
		if (ile > 1)
		{
			while (tempSesja)
			{
				utwor* tempUtwor = tempSesja->utwory;
				while (tempUtwor->nastU)
				{


					if (wykonawca.compare(tempUtwor->nastU->wyk) == 0)
					{
						if (b == 1)
						{
							tempUtwor = tempUtwor->nastU;
							b--;
						}
						else
						{
							utwor* us = tempUtwor->nastU;
							tempUtwor->nastU = us->nastU;
							delete us;
						}

					}
					else
						tempUtwor = tempUtwor->nastU;

				}
				tempSesja = tempSesja->nastS;
			}
		}
	}
	else
		cout << "Nie istnieje taki wykonawca" << endl;
}






void czytaniePliku(sesja*& pSesja, string przelacznik1, bool& spr)
{
	
	ifstream Konkurs(przelacznik1);
	string fileLine, sesja;
	int b = 0, s = 0;
	spr = true;
	if (Konkurs)
	{


		while (getline(Konkurs, fileLine) && spr)
		{



			if (fileLine.compare("sesja:") == 0)
			{
				getline(Konkurs, fileLine);
				odczytajSesje(pSesja, fileLine);
				b++;
			}

			else if (fileLine.compare("utwor:") == 0 && b > 0)
			{

				getline(Konkurs, fileLine);

				//istringstream iss(fileLine);
				string wykonawca;
				string utwor;
				int czas;
				utwor = fileLine;
				getline(Konkurs, fileLine);
				if (fileLine.compare("wykonawca:") == 0)
				{
					getline(Konkurs, fileLine);
					wykonawca = fileLine;
					getline(Konkurs, fileLine);
					if (fileLine.compare("czas(sec):") == 0)
					{
						getline(Konkurs, fileLine);
						istringstream iss(fileLine);
						if (iss >> czas)
						{
							odczytajUtwory(pSesja, utwor, wykonawca, czas);
						}
						else
							spr = false;



					}
					else
						spr = false;
				}
				else
					spr = false;


			}

			else if (fileLine.compare("sesja:") != 0 || fileLine.compare("utwor:") != 0)
			{
				spr = false;
			}




		}
		if (spr == false)
		{
			cout << " zla struktura";
		}


	}

	else
	{
		cout << "Nie ma takiego pliku txt do przeczytania." << endl;
		spr = false;

	}
	if (ifstream(przelacznik1, ios::ate).tellg() == 0)
	{
		cout << " plik pusty" << endl;
		spr = false;
	}


	Konkurs.close();
}
string txt(string nazwaP)
{
	string roz = ".txt";
	for (int i = 0; roz[i] != '\0'; i++)
	{
		nazwaP.push_back(roz[i]);
	}
	return nazwaP;
}

void wypiszDoPliku(sesja* pSesja, string przelacznik5)
{
	if (przelacznik5.substr(przelacznik5.length() - 4, 4).compare(".txt") != 0)
		przelacznik5 = txt(przelacznik5);

	ofstream plikWy;
	plikWy.open(przelacznik5);

	if (plikWy)
	{

		while (pSesja)
		{
			plikWy << "sesja:" << endl << pSesja->nazwaSesji << endl;

			utwor* utwor = pSesja->utwory;
			while (utwor != nullptr)
			{


				plikWy << "utwor:" << endl << utwor->nazwaUtworu << endl << "wykonawca:" << endl << utwor->wyk << endl << "czas(sec):" << endl << utwor->czas << endl;


				utwor = utwor->nastU;
			}
			pSesja = pSesja->nastS;
		}

		plikWy << flush;
		plikWy.close();

	}
}




void przelaczniki(int argc, char* argv[], string& przelacznik1, string& przelacznik2, string& przelacznik3, string& przelacznik4, string& przelacznik5)
{

	for (int i = 0; i < argc; i++)
	{
		string a = argv[i];
		if (a.compare("-fin") == 0)
		{
			przelacznik1 = argv[i + 1];
			i++;
		}

		if (a.compare("-w") == 0)
		{
			przelacznik2 = argv[i + 1];
			i++;
		}

		if (a.compare("-u") == 0)
		{
			przelacznik3 = argv[i + 1];
			i++;
		}
		if (a.compare("-sesja") == 0)
		{
			przelacznik4 = argv[i + 1];
			i++;
		}
		if (a.compare("-fout") == 0)
		{
			przelacznik5 = argv[i + 1];
			i++;
		}
	}

}

void Dzialania(sesja*& pSesja, string przelacznik1, string przelacznik2, string przelacznik3, string przelacznik4, string przelacznik5)
{
	if (przelacznik1.length() != 0 && przelacznik1.substr(przelacznik1.length() - 4, 4).compare(".txt") == 0)
	{
		bool spr;
		czytaniePliku(pSesja, przelacznik1, spr);
		if (spr)
		{
			if (przelacznik3.length() != 0)
			{
				WypiszRaportOUtworze(pSesja, przelacznik3);
			}
			else
				cout << "Nie podano parametru zwiazanego z utworem." << endl;
			if (przelacznik4.length() != 0)
			{
				WypiszInformacjeOSesji(pSesja, przelacznik4);
			}
			else
				cout << "Nie podano parametru zwiazanego z sesja." << endl;
			if (przelacznik2.length() != 0)
			{
				usuwanieWystapien(pSesja, przelacznik2);
			}
			else
				cout << "Nie podano parametru zwiazanego z wykonawca." << endl;


			if (przelacznik5.length() != 0)
			{

				wypiszDoPliku(pSesja, przelacznik5);
			}
			else
				cout << "Nie podano nazwy pliku do zapisu." << endl;


		}
	}
	else
		cout << "zly przelacznik/brak pliku." << endl;


}

