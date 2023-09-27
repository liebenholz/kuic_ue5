#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

// custom strLength : �Է¹��� ���ڿ��� ���� ��ȯ
unsigned int getStrLength(const wchar_t* _pString) {
	int i = 0;
	while (1) {
		wchar_t c = *(_pString + i);	// �������� �ּҰ��� ���ڸ� ����
		if (c == '\0') break;
		i++;
	}
	return i;
}

// custom strConcat : _Dest �� _pSource ��ġ��
void wcStrCat(wchar_t* _Dest, unsigned int n, const wchar_t* _pSource) {
	int destN = getStrLength(_Dest);
	int sourceN = getStrLength(_pSource);

	// ����ó��
	if (n < destN + sourceN + 1) {
		// printf("ERROR: Over Max Size!\n");
		assert(nullptr);
		return;
	}
	for (int i = 0; i < sourceN; i++) {
		*(_Dest + destN + i) = *(_pSource + i);	// ������ ���
		// _Dest[destN + i] = _pSource[i];		// �迭 ���
	}
}

int wcStrCmp(wchar_t* strL, wchar_t* strR) {
	int lenL = getStrLength(strL);
	int lenR = getStrLength(strR);
	int n = (lenL > lenR) ? lenL : lenR;

	for (int i = 0; i < n; i++) {
		if (strL[i] == strR[i]) continue;
		return (strL[i] < strR[i]) ? -1 : 1;
	}
	return 0;
}

void string01() {

	// ���� ó�� by �ƽ�Ű�ڵ�
	char c1 = 97;	// 1����Ʈ 0~255, ��ǻ� 128��
	char c2 = 'a';	// ���� �ϳ��� ���� ����ǥ, %c ��� 
	printf("c1 : %c, c2 : %c\n", c1, c2);	

	// �FƼ ����Ʈ �ڵ�: ���ڿ� ���� ���������� ũ�Ⱑ �����.
	// �������� ȣȯ�� ���� �ʴ� ������� �ٸ� �ý������� ������ ���ڸ� �˾ƺ� �� ���� ����
	// �Ϻ��� �ؽ�Ʈ ������ �ѱۿ��� ���� ���� ���� ���� �߻�
	// ö���� �ڱ��� ǥ�⸸�� ���� ���ڵ�, �ܱ��� ���� �� �ٸ� ����ü�谡 �ʿ��� ��� ������.

	// ���ڿ�(string) : ���� �迭
	char arrC1[10] = "abc�ѱ�";	// ���ڿ��� ���� �ֵ���ǥ, %s ���
	// ����� ���ڴ� 1����Ʈ, �ѱ���� ���ڴ� 2����Ʈ ���
	printf("arrC1 : %s\n", arrC1);

	// ���� ����� ������ �ֱ� ������ �� ������� �ʴ´�.

	// ���̵� ����(wide char) : ��Ƽ����Ʈ ������ �ذ��ϱ� ���� ����. �����ڵ� ���.
	// ������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱ� ���� ���(UTF-8)
	wchar_t wc1 = L'a';	// ���̵� 2����Ʈ 0~65535, ��ǻ� �� 3�� ��, ���� �� ���ڿ� ���� �� ���ڿ� �տ� L�� ����
	wprintf(L"wc1 : %c\n", wc1);	// ������ ��� ��� �� wprintf ���, ��� ���ڿ� �տ� L�� ����.

	_wsetlocale(LC_ALL, L"korean");	// ���̵� ���� ��� ����.
	wchar_t arrWC1[10] = L"abc�ѱ�";
	wprintf(L"arrWC1 : %s\n", arrWC1);

	wchar_t szWC[10] = L"abcdefghi";	// ������ �������̶�� ǥ��� \0�� �������� ��.(�� �� ����� ��)
	wprintf(L"szWC : %s\n", szWC);

	wchar_t szWCLen[20] = L"abcdefg";	// ���̵� ������ ���� ������ִ� �Լ� wcslen(wchar_t), int64�� ����.
	printf("szWCLen size : %d\n", (int)wcslen(szWCLen));		// 7
	printf("szWCLen size : %d\n", getStrLength(szWCLen));	// 7
}

// strLength, concatLength
void string02() {
	wchar_t szWCLen[20] = L"abcdef";
	wprintf(L"szWCLen : %s\n", szWCLen);
	printf("-------------------------\n");

	// cat(concatenation) : ���ڿ� �̾���̱� wcscat_s(wchar_t1, int, wchar_t2)
	// abcdefg\0 + hij\0 -> abcdefghij\0
	// wcscat_s(szWCLen, 20, L"ghij");
	wcStrCat(szWCLen, 20, L"ghij");
	wprintf(L"szWCLen : %s\n", szWCLen);
}

// strCopy, strCompare
void string03() {
	wchar_t szWCComp[20] = L"asdf";
	wprintf(L"szWComp : %s\n", szWCComp);
	printf("-------------------------\n");

	// ���� ���ڿ��� �� ���ڿ� ���� �ٿ��ֱ�
	wcscpy_s(szWCComp, L"abcdef");

	// ������ 0, ���� ������ ������ -1, �ڰ� ������ 1
	int nResult = wcscmp(L"asdf", L"qwer");
	printf("asdf / qwer compare result : %d\n", nResult);
	printf("=========================\n");

	wchar_t szWCComp1[20] = L"asdf";
	wchar_t szWCComp2[20] = L"asdf";

	printf("asdf ? asdf : %d\n", wcStrCmp(szWCComp1, szWCComp2));	 // 0
	wcscpy_s(szWCComp2, L"abcdef");
	printf("asdf ? abcdef : %d\n", wcStrCmp(szWCComp1, szWCComp2));  // 1
	wcscpy_s(szWCComp1, L"abcde");
	printf("abcde ? abcdef : %d\n", wcStrCmp(szWCComp1, szWCComp2)); // -1
}

int main() {
	// string01();
	// string02();
	// string03();

	system("pause");
}

// ����, ����Ʈ
// �����Ҵ�
// Ŭ����