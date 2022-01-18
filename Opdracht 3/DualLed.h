#ifndef DUAL_LED_H
#define DUAL_LED_H

#include <string>
#include "Led.h"
#include "Platform.h"

using namespace std;

class DualLed : public Led {
    private:
        string kleur;
        string kleur1;
        int status;
        int status1;
        Platform *gpio;
        Platform *gpio1;
    public:
        DualLed(string, double, string, string, Platform*, Platform*);
        DualLed(const DualLed &led);
        bool zetAan(string);
        void zetUit();
        string connectie();
        int ledStatus();
};

#endif
