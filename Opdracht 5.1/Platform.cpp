/*
 * Platform.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: john
 */

#include "Platform.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include<unistd.h>

using namespace std;

Platform::Platform(int nr,int snr):gpioNummer(nr),studentnummer(snr),productienummer(0){

	string s=to_string(gpioNummer);
	zetPin("export",s);
	usleep(250000); // 250ms delay
	zetPin("direction","out");
    int x=studentnummer;
	while(x) {productienummer+=x%10;x/=10;}

}


Platform::~Platform() {
	string s=to_string(gpioNummer);
	zetPin("unexport",s);
}


int Platform::nummerGPIO() {
	return gpioNummer;
}

void Platform::zetSpanningOpPin(bool b) {
   if(b)
	   zetPin("value","1");
   else
	   zetPin("value","0");
}

void Platform::ontkoppel() {
	string s=to_string(gpioNummer);
	zetPin("unexport",s);
}

void Platform::zetPin(string s,string value) {

	stringstream p;
	p << GPIO_PATH;
	if(s != "export" && s != "unexport")
		p <<"gpio"<< gpioNummer<<"/";

	p<<s;
    string naam=p.str();
    ofstream fs;

	fs.open(naam);
	fs << value;
	fs.close();
}
