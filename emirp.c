#include "emirp.h"

int revers_digits(int number)
{
  static const int base = 10;

  int reversed = number % base;
  number /= base;
  if (number > 0)
  {
    reversed *= base;
    reversed += number;
  }
  return reversed;
}
