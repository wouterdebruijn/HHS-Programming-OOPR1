#ifndef LED_LAMP_H
#define LED_LAMP_H

#include <string>
#include "Led.h"

#include <array>

using namespace std;

class LedLamp : public Led {
    private:
        array<Led*, 8> leds = {nullptr};
    public:
        LedLamp(string);
        bool zetAan(string);
        void zetUit();
        string connectie();
        void voegLedToe(Led*);
        int ledStatus();
};

#endif
