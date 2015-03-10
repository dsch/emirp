#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "emirp.h"

#define TEST_IS_A_EMIRP(number) \
CU_add_test(is_emirp_suite, #number " is a emirp", ({void test() \
{ \
  CU_ASSERT_TRUE(is_emirp(number)); \
} test; }))

#define TEST_IS_NOT_A_EMIRP(number) \
CU_add_test(is_emirp_suite, #number " is not a emirp", ({void test() \
{ \
  CU_ASSERT_FALSE(is_emirp(number)); \
} test; }))

int main()
{
  CU_initialize_registry();
  CU_basic_set_mode(CU_BRM_VERBOSE);

  CU_pSuite is_emirp_suite = CU_add_suite("is_emirp", NULL, NULL);

  TEST_IS_NOT_A_EMIRP(5);    /* single digit prime */
  TEST_IS_A_EMIRP(13);       /* two digits emirp */
  TEST_IS_NOT_A_EMIRP(12);   /* two digits non prime */
  TEST_IS_NOT_A_EMIRP(15);   /* two digits non prime */
  TEST_IS_NOT_A_EMIRP(11);   /* two digits palindromic prime */

  CU_ErrorCode error_code = CU_basic_run_tests();
  CU_cleanup_registry();

  return error_code;
}
