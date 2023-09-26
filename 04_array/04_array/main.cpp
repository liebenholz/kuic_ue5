#include <stdio.h>
#include <iostream>
#include "bank.h"
#include "calcFunc.h"
#include "overloading.h"

static int s_balance; // ��������. �����Ϳ����� ����

struct grocery { 
	int appleCost;
	int mangoCost;
	int bananaCost;

	// ����ü ������ ":"�� ���� �����ʿ� ������ �ʱⰪ�� �����Ѵ�.
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

	// ����ü ������ ":"�� ���� �����ʿ� ������ �ʱⰪ�� �����Ѵ�.
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
	int t_balance = 1000;	// �ڵ念���� ����
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
	// int arrInt[10] = { 0 };		// �迭 ���� �� ���� 0���� �ʱ�ȭ
	// int arrInt[10] = { 0, };		// �迭 ���� �� ���� 0���� �ʱ�ȭ

	// �迭 �ȿ� �������� �������ִ� ����
	int arrInt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	// �迭 ���� �� �迭�� �ʱⰪ ����
	arrInt[0] = 10;		// 0�� ĭ�� �� �ֱ�
	arrInt[4] = 40;		// 4�� ĭ�� �� �ֱ�
	arrInt[9] = 90;		// 9�� ĭ�� �� �ֱ�
	// arrInt[10] = 100;	// ����
	// arrInt2[10][10];	// 2���� �迭

	// �迭 �ȿ� ���� ���� ������ִ� ����
	// for ���
	for (int i = 0; i < sizeof(arrInt)/sizeof(*arrInt); i++) {
		printf("%d: %d\t", i, arrInt[i]);
	}
	printf("\n");

	// for each ���
	int num = 0;
	for (int value : arrInt) {
		printf("%d: %d\t", num, value);
		num++;
	}
	printf("\n");
}

void structure01() {
	// grocery��� ������ ���, shop: �����̸�
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

	// �迭
	// array01();

	// ����ü
	// structure01();
	structure02();

	system("pause");
}

