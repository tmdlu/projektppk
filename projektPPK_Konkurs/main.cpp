#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>  
#include <string>
#include <string.h>

#include <stdio.h>
#include "funkcje.h"











int main(int argc, char* argv[])
{
	{
		sesja* pKon = nullptr;
		string przelacznik1, przelacznik2, przelacznik3, przelacznik4, przelacznik5;
		przelaczniki(argc, argv, przelacznik1, przelacznik2, przelacznik3, przelacznik4, przelacznik5);
		Dzialania(pKon, przelacznik1, przelacznik2, przelacznik3, przelacznik4, przelacznik5);
		usunListy(pKon);
	}
	_CrtDumpMemoryLeaks();
	

	return 0;
}

