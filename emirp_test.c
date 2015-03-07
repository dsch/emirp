#include <CUnit/CUnit.h>

#include "emirp.h"

int main()
{
  if (CU_initialize_registry()) 
  {
    printf("Initialization of Test Registry failed.\n");
  }
  else
  {
    CU_basic_run_tests();
    CU_cleanup_registry();
  }
}
