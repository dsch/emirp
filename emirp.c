#include "emirp.h"

int revers_digits(int number)
{
  int reversed = number % 10;
  number /= 10;
  if (number > 0)
  {
    reversed *= 10;
    reversed += number;
  }
  return reversed;
}
