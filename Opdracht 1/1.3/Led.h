#ifndef LED_H
#define LED_H
#pragma once

#include <string>
#define GPIO_SYSFS "/sys/class/gpio/"
#define WACHTTIJD 100000
using namespace std;
class Led
{
private:
    bool aangesloten;
    int portnummer;
    string eigenaar;
    int writeGPIO(const char *, const char *);

public:
    Led(int);
    Led(int, string);
    Led();
    void zetAan();
    void zetUit();
    bool isAangesloten() const;
    int gpioPin() const;
};
#endif