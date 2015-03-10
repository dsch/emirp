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

static bool has_no_factor(N number)
{
  return ((number % 2U) != 0U) && has_no_odd_factor(number);
}

#define BASE 10U

static bool is_not_palindromic(N number)
{
  static const N base2 = BASE * BASE;
  N max_base = (number < base2) ? BASE : base2;
  return ((number % BASE) != (number / max_base));
}

static bool reversed_digit_has_no_factors(N number)
{
  static const N base2 = BASE * BASE;
  N reversed;
  if (number < base2)
  {
    reversed = (number % 10) * BASE + (number / 10);
  }
  else
  {
    reversed = ((number % 10) * base2) +
            (((number / 10) % 10) * BASE) +
            (number / base2);
  }
  return has_no_factor(reversed);
}

bool is_emirp(N number)
{
  return (number >= BASE) &&
          has_no_factor(number) &&
          reversed_digit_has_no_factors(number) &&
          is_not_palindromic(number);
}
