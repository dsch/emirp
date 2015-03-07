#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "emirp.h"

static const int one_digit_number = 5;

static void revers_digits_one_digit()
{
  int reversed = revers_digits(one_digit_number);
  CU_ASSERT_EQUAL(reversed, one_digit_number);
}

int main()
{
  CU_initialize_registry();
  CU_basic_set_mode(CU_BRM_VERBOSE);

  CU_pSuite suite = CU_add_suite("revers digits", NULL, NULL);
  CU_add_test(suite, "single digit numbers should return the same number",
              revers_digits_one_digit);

  CU_ErrorCode error_code = CU_basic_run_tests();
  CU_cleanup_registry();

  return error_code;
}
