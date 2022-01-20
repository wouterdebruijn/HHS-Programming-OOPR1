#include <iostream>
#include "Tijdsduur.h"
#include <iomanip>
using namespace std;

Tijdsduur::Tijdsduur(int minutes, int seconds)
{
  sec = seconds + minutes * 60;
}

Tijdsduur::Tijdsduur(int seconds)
{
  sec = seconds;
}

Tijdsduur::Tijdsduur()
{
  sec = 0;
}

void Tijdsduur::print() const
{
  int minutes = this->sec / 60;
  int seconds = this->sec - minutes * 60;

  if (minutes > 0)
  {
    cout << minutes << " minutes and " << seconds << " seconds";
  }
  else
  {
    cout << "               " << seconds << " seconds";
  }
}

void Tijdsduur::eraf(Tijdsduur t)
{
  sec -= t.sec;
  if (sec < 0)
    sec = 0;
}

void Tijdsduur::erbij(Tijdsduur t)
{
  sec += t.sec;
}

void Tijdsduur::maal(int times)
{
  sec *= times;
}

int Tijdsduur::getSeconds() {
  return this->sec - getMinutes() * 60;
}

int Tijdsduur::getMinutes() {
  return this->sec / 60;
}