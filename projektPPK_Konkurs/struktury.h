

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream> 
#include <string>
#include <string.h>

using namespace std;

/** Element listy podwieszanej */
struct utwor {

	string nazwaUtworu; ///< nazwa utowru przechowywana w  elemencie listy podwieszanej
	string wyk; ///< nazwa wykonawcy przechowywana w  elemencie listy podwieszanej
	int czas; ///< czas utworu przechowywany w  elemencie listy podwieszanej

	utwor* nastU; ///< wska�nik na kolejny element listy podwieszanej

};

/** Element listy jednokierunkowej glownej */
struct sesja {
	string nazwaSesji; ///< nazwa sesji przechowywana w  elemencie listy


	sesja* nastS; ///< wska�nik na kolejny element listy
	utwor* utwory;  ///< wska�nik na element listy podwieszanej
};
/** Element listy jednokierunkowej*/
struct tablica {
	string wyk; ///< nazwa wykonawcy przechowywana w  elemencie listy jednokierunkowej
	string sesja; ///< nazwa sesji przechowywana w  elemencie listy jednokierunkowej
	tablica* nastT; ///< wska�nik na kolejny element listy jednokierunkowej
};

#endif
