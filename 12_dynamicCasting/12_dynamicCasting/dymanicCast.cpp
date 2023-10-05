#include <stdio.h>
#include <iostream>

// RTTI(Run Time Type Information/Identification)
// x64일 경우 클래스 크기를 8/16/24/32 순으로 8바이트 간격으로 할당
// RTTI 공간 할당 8바이트 + 4바이트 = 12바이트
// 12바이트 담을 수 있는 최소 공간은 16바이트

class CBase {
public:
	// 가상함수 virtual function
	// 자식 클래스에서 함수를 override를 해서 재구현 가능
	// 가상함수가 되면 RTTI 정보를 가리키는 포인터 변수 공간 (x64기준) 8바이트 할당
	// RTTI 포인터는 해당 클래스의 정보를 가리키게 됨 
	// 동적 형변환 시 클래스의 크기를 참조하는 게 아니라
	// 추가로 할당된 RTTI 포인터에 클래스의 정보를 참조
	// 런타임 중 동적으로 할당
	virtual void printX() {
		printf("x : %d\n", m_X);
	}
	int m_X = 10;
};

// RTTI 공간 할당 8바이트 + 8바이트 = 16바이트
// 16바이트 담을 수 있는 최소 공간은 24바이트
class CChild1 : public CBase {
public:
	void printY() {
		printf("y : %d\n", m_Y);
	}
	int m_Y = 20;
};

class CChild2 : public CBase {
public:
	void printZ() {
		printf("z : %d\n", m_Z);
	}
	int m_Z = 30;
};

void dcast01() {
	printf("CBase Size : %I64d\n", sizeof(CBase));		// CBase 객체의 크기 반환 가능 (%I64d: int64 출력)
	printf("CChild Size : %I64d\n", sizeof(CChild1));	// CChild 객체의 크기 반환 가능

	int64_t* pB = (int64_t*)new CBase;
	int64_t* pC = (int64_t*)new CChild1;
	// RTTI 포인터 주소, m_X(, m_Y)가 차례대로 출력
	printf("pB[0] : %I64d, pB[1] : %d\n", pB[0], (int)pB[1]);
	printf("pC[0] : %I64d, pC[1] : %d, pC[2] : %d\n", pC[0], (int)pC[1], (int)pC[2]);

	delete pB;	delete pC;
}

void dcast02() {

}

int main() {
	dcast01();

	CBase* pBase[] = { new CChild1, new CChild2 };

	for (CBase* pTemp : pBase) {
		pTemp->printX();	// base에 있기 때문에 다 됨

		// Dynamic Casting : 동적 형변환
		// <CChild1*> : 형변환할 클래스 타입
		// (pTemp) : 형변환할 객체
		// CChild1* pChild : 형변환 결과 반환 값
		CChild1* pChild = dynamic_cast<CChild1*>(pTemp);
		if (pChild == nullptr) continue;	// 정상적으로 형변환되지 않으면 nullptr이 나옴
		pChild->printY();	// 정상적으로 형변환되면 객체가 반환됨. CChild1의 printY 사용 가능
	}

	for (CBase* pTemp : pBase) {
		delete pTemp;
	}
	
}