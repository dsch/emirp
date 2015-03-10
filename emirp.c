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

bool is_emirp(N number)
{
  static const N base = 10U;
  return (number >= base) &&
          ((number % 2U) != 0U) &&
          has_no_odd_factor(number) &&
          ((number % base) != (number / base));
}
