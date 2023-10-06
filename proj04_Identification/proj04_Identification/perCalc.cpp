#include <stdio.h>
#include <iostream>
#include "perCalc.h"

int myPER(int sal) {
	if (sal > 100000)
		return sal * 0.45;
	else if (sal > 50000)
		return sal * 0.42;
	else if (sal > 30000)
		return sal * 0.40;
	else if (sal > 15000)
		return sal * 0.38;
	else if (sal > 8800)
		return sal * 0.35;
	else if (sal > 4600)
		return sal * 0.24;
	else if (sal > 1200)
		return sal * 0.15;
	else
		return sal * 0.06;
}

void perCalc() {
	int salary = 1;

	while (salary != 0) {
		printf("Type your annual salary (¸¸¿ø): ");
		scanf_s("%d", &salary);

		printf("My PER : %d KRW\n", myPER(salary));
	}
	system("pause");
}