#include "emirp.h"

static bool has_no_odd_factor(N number)
{
  N odd_factor = 3U;
  do
  {
    if ((number % odd_factor) == 0U)
    {
      return false;
    }
    odd_factor += 2U;
  }
  while ((odd_factor * odd_factor) <= number);
  return true;
}

#define BASE 10U

static bool is_not_palindromic(N number)
{
  static const N base2 = BASE * BASE;
  N max_base = (number < base2) ? BASE : base2;
  return ((number % BASE) != (number / max_base));
}

static bool reversed_digit_is_prime(N number)
{
  N reversed;
  if (number < (BASE * BASE))
  {
    reversed = (number % 10) * BASE + (number / 10);
  }
  else
  {
    reversed = ((number % 10) * BASE * BASE) +
            (((number / 10) % 10) * BASE) +
            (number / (BASE * BASE));
  }
  return has_no_odd_factor(reversed);
}

bool is_emirp(N number)
{
  return (number >= BASE) &&
          ((number % 2U) != 0U) &&
          has_no_odd_factor(number) &&
          reversed_digit_is_prime(number) &&
          is_not_palindromic(number);
}
