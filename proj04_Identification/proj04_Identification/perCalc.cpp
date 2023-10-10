#include <stdio.h>
#include <iostream>
#include "perCalc.h"

int myPER(int sal) {
	// �ҵ� 10�� �ʰ� : 45%
	if (sal > 100000) {
		printf("PER: 45%\n");
		return sal * 0.45;
	}
	// �ҵ� 5�� �ʰ� 10�� ���� : 42%
	else if (sal > 50000) {
		printf("PER: 42%\n");
		return sal * 0.42;
	}
	// �ҵ� 3�� �ʰ� 5�� ���� : 40%
	else if (sal > 30000) {
		printf("PER: 40%\n");
		return sal * 0.40;
	}
	// �ҵ� 1��5õ �ʰ� 3�� ���� : 38%
	else if (sal > 15000) {
		printf("PER: 38%\n");
		return sal * 0.38;
	}
	// �ҵ� 8800�� �ʰ� 1��5õ ���� : 35%
	else if (sal > 8800) {
		printf("PER: 35%\n");
		return sal * 0.35;
	}
	// �ҵ� 4600�� �ʰ� 8800�� ���� : 24%
	else if (sal > 4600) {
		printf("PER: 24%\n");
		return sal * 0.24;
	}
	// �ҵ� 1200�� �ʰ� 4600�� ���� : 15%
	else if (sal > 1200) {
		printf("PER: 15%\n");
		return sal * 0.15;
	}
	// �ҵ� 1200�� ���� : 6%
	else {
		printf("PER: 6%\n");
		return sal * 0.06;
	}
}

void perCalc() {
	int salary = 1;

	// �ҵ� �Է��� 0�� ������ �ݺ���.
	while (salary != 0) {
		printf("Type your annual salary (����): ");
		// �ҵ��� �Է¹���
		scanf_s("%d", &salary);
		// ���� �ҵ漼 ���
		printf("My PER : %d KRW\n", myPER(salary));
	}
	system("pause");
}