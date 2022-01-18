#include "SingleLed.h"
#include "DualLed.h"
#include "RaspberryPi.h"
#include "LedLamp.h"

#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
    RaspberryPi aansluiting2(12, 20180225);
    RaspberryPi aansluiting3(13, 20180225);
    RaspberryPi aansluiting4(19, 20180225);
    RaspberryPi aansluiting5(24, 20180225);

    LedLamp ll("Pietje Puk ll");
    
    ll.voegLedToe(new SingleLed("Wouter de Bruijn 1", 0.7, "Rood", &aansluiting4));
    ll.voegLedToe(new DualLed("Wouter de Bruijn 2", 1.2, "Rood", "Groen", &aansluiting2, &aansluiting3));
    ll.voegLedToe(new SingleLed("Wouter de Bruijn 3", 0.65, "Groen", &aansluiting5));
    ll.zetAan("Rood");
    sleep(3);
    ll.zetAan("Groen");
    sleep(3);
    ll.zetUit();
    sleep(1);
    cout << "connectie(s) van ll:" << ll.connectie() << "\n";

    aansluiting2.ontkoppel();
    aansluiting3.ontkoppel();
    aansluiting4.ontkoppel();
    aansluiting5.ontkoppel();
    return 0;
}
