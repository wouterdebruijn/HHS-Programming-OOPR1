#include "DualLed.h"

bool DualLed::zetAan(string kleur) {
    // Check if color matches, otherwise return false.
    if (this->kleur.compare(kleur) == 0) {
        this->gpio->zetSpanningOpPin(true);
        this->status = 1;
        return true;
    }

    if (this->kleur1.compare(kleur) == 0) {
        this->gpio1->zetSpanningOpPin(true);
        this->status1 = 1;
        return true;
    }

    
    return false;
}

void DualLed::zetUit() {
    this->status = 0;
    this->status1 = 1;
    this->gpio->zetSpanningOpPin(false);
}

string DualLed::connectie() {
    return to_string(this->gpio->nummerGPIO());
}

int DualLed::ledStatus() {
    // Return bitwise status of leds.
    return (this->status << 1 | this->status1);
}

DualLed::DualLed(string eigenaar, double lumen, string kleur, string kleur1, AansluitingsPlatform *gpio, AansluitingsPlatform *gpio1) {
    this->eigenaar = eigenaar;
    this->veranderLichsterkte(lumen);
    this->kleur = kleur;
    this->kleur1 = kleur1;
    this->gpio = gpio;
    this->gpio1 = gpio1;
}

DualLed::DualLed(const DualLed &led) {
    this->eigenaar = led.eigenaar;
    this->veranderLichsterkte(led.hoeveelheidLicht());
    this->kleur = led.kleur;
    this->gpio = led.gpio;
    this->gpio1 = led.gpio1;
}