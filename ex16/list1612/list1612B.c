#include <CUnit/CUnit.h>
#include <CUnit/Console.h>

// --- target function ---
extern void sort(int a[], int n);

void test_func_1();
void test_func_2();
void test_func_3();

int main() {
  CU_pSuite test_suite;

  CU_initialize_registry();
  test_suite = CU_add_suite("TestSuite", NULL, NULL);
  CU_add_test(test_suite, "test_1", test_func_1);
  CU_add_test(test_suite, "test_2", test_func_2);
  CU_add_test(test_suite, "test_3", test_func_3);
  // CU_console_run_tests();
  CU_automated_run_tests();
  CU_cleanup_registry();

  return 0;
}

void test_func_1() {
  int a[] = {10};
  sort(a, 1);
  CU_ASSERT(a[0] == 10);
}

void test_func_2() {
  int a[] = {9,1,5,3,7};

  sort(a, 5);
  CU_ASSERT(a[0] == 1);
  CU_ASSERT(a[1] == 3);
  CU_ASSERT(a[2] == 5);
  CU_ASSERT(a[3] == 7);
  CU_ASSERT(a[4] == 9);
}

void test_func_3() {
  int a[] = {3, -4, -2, -5, 0, -1, -3, 1, 2, 4};
  sort(a, 10);
  CU_ASSERT(a[0] == -5);
  CU_ASSERT(a[1] == -4);
  CU_ASSERT(a[2] == -3);
  CU_ASSERT(a[3] == -2);
  CU_ASSERT(a[4] == -1);
  CU_ASSERT(a[5] == 0);
  CU_ASSERT(a[6] == 1);
  CU_ASSERT(a[7] == 2);
  CU_ASSERT(a[8] == 3);
  CU_ASSERT(a[9] == 4);
}
