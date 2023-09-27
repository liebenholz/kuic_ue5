#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>

// custom strLength : 입력받은 문자열의 길이 반환
unsigned int getStrLength(const wchar_t* _pString) {
	int i = 0;
	while (1) {
		wchar_t c = *(_pString + i);	// 순차적인 주소값에 문자를 저장
		if (c == '\0') break;
		i++;
	}
	return i;
}

// custom strConcat : _Dest 에 _pSource 합치기
void wcStrCat(wchar_t* _Dest, unsigned int n, const wchar_t* _pSource) {
	int destN = getStrLength(_Dest);
	int sourceN = getStrLength(_pSource);

	// 예외처리
	if (n < destN + sourceN + 1) {
		// printf("ERROR: Over Max Size!\n");
		assert(nullptr);
		return;
	}
	for (int i = 0; i < sourceN; i++) {
		*(_Dest + destN + i) = *(_pSource + i);	// 포인터 사용
		// _Dest[destN + i] = _pSource[i];		// 배열 사용
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

	// 문자 처리 by 아스키코드
	char c1 = 97;	// 1바이트 0~255, 사실상 128개
	char c2 = 'a';	// 문자 하나일 때는 따옴표, %c 사용 
	printf("c1 : %c, c2 : %c\n", c1, c2);	

	// 멑티 바이트 코드: 문자에 따라 가면형으로 크기가 변경됨.
	// 국가간의 호환이 되지 않는 방식으로 다른 시스템으로 보내면 글자를 알아볼 수 없게 깨짐
	// 일본어 텍스트 파일을 한글에서 열면 문자 깨짐 현상 발생
	// 철저히 자국어 표기만을 위해 인코딩, 외국어 교재 등 다른 문자체계가 필요한 경우 불편함.

	// 문자열(string) : 문자 배열
	char arrC1[10] = "abc한글";	// 문자열일 때는 쌍따옴표, %s 사용
	// 영어는 글자당 1바이트, 한국어는 글자당 2바이트 사용
	printf("arrC1 : %s\n", arrC1);

	// 위의 방식은 문제가 있기 때문에 잘 사용하지 않는다.

	// 와이드 문자(wide char) : 멀티바이트 문제를 해결하기 위해 등장. 유니코드 방식.
	// 세계의 거의 모든 문자를 표현할 수 있기 때문에 최근 많이 사용(UTF-8)
	wchar_t wc1 = L'a';	// 와이드 2바이트 0~65535, 사실상 약 3만 개, 문자 및 문자열 넣을 때 문자열 앞에 L을 붙임
	wprintf(L"wc1 : %c\n", wc1);	// 문자의 경우 출력 시 wprintf 사용, 출력 문자열 앞에 L을 붙임.

	_wsetlocale(LC_ALL, L"korean");	// 와이드 문자 언어 설정.
	wchar_t arrWC1[10] = L"abc한글";
	wprintf(L"arrWC1 : %s\n", arrWC1);

	wchar_t szWC[10] = L"abcdefghi";	// 문자의 마지막이라는 표기로 \0이 마지막에 들어감.(한 개 빼줘야 함)
	wprintf(L"szWC : %s\n", szWC);

	wchar_t szWCLen[20] = L"abcdefg";	// 와이드 문자의 길이 출력해주는 함수 wcslen(wchar_t), int64로 받음.
	printf("szWCLen size : %d\n", (int)wcslen(szWCLen));		// 7
	printf("szWCLen size : %d\n", getStrLength(szWCLen));	// 7
}

// strLength, concatLength
void string02() {
	wchar_t szWCLen[20] = L"abcdef";
	wprintf(L"szWCLen : %s\n", szWCLen);
	printf("-------------------------\n");

	// cat(concatenation) : 문자열 이어붙이기 wcscat_s(wchar_t1, int, wchar_t2)
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

	// 앞쪽 문자열에 뒷 문자열 복사 붙여넣기
	wcscpy_s(szWCComp, L"abcdef");

	// 같으면 0, 앞이 순번이 빠르면 -1, 뒤가 빠르면 1
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

// 벡터, 리스트
// 동적할당
// 클래스