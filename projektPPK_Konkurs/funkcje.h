#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 
#include <string>

#include "struktury.h"



/** Funkcja dodaje nazwê sesji na koniec listy g³ownej.
@param pSesja wskaznik na pierwszy element listy – je¿eli element zostanie dododany do listy, wskaŸnik zostanie zmodyfikowany.
@param Sesja nazwa  do dodania na koniec listy g³ownej
*/
void odczytajSesje(sesja*& pSesja, string Sesja);

/** Funkcja dodaje nazwê utworu, wykonawce oraz czas  na koniec listy g³ownej.
@param pSesja wskaznik na pierwszy element listy – je¿eli element zostanie dododany do listy, wskaŸnik na wskaŸnik zostanie zmodyfikowany.
@param nazwaUtoru nazwa utworu  do dodania na koniec listy podwieszanej
@param nazwaWykonawcy nazwa wykonawcy  do dodania na koniec listy podwieszanej
@param czas czas  do dodania na koniec listy podwieszanej
*/
void odczytajUtwory(sesja*& pSesja, string nazwaUtworu, string nazwaWykonawcy, int czas);


/** Funkcja wyszukuje w liœcie szukany element w liœcie g³ownej.
@param pSesja wskaŸnik na pierwszy element listy
@param nazwS nazwa sesji, która jest szukany
@return adres elementu, którego szukamy; je¿eli nie ma takiego elementu, funkcja zwraca wskaŸnik zerowy; je¿eli lista jest pusta, funkcja wzraca wskaŸnik zerowy. */

sesja* ZnajdzSesje(sesja* pSesja, string nazwS);


/** Funkcja zwraca ca³kowity czas trwania wszystkich utworów w danej sesji.
@param pSesja wskaŸnik na pierwszy element listy
@param nazwS nazwa sesji, której chcemy otrzymaæ czas
@return ca³kowity czas trwania sesji */

int CzasCal(sesja* pSesja, string nazwS);

/** Funkcja zwraca iloœæ utworów w danej sesji.
@param pSesja wskaŸnik na pierwszy element listy
@param nazwS nazwa sesji, której chcemy znaæ iloœæ utworów
@return iloœæ utworów w sesji */

int IloscUtworow(sesja* pSesja, string nazwS);

/** Funkcja sprawdza czy istnieje sesja.
@param pSesja wskaŸnik na pierwszy element listy
@param nazwS nazwa sesji, której istnienie chcemy sprawdziæ
@return true lub false*/

bool czyIstniejeSesja(sesja* pSesja, string nazwS);

/** Funkcja usuwa listê internacyjnie.
@param pSesja wskaŸnik na pierwszy element listy – po usuniêciu listy jest równy nullptr.
*/
void usunListy(sesja*& pSesja);



/** Funkcja wypisuje informacje o sesji.
@param pSesja wskaznik na pierwszy element listy.
@param nazwaS nazwa sesji, dla której chcemy wypisaæ informacje

*/

void WypiszInformacjeOSesji(sesja* pSesja, string nazwS);

/** Funkcja zwraca iloœæ wykonaæ  danego utworu.
@param pSesja wskaŸnik na pierwszy element listy
@param nazwU nazwa utworu, którego liczbe wykonañ chcemy
@return iloœæ  wykonañ utworu */
int IloscWykonanU(sesja* pSesja, string nazwU);



/** Funkcja zwraca iloœæ wykonañ utworu przez danego wykonawce.
@param pSesja wskaŸnik na pierwszy element listy
@param wykonawca nazwa nazwa, którego liczbe wykonañ chcemy
@return iloœæ wyst¹pieñ danego wykonawcy */

int IloscWykonanWyk(sesja* pSesja, string wykonawca);


/** Funkcja wypisuje wykonawców i sesje dla danego utworu.
@param pSesja wskaŸnik na pierwszy element listy
@param nazwaU nazwa utworu, dla którego chcemy wypisaæ wykonawców i sesje
*/
void WypisywanieWykonawcowISesje(sesja* pSesja, string nazwU);

/** Funkcja raport o utworze.
@param pSesja wskaŸnik na pierwszy element listy
@param nazwaU nazwa utworu, dla którego chcemy wypisaæ wykonawców i sesje
*/
void WypiszRaportOUtworze(sesja* pSesja, string nazwaU);






/** Funkcja usuwa wiêcej ni¿ jedno wyst¹pienie wykonawcy.
@param pSesja wskaŸnik na pierwszy element listy.
@param wykonawca nazwa wykonawcy, dla którego usuwamy wiêcej ni¿ jedno wyst¹pienie
*/
void usuwanieWystapien(sesja*& pSesja, string wykonawca);



/** Funkcja sprawdza czy strukura pliku tekstowego jest dobra oraz dodaje dane do listy.
@param pSesja wskaŸnik na pierwszy element listy.
@param przelacznik1 parametr z nazw¹ pliku wejœciowego
@param spr wartoœæ logiczna, która na pocz¹tku wskazuje na true
*/

void czytaniePliku(sesja*& pSesja, string przelacznik1, bool& spr);

/** Funkcja zwraca nazwe pliku wyjœciwego, gdy nazwa pliku nie ma rozszerzenia .txt .
@param nazwaP nazwa pliku wejœciowego bez rozszerzenia .txt
@return nazwaPliku z rozszerzeniem */
string txt(string nazwaP);

/** Funkcja zapisuje do pliku wyjœciowego wartoœci zmienionej listy.
@param pSesja wskaŸnik na pierwszy element listy.
@param przelacznik5 parametr z nazw¹ pliku wyjœciowego
*/
void wypiszDoPliku(sesja* pSesja, string przelacznik5);



/** Funkcja zapisuje wartoœci parametrów.
@param argc iloœæ argumentów 
@param argv[] argumenty
@param przelacznik1 parametr z nazw¹ pliku wejœciowego
@param przelacznik2 parametr z nazw¹ wykonawcy
@param przelacznik3 parametr z nazw¹ utworu
@param przelacznik4 parametr z nazw¹ sesji
@param przelacznik5 parametr z nazw¹ pliku wyjœciowego
*/
void przelaczniki(int argc, char* argv[], string& przelacznik1, string& przelacznik2, string& przelacznik3, string& przelacznik4, string& przelacznik5);

/** Funkcja sprawdza czy parametry istniej¹ i czy plik wejœciowy jest dobrze zapisany oraz jak sprawdzanie powiedzie siê pozytywnie, to wykonuje funkcje zwi¹zane z parametrami.
@param pSesja wskaŸnik na pierwszy element listy.
@param przelacznik1 parametr z nazw¹ pliku wejœciowego
@param przelacznik2 parametr z nazw¹ wykonawcy
@param przelacznik3 parametr z nazw¹ utworu
@param przelacznik4 parametr z nazw¹ sesji
@param przelacznik5 parametr z nazw¹ pliku wyjœciowego
*/
void Dzialania(sesja*& pSesja, string przelacznik1, string przelacznik2, string przelacznik3, string przelacznik4, string przelacznik5);

/** Funkcja dodaje nazwy wykonawcy oraz sesji na koniec listy jednokierunkowej.
@param pHead wskaznik na pierwszy element listy – je¿eli element zostanie dododany do listy, wskaŸnik  zostanie zmodyfikowany.
@param nazwaW nazwa wykonawcy  do dodania na koniec listy
@param nazwS nazwa sesji  do dodania na koniec listy
*/

void odczytajTab(tablica*& pHead, string nazwaW, string nazwS);


/**Funkcja sortuje tablice wed³ug wykonwaców.
@param pHead wskaznik na pierwszy element listy

*/

void sortowanieTab(tablica*& pHead);

/** Funkcja usuwa listê internacyjnie.
@param pHead wskaŸnik na pierwszy element listy – po usuniêciu listy jest równy nullptr
*/

void usunTab(tablica*& pHead);

/** Funkcja wypisuje sesje bez powtórzeñ.
@param pHead wskaŸnik na pierwszy element listy
*/

void WypiszSesjeBezPowtarzania(tablica* pHead);

/** Funkcja wypisuje wykonawców bez powtórzeñ.
@param pHead wskaŸnik na pierwszy element listy
*/
void WypiszWykonawcowBezPowtarzania(tablica* pHead);














#endif
