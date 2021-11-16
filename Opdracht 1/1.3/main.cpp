#include <iostream>
#include <unistd.h>
using namespace std;

#include "Led.h"

int main()
{
    cout << "hoi embedded OO programmeurs" << endl;
    Led l1(19);
    Led l2(26, "Wouter de Bruijn"); //Zet hier je eigen naam
    l1.zetAan();
    cout << "l1 is aan" << endl;
    usleep(1000000);
    l2.zetAan();
    cout << "l2 is aan" << endl;
    usleep(1000000);
    l1.zetUit();
    usleep(1000000);
    l2.zetUit();
}