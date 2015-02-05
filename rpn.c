#include <stdlib.h>
#include <stdio.h>
#include "expr_assert.h"
#include "rpn.h"
#include <string.h>

int handleEquation(int first, int second, char operator){
	switch(operator){
		case '+' :return first + second;
		case '-' :return first - second;
		case '*' :return first * second;
		case '/' :return first / second;
		default: return 0;
	}
}

int isOperator(char operator){
	return operator == '+' || operator == '-' || operator == '*' || operator == '/';
}

int handleOprator(Stack* evalStack, char operator){
	int first, second;
	first = *(int *)pop(evalStack);
	second = *(int *)pop(evalStack);
	return handleEquation(second, first, operator);
}

Result evaluate(char *expression){
	int i,resultValue,operandCount = 0,operatorCount = 0, length = strlen(expression);
	int *holder = malloc(length/2 * sizeof(int));
	Result calculater, invalidExpression = {1,0};
	Stack evalStack = createStack();
	for (i = 0; i < length; i++){
		if(!isOperator(expression[i]) && expression[i] != ' '){
			holder[++operandCount] = atoi(&expression[i]);
			push(&evalStack, &holder[operandCount]);
			while(expression[++i] != ' '){};
		}
		if(isOperator(expression[i])){
			if(evalStack.list->count <= 1)
				return invalidExpression;
			resultValue = handleOprator(&evalStack, expression[i]);
			push(&evalStack, &resultValue);
			operatorCount++;
		}
	}
	if(operandCount != operatorCount + 1)
		return invalidExpression;
	calculater.status = resultValue;
	calculater.error = 0;//isError(operandCount, operatorCount, &evalStack);
	return calculater;
}