#include <stdio.h>
#include <iostream>

// 상속: 기존 클래스의 기능을 추가하거나 재정의해 새로운 클래스를 정의
// 생물: 기본 최상위 클래스
// 동물: 생물 + 움직인다, 생물의 기능을 상속받음
// 포유류: 동물 + 젖먹이, 동물의 기능을 상속받음
// 사람: 포유류 + 지적능력, 포유류의 기능을 상속받음

void drawLine() {
	printf("------------------------------------\n");
}

class CBase {
public:
	CBase(int x) : m_X(x) {
		printf("Parent Class Generated!\n");
	}
	int m_X;

	~CBase() { printf("Parent Class Destroyed!\n"); }
};

class CChild : public CBase { // : 상속받을 클래스
public:
	// ":" 뒤에 부모클래스를 넣어 부모클래스의 생성자를 호출
	// 부모클래스 생성자 선 호출, 이후 자식클래스 생성자
	CChild(int x, int y) : m_Y(y), CBase(x) {
		printf("Child Class Generated!\n"); 
	}
	int m_Y;

	// 자식클래스 파괴자 선 호출, 이후 부모클래스 파괴자
	~CChild() { printf("Child Class Destroyed!\n"); }
};

int main() {
	CBase base(10);
	base.m_X = 100;

	CChild child(10, 20);
	base.m_X = 200;	// 상속받은 부모의 기능을 그대로 사용 가능
	drawLine();

}

