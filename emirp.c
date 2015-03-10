#include "emirp.h"

static bool has_no_odd_factor(N number)
{
  N odd_factor = 3U;
  while (((number % odd_factor) != 0U) && ((odd_factor * odd_factor) <= number))
  {
    odd_factor += 2U;
  }
  return (odd_factor * odd_factor) > number;
}

static bool has_no_factors(N number)
{
  return ((number % 2U) != 0U) && has_no_odd_factor(number);
}

#define BASE 10U

static bool reversed_digit_has_no_factors_and_is_not_palindromic(N number)
{
  static const N base2 = BASE * BASE;
  N lowest_digit = number % BASE;
  N hightes_digit;
  N reversed;
  if (number < base2)
  {
    hightes_digit = number / BASE;
    reversed = lowest_digit * BASE + hightes_digit;
  }
  else
  {
    hightes_digit = number / base2;
    reversed = (lowest_digit * base2) +
            (((number / 10) % 10) * BASE) +
            hightes_digit;
  }

  return (lowest_digit != hightes_digit) && has_no_factors(reversed);
}

bool is_emirp(N number)
{
  return has_no_factors(number) &&
          reversed_digit_has_no_factors_and_is_not_palindromic(number);
}
