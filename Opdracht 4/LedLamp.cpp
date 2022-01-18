#include "LedLamp.h"

#include <iostream>

bool LedLamp::zetAan(string kleur) {
    bool value = false;

    for (int i = 0; i < this->leds.size(); i++) {
        if (this->leds.at(i) != nullptr)
            value |= this->leds.at(i)->zetAan(kleur);
    }

    return value;
}

void LedLamp::zetUit() {
    for (int i = 0; i < this->leds.size(); i++) {
        if (this->leds[i] != nullptr)
            this->leds.at(i)->zetUit();
    }
}

string LedLamp::connectie() {
    for (int i = 0; i < this->leds.size(); i++) {
        if (this->leds.at(i) != nullptr) {
            // Not relevent for this assignment.
            cout << this->leds.at(i)->connectie();
            cout << "\n";
        }
    }

    return ""; // Should create this string from stream. But that doesn't matter for this assignment.
}

int LedLamp::ledStatus() {
    // Not relevent for this assignment.
    return 42;
}

LedLamp::LedLamp(string owner) {
    this->eigenaar = owner;
}

void LedLamp::voegLedToe(Led *led) {
    // Add LED to storage vector;
    this->leds.push_back(led);
}