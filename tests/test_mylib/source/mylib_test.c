/*
 * File:   mylib_test.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "mylib.h"
/*
 * CUnit Test Suite
 */

int init_suite(void) {
	return 0;
}

int clean_suite(void) {
	return 0;
}

void test_mylib_add() {
	CU_ASSERT(mylib_add(2,2) == 4);
}

void test_mylib_substract() {
	CU_ASSERT(mylib_substract(2,2) == 0);
}

void test_mylib_multiply() {
	CU_ASSERT(mylib_multiply(2,0) == 0);
	CU_ASSERT(mylib_multiply(2,1) == 2);
	CU_ASSERT(mylib_multiply(2,2) == 4);
}

void test_mylib_divide() {
	CU_ASSERT(mylib_divide(2,2) == 1);
	CU_ASSERT(mylib_divide(0,2) == 0);
}

void test_mylib_power() {
	CU_ASSERT(mylib_power(1,0) == 1);
	CU_ASSERT(mylib_power(1,1) == 1);
	CU_ASSERT(mylib_power(1,2) == 1);
	CU_ASSERT(mylib_power(2,0) == 1);
	CU_ASSERT(mylib_power(2,1) == 2);
	CU_ASSERT(mylib_power(2,2) == 4);
	CU_ASSERT(mylib_power(2,3) == 8);
}

int main() {
	CU_pSuite pSuite = NULL;

	/* Initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* Add a suite to the registry */
	pSuite = CU_add_suite("mylib_add_test", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "test mylib_add", test_mylib_add)) ||
			(NULL == CU_add_test(pSuite, "test mylib_substract", test_mylib_substract)) ||
			(NULL == CU_add_test(pSuite, "test mylib_multiply", test_mylib_multiply)) ||
			(NULL == CU_add_test(pSuite, "test mylib_multiply", test_mylib_divide)) ||
			(NULL == CU_add_test(pSuite, "test mylib_power", test_mylib_power))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
