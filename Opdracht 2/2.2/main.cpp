#include "Platform.h"
#include "Led.h"
#include <unistd.h>

int main() {

    Platform gpio(23,20180225); //platform 23 met studienummer 123456
    Platform gpio2(18,20180225); //platform 18 met studienummer 123456

    Led lampje1("Wouter de Bruijn",&gpio); 
    Led lampje2("Wouter de Bruijn",&gpio2); 

    lampje1.zetAan();
    sleep(1);
    lampje2.zetAan();
    sleep(2);
    lampje1.zetUit();
    sleep(1);
    lampje2.zetUit();
    return 0;
}