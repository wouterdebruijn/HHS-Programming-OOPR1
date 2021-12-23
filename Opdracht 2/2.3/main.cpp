#include "Platform.h"
#include "LogLed.h"
#include <unistd.h>

int main()
{
  // platform 23 met studienummer 123456
  Platform gpio(23, 20180225);
  Platform gpio2(18, 20180225);

  LogLed lampje1("Wouter de Bruijn", &gpio, 4);
  LogLed lampje2("Wouter de Bruijn", &gpio2, 4);

  lampje1.zetAan();
  sleep(1);
  lampje2.zetAan();
  sleep(2);
  lampje1.zetUit();
  sleep(1);
  lampje2.zetUit();
  return 0;
}