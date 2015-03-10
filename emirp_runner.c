#include <stdio.h>
#include "emirp.h"

int main()
{
  N number = 0;
  for (number = 0; number <= 1000; ++number)
  {
    if (is_emirp(number))
    {
      printf("%d is emirp\n", number);
    }
  }
  return 0;
}
