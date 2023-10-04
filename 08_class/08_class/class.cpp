#include <stdio.h>
#include <iostream>
#include "myClass.h"

// 변수, 자료형
struct stMyStruct {
	int a; int b; int c;

	// 구조체의 초기화
	stMyStruct() : a(0), b(0) {
		c = 0;
	}

	void printABC() {
		printf("%d %d %d\n", a, b, c);
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
	// int a1, a2;

	// 생성자: 클래스 생성 시 호출. 선언하지 않아도 기본 생성자가 존재.
	// 반드시 파괴자는 public이어야 한다. private이면 외부에서 호출 불가.
public:	
	cMyClass() : a(0), b(0), c(0) {
		// a1 = value; a2 = value;
	}

	// 생성자도 파라미터의 개수와 타입에 따라 Overload(타입별 여러개의 함수 생성) 가능
	// (int valA = 0) 형식으로 파라미터 초기화도 가능
	// :a(valA), b(valB), c(0) 형식으로 멤버변수 초기화도 가능
	// 파라미터 변수의 형태가 입력 방식에 의해 선택이 불가능하면 문제가 발생한다.
	cMyClass(int value) : a(value), b(value), c(value) {
		// printf("Class A Generated!\n");
		// a1 = value; a2 = value;
	}

	cMyClass(int valA, int valB) : a(valA), b(valB), c(0) {
		// printf("Class B Generated!\n");
		// a1 = valA; a2 = valB;
	}

	cMyClass(int valA, int valB, int valC) : a(valA), b(valB), c(valC) {
		// printf("Class B Generated!\n");
		// a1 = valA; a2 = valB;
	}

	// 파괴자: 클래스 파괴 시 호출. 선언하지 않아도 기본 파괴자가 존재.	
	// 반드시 생성자는 public이어야 한다. private이면 외부에서 호출 불가.
	~cMyClass() {
		// printf("Class Destroyed!\n");
	}

	/*
	void printAA() {
		printf("%d %d\n", a1, a2);
	}
	*/

	void printABC() {
		printf("%d %d %d\n", a, b, c);
	}

	void setPrivA(int n) {
		// 일반적으로는 this 키워드는 생략
		// 클래스 안의 함수를 호출한 대상 객체를 의미
		this->a = n;
	}

	// 연산자 오버로딩(Operator Overloading) 
	// 대입연산자: 직접 구현하지 않아도 자동생성됨
	// const cMyClass& : 왼쪽으로 반환될 변수형
	// operator= 오버로딩할 연산자
	// (const cMyClass& other) : 오른쪽에 입력될 변수
	// a = b
	const cMyClass& operator=(const cMyClass& other) {
		a = other.a;
		b = other.b;
		c = other.c;
		// a1 = other.a1;
		// a2 = other.a2;

		return *this;
	}

	// myCl3 = myCl + myCl2;
	// myCl3 = cMyClass(a+other.a, b+other.b, c+other.c);

	// a + b
	// cMyClass(a+other.a, b+other.b, c+other.c);
	const cMyClass& operator+(const cMyClass& other) {
		return cMyClass(a+other.a, b+other.b, c+other.c);
	}

private:	// 외부에서 접근 불가
	int a;		
protected:  // 상속관계일 경우 접근 가능, 이외에는 접근 불가
	int b;	
public:		// 외부 어디서든 접근 가능
	int c;		
};

// 객체(Object)
// Class를 사용해서 생성된 것, Class에 선언한 변수들이 생성되거, 메모리에서 공간을 차지.

// 객체 지향 프로그래밍(Object-Oriented Programming)
// 컴퓨터 프로그램을 명령어의 목록으로 보는 시각에서 벗어나 
// 여러 개의 독립된 단위(객체)의 모임으로 구조를 만드는 패러다임
// 각각의 객체는 메세지를 주고 받고, 데이터를 독립적으로 처리 가능.

void class01() {
	stMyStruct mySt;
	mySt.a = 0;

	cMyClass myCl(10);	// 생성자 호출됨
	myCl.c = 10;

	// 특정 변수를 수정하기 위한 함수를 생성해서 개발하는 게 기본 규칙
	myCl.setPrivA(2);
	myCl.setPrivA(3);
	myCl.setPrivA(5);
	myCl.setPrivA(8);
	myCl.setPrivA(13);

	// 만약 변수를 private로 되어있다면 개발자가 직접 접근하지 말라는 의도가 있음.
	// myCl.a = 21;
} // 파괴자 호출됨

void class02() {
	cMyClass myClA(10);
	cMyClass myClB(10, 20);

	myClA.printABC();
	myClB.printABC();
}

// 참조 연산자(Reference, &)
// 메모리 복제가 되지 않고 원본을 참조해 메모리를 효율적으로 사용하기 위한 연산자
void ref01() {
	int num = 100;
	stMyStruct stTest;

	// 포인터 참조는 포인터 변수의 주소값을 참조한다.
	// 포인터 변수의 주소값 != 포인터가 가리키고 있는 주소값
	int* pNum = &num;
	stMyStruct* ptest = &stTest;
	ptest->a = 0;
	printf("&pNum == &num ? : %d\n %d\n %d\n", (int(& pNum) == int(&num)), int(&pNum), int(&num));	// false

	// 참조 연산자는 원본 대상의 주소 값과 동일.
	int& refNum = num;
	stMyStruct& refTest = stTest;
	refTest.a = 0;
	printf("&refNum == &num ? : %d\n %d\n %d\n", (int(&refNum) == int(&num)), int(&refNum), int(&num));	// true
}

void drawLine() {
	printf("--------------------------\n");
}

int main() {
	// class01();
	// ref01();
	// class02();

	cMyClass myCl(100);
	cMyClass myCl2(0, 50);

	myCl.printABC();
	myCl2.printABC();
	drawLine();

	myCl = myCl2;
	myCl.printABC();
	myCl2.printABC();
	drawLine();

	cMyClass myCl3;
	myCl3 = myCl + myCl2;
	myCl3.printABC();
	drawLine();

	system("pause");
}