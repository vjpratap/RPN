#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_that_function_evaluate_works_as_calculater_for_addition_or_not,test_that_function_evaluate_works_as_calculater_for_subtraction_or_not,test_that_function_evaluate_works_as_calculater_for_munltiplication_or_not,test_that_function_evaluate_works_as_calculater_for_devidetion_or_not,test_that_function_evaluate_works_as_calculater_for_long_calculation,test_that_function_evaluate_works_as_calculater_for_long_calculation_of_multiplication,test_that_function_evaluate_works_as_calculater_for_long_calculation_for_version_2,test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression2_at_version_2,test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression3_at_version_2,test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression4_at_version_2,test_that_function_evaluate_give_1_in_error_in_operator_isEqual_to_operand,test_that_function_evaluate_give_in_the_error_when_number_of_operator_is_greater_than_number_of_operands,test_that_function_evaluate_give_an_error_when_operator_is_less_than_than_number_of_operands,test_that_function_evaluate_give_1_in_error_when_RPN_is_wrong_given,test_that_function_evaluate_works_two_digit_interger,test_that_function_evaluate_should_give_error_when_operator_comes_before_operand,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_multipleDigit,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_multipleDigit,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_presidence,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_multipleDigit_for_presidence,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression1,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression2,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression3,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_ex,test_that_function_infixToPostfix_works_for_brase_expression1,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression4,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression5,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression6,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression7,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression8,test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression9;
Test test[] = {"test_that_function_evaluate_works_as_calculater_for_addition_or_not",test_that_function_evaluate_works_as_calculater_for_addition_or_not,"test_that_function_evaluate_works_as_calculater_for_subtraction_or_not",test_that_function_evaluate_works_as_calculater_for_subtraction_or_not,"test_that_function_evaluate_works_as_calculater_for_munltiplication_or_not",test_that_function_evaluate_works_as_calculater_for_munltiplication_or_not,"test_that_function_evaluate_works_as_calculater_for_devidetion_or_not",test_that_function_evaluate_works_as_calculater_for_devidetion_or_not,"test_that_function_evaluate_works_as_calculater_for_long_calculation",test_that_function_evaluate_works_as_calculater_for_long_calculation,"test_that_function_evaluate_works_as_calculater_for_long_calculation_of_multiplication",test_that_function_evaluate_works_as_calculater_for_long_calculation_of_multiplication,"test_that_function_evaluate_works_as_calculater_for_long_calculation_for_version_2",test_that_function_evaluate_works_as_calculater_for_long_calculation_for_version_2,"test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression2_at_version_2",test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression2_at_version_2,"test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression3_at_version_2",test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression3_at_version_2,"test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression4_at_version_2",test_that_function_evaluate_works_as_calculater_for_long_calculation_for_expression4_at_version_2,"test_that_function_evaluate_give_1_in_error_in_operator_isEqual_to_operand",test_that_function_evaluate_give_1_in_error_in_operator_isEqual_to_operand,"test_that_function_evaluate_give_in_the_error_when_number_of_operator_is_greater_than_number_of_operands",test_that_function_evaluate_give_in_the_error_when_number_of_operator_is_greater_than_number_of_operands,"test_that_function_evaluate_give_an_error_when_operator_is_less_than_than_number_of_operands",test_that_function_evaluate_give_an_error_when_operator_is_less_than_than_number_of_operands,"test_that_function_evaluate_give_1_in_error_when_RPN_is_wrong_given",test_that_function_evaluate_give_1_in_error_when_RPN_is_wrong_given,"test_that_function_evaluate_works_two_digit_interger",test_that_function_evaluate_works_two_digit_interger,"test_that_function_evaluate_should_give_error_when_operator_comes_before_operand",test_that_function_evaluate_should_give_error_when_operator_comes_before_operand,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_multipleDigit",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_multipleDigit,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_multipleDigit",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_multipleDigit,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_presidence",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_presidence,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_multipleDigit_for_presidence",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_with_multipleDigit_for_presidence,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression1",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression1,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression2",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression2,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression3",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression3,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_ex",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_long_for_ex,"test_that_function_infixToPostfix_works_for_brase_expression1",test_that_function_infixToPostfix_works_for_brase_expression1,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression4",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression4,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression5",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression5,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression6",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression6,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression7",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression7,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression8",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression8,"test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression9",test_that_function_infixToPostfix_gives_the_postfix_of_given_infix_function_for_expression9};
char testFileName[] = {"rpnTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}