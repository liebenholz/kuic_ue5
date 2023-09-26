#include <stdio.h>
#include <iostream>
#include "bank.h"
#include "calcFunc.h"
#include "overloading.h"

static int s_balance; // 정적변수. 데이터영역에 존재

struct grocery { 
	int appleCost;
	int mangoCost;
	int bananaCost;

	// 구조체 생성자 ":"이 구문 오른쪽에 변수의 초기값을 설정한다.
	grocery(): appleCost(1000), mangoCost(1000), bananaCost(1000) { }

	void setFruitValue(int apple, int mango, int banana) {
		appleCost = apple;
		mangoCost = mango;
		bananaCost = banana;
	}

	void printFruitValue() {
		printf("apple: %d, mango: %d, banana: %d\n", appleCost, mangoCost, bananaCost);
	}
};

struct phoneShop {
	int iPhoneCost;
	int zFlipCost;
	int zFoldCost;
	int gal23Cost;

	// 구조체 생성자 ":"이 구문 오른쪽에 변수의 초기값을 설정한다.
	phoneShop() : iPhoneCost(999), zFlipCost(899), zFoldCost(1299), gal23Cost(799) { }

	void setPriceValue(int iphone, int zFlip, int zFold, int gal23) {
		iPhoneCost = iphone;
		zFlipCost = zFlip;
		zFoldCost = zFold;
		gal23Cost = gal23;
	}

	void printPriceValue() {
		printf("iPhone: %d, zFlip: %d, zFold: %d, gal23: %d\n", iPhoneCost, zFlipCost, zFoldCost, gal23Cost);
	}
};

void bankAccount() {
	int t_balance = 1000;	// 코드영역에 존재
	myBalance(t_balance);
	deposit(2000, t_balance);
	withdraw(1000, t_balance);
	withdraw(5000, t_balance);
	myBalance(t_balance);
}

void calculator() {
	bool bRun = true;
	while (bRun) {
		typeNums();
		chooseCalc();
		bRun = isContinue(bRun);
		drawLine();
	}
}

void overload() {
	printf("result = %d\n", add(3, 2));
	printf("result = %.1f\n", addF(3.0f, 2.4f));
	printf("result = %.1f\n", add(3.0, 2.4));
}

void array01() {
	// int arrInt[10] = { 0 };		// 배열 생성 및 전부 0으로 초기화
	// int arrInt[10] = { 0, };		// 배열 생성 및 전부 0으로 초기화

	// 배열 안에 변수값을 설정해주는 역할
	int arrInt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	// 배열 생성 및 배열의 초기값 설정
	arrInt[0] = 10;		// 0번 칸에 값 넣기
	arrInt[4] = 40;		// 4번 칸에 값 넣기
	arrInt[9] = 90;		// 9번 칸에 값 넣기
	// arrInt[10] = 100;	// 에러
	// arrInt2[10][10];	// 2차원 배열

	// 배열 안에 변수 값을 출력해주는 역할
	// for 사용
	for (int i = 0; i < sizeof(arrInt)/sizeof(*arrInt); i++) {
		printf("%d: %d\t", i, arrInt[i]);
	}
	printf("\n");

	// for each 사용
	int num = 0;
	for (int value : arrInt) {
		printf("%d: %d\t", num, value);
		num++;
	}
	printf("\n");
}

void structure01() {
	// grocery라는 변수형 사용, shop: 변수이름
	grocery shopA;
	shopA.appleCost = 2000;
	shopA.bananaCost = 1500;
	shopA.mangoCost = 4000;

	grocery shop[3];

	shop[0].setFruitValue(1500, 2000, 3500);
	shop[1].setFruitValue(2000, 2000, 4500);
	shop[2].setFruitValue(2000, 1500, 3500);

	for (grocery price : shop) {
		price.printFruitValue();
	}
}

void structure02() {
	phoneShop shop[3];

	shop[0].setPriceValue(899, 759, 1199, 699);
	shop[1].setPriceValue(949, 729, 1239, 709);
	shop[2].setPriceValue(999, 699, 1199, 729);

	for (phoneShop price : shop) {
		price.printPriceValue();
	}
}

int main() {
	// bankAccount();
	// calculator();
	// overload();

	// 배열
	// array01();

	// 구조체
	// structure01();
	structure02();

	system("pause");
}

