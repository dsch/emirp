#include "emirp.h"

unsigned int revers_digits(unsigned int number)
{
  static const unsigned int base = 10;

  unsigned int reversed = 0;
  while (number > 0)
  {
    reversed *= base;
    reversed += number % base;
    number /= base;
  }
  return reversed;
}
