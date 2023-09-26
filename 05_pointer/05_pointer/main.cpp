#include <stdio.h>
#include <iostream>

using namespace std;

// �� ������ ���� ���� �� �ش� ���� ������ ����.
int buyItem(int deposit, int price) {
	return deposit - price;
}

// ���� ������ ���� ���� �޸� ������ ������ ���� ����.
void buyItemP(int& deposit, int price) {
	deposit -= price;
}

// �ϳ��� ���� �ο��ϸ� �������� �ڵ����� ���ʴ�� ��.
enum ePhoneType {
	iPhone = 0, zFlip, zFold, galaxyS23
};

struct phoneShop {
	int iPhoneCnt, zFlipCnt, zFoldCnt, gal23Cnt;

	phoneShop(): iPhoneCnt(100), zFlipCnt(100), zFoldCnt(100), gal23Cnt(100) { }

	void buyiPhone(phoneShop* pps) {
		pps->iPhoneCnt--;	// �����͸� �����ϴ� ����ü�� ������ '->'�� �����Ѵ�.	
	}

	void buyZFlip(phoneShop* pps) {
		pps->zFlipCnt--;	// �����͸� �����ϴ� ����ü�� ������ '->'�� �����Ѵ�.	
	}

	void buyZFold(phoneShop* pps) {
		pps->zFoldCnt--;	// �����͸� �����ϴ� ����ü�� ������ '->'�� �����Ѵ�.	
	}

	void buyGal23(phoneShop* pps) {
		pps->gal23Cnt--;	// �����͸� �����ϴ� ����ü�� ������ '->'�� �����Ѵ�.	
	}

	void printStock() {
		printf("%d %d %d %d\n", iPhoneCnt, zFlipCnt, zFoldCnt, gal23Cnt);
	}

	// enum�� �ʿ伺
	void buyPhone(int phoneType, phoneShop* pps) {
		switch (phoneType) {
		case 0:	// ������
			pps->iPhoneCnt--;
			break;
		case 1:	// �ø�
			pps->zFlipCnt--;
			break;
		case 2:	// ����
			pps->zFoldCnt--;
			break;
		case 3:	// ��23
			pps->gal23Cnt--;
			break;
		default:
			break;
		}
	}

	// enum���� �ٲٱ�
	void eBuyPhone(ePhoneType phoneType, phoneShop* pps) {
		switch (phoneType) {
		case ePhoneType::iPhone:
			pps->iPhoneCnt--;
			break;
		case ePhoneType::zFlip:
			pps->zFlipCnt--;
			break;
		case ePhoneType::zFold:
			pps->zFoldCnt--;
			break;
		case ePhoneType::galaxyS23:
			pps->gal23Cnt--;
			break;
		default:
			break;
		}
	}
};

void ptrIntro() {
	int a = 0, b = 0;	// 4����Ʈ ����
	// ������ ���� ����(pa�� ���ִ� �ּҿ� int���� ũ�⸸ŭ �����ϰڴ�)
	// ������ �ʱ�ȭ(�ּҰ��� �������)
	int* pa = nullptr;
	// ������ NULL�� �����, ������ �ǹ�, 0�� �ǹ̰� ������ ������ ���� �߻��߾���.
	// �ּҰ��� ����ִٴ� ��Ȯ�� �ǹ̸� ���� nullptr�� ���.
	// �������� ũ��� x86:4����Ʈ, 64x: 8����Ʈ �� ����

	// �ּҰ��� ����� ���� ������ ����, ���� �ٲ� �� �ִ�.
	// * : ���۷��� ����(�ּҰ� ����Ű�� �ִ� ���� �����Ѵ�.)
	// & : �ּ� �� �ҷ��� 
	pa = &a;	// a�� �ּҰ��� pa�� �־��ְڴٴ� �ǹ�.
	b = *pa;	// b�� pa�� ����Ű�� �ִ� �ּҿ� ���� �ִ´�.
	*pa = 10;	// pa�� ����Ű�� �ִ� �ּ��� ���� 10���� ����.

	printf("*pa:%d, a:%d, b:%d\n", *pa, a, b);

	// �����͸� ����ϴ� ���� : �޸��� ȿ������ ���� �� ������ ������ ��.

}

void ptr01() {
	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1;   // pNum�� num1�� �ּҸ� �ִ´�, pNum�� num1�� ����Ű�� ����
	printf("*pNum: %d", *pNum);	// 0
	*pNum = 20;		// pNum�� ����Ű�� �ִ� num1�� 20�� �ִ´�.
	printf("*pNum: %d", *pNum);	// 20
	pNum = &num2;   // pNum�� num2�� �ּҸ� �ִ´�, pNum�� num2�� ����Ű�� ����
	printf("*pNum: %d", *pNum);	// 0
	*pNum = 30;		// pNum�� ����Ű�� �ִ� num2�� 30�� �ִ´�. 
	printf("*pNum: %d", *pNum);	// 30

	// 20 30
	printf("%d %d", num1, num2);
}

void ptr02() {
	int deposit = 10000;
	// �� ����
	deposit = buyItem(deposit, 1000);	// 9000
	printf("Remain : %d\n", deposit);

	// ���� ����
	buyItemP(deposit, 1000);			// 8000
	printf("Remain : %d\n", deposit);
}

void ptr03() {
	phoneShop ps;
	ps.buyiPhone(&ps);	// ������ �ϳ� ����
	ps.printStock();	// 99 100 100 100
}

void ptr04() {
	int num = 0;
	phoneShop ps;
	printf("Which phone do you want to buy?\n(iPhone:0, zFilp:1, zFold:2, galzxyS23:3): ");
	scanf_s("%d", &num);
	ps.buyPhone(num, &ps);	// �� �ϳ� ����(������ ���x)
	ps.printStock();		

	printf("--------------------\nBought iPhone by enum!\n");
	ps.eBuyPhone(ePhoneType::iPhone, &ps);	// ���� ������!
	ps.printStock();
}

// �迭�� ������
void ptr05() {
	int arrInt[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int* pInt = nullptr;
	pInt = arrInt;	// �迭�� ù��° �ε����� ����Ų��.
	printf("pInt: %d\n", *pInt);	// 0

	pInt += 1;		// ���� �迭 �������� �ּҷ� ����.
	printf("pInt: %d\n", *pInt);	// 10
	printf("--------------------\n");

	// short�� 2����Ʈ
	short arrSht[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	pInt = (int*)arrSht;			// 0
	pInt += 1;	// int�� 4����Ʈ�̹Ƿ� short������ �ٴ��� �迭 �ε����� ����Ŵ
	short* pSht = (short*)pInt;
	printf("pSht: %d\n", *pSht);	// 0 -> 20

	pSht += 1;
	printf("pSht: %d\n", *pSht);	// 20 -> 30
}

void selectionSort(int arr[], int n) {
	int minIdx;
	for (int i = 0; i < n - 1; i++) {
		minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		// ���� ���� ���� ù��° ���Ҹ� ��ü
		if (minIdx != i) {
			swap(arr[minIdx], arr[i]);
		}
	}
}

void bubbleSort(int arr[], int n) {
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		// �� ���� ���ҵ��� ���� ��ü�Ǿ��ٸ�
		// ���� �ݺ��� ����
		if (swapped == false) break;
	}
}

void ptr06() {
	// �Ʒ� �迭�� ���� ���� ������� ���
	int arrInt[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 };
	int n = sizeof(arrInt) / sizeof(*arrInt);

	selectionSort(arrInt, n);
	// bubbleSort(arrInt, n);
	for (int value : arrInt) {
		printf("%d\t", value);
	}printf("\n");
}

int main() {
	// ptrIntro();
	// ptr01();
	// ptr02();
	// ptr03();
	// ptr04();
	// ptr05();
	ptr06();

	system("pause");
}