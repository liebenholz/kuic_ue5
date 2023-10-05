#include <stdio.h>
#include <iostream>

void drawLine() {
	printf("------------------------------------\n");
}

// 상속: 기존 클래스의 기능을 추가하거나 재정의해 새로운 클래스를 정의
// 생물: 기본 최상위 클래스
// 동물: 생물 + 움직인다, 생물의 기능을 상속받음
// 포유류: 동물 + 젖먹이, 동물의 기능을 상속받음
// 사람: 포유류 + 지적능력, 포유류의 기능을 상속받음

class CBase {
public:
	CBase(int x = 1, int y = 2) : m_X(x), m_Y(y) {
		printf("Parent Class Generated!\n");
	}

	~CBase() { printf("Parent Class Destroyed!\n"); }

	/*
	virtual void printValue() {
		printf("m_X : %d, m_Y: %d\n", m_X, m_Y);
	}
	*/
	int m_X;
	int m_Y;
};

class CChild : public CBase { // : 상속받을 클래스
public:
	// ":" 뒤에 부모클래스를 넣어 부모클래스의 생성자를 호출
	// 부모클래스 생성자 선 호출, 이후 자식클래스 생성자
	CChild(int x = 1, int y = 2, int z = 3) : m_Z(z), CBase(x,y) {
		printf("Child Class Generated!\n"); 
	}

	// 자식클래스 파괴자 선 호출, 이후 부모클래스 파괴자
	~CChild() { printf("Child Class Destroyed!\n"); }

	// 가상함수 : 자식 클래스에서 재정의할 것으로 기대하는 멤버 함수
	/*
	virtual void printValue() override {
		CBase::printValue();	// 부모의 처리를 그대로 실행
		printf("m_X : %d, m_Y: %d, m_Z: %d\n", m_X, m_Y, m_Z);
	}
	*/
	int m_Z;
};

void inheritance() {
	CBase base(10);
	base.m_X = 100;
	// base.printValue();

	CChild child(20);
	base.m_X = 200;	// 상속받은 부모의 기능을 그대로 사용 가능
	// child.printValue();
	drawLine();
}

// Upcasting : 자식에서 부모로 형변환될 때는 
// 별다른 연산자 없이 자동으로 형변환이 이루어짐
void printObject(CBase** pBase, int n) {
	for (int i = 0; i < n; i++) {
		printf("xpos : %d, ypos : %d\n", pBase[i]->m_X, pBase[i]->m_Y);
	}
}

/*
void upcast01() {
	CChild* pArrChild = new CChild[10];
	printObject(pArrChild, 10);	// 업캐스팅
	delete[] pArrChild;
}
*/

// 보통 STL 사용.. 그냥 해 보는거임
void upcast02() {

	CBase** pArrBase = new CBase * [10];
	for (int i = 0; i < 10; i++) {
		pArrBase[i] = new CChild;
	}
	printObject(pArrBase, 10);

	for (int i = 0; i < 10; i++) {
		delete pArrBase[i];
	}
	// delete[] pArrBase;
}

int main() {
	// inheritance();
	// upcast01();
	upcast02();

	system("pause");
}

