#include "Led.h"
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constructors (with overloading)
Led::Led()
{
    portnummer = 0;
    eigenaar = "nobody";
    aangesloten = true;

    writeGPIO(GPIO_SYSFS "export", to_string(portnummer).c_str());
}

Led::Led(int x) : portnummer(x), eigenaar("nobody"), aangesloten(true)
{
    writeGPIO(GPIO_SYSFS "export", to_string(portnummer).c_str());
}

Led::Led(int x, string y) : portnummer(x), eigenaar(y), aangesloten(true)
{
    writeGPIO(GPIO_SYSFS "export", to_string(portnummer).c_str());
}

// Public functions
void Led::zetAan()
{
    // Construct the correct path to the provided GPIO pin.
    ostringstream oss;
    oss << GPIO_SYSFS "gpio" << this->portnummer << "/value";
    string path = oss.str();

    // Write to the GPIO file
    writeGPIO(path.c_str(), "1");
}

void Led::zetUit()
{
    // Construct the correct path to the provided GPIO pin.
    ostringstream oss;
    oss << GPIO_SYSFS "gpio" << this->portnummer << "/value";
    string path = oss.str();

    // Write to the GPIO file
    writeGPIO(path.c_str(), "0");
}

// Simple getters
bool Led::isAangesloten() const
{
    return aangesloten;
}

int Led::gpioPin() const
{
    return portnummer;
}

// Private functions
int Led::writeGPIO(const char filename[], const char value[])
{
    FILE *fp;                  // create a file pointer fp
    fp = fopen(filename, "w"); // open file for writing
    fprintf(fp, "%s", value);  // send the value to the file
    fclose(fp);                // close the file using fp
    return 0;
}
