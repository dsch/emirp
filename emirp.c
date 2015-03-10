#include "emirp.h"

#define BASE 10U

static N revers_digits(N number)
{
  unsigned int reversed = 0;
  while (number > 0)
  {
    reversed *= BASE;
    reversed += number % BASE;
    number /= BASE;
  }
  return reversed;
}

static bool is_prime(N number)
{
  N i;
  for (i = 2U; i * i <= number; ++i)
  {
    if ((number % i) == 0U)
    {
      return false;
    }
  }
  return number > 1U;
}

bool is_emirp(N number)
{
  N reversed = revers_digits(number);
  return (number != reversed) &&
          is_prime(number) &&
          is_prime(reversed);
}
