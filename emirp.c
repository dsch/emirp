#include "emirp.h"

bool is_emirp(N number) {
  return (number >= 10U) &&
          ((number % 2) != 0);
}
