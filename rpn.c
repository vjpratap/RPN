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
	char* operators = "+-/*^%";
	int i;
	for(i=0; i< strlen(operators); i++){
		if(operator == operators[i]) 
			return 1;
	}
	return 0;
}

int handleOprator(Stack* evalStack, char operator){
	int first, second;
	first = *(int *)pop(evalStack);
	second = *(int *)pop(evalStack);
	return handleEquation(second, first, operator);
}

Result giveResult(int operandCount,int operatorCount,int resultValue){
	Result calculater, invalidExpression = {1,0};
	if(operandCount != operatorCount + 1)
		return invalidExpression;
	calculater.status = resultValue;
	calculater.error = 0;//isError(operandCount, operatorCount, &evalStack);
	return calculater;
}

void operandHandle(char* expression, Stack *evalStack, int length,  int *i, int* holder){
	*holder = atoi(&expression[(*i)]);
	push(evalStack, holder);
	while(expression[(*i)] != ' '){(*i)++;}; 
}

Result evaluate(char *expression){
	int i,resultValue,operandCount = 0,operatorCount = 0, length = strlen(expression);
	int *holder = malloc(length/2 * sizeof(int));
	Result invalidExpression = {1,0};
	Stack evalStack = createStack();
	for (i = 0; i < length; i++){
		if(!isOperator(expression[i]) && expression[i] != ' ')
			operandHandle(expression, &evalStack, length/2, &i,&holder[++operandCount]);
		if(isOperator(expression[i])){
			if(evalStack.list->count <= 1)
				return invalidExpression;
			resultValue = handleOprator(&evalStack, expression[i]);
			push(&evalStack, &resultValue);
			operatorCount++;
		}
	}
	return giveResult(operandCount, operatorCount, resultValue);
}

int presidence(char operator){
	switch(operator){
		case '+' :return 2;
		case '-' :return 2;
		case '*' :return 3;
		case '/' :return 3;
		case '^' :return 4;
		default: return 0;
	}
}

void checkBODMAS(Stack* operatorStack, Stack* operandStack, char* expr, char* getLowOperator){
	char first, second,*whiteSpace = " ";
	int i, length;
	push(operatorStack, expr);
	length = operatorStack->list->count;
	for(i = 0;i < length - 1; i++){
		first = *(char*)getElementAt(*(operatorStack->list), (operatorStack->list)->count - 1);
		second = *(char*)getElementAt(*operatorStack->list, operatorStack->list->count - 2);
		if(presidence(first) <= presidence(second)){
			getLowOperator = (char*)deleteElementAt(operatorStack->list, operatorStack->list->count - 2);
			push(operandStack, getLowOperator);
			push(operandStack, whiteSpace);
		}
	}
}

char* getResult(Stack* operatorStack, Stack* operandStack){
	int i, operandCount, operatorCount = operatorStack->list->count;
	char* str = malloc(sizeof(char) * operatorCount), *result, whiteSpace = ' ';
	for(i = 0;i < operatorCount;i++){
		str[i] = *(char *)pop(operatorStack);
		push(operandStack, &whiteSpace);
		push(operandStack, &str[i]);	
	}
	operandCount = operandStack->list->count;
	result = calloc(operandCount, sizeof(char));
	for(i = 0;i < operandCount; i++)
		result[i] = *(char *)lifo(operandStack);
	return result;
}

char * infixToPostfix(char * expression){
	int i, length = strlen(expression), operandCount = 0, count = 0;
	char* getLowOperator = malloc(length/2 * sizeof(char)), *cpyExp;
	Stack operandStack = createStack();
	Stack operatorStack = createStack();
	for(i = 0; i < length; i++){
		if(!isOperator(expression[i]))
			push(&operandStack, &expression[i]);
		else
			checkBODMAS(&operatorStack, &operandStack, &expression[i++], &getLowOperator[count++]);
	}
	return getResult(&operatorStack, &operandStack);
}