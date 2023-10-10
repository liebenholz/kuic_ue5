#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// 네임스페이스는 내부 식별자로 여러 개의 라이브러리를 사용할 때 이름간의 충돌을 방지하기 위해 사용
using namespace std;	// std 이름 공간을 가져오겠다. std 라이브러리 함수 앞에 std를 붙이지 않아도 됨

void stringCpp() {
	/*
	* String이란? cpp STL에서 제공하는 클래스로, 문자열을 다룸
	* C에서는 char* 또는 char[]의 형태로 문자열을 나누었다면, cpp에서는 문자열을 하나의 변수 타입처럼 사용
	* 문자열을 다양하고 쉽게 다룰 수 있도록 한다
	* char*, char[]과 다르게 문자열의 끝에 '\0'문자가 들어가지 않으며, 문자열의 길이를 동적으로 변경 가능
	*/

	wchar_t chars[20] = L"abcdef";
	int result = wcscmp(chars, L"abcdef");
	wcscpy_s(chars, L"abcdef");

	// 변수형: std:string
	// 변수이름: strA
	// 기본값: L"abcdef"
	std::string strA("abcdef");
	printf("strA = %s\n", strA.c_str());	// 문자열 출력은 c_str() 함수를 사용
	size_t size = strA.size();		// 문자열의 크기 구하기(물리적인 데이터공간 크기) 
	size_t len = strA.length();		// 문자열의 길이 구하기(문자의 개수)
	printf("----------------------\n");

	std::string A("12");
	std::string B("34");
	A += B;	// 대입연산자 적용됨, append() 기능
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());
	A = B;	// 대입연산자 적용됨, wcscpy() 기능
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());

	if (A == B) {	// 비교연산자 적용됨, wcscmp() 기능
		printf("A==B\n");
	}
	else printf("A!=B\n");
}

void wstringCpp() {
	std::wstring wstr;	//wchar_t형 string
	// auto: 대입한 값의 형태에 따라 자동의로 변수형이 설정됨
	// literals: https://learn.microsoft.com/ko-kr/cpp/cpp/string-and-character-literals-cpp?view=msvc-170 
	auto stringS = "abcdef"s;	// string형 문자형 표기

	double d = 3.14;
	string strD = to_string(d);	// to_string(): 숫자에서 문자로 변환
	printf("strD: %s\n", strD.c_str());

	string toParse = "123USD";
	size_t index = 0;
	// stoi(int), stof(float), stod(double), stol(long)
	int nResult = stoi(toParse, &index);	// 문자에서 숫자로 변환
	printf("stoi result: %d\n", nResult);	// nResult: 변환된 숫자
	// toParse[index]: Parser 실행이 불가능한 첫번째 인덱스
	printf("toParse index character: %c\n", toParse[index]);

	string findStr = "123SABC456SORRY";
	int nPointL = findStr.find('S');	// find(): 왼쪽에서부터 문자 찾기, nPoint: 첫번째 찾은 문자의 문자열상 위치
	printf("Left found point[%d] character: %c\n", nPointL, findStr[nPointL]);
	int nPointR = findStr.rfind('S');	// rfind(): 오른쪽에서부터 문자 찾기
	printf("Right found point[%d] character: %c\n", nPointR, findStr[nPointR]);

	// substr(잘라오기 시작하고싶은 인덱스 번호, 길이): 대상이 되는 문자열을 잘라오기
	// findStr에서 처음부터 nPointL 기준 왼쪽 자르기
	string strL = findStr.substr(0, nPointL);
	// findStr에서 nPointL부터 nPointR까지 자르기
	string strC = findStr.substr(nPointL, nPointR - nPointL);
	// findStr에서 nPointR부터 끝까지 자르기
	string strR = findStr.substr(nPointR, findStr.length() - nPointR);
	printf("strL: %s\nstrC: %s\nstrR: %s\n", strL.c_str(), strC.c_str(), strR.c_str());

}

void sstreamCpp() {
	string findStr = "123SABC456SORRY";
	string testStr = "1,2,3,4,5,6,7,8,9";
	stringstream ssTest(testStr);
	string line;

	// ssTest 왼쪽부터, ','를 기준으로 문자를 잘라 line에 넣는다.
	// getLine 결과가 false(더 이상 읽을 문자열이 없으면): 종료
	while (getline(ssTest, line, ',')) {
		printf("line: %s\n", line.c_str());
	}
}


int main() {

	// stringCpp();
	// wstringCpp();
	sstreamCpp();

	system("pause");

}