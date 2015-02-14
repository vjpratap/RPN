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
		if(!presidence(expression[i])/*!isOperator(expression[i])*/&& expression[i] != ' ')
			operandHandle(expression, &evalStack, length/2, &i,&holder[++operandCount]);
		if(presidence(expression[i])){
			if(evalStack.list->count <= 1)
				return invalidExpression;
			resultValue = handleOprator(&evalStack, expression[i]);
			push(&evalStack, &resultValue);
			operatorCount++;
		}
	}
	return giveResult(operandCount, operatorCount, resultValue);
}

void handelOperatorStack(Stack* operatorStack, Stack* operandStack, char* expr, char* getLowOperator){
	char first, second,*whiteSpace = " ";
	int i, length;
	push(operatorStack, expr);
	length = operatorStack->list->count;
	for(i = 0;i < length - 1; i++){
		first = *(char*)getElementAt(*(operatorStack->list), (operatorStack->list)->count - 1);
		second = *(char*)getElementAt(*operatorStack->list, operatorStack->list->count - 2);
		if(presidence(first) <= presidence(second)){
			if(first != '^' && second != '^'){
				getLowOperator = (char*)deleteElementAt(operatorStack->list, operatorStack->list->count - 2);
				push(operandStack, getLowOperator);
				push(operandStack, whiteSpace);
			}
		}
	}
}

char* getResult(Stack* operatorStack, Stack* operandStack){
	int i, operandCount, operatorCount = operatorStack->list->count;
	char* str = malloc(sizeof(char) * operatorCount), *result, *whiteSpace = " ";
	for(i = 0;i < operatorCount;i++){
		str[i] = *(char *)pop(operatorStack);
		push(operandStack, whiteSpace);
		push(operandStack, &str[i]);	
	}
	operandCount = operandStack->list->count;
	result = calloc(operandCount + 2, sizeof(char));
	for(i = 0;i < operandCount; i++)
		result[i] = *(char *)lifo(operandStack);
	return result;
}

int giveTheIndexOfclosedBraket(char * expression, int index){
	int i, count = 0, openBrace = 0, closeBrace = 0;
	for(i = index; i < strlen(expression); i++){
		if(expression[i] == '(')
			openBrace++;
		if(expression[i] == ')')
			closeBrace++;
		if(openBrace - closeBrace == 0)
			return i;
	}
}

char * giveInBraseExpression(char * expression, int index){
	int inBraceLength,i,j = 0;
	char* braceExp;// = calloc(inBraceLength + 2, sizeof(char));
	inBraceLength = giveTheIndexOfclosedBraket(expression, index);
	braceExp = calloc((inBraceLength - index)+ 2, sizeof(char));
	for(i = index + 1; i < inBraceLength; i++)
		braceExp[j++] = expression[i];
	return infixToPostfix(braceExp);
}

void handleBrase(char * expression, Stack* operandStack, int* index){
	int inBraceLength, i, braceCount = 0,j, startingExpLength;
	char* cpyExp;
	inBraceLength = strlen(giveInBraseExpression(expression, *index));
	cpyExp = calloc((inBraceLength - *index), sizeof(char));
	strcpy(cpyExp, giveInBraseExpression(expression, *index));
	for(i = 0; i < inBraceLength; i++)
		push(operandStack, &cpyExp[i]);
	startingExpLength = (*index) + strlen(cpyExp);
	for(j = 0; j < startingExpLength;j++) if(expression[j] == '(') braceCount++;
	(*index) = (*index) + inBraceLength + braceCount;
}

char * infixToPostfix(char * expression){
	int i, length = strlen(expression), operandCount = 0, count = 0,inBraceLength,j, braceCount = 0;
	char* getLowOperator = malloc(length/2 * sizeof(char)), *cpyExp;
	Stack operandStack = createStack();
	Stack operatorStack = createStack();
	for(i = 0; i < length; i++){
		if(expression[i] == '('){
			handleBrase(expression, &operandStack, &i);
			if(expression[i] != ' ')
				continue;
		}
		if(!presidence(expression[i]) && expression[i] != ')')// && i < length)
			push(&operandStack, &expression[i]);
		if(presidence(expression[i])) //|| expression[i] = ')')
			handelOperatorStack(&operatorStack, &operandStack, &expression[i++], &getLowOperator[count++]);
	}
	return getResult(&operatorStack, &operandStack);
}

