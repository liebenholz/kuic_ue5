#include <stdio.h>
#include <iostream>

// 0부터 100까지 2의 배수와 입력받은 수의 n의 배수 구하기
void multipleTo100(int n) {
	int count = 0;
	for (int i = 0; i <= 100; i++) {
		if (i % n == 0) {
			printf("%d\t", i); count++;
			if (count % 10 == 0 && i!=100) {
				printf("\n");
			}
		}
	} printf("\n");
	printf("# multiple of %d: %d\n", n, count);
}

void test01() {
	multipleTo100(2);
	printf("--------------------------------\n");
	int n;
	printf("Type num: ");
	scanf_s("%d", &n);
	multipleTo100(n);
	printf("=================================\n");
}

// abcdef 역으로 출력하기
void test02() {
	wchar_t szWChar[20] = L"abcdef";
	int n = (int)wcslen(szWChar);

	for (int i = 0; i < n; i++) {
		printf("%c", * (szWChar + n - 1 - i));
	}
	printf("\n=================================\n");
}

// 입력받은 문자열에서 'a'문자 갯수 출력하기
void test03() {
	wchar_t szWCharInput[20] = L"";
	printf("Type string : ");
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	wprintf(L"szWCharInput : %s\n", szWCharInput);

	int countA = 0;
	int n = (int)wcslen(szWCharInput);
	for (int i = 0; i < n; i++) {
		if (*(szWCharInput + i) == 'a' || *(szWCharInput + i) == 'A') countA++;
	//	if (szWCharInput[i] == 'a' || (szWCharInput[i] == 'A') countA++;
		// 문자열 비교는 cmp를 써야함
	}
	printf("# of 'a': %d\n", countA);
	printf("=================================\n");
}

int main() {
	test01();
	test02();
	test03();

	system("pause");
}