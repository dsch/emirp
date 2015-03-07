#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "emirp.h"

void test1()
{
  CU_ASSERT(0);
}

int main()
{
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("suite", NULL, NULL);
  CU_add_test(suite, "test1", test1);

  CU_ErrorCode error_code = CU_basic_run_tests();
  CU_cleanup_registry();

  return error_code;
}
