#ifndef LED_H
#define LED_H
#pragma once

#include <string>
#include "Platform.h"
#define GPIO_SYSFS "/sys/class/gpio/"
#define WACHTTIJD 100000
using namespace std;
class Led
{
private:
    bool status;
    string eigenaar;
    bool aangesloten;
    int writeGPIO(const char *, const char *);
    Platform *platform;

public:
    Led(string owner, Platform *platform);
    bool ledStatus();
    void zetAan();
    void zetUit();
    bool isAangesloten() const;
    int gpioPin() const;
};
#endif