#include <stdio.h>
#include <iostream>

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


int main() {
	bool bRun = true;

	while (bRun) {
		int n1, n2;
		int nCalc = 0, nCont = 0;
		printf("Type two numbers: ");
		scanf_s("%d %d", &n1, &n2);

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
			printf("Division is %.2f\n", divi(n1, n2));
			break;
		case 4:
			printf("Remainder is %d\n", rem(n1, n2));
			break;

		}

		printf("continue?(y=0/n=1): ");
		scanf_s("%d", &nCont);
		
		switch (nCont) {
		case 1:
			bRun = false;
			break;
		}
	}
	system("pause");
 }