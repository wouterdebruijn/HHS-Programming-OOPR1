#ifndef TIJDSDUUR_H
#define TIJDSDUUR_H
// De declaratie van de ADT Tijdsduur:
class Tijdsduur
{
public:
  void eraf(Tijdsduur);
  void erbij(Tijdsduur);
  void print() const;
  void maal(int);
  int getSeconds();
  int getMinutes();
  Tijdsduur(int, int);
  Tijdsduur(int);
  Tijdsduur();

private:
  int sec;
};
#endif // TIJDSDUUR_H