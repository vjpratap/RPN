#include "expr_assert.h"
#include <stdlib.h>
#include "rpn.h"

void test_that_function_evaluate_works_as_calculater_for_addition_or_not(){
	Result resultValue = evaluate("2546 3 +");
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,2549);
}

void test_that_function_evaluate_works_as_calculater_for_subtraction_or_not(){
	Result resultValue = evaluate("2 3 -");
	// assertEqual(evaluate("2 3 -"),-1);
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,-1);
}

void test_that_function_evaluate_works_as_calculater_for_munltiplication_or_not(){
	Result resultValue = evaluate("2 3 *");
	// assertEqual(evaluate("2 3 *"),6);
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,6);
}
void test_that_function_evaluate_works_as_calculater_for_devidetion_or_not(){
	Result resultValue = evaluate("2 3 /");
	// assertEqual(evaluate("2 3 /"),0);
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,0);
}
void test_that_function_evaluate_works_as_calculater_for_long_calculation(){
	Result resultValue = evaluate("4 8 2 + -");
	// assertEqual(evaluate("4 8 2 + -"),-6);
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,-6);
}
void test_that_function_evaluate_works_as_calculater_for_long_calculation_of_multiplication(){
	Result resultValue = evaluate("1 2 3 4 5 * * * *");
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,120);
}


void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_version_2(){
	Result resultValue = evaluate("5 1 2 + 4 * + 3 -");
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,14);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression2_at_version_2(){
	Result resultValue = evaluate("2 2 2 * 2 - 3 + +");
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,7);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression3_at_version_2(){
	Result resultValue = evaluate("2 2 2 2 2 * * 2 + + 2 - *");
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,20);
}

void test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression4_at_version_2(){
	Result resultValue = evaluate("2 2 - 2 2 2 * 2 - - -");
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status,0);
}

void test_that_function_evaluate_give_1_in_error_in_operator_isEqual_to_operand(){
	Result resultValue = evaluate("2 2 - 2 2 2 * 2 - - - +");
	assertEqual(resultValue.error, 1);
	assertEqual(resultValue.status, 0);
}

void test_that_function_evaluate_give_in_the_error_when_number_of_operator_is_greater_than_number_of_operands(){
	Result resultValue = evaluate("2 2 - 2 2 2 * 2 + - - - +");
	assertEqual(resultValue.error , 1);
	assertEqual(resultValue.status, 0);
}

void test_that_function_evaluate_give_an_error_when_operator_is_less_than_than_number_of_operands(){
	Result resultValue = evaluate("2 2 2 2 2 * * 2 + + 2 -");
	assertEqual(resultValue.error , 1);
	assertEqual(resultValue.status, 0);
}

void test_that_function_evaluate_give_1_in_error_when_RPN_is_wrong_given(){
	Result resultValue = evaluate("3 + 3 - 6");
	assertEqual(resultValue.error, 1);
	assertEqual(resultValue.status, 0);
}

void test_that_function_evaluate_works_two_digit_interger(){
	Result resultValue = evaluate("45 25 +");
	assertEqual(resultValue.error, 0);
	assertEqual(resultValue.status, 70);
}

void test_that_function_evaluate_should_give_error_when_operator_comes_before_operand(){
	Result resultValue = evaluate("+ 3 6");
	assertEqual(resultValue.error, 1);
	assertEqual(resultValue.status, 0);
}







