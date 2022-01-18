#ifndef LED_LAMP_H
#define LED_LAMP_H

#include <string>
#include "Led.h"

#include <vector>

using namespace std;

class LedLamp : public Led {
    private:
        vector<Led*> leds;
    public:
        LedLamp(string);
        bool zetAan(string);
        void zetUit();
        string connectie();
        void voegLedToe(Led*);
        int ledStatus();
};

#endif
