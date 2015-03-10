#include "emirp.h"

static bool has_no_odd_factor(N number)
{
  return ((number % 3) != 0) &&
          ((number % 5) != 0);
}



bool is_emirp(N number) {
  static const N base = 10U;
  return (number >= base) &&
          ((number % 2) != 0) &&
          has_no_odd_factor(number) &&
          ((number % base) != (number / base));
}
