#ifndef AANSL_PLATFORM_H
#define AANSL_PLATFORM_H

class AansluitingsPlatform {
  public:
    virtual void zetSpanningOpPin(bool) = 0;
    virtual int nummerGPIO() = 0;
};

#endif