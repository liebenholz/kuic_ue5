#include <stdio.h>
#include <iostream>

class cName {

public:
	// 생성자(이름): 이름 및 길이 초기화
	cName(const wchar_t* name) :szName(nullptr), len(0) {
		// szName = name;	 // 길이가 다를 수 있기 때문에 불가
		len = wcslen(name) + 1;		// 공백문자까지 포함
		szName = new wchar_t[len];	// 동적할당

		// szName에 내가 입력한 이름을 복사
		wcscpy_s(szName, len, name);
	}

	// 복사 생성자 및 복사할당 연산자
	// 파라미터로 (const cName& other) 와 같이 자신의 클래스 카입을 레퍼런스로 받을 때
	cName(const cName& other) :szName(nullptr), len(0) {
		if (szName != nullptr) { delete[] szName; }
		len = wcslen(other.szName) + 1;	
		szName = new wchar_t[len];	
		wcscpy_s(szName, len, other.szName);
	}

	// 파괴자
	~cName() { delete[] szName; }

	// 이름 가져오기
	wchar_t* getName() { return szName; }

	// 대입연산자 오버로딩
	const cName& operator=(const cName& other) {
		// 얕은 복사: other.szName이 가리키고 있는 곳을 szName도 가리키게 하겠다
		// szName = other.szName;
		// len = other.len;
		// main에서 name1 = name2; 를 진행하면 오류 발생

		// 깊은 복사: other.szName을 복사해서 szName에 넣는다
		if (szName != nullptr) { delete[] szName; }
		len = wcslen(other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, other.szName);

		return *this;
	}

	wchar_t* szName;
	size_t len;
};

int main() {

	_wsetlocale(LC_ALL, L"korean");

	cName name1(L"성혁");
	cName name2(L"즌");
	wprintf(L"name1: %s,\t name2: %s\n", name1.getName(), name2.getName());

	// 대입연산자 처리
	// const cName& operator=(const cName & other)
	name1 = name2;	

	// 복사 생성자 및 복사할당 연산자
	// cName(const cName & other) :szName(nullptr), len(0)
	cName name3 = name1;

	wprintf(L"name1: %s,\t name3: %s\n", name1.getName(), name3.getName());

}