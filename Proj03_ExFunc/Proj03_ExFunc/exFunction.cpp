#include <stdio.h>
#include <iostream>
#include "calcSum.h"
#include "calcSubt.h"
#include "calcMul.h"
#include "calcDiv.h"

void avg(int& sum, int a, int b, int c) {
	sum = (a + b + c) / 3;
}

int arrSum(int* arr, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}

// 클래스 이름 : CShop
class cShop {
public:
	// 맴버 변수 : m_value(기본값:0)
	cShop():m_value(0) {}

	~cShop() {}

	// 멤버 함수 추가 : printValue
	// printValue 함수 결과 : "Value=%d"로 m_value 출력
	void printValue() {
		printf("value : %d\n", m_value);
	}

	int m_value;
};

// 클래스 이름 : CPhoneShop
// 부모 클래스 : CShop
class cPhoneShop : public cShop {
public:
	// 생성자 파라메타 : int PhoneCnt (m_PhoneCnt에 값 적용), int PhonePrice (m_PhonePrice에 값 적용)
	cPhoneShop(int phoneCnt, int phonePrice) : m_PhoneCnt(phoneCnt), m_PhonePrice(phonePrice) { }

	~cPhoneShop() {}

	// printValue 함수 결과 : "Value=%d"로 m_PhoneCnt * m_PhonePrice출력
	void printValue() {
		printf("value : %d\n", m_PhoneCnt * m_PhonePrice);
	}

	int m_PhoneCnt;		// 멤버 변수 : m_PhoneCnt
	int m_PhonePrice;	// 멤버 변수 : m_PhonePrice

};

// 클래스 이름 : CFruitShop
// 부모 클래스 : CShop
class cFruitShop : public cShop {
public:
	// 생성자 파라메타 : int FruitCnt (m_FruitCnt에 값 적용), int FruitPrice (m_FruitPrice에 값 적용)
	cFruitShop(int fruitCnt, int fruitPrice) : m_FruitCnt(fruitCnt), m_FruitPrice(fruitPrice) { }

	~cFruitShop() {}

	// printValue 함수 결과 : "Value=%d"로 m_PhoneCnt * m_PhonePrice출력
	void printValue() {
		printf("value : %d\n", m_FruitCnt * m_FruitPrice);
	}

	int m_FruitCnt;		// 멤버 변수 : m_FruitCnt
	int m_FruitPrice;	// 멤버 변수 : m_FruitPrice
};


int main() {

	int a = 20, b = 12;
	printf("Sum : %d\n", calcSum(a,b));
	printf("Subt : %d\n", calcSubt(a, b));
	printf("Multi : %d\n", calcMul(a, b));
	printf("Divi : %.2f\n", calcDiv(a, b));

	int sum, c = 10;
	avg(sum, a, b, c);
	printf("Average : %d\n", sum);

	int arr[10] = { 1, 2, 3, 4, 5, 5, 6, 7, 8, 9 };
	printf("Sum of Array : %d\n", arrSum(arr, 10));

	// CPhoneShop(10, 100) 생성 후 객체에 printValue 출력
	cPhoneShop myShop1(10, 100);
	myShop1.printValue();

	// CFruitShop(10, 100) 생성 후 객체에 printValue 출력
	cFruitShop myShop2(10, 100);
	myShop2.printValue();

	system("pause");
}