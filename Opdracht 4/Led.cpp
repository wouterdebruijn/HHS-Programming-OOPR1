#include "Led.h"

void Led::veranderLichsterkte(double value) {
    this->lichtsterkte = value;
}

double Led::hoeveelheidLicht() const {
    return this->lichtsterkte;
}