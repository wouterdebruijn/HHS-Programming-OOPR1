#ifndef SINGLE_LED_H
#define SINGLE_LED_H

#include <string>
#include "Led.h"
#include "Platform.h"

using namespace std;

class SingleLed : public Led {
    private:
        string kleur;
        int status;
        Platform *gpio;
    public:
        SingleLed(string, double, string, Platform*);
        SingleLed(const SingleLed &led);
        bool zetAan(string);
        void zetUit();
        string connectie();
        int ledStatus();
};

#endif
