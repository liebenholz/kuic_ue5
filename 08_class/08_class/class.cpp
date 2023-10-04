#include <stdio.h>
#include <iostream>

// 변수, 자료형
struct stMyStruct {
	int a; int b; int c;

	// 구조체의 초기화
	stMyStruct() : a(0), b(0) {
		c = 0;
	}
};

// 변수, 자료형
// Class는 사용자 정의 type이라 한다. struct의 확장.
// cpp의 클래스는 세 가지 접근 지정자(private, protected, public)에 의해
// 접근이 제어되는 멤버로 데이터 및 함수가 있는 사용자 정의 유형, 데이터 구조를 만든다.

// 접근 지정자를 사용하여 데이터 및 함수를 만드는 것을 캡슐화(capsulization) 라고 한다.
// Class를 번역하면 '형틀'로, 사용가능한 객체가 아님. 객체를 사용하기 위한 모양을 나타냄.
class cMyClass {
	// 위에 접근 지정자가 없으면 기본적으로 private.
	int a1, a2;

	// 생성자: 클래스 생성 시 호출. 선언하지 않아도 기본 생성자가 존재.
	// 반드시 파괴자는 public이어야 한다. private이면 외부에서 호출 불가.
public:	
	cMyClass(int value) : a(0), b(0), c(0) {
		printf("Class Generated!\n");
		a1 = value; a2 = value;
	}

	// 파괴자: 클래스 파괴 시 호출. 선언하지 않아도 기본 파괴자가 존재.	
	// 반드시 생성자는 public이어야 한다. private이면 외부에서 호출 불가.
	~cMyClass() {
		printf("Class Destroyed!\n");
	}

private:	// 외부에서 접근 불가
	int a;		
protected:  // 상속관계일 경우 접근 가능, 이외에는 접근 불가
	int b;	
public:		// 외부 어디서든 접근 가능
	int c;		
};

int main() {
	stMyStruct mySt;
	mySt.a = 0;

	cMyClass myCl(10);	// 생성자 호출됨
	myCl.c = 10;
	// 파괴자 호출됨
}