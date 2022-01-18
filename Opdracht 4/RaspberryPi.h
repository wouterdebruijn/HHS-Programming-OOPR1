/*
 * Platform.h
 *
 *  Created on: Oct 15, 2018
 *      Author: john
 */

#ifndef RASPBERRY_H
#define RASPBERRY_H
#define GPIO_PATH "/sys/class/gpio/"
#include <string>

#include "AansluitingsPlatform.h"

using namespace std;

class RaspberryPi : public AansluitingsPlatform {
public:
	RaspberryPi(int,int);
	~RaspberryPi();
	void zetSpanningOpPin(bool);
	void ontkoppel();

	int nummerGPIO();

private:
	int gpioNummer;
	string gpioPath;
	void zetPin(string,string);
	int studentnummer;
	int productienummer;

};

#endif /* RASPBERRY_H */
