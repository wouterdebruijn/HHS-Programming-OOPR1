#include "SingleLed.h"
#include "DualLed.h"
#include "Platform.h"

#include <unistd.h>

int main()
{
    // Platform gpioA(18, 20180225);
    // SingleLed sl1("Wouter de Bruijn", 0.9, "groen", &gpioA);

    // SingleLed sl2(sl1); // Copy constructor
    // sl1.veranderLichsterkte(1.2);

    // sl1.zetAan("groen");
    // sleep(1);
    // sl2.zetUit();

    Platform gpioA(18, 20180225);
    Platform gpioB(23, 20180225);
    Platform gpioC(24, 20180225);

    SingleLed* sl1 = new SingleLed("Wouter de Bruijn", 0.9, "groen", &gpioA);
    DualLed* dl1 = new DualLed("Wouter de bruijn", 1.5, "rood", "groen", &gpioB, &gpioC);
    
    Led* l1=sl1;
    Led* l2=dl1;

    l1->zetAan("groen");
    sleep(1);
    l2->zetAan("groen");
    sleep(1);
    l2->zetAan("rood");
    sleep(1);

    Led* uit=sl1;
    uit->zetUit();
    sleep(1);
    uit=dl1;
    uit->zetUit();

    delete sl1;
    delete dl1;

    return 0;
}


