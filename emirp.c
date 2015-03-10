#include "emirp.h"

static bool has_no_odd_factor(N number)
{
  N odd_factor = 3U;
  while (((number % odd_factor) != 0U) &&
          ((odd_factor * odd_factor) <= number))
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
#define BASE2 (BASE * BASE)

static bool reversed_digit_is_not_palindromic_and_has_no_factors(N number)
{
  N last_digit = number % BASE;
  N first_digit;
  N reversed;
  if (number < BASE2)
  {
    first_digit = number / BASE;
    reversed = last_digit * BASE + first_digit;
  }
  else
  {
    first_digit = number / BASE2;
    reversed = (last_digit * BASE2) +
            (((number / BASE) % BASE) * BASE) +
            first_digit;
  }

  return (last_digit != first_digit) && has_no_factors(reversed);
}

bool is_emirp(N number)
{
  return has_no_factors(number) &&
          reversed_digit_is_not_palindromic_and_has_no_factors(number);
}
