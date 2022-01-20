#ifndef LOG_LED
#define LOG_LED

#include "Tijdsduur.h"
#include "Platform.h"
#include "Stopwatch.h"

class LogLed {
  private:
    Tijdsduur branduren;
    Stopwatch tijdmeting;
    Platform *aangeslotenOp;
    bool status;
    std::string eigendomVan;
  public:
    void zetAan();
    void zetUit();
    bool ledStatus();
    unsigned int hoeveelTijdTeGaan();
    LogLed(std::string eigenaar, Platform *platform, int branduren);
};

#endif /* LOG_LED */