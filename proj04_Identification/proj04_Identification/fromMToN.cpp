#include <stdio.h>
#include <iostream>
#include "fromMToN.h"

void swap(int* i, int* j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void fromMToN() {
	int m, n;
	printf("Type two integers you want to know the sum between them: ");
	// ������ ���� ���� �� ������ �Է¹޴´�.
	scanf_s("%d %d", &m, &n);
	// m�� n���� ũ�� �� ���� ���� �ٲ۴�.
	if (m > n) swap(&m, &n);

	// m���� n������ ���� sum�� �����Ѵ�.
	int sum = 0;
	for (int i = m; i <= n; i++) {
		sum += i;
	}
	printf("Sum between %d and %d is %d.\n", m, n, sum);
	system("pause");
}


