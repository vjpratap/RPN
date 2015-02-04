#include "expr_assert.h"
#include <stdlib.h>
#include "rpn.h"

void test_that_function_evaluate_works_as_calculater_for_addition_or_not(){
	assertEqual(evaluate("2 3 +"),5);
}

void test_that_function_evaluate_works_as_calculater_for_subtraction_or_not(){
	assertEqual(evaluate("2 3 -"),-1);
}

void test_that_function_evaluate_works_as_calculater_for_munltiplication_or_not(){
	assertEqual(evaluate("2 3 *"),6);
}

void test_that_function_evaluate_works_as_calculater_for_devidetion_or_not(){
	assertEqual(evaluate("2 3 /"),0);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation(){
	assertEqual(evaluate("4 8 2 + -"),-6);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_of_multiplication(){
	assertEqual(evaluate("1 2 3 4 5 * * * *"), 120);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_version_2(){
	assertEqual(evaluate("5 1 2 + 4 * + 3 -"), 14);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression2_at_version_2(){
	assertEqual(evaluate("2 2 2 * 2 - 3 + +"), 7);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression3_at_version_2(){
	assertEqual(evaluate("2 2 2 2 2 * * 2 + + 2 - *"), 20);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression4_at_version_2(){
	assertEqual(evaluate("2 2 - 2 2 2 * 2 - - -"), 0);
}


