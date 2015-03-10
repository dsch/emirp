#include "emirp.h"

bool is_emirp(N number) {
  static const N base = 10U;
  return (number >= base) &&
          ((number % 2) != 0) &&
          ((number % 3) != 0) &&
          ((number % 5) != 0) &&
          ((number % base) != (number / base));
}
