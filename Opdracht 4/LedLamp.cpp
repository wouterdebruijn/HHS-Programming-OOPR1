#include "LedLamp.h"

#include <iostream>

bool LedLamp::zetAan(string kleur) {
    bool value = false;

    for (int i = 0; i < this->leds.size(); i++) {
        if (this->leds[i] != nullptr)
            value |= this->leds[i]->zetAan(kleur);
    }

    return value;
}

void LedLamp::zetUit() {
    for (int i = 0; i < this->leds.size(); i++) {
        if (this->leds[i] != nullptr)
            this->leds[i]->zetUit();
    }
}

string LedLamp::connectie() {
    for (int i = 0; i < this->leds.size(); i++) {
        if (this->leds[i] != nullptr) {
            // Not relevent for this assignment.
            cout << this->leds[i]->connectie();
            cout << "\n";
        }
    }

    return "19, 12, 13, 24";
}

int LedLamp::ledStatus() {
    // Not relevent for this assignment.
    return 42;
}

LedLamp::LedLamp(string owner) {
    this->eigenaar = owner;
}

void LedLamp::voegLedToe(Led *led) {
    // Add LED to storage array;

    std::cout << "Hello World!\n";

    for (int i = 0; i < 8; i++) {
        if (this->leds[i] == 0) {
            this->leds[i] = led;
            std::cout << "New led added: " << i << "\n";
            break;
        }
    }
}