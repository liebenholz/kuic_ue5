#include <iostream>
#include <stdio.h>

void DrawLine() {
	printf("======================\n");
}

void DrawsLine() {
	printf("----------------------\n");
}

int CalculatorSum(int x, int y) {
	return x + y; // 더하기
}

int CalculatorSub(int x, int y) {
	return x - y; // 빼기
}

int CalculatorMul(int x, int y) {
	return x * y;	// 곱하기
}

float CalculatorDiv(int x, int y) {
	return (float)x / y; // 나누기
}

int CalculatorMod(int x, int y) {
	return x % y;	// 나머지
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
	printf("1. 사칙연산 계산기\n두 개의 정수를 입력하세요: ");
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

	// Factorial(계승)
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
		break; // break를 만나면 반복문이 즉시 종료
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
			continue; // continue를 만나면 아래 코드를 실행하지 않고 점프
		}
		eRes += i;
		i++;
	} */

	for (i = 0; i <= num; i++) {
		if (i % 2 != 0) {
			oRes += i;
			continue; // continue를 만나면 아래 코드를 실행하지 않고 점프
		}
		eRes += i;
	}

	printf("Odd Addition to %d: %d\n", num, oRes);
	printf("Even Addition to %d: %d\n", num, eRes);
	DrawLine();
}

int main() {
	
	// start01();

	// 반복문: for
	// for(초기설정; 반복조건; 반복 후처리) { 반복처리 할 코드 }

	/*for (int i = 0; i < 10; i++) {
		printf("%d\t hello\n", i);
	} printf("\n");*/
	// start02();
	
	// 반복문: while
	// while(해당 조건이 true이면) { 반복처리 할 코드 }
	// start03();
	
	// return, break 이해
	// AAA();

	system("pause");
}