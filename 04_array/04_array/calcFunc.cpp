#include <stdio.h>
#include <iostream>
#include "calcFunc.h"

using namespace std;

extern int n1 = 0, n2 = 0;

int sum(int a, int b) {
	return a + b;
}

int subt(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

float divi(int a, int b) {
	return (float)a / b;
}

int rem(int a, int b) {
	return a % b;
}

void typeNums() {
	printf("Type two numbers: ");
	scanf_s("%d %d", &n1, &n2);
}

void chooseCalc() {
	int nCalc = 0;
	printf("Choose computation you want to do.\n");
	printf("(0:Add, 1:Subtract, 2:Multiply, 3:Divide, 4:Remain : ");
	scanf_s("%d", &nCalc);

	switch (nCalc) {
	case 0:
		printf("Sum is %d\n", sum(n1, n2));
		break;
	case 1:
		printf("Subtraction is %d\n", subt(n1, n2));
		break;
	case 2:
		printf("Multiplication is %d\n", mul(n1, n2));
		break;
	case 3:
		printf("Division is %.3f\n", divi(n1, n2));
		break;
	case 4:
		printf("Remainder is %d\n", rem(n1, n2));
		break;
	}
}

bool isContinue(bool run) {
	char nCont = 'y';
	cout << "continue?(y/n): ";
	cin >> nCont;

	switch (nCont) {
	case 'n':
		return false;
	}
	return true;
}