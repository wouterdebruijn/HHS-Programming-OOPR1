#include "SingleLed.h"

bool SingleLed::zetAan(string kleur) {
    // Check if color matches, otherwise return false.
    if (this->kleur.compare(kleur) != 0) {
        return false;
    }

    this->gpio->zetSpanningOpPin(true);
    this->status = 1;
    return true;
}

void SingleLed::zetUit() {
    this->status = 0;
    this->gpio->zetSpanningOpPin(false);
}

string SingleLed::connectie() {
    return to_string(this->gpio->nummerGPIO());
}

int SingleLed::ledStatus() {
    return this->status;
}

SingleLed::SingleLed(string eigenaar, double lumen, string kleur, AansluitingsPlatform *gpio) {
    this->eigenaar = eigenaar;
    this->veranderLichsterkte(lumen);
    this->kleur = kleur;
    this->gpio = gpio;
}

SingleLed::SingleLed(const SingleLed &led) {
    this->eigenaar = led.eigenaar;
    this->veranderLichsterkte(led.hoeveelheidLicht());
    this->kleur = led.kleur;

    // Had to change this back because we are using an virtual for platform. I think I am misunderstanding something here.
    this->gpio = led.gpio;
}