#ifndef SINGLE_LED_H
#define SINGLE_LED_H

#include <string>
#include "Led.h"
#include "AansluitingsPlatform.h"

using namespace std;

class SingleLed : public Led {
    private:
        string kleur;
        int status;
        AansluitingsPlatform *gpio;
    public:
        SingleLed(string, double, string, AansluitingsPlatform*);
        SingleLed(const SingleLed &led);
        bool zetAan(string);
        void zetUit();
        string connectie();
        int ledStatus();
};

#endif
