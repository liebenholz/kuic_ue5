#include <stdio.h>
#include <iostream>

// 0���� 100���� 2�� ����� �Է¹��� ���� n�� ��� ���ϱ�
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

// abcdef ������ ����ϱ�
void test02() {
	wchar_t szWChar[20] = L"abcdef";
	int n = (int)wcslen(szWChar);

	for (int i = 0; i < n; i++) {
		printf("%c", * (szWChar + n - 1 - i));
	}
	printf("\n=================================\n");
}

// �Է¹��� ���ڿ����� 'a'���� ���� ����ϱ�
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
		// ���ڿ� �񱳴� cmp�� �����
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