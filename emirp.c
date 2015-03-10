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

bool is_emirp(N number)
{
  return (number >= BASE) &&
          ((number % 2U) != 0U) &&
          has_no_odd_factor(number) &&
          has_no_odd_factor((number % 10) * BASE + (number / 10)) &&
          is_not_palindromic(number);
}
