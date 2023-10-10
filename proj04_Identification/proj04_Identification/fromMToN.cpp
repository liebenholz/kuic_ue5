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
	// 사이의 합을 구할 두 정수를 입력받는다.
	scanf_s("%d %d", &m, &n);
	// m이 n보다 크면 두 개의 값을 바꾼다.
	if (m > n) swap(&m, &n);

	// m부터 n까지의 합을 sum에 저장한다.
	int sum = 0;
	for (int i = m; i <= n; i++) {
		sum += i;
	}
	printf("Sum between %d and %d is %d.\n", m, n, sum);
	system("pause");
}


