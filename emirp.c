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
  unsigned int i;
  for (i = 2; i * i <= number; ++i)
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
#if 1
  unsigned int reversed = revers_digits(number);
  return (number != reversed) &&
          is_prime(number) &&
          is_prime(reversed);
#else // ca 10%-15% faster
  if (!is_prime(number))
  {
    return 0;
  }

  unsigned int reversed = revers_digits(number);
  return (number != reversed) &&
          is_prime(reversed);

#endif
}
