#include "LogLed.h"

LogLed::LogLed(std::string eigenaar, Platform *platform, int branduren) : eigendomVan(eigenaar), aangeslotenOp(platform)
{
  this->branduren = Tijdsduur(branduren);
  this->tijdmeting = Stopwatch();
  this->status = true;
}

void LogLed::zetAan() {
  this->branduren.print();
  this->tijdmeting.reset();
  this->tijdmeting.begin();
  this->aangeslotenOp->zetSpanningOpPin(true);
}

void LogLed::zetUit() {
  this->tijdmeting.stop();
  unsigned int time = this->tijdmeting.deTijd();

  this->branduren.eraf(time);
  this->aangeslotenOp->zetSpanningOpPin(false);

  this->branduren.print();
}

unsigned int LogLed::hoeveelTijdTeGaan() {
  return this->branduren.getSeconds();
}