#include <iostream>
#include <stdio.h>

void DrawLine() {
	printf("======================\n");
}

void DrawsLine() {
	printf("----------------------\n");
}

int CalculatorSum(int x, int y) {
	return x + y; // ���ϱ�
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

void increase(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t hello\n", i);
	}
}

int facIncrease(int n) {
	int facF = 1;
	for (int i = 1; i <= n; i++) {
		facF *= i;
	}
	return facF;
}

int facDecrease(int n) {
	int facD = 1;
	for (int i = n; i > 0; i--) {
		facD *= i;
	}
	return facD;
}

int facRecursion(int n) {
	if (n == 1) {
		return n;
	} return n * facRecursion(n - 1);
}

int numSumToF(int n) {
	int num = 0;
	for (int i = 1; i <= n; i++) {
		num += i;
	}
	return num;
}

int numSumToR(int n) {
	if (n == 1) {
		return n;
	} return n + numSumToR(n - 1);
}

int AAA() {
	while (1) {
		printf("1 while op\n");
		break;
		printf("1 while ed\n");
	}

	while (1) {
		printf("2 while op\n");
		return 0;
		printf("2 while ed\n");
	}

	while (1) {
		printf("3 while op\n");
		break;
		printf("3 while ed\n");
	}
}

void start01() {
	int a = 0, b = 0;
	printf("1. ��Ģ���� ����\n�� ���� ������ �Է��ϼ���: ");
	scanf_s("%d %d", &a, &b);
	DrawsLine();
	printf("Sum : %d\n", CalculatorSum(a, b));
	printf("Subtraction : %d\n", CalculatorSub(a, b));
	printf("Multiplication : %d\n", CalculatorMul(a, b));
	printf("Division : %.2f\n", CalculatorDiv(a, b));
	printf("Modular : %d\n", CalculatorMod(a, b));
	DrawLine();
}

void start02() {
	// increase(10);
	// printf("\n");

	// Factorial(���)
	// 5! = 5*4*3*2*1 = 120
	printf("%d\n", facIncrease(5));
	printf("%d\n", facDecrease(5));
	printf("%d\n", facRecursion(5));
	DrawsLine();

	printf("%d\n", numSumToF(100));
	printf("%d\n", numSumToR(100));
	DrawLine();
}

void start03() {
	int nResult = 1;
	int i = 1;
	while (i <= 10) {
		nResult *= i;
		i++;
	}
	printf("%d\n", nResult);
	DrawsLine();

	while (true) {
		printf("%d ", i);
		break; // break�� ������ �ݺ����� ��� ����
	}
	printf("\n");
	DrawsLine();

	i = 0;
	int num = 10;
	int oRes = 0, eRes = 0;

	/*
	while (i <= num) {
		if (i % 2 != 0) {
			oRes += i;
			continue; // continue�� ������ �Ʒ� �ڵ带 �������� �ʰ� ����
		}
		eRes += i;
		i++;
	} */

	for (i = 0; i <= num; i++) {
		if (i % 2 != 0) {
			oRes += i;
			continue; // continue�� ������ �Ʒ� �ڵ带 �������� �ʰ� ����
		}
		eRes += i;
	}

	printf("Odd Addition to %d: %d\n", num, oRes);
	printf("Even Addition to %d: %d\n", num, eRes);
	DrawLine();
}

int main() {
	
	// start01();

	// �ݺ���: for
	// for(�ʱ⼳��; �ݺ�����; �ݺ� ��ó��) { �ݺ�ó�� �� �ڵ� }

	/*for (int i = 0; i < 10; i++) {
		printf("%d\t hello\n", i);
	} printf("\n");*/
	// start02();
	
	// �ݺ���: while
	// while(�ش� ������ true�̸�) { �ݺ�ó�� �� �ڵ� }
	// start03();
	
	// return, break ����
	// AAA();

	system("pause");
}