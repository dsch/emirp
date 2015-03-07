#include "emirp.h"

int revers_digits(int number)
{
  static const int base = 10;

  int reversed = 0;
  while (number > 0)
  {
    reversed *= base;
    reversed += number % base;
    number /= base;
  }
  return reversed;
}
