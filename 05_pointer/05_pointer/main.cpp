#include <stdio.h>
#include <iostream>

using namespace std;

// 값 전달을 통해 연산 후 해당 값을 변수에 갱신.
int buyItem(int deposit, int price) {
	return deposit - price;
}

// 참조 전달을 통해 직접 메모리 영역에 접근해 값을 변경.
void buyItemP(int& deposit, int price) {
	deposit -= price;
}

// 하나에 값을 부여하면 나머지는 자동으로 차례대로 들어감.
enum ePhoneType {
	iPhone = 0, zFlip, zFold, galaxyS23
};

struct phoneShop {
	int iPhoneCnt, zFlipCnt, zFoldCnt, gal23Cnt;

	phoneShop(): iPhoneCnt(100), zFlipCnt(100), zFoldCnt(100), gal23Cnt(100) { }

	void buyiPhone(phoneShop* pps) {
		pps->iPhoneCnt--;	// 포인터를 참조하는 구조체에 변수는 '->'로 참조한다.	
	}

	void buyZFlip(phoneShop* pps) {
		pps->zFlipCnt--;	// 포인터를 참조하는 구조체에 변수는 '->'로 참조한다.	
	}

	void buyZFold(phoneShop* pps) {
		pps->zFoldCnt--;	// 포인터를 참조하는 구조체에 변수는 '->'로 참조한다.	
	}

	void buyGal23(phoneShop* pps) {
		pps->gal23Cnt--;	// 포인터를 참조하는 구조체에 변수는 '->'로 참조한다.	
	}

	void printStock() {
		printf("%d %d %d %d\n", iPhoneCnt, zFlipCnt, zFoldCnt, gal23Cnt);
	}

	// enum의 필요성
	void buyPhone(int phoneType, phoneShop* pps) {
		switch (phoneType) {
		case 0:	// 아이폰
			pps->iPhoneCnt--;
			break;
		case 1:	// 플립
			pps->zFlipCnt--;
			break;
		case 2:	// 폴드
			pps->zFoldCnt--;
			break;
		case 3:	// 갤23
			pps->gal23Cnt--;
			break;
		default:
			break;
		}
	}

	// enum으로 바꾸기
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
	int a = 0, b = 0;	// 4바이트 정수
	// 포인터 변수 선언(pa가 들어가있는 주소에 int형의 크기만큼 참조하겠다)
	// 포인터 초기화(주소값이 비어있음)
	int* pa = nullptr;
	// 이전엔 NULL을 사용함, 없다의 의미, 0과 의미가 동일해 문제가 많이 발생했었음.
	// 주소값이 비어있다는 명확한 의미를 가진 nullptr을 사용.
	// 포인터의 크기는 x86:4바이트, 64x: 8바이트 로 고정

	// 주소값을 사용해 참조 전달이 가능, 값이 바꿀 수 있다.
	// * : 레퍼런스 참조(주소가 가리키고 있는 값을 참조한다.)
	// & : 주소 값 불러옴 
	pa = &a;	// a의 주소값을 pa에 넣어주겠다는 의미.
	b = *pa;	// b에 pa가 가리키고 있는 주소에 값을 넣는다.
	*pa = 10;	// pa가 가리키고 있는 주소의 값을 10으로 변경.

	printf("*pa:%d, a:%d, b:%d\n", *pa, a, b);

	// 포인터를 사용하는 이유 : 메모리의 효율적인 관리 및 데이터 참조가 편리.

}

void ptr01() {
	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1;   // pNum에 num1의 주소를 넣는다, pNum은 num1을 가리키고 있음
	printf("*pNum: %d", *pNum);	// 0
	*pNum = 20;		// pNum이 가리키고 있는 num1에 20을 넣는다.
	printf("*pNum: %d", *pNum);	// 20
	pNum = &num2;   // pNum에 num2의 주소를 넣는다, pNum은 num2을 가리키고 있음
	printf("*pNum: %d", *pNum);	// 0
	*pNum = 30;		// pNum이 가리키고 있는 num2에 30을 넣는다. 
	printf("*pNum: %d", *pNum);	// 30

	// 20 30
	printf("%d %d", num1, num2);
}

void ptr02() {
	int deposit = 10000;
	// 값 전달
	deposit = buyItem(deposit, 1000);	// 9000
	printf("Remain : %d\n", deposit);

	// 참조 전달
	buyItemP(deposit, 1000);			// 8000
	printf("Remain : %d\n", deposit);
}

void ptr03() {
	phoneShop ps;
	ps.buyiPhone(&ps);	// 아이폰 하나 구매
	ps.printStock();	// 99 100 100 100
}

void ptr04() {
	int num = 0;
	phoneShop ps;
	printf("Which phone do you want to buy?\n(iPhone:0, zFilp:1, zFold:2, galzxyS23:3): ");
	scanf_s("%d", &num);
	ps.buyPhone(num, &ps);	// 폰 하나 구매(열거형 사용x)
	ps.printStock();		

	printf("--------------------\nBought iPhone by enum!\n");
	ps.eBuyPhone(ePhoneType::iPhone, &ps);	// 보다 직관적!
	ps.printStock();
}

// 배열과 포인터
void ptr05() {
	int arrInt[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int* pInt = nullptr;
	pInt = arrInt;	// 배열의 첫번째 인덱스를 가리킨다.
	printf("pInt: %d\n", *pInt);	// 0

	pInt += 1;		// 다음 배열 포인터의 주소로 변경.
	printf("pInt: %d\n", *pInt);	// 10
	printf("--------------------\n");

	// short는 2바이트
	short arrSht[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	pInt = (int*)arrSht;			// 0
	pInt += 1;	// int는 4바이트이므로 short에서는 다다음 배열 인덱스를 가리킴
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
		// 가장 작은 값과 첫번째 원소를 교체
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
		// 두 개의 원소들이 서로 교체되었다면
		// 내부 반복문 진행
		if (swapped == false) break;
	}
}

void ptr06() {
	// 아래 배열을 낮은 숫자 순서대로 출력
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