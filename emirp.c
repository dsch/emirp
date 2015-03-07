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

int is_prime(unsigned int number)
{
  unsigned i;
  for (i = 2; i < number; ++i)
  {
    if ((number % i) == 0)
    {
      return 0;
    }
  }
  return number > 1;
}

int is_emirp(unsigned int number)
{
  unsigned int reversed = revers_digits(number);
  return (number != reversed) &&
          is_prime(number) &&
          is_prime(reversed);
}
