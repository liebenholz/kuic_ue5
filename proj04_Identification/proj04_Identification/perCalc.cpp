#include <stdio.h>
#include <iostream>
#include "perCalc.h"

int myPER(int sal) {
	// 소득 10억 초과 : 45%
	if (sal > 100000) {
		printf("PER: 45%\n");
		return sal * 0.45;
	}
	// 소득 5억 초과 10억 이하 : 42%
	else if (sal > 50000) {
		printf("PER: 42%\n");
		return sal * 0.42;
	}
	// 소득 3억 초과 5억 이하 : 40%
	else if (sal > 30000) {
		printf("PER: 40%\n");
		return sal * 0.40;
	}
	// 소득 1억5천 초과 3억 이하 : 38%
	else if (sal > 15000) {
		printf("PER: 38%\n");
		return sal * 0.38;
	}
	// 소득 8800만 초과 1억5천 이하 : 35%
	else if (sal > 8800) {
		printf("PER: 35%\n");
		return sal * 0.35;
	}
	// 소득 4600만 초과 8800만 이하 : 24%
	else if (sal > 4600) {
		printf("PER: 24%\n");
		return sal * 0.24;
	}
	// 소득 1200만 초과 4600만 이하 : 15%
	else if (sal > 1200) {
		printf("PER: 15%\n");
		return sal * 0.15;
	}
	// 소득 1200만 이하 : 6%
	else {
		printf("PER: 6%\n");
		return sal * 0.06;
	}
}

void perCalc() {
	int salary = 1;

	// 소득 입력이 0일 때까지 반복함.
	while (salary != 0) {
		printf("Type your annual salary (만원): ");
		// 소득을 입력받음
		scanf_s("%d", &salary);
		// 계산된 소득세 출력
		printf("My PER : %d KRW\n", myPER(salary));
	}
	system("pause");
}