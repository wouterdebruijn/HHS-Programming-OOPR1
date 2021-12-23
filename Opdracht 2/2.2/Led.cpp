#include "Led.h"
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constructors (with overloading)
Led::Led(string owner, Platform *platform) {
    this->platform = platform;
    this->eigenaar = owner;
}

bool Led::ledStatus() {
    return this->status;
}

// Public functions
void Led::zetAan()
{
    this->platform->zetSpanningOpPin(true);
    this->status = true;
}

void Led::zetUit()
{
    this->platform->zetSpanningOpPin(false);
    this->status = false;
}

// Simple getters
bool Led::isAangesloten() const
{
    return aangesloten;
}

int Led::gpioPin() const
{
    return this->platform->nummerGPIO();
}