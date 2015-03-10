#include <stdio.h>
#include "emirp.h"

static void output(N number)
{
  printf("%d is emirp\n", number);
}

int main()
{
  unsigned i;
  for (i=0; i<100000; ++i)
  {
    unsigned number = 0;
    for (number = 0; number <= 1000; ++number)
    {
      if (is_emirp(number))
      {
        output(number);
      }
    }
  }
  return 0;
}
