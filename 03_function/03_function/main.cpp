#include <iostream>
#include <stdio.h>

int CalculatorSum(int x, int y) {
	return x + y; // ���ϱ�
}

void DrawLine() {
	printf("======================\n");
}

int CalculatorSub(int x, int y) {
	return x - y; // ����
}

int CalculatorMul(int x, int y) {
	return x * y;	// ���ϱ�
}

float CalculatorDiv(int x, int y) {
	return (float)x / y; // ������
}

int CalculatorMod(int x, int y) {
	return x % y;	// ������
}

void CallFunc() {
	printf("Called Function!\n");
}

int main() {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	DrawLine();
	printf("Sum : %d\n", CalculatorSum(a, b));
	printf("Subtraction : %d\n", CalculatorSub(a, b));
	printf("Multiplication : %d\n", CalculatorMul(a, b));
	printf("Division : %.2f\n", CalculatorDiv(a, b));
	printf("Modular : %d\n", CalculatorMod(a, b));
	DrawLine();

	system("pause");
}