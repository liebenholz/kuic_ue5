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

// Ŭ���� �̸� : CShop
class cShop {
public:
	// �ɹ� ���� : m_value(�⺻��:0)
	cShop():m_value(0) {}

	~cShop() {}

	// ��� �Լ� �߰� : printValue
	// printValue �Լ� ��� : "Value=%d"�� m_value ���
	void printValue() {
		printf("value : %d\n", m_value);
	}

	int m_value;
};

// Ŭ���� �̸� : CPhoneShop
// �θ� Ŭ���� : CShop
class cPhoneShop : public cShop {
public:
	// ������ �Ķ��Ÿ : int PhoneCnt (m_PhoneCnt�� �� ����), int PhonePrice (m_PhonePrice�� �� ����)
	cPhoneShop(int phoneCnt, int phonePrice) : m_PhoneCnt(phoneCnt), m_PhonePrice(phonePrice) { }

	~cPhoneShop() {}

	// printValue �Լ� ��� : "Value=%d"�� m_PhoneCnt * m_PhonePrice���
	void printValue() {
		printf("value : %d\n", m_PhoneCnt * m_PhonePrice);
	}

	int m_PhoneCnt;		// ��� ���� : m_PhoneCnt
	int m_PhonePrice;	// ��� ���� : m_PhonePrice

};

// Ŭ���� �̸� : CFruitShop
// �θ� Ŭ���� : CShop
class cFruitShop : public cShop {
public:
	// ������ �Ķ��Ÿ : int FruitCnt (m_FruitCnt�� �� ����), int FruitPrice (m_FruitPrice�� �� ����)
	cFruitShop(int fruitCnt, int fruitPrice) : m_FruitCnt(fruitCnt), m_FruitPrice(fruitPrice) { }

	~cFruitShop() {}

	// printValue �Լ� ��� : "Value=%d"�� m_PhoneCnt * m_PhonePrice���
	void printValue() {
		printf("value : %d\n", m_FruitCnt * m_FruitPrice);
	}

	int m_FruitCnt;		// ��� ���� : m_FruitCnt
	int m_FruitPrice;	// ��� ���� : m_FruitPrice
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

	// CPhoneShop(10, 100) ���� �� ��ü�� printValue ���
	cPhoneShop myShop1(10, 100);
	myShop1.printValue();

	// CFruitShop(10, 100) ���� �� ��ü�� printValue ���
	cFruitShop myShop2(10, 100);
	myShop2.printValue();

	system("pause");
}