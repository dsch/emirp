#include <stdio.h>
#include "emirp.h"

int main()
{
  unsigned i;
  for (i=0; i<10000; ++i)
  {
    unsigned number = 0;
    for (number = 0; number <= 1000; ++number)
    {
      if (is_emirp(number))
      {
        printf("%d is emirp\n", number);
      }
    }
  }
  return 0;
}
