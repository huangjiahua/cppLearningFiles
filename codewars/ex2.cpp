#include <iostream>
#include <cmath>

class Arge
{
  public:
  static int nbYear(int p0, double percent, int aug, int p);
};

int Arge::nbYear(int p0, double percent, int aug, int p)
{
    int i = 0, num = p0;
    for ( ; num < p; ++i)
        num = num * (percent/100.0) + aug + num;
    return i;
}
