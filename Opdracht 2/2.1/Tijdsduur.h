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
  Tijdsduur(int, int);
  Tijdsduur(int);

private:
  int sec;
};
#endif // TIJDSDUUR_H