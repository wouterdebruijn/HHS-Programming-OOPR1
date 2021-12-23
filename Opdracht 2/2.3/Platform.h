/*
 * Platform.h
 *
 *  Created on: Oct 15, 2018
 *      Author: john
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_
#define GPIO_PATH "/sys/class/gpio/"
#include <string>

using namespace std;

class Platform {
public:
	Platform(int,int);
	~Platform();
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

#endif /* PLATFORM_H_ */
