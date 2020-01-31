#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 
#include <string>

#include "struktury.h"



/** Funkcja dodaje nazw� sesji na koniec listy g�ownej.
@param pSesja wskaznik na pierwszy element listy � je�eli element zostanie dododany do listy, wska�nik zostanie zmodyfikowany.
@param Sesja nazwa  do dodania na koniec listy g�ownej
*/
void odczytajSesje(sesja*& pSesja, string Sesja);

/** Funkcja dodaje nazw� utworu, wykonawce oraz czas  na koniec listy g�ownej.
@param pSesja wskaznik na pierwszy element listy � je�eli element zostanie dododany do listy, wska�nik na wska�nik zostanie zmodyfikowany.
@param nazwaUtoru nazwa utworu  do dodania na koniec listy podwieszanej
@param nazwaWykonawcy nazwa wykonawcy  do dodania na koniec listy podwieszanej
@param czas czas  do dodania na koniec listy podwieszanej
*/
void odczytajUtwory(sesja*& pSesja, string nazwaUtworu, string nazwaWykonawcy, int czas);


/** Funkcja wyszukuje w li�cie szukany element w li�cie g�ownej.
@param pSesja wska�nik na pierwszy element listy
@param nazwS nazwa sesji, kt�ra jest szukany
@return adres elementu, kt�rego szukamy; je�eli nie ma takiego elementu, funkcja zwraca wska�nik zerowy; je�eli lista jest pusta, funkcja wzraca wska�nik zerowy. */

sesja* ZnajdzSesje(sesja* pSesja, string nazwS);


/** Funkcja zwraca ca�kowity czas trwania wszystkich utwor�w w danej sesji.
@param pSesja wska�nik na pierwszy element listy
@param nazwS nazwa sesji, kt�rej chcemy otrzyma� czas
@return ca�kowity czas trwania sesji */

int CzasCal(sesja* pSesja, string nazwS);

/** Funkcja zwraca ilo�� utwor�w w danej sesji.
@param pSesja wska�nik na pierwszy element listy
@param nazwS nazwa sesji, kt�rej chcemy zna� ilo�� utwor�w
@return ilo�� utwor�w w sesji */

int IloscUtworow(sesja* pSesja, string nazwS);

/** Funkcja sprawdza czy istnieje sesja.
@param pSesja wska�nik na pierwszy element listy
@param nazwS nazwa sesji, kt�rej istnienie chcemy sprawdzi�
@return true lub false*/

bool czyIstniejeSesja(sesja* pSesja, string nazwS);

/** Funkcja usuwa list� internacyjnie.
@param pSesja wska�nik na pierwszy element listy � po usuni�ciu listy jest r�wny nullptr.
*/
void usunListy(sesja*& pSesja);



/** Funkcja wypisuje informacje o sesji.
@param pSesja wskaznik na pierwszy element listy.
@param nazwaS nazwa sesji, dla kt�rej chcemy wypisa� informacje

*/

void WypiszInformacjeOSesji(sesja* pSesja, string nazwS);

/** Funkcja zwraca ilo�� wykona�  danego utworu.
@param pSesja wska�nik na pierwszy element listy
@param nazwU nazwa utworu, kt�rego liczbe wykona� chcemy
@return ilo��  wykona� utworu */
int IloscWykonanU(sesja* pSesja, string nazwU);



/** Funkcja zwraca ilo�� wykona� utworu przez danego wykonawce.
@param pSesja wska�nik na pierwszy element listy
@param wykonawca nazwa nazwa, kt�rego liczbe wykona� chcemy
@return ilo�� wyst�pie� danego wykonawcy */

int IloscWykonanWyk(sesja* pSesja, string wykonawca);


/** Funkcja wypisuje wykonawc�w i sesje dla danego utworu.
@param pSesja wska�nik na pierwszy element listy
@param nazwaU nazwa utworu, dla kt�rego chcemy wypisa� wykonawc�w i sesje
*/
void WypisywanieWykonawcowISesje(sesja* pSesja, string nazwU);

/** Funkcja raport o utworze.
@param pSesja wska�nik na pierwszy element listy
@param nazwaU nazwa utworu, dla kt�rego chcemy wypisa� wykonawc�w i sesje
*/
void WypiszRaportOUtworze(sesja* pSesja, string nazwaU);






/** Funkcja usuwa wi�cej ni� jedno wyst�pienie wykonawcy.
@param pSesja wska�nik na pierwszy element listy.
@param wykonawca nazwa wykonawcy, dla kt�rego usuwamy wi�cej ni� jedno wyst�pienie
*/
void usuwanieWystapien(sesja*& pSesja, string wykonawca);



/** Funkcja sprawdza czy strukura pliku tekstowego jest dobra oraz dodaje dane do listy.
@param pSesja wska�nik na pierwszy element listy.
@param przelacznik1 parametr z nazw� pliku wej�ciowego
@param spr warto�� logiczna, kt�ra na pocz�tku wskazuje na true
*/

void czytaniePliku(sesja*& pSesja, string przelacznik1, bool& spr);

/** Funkcja zwraca nazwe pliku wyj�ciwego, gdy nazwa pliku nie ma rozszerzenia .txt .
@param nazwaP nazwa pliku wej�ciowego bez rozszerzenia .txt
@return nazwaPliku z rozszerzeniem */
string txt(string nazwaP);

/** Funkcja zapisuje do pliku wyj�ciowego warto�ci zmienionej listy.
@param pSesja wska�nik na pierwszy element listy.
@param przelacznik5 parametr z nazw� pliku wyj�ciowego
*/
void wypiszDoPliku(sesja* pSesja, string przelacznik5);



/** Funkcja zapisuje warto�ci parametr�w.
@param argc ilo�� argument�w 
@param argv[] argumenty
@param przelacznik1 parametr z nazw� pliku wej�ciowego
@param przelacznik2 parametr z nazw� wykonawcy
@param przelacznik3 parametr z nazw� utworu
@param przelacznik4 parametr z nazw� sesji
@param przelacznik5 parametr z nazw� pliku wyj�ciowego
*/
void przelaczniki(int argc, char* argv[], string& przelacznik1, string& przelacznik2, string& przelacznik3, string& przelacznik4, string& przelacznik5);

/** Funkcja sprawdza czy parametry istniej� i czy plik wej�ciowy jest dobrze zapisany oraz jak sprawdzanie powiedzie si� pozytywnie, to wykonuje funkcje zwi�zane z parametrami.
@param pSesja wska�nik na pierwszy element listy.
@param przelacznik1 parametr z nazw� pliku wej�ciowego
@param przelacznik2 parametr z nazw� wykonawcy
@param przelacznik3 parametr z nazw� utworu
@param przelacznik4 parametr z nazw� sesji
@param przelacznik5 parametr z nazw� pliku wyj�ciowego
*/
void Dzialania(sesja*& pSesja, string przelacznik1, string przelacznik2, string przelacznik3, string przelacznik4, string przelacznik5);

/** Funkcja dodaje nazwy wykonawcy oraz sesji na koniec listy jednokierunkowej.
@param pHead wskaznik na pierwszy element listy � je�eli element zostanie dododany do listy, wska�nik  zostanie zmodyfikowany.
@param nazwaW nazwa wykonawcy  do dodania na koniec listy
@param nazwS nazwa sesji  do dodania na koniec listy
*/

void odczytajTab(tablica*& pHead, string nazwaW, string nazwS);


/**Funkcja sortuje tablice wed�ug wykonwac�w.
@param pHead wskaznik na pierwszy element listy

*/

void sortowanieTab(tablica*& pHead);

/** Funkcja usuwa list� internacyjnie.
@param pHead wska�nik na pierwszy element listy � po usuni�ciu listy jest r�wny nullptr
*/

void usunTab(tablica*& pHead);

/** Funkcja wypisuje sesje bez powt�rze�.
@param pHead wska�nik na pierwszy element listy
*/

void WypiszSesjeBezPowtarzania(tablica* pHead);

/** Funkcja wypisuje wykonawc�w bez powt�rze�.
@param pHead wska�nik na pierwszy element listy
*/
void WypiszWykonawcowBezPowtarzania(tablica* pHead);














#endif
