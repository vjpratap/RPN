#include <stdlib.h>
#include <stdio.h>
#include "expr_assert.h"
#include "rpn.h"
#include <string.h>

char* conCat(char* string, char ch){
	int i;
	char* newString = malloc(sizeof(char) * strlen(string) + 2);
	for(i = 0;i <= strlen(string); i++){
		if(string[i] == 0){
			newString[i] = ch;
		}
		else
			newString[i] = string[i];
	}
	newString[i] = 0;
	return newString;
}

int handleOperator(int first, int second, char operator){
	switch(operator){
		case '+' :return first + second;
		case '-' :return first - second;
		case '*' :return first * second;
		case '/' :return first / second;
		default: return 0;
	}
}

int isOperator(char* operator){
	return operator[0] == '+' || operator[0] == '-' || operator[0] == '*' || operator[0] == '/';
}

int evaluate(char *expression){
	int i,first, second,result,j = 0;
	int *holder = malloc(strlen(expression) * sizeof(int));
	char operator;
	char* string = calloc(2, sizeof(char));
	Stack evalStack = createStack();
	for (i = 0; i <= strlen(expression); ++i){
		if(expression[i] != ' ' && expression[i] != 0)
			string = conCat(string, expression[i]);	
		else{

			if(!isOperator(string)){
				holder[j] = atoi(string);
				push(&evalStack, &holder[j]);
				j++;
			}
			else{
				first = *(int *)pop(&evalStack);
				second = *(int *)pop(&evalStack);
				operator = string[0];
				result = handleOperator(second, first, operator);
				push(&evalStack, &result);
			}
			string = calloc(2, sizeof(char));
		}	
	}
	return *(int *)evalStack.list->tail->data;
}