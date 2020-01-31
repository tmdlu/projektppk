

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

	utwor* nastU; ///< wskaŸnik na kolejny element listy podwieszanej

};

/** Element listy jednokierunkowej glownej */
struct sesja {
	string nazwaSesji; ///< nazwa sesji przechowywana w  elemencie listy


	sesja* nastS; ///< wskaŸnik na kolejny element listy
	utwor* utwory;  ///< wskaŸnik na element listy podwieszanej
};
/** Element listy jednokierunkowej*/
struct tablica {
	string wyk; ///< nazwa wykonawcy przechowywana w  elemencie listy jednokierunkowej
	string sesja; ///< nazwa sesji przechowywana w  elemencie listy jednokierunkowej
	tablica* nastT; ///< wskaŸnik na kolejny element listy jednokierunkowej
};

#endif
