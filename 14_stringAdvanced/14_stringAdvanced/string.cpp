#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// ���ӽ����̽��� ���� �ĺ��ڷ� ���� ���� ���̺귯���� ����� �� �̸����� �浹�� �����ϱ� ���� ���
using namespace std;	// std �̸� ������ �������ڴ�. std ���̺귯�� �Լ� �տ� std�� ������ �ʾƵ� ��

void stringCpp() {
	/*
	* String�̶�? cpp STL���� �����ϴ� Ŭ������, ���ڿ��� �ٷ�
	* C������ char* �Ǵ� char[]�� ���·� ���ڿ��� �������ٸ�, cpp������ ���ڿ��� �ϳ��� ���� Ÿ��ó�� ���
	* ���ڿ��� �پ��ϰ� ���� �ٷ� �� �ֵ��� �Ѵ�
	* char*, char[]�� �ٸ��� ���ڿ��� ���� '\0'���ڰ� ���� ������, ���ڿ��� ���̸� �������� ���� ����
	*/

	wchar_t chars[20] = L"abcdef";
	int result = wcscmp(chars, L"abcdef");
	wcscpy_s(chars, L"abcdef");

	// ������: std:string
	// �����̸�: strA
	// �⺻��: L"abcdef"
	std::string strA("abcdef");
	printf("strA = %s\n", strA.c_str());	// ���ڿ� ����� c_str() �Լ��� ���
	size_t size = strA.size();		// ���ڿ��� ũ�� ���ϱ�(�������� �����Ͱ��� ũ��) 
	size_t len = strA.length();		// ���ڿ��� ���� ���ϱ�(������ ����)
	printf("----------------------\n");

	std::string A("12");
	std::string B("34");
	A += B;	// ���Կ����� �����, append() ���
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());
	A = B;	// ���Կ����� �����, wcscpy() ���
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());

	if (A == B) {	// �񱳿����� �����, wcscmp() ���
		printf("A==B\n");
	}
	else printf("A!=B\n");
}

void wstringCpp() {
	std::wstring wstr;	//wchar_t�� string
	// auto: ������ ���� ���¿� ���� �ڵ��Ƿ� �������� ������
	// literals: https://learn.microsoft.com/ko-kr/cpp/cpp/string-and-character-literals-cpp?view=msvc-170 
	auto stringS = "abcdef"s;	// string�� ������ ǥ��

	double d = 3.14;
	string strD = to_string(d);	// to_string(): ���ڿ��� ���ڷ� ��ȯ
	printf("strD: %s\n", strD.c_str());

	string toParse = "123USD";
	size_t index = 0;
	// stoi(int), stof(float), stod(double), stol(long)
	int nResult = stoi(toParse, &index);	// ���ڿ��� ���ڷ� ��ȯ
	printf("stoi result: %d\n", nResult);	// nResult: ��ȯ�� ����
	// toParse[index]: Parser ������ �Ұ����� ù��° �ε���
	printf("toParse index character: %c\n", toParse[index]);

	string findStr = "123SABC456SORRY";
	int nPointL = findStr.find('S');	// find(): ���ʿ������� ���� ã��, nPoint: ù��° ã�� ������ ���ڿ��� ��ġ
	printf("Left found point[%d] character: %c\n", nPointL, findStr[nPointL]);
	int nPointR = findStr.rfind('S');	// rfind(): �����ʿ������� ���� ã��
	printf("Right found point[%d] character: %c\n", nPointR, findStr[nPointR]);

	// substr(�߶���� �����ϰ���� �ε��� ��ȣ, ����): ����� �Ǵ� ���ڿ��� �߶����
	// findStr���� ó������ nPointL ���� ���� �ڸ���
	string strL = findStr.substr(0, nPointL);
	// findStr���� nPointL���� nPointR���� �ڸ���
	string strC = findStr.substr(nPointL, nPointR - nPointL);
	// findStr���� nPointR���� ������ �ڸ���
	string strR = findStr.substr(nPointR, findStr.length() - nPointR);
	printf("strL: %s\nstrC: %s\nstrR: %s\n", strL.c_str(), strC.c_str(), strR.c_str());

}

void sstreamCpp() {
	string findStr = "123SABC456SORRY";
	string testStr = "1,2,3,4,5,6,7,8,9";
	stringstream ssTest(testStr);
	string line;

	// ssTest ���ʺ���, ','�� �������� ���ڸ� �߶� line�� �ִ´�.
	// getLine ����� false(�� �̻� ���� ���ڿ��� ������): ����
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