#include <stdlib.h>
#include <stdio.h>
#include "expr_assert.h"
#include "rpn.h"
#include <string.h>

char* conCat(char* token, char digit){
	int i;
	char* newToken = malloc(sizeof(char) * strlen(token) + 2);
	for(i = 0;i <= strlen(token); i++){
		if(token[i] == 0){
			newToken[i] = digit;
		}
		else
			newToken[i] = token[i];
	}
	newToken[i] = 0;
	return newToken;
}

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

Result evaluate(char *expression){
	int i,first, second,resultValue,operandCount = 0,operatorCount = 0, length = strlen(expression);
	int *holder = malloc(length/2 * sizeof(int));
	char operator;
	char* token = calloc(2, sizeof(char));
	Result calculater, invalidExpression = {1,0};
	Stack evalStack = createStack();
	for (i = 0; i <= length; ++i){
		if(expression[i] != ' ' && expression[i] != '\0')
			token = conCat(token, expression[i]);	
		else{

			if(!isOperator(token[0])){
				holder[operandCount] = atoi(token);
				push(&evalStack, &holder[operandCount]);
				operandCount++;
			}
			else{
				if(evalStack.list->count <= 1)
					return invalidExpression;
				first = *(int *)pop(&evalStack);
				second = *(int *)pop(&evalStack);
				operator = token[0];
				resultValue = handleEquation(second, first, operator);
				push(&evalStack, &resultValue);
				operatorCount++;
			}
			token = calloc(2, sizeof(char));
		}	
	}
	if(operandCount != operatorCount + 1)
		return invalidExpression;
	calculater.status = resultValue;
	calculater.error = 0;//isError(operandCount, operatorCount, &evalStack);
	return calculater;
}