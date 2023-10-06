#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

struct stMonster {
	int index = 0;	// 몬스터 타입
};

// mon.index가 3이면 true, 아니면 false.
bool isFindMonIndex(const stMonster& mon) {
	return mon.index == 3;
}

class CShop {
public:
	int isOpen = false;
};

void drawLine() {
	printf("-----------------\n");
}

void vector01() {
	// std::vector<int> : int형 vector 배열
	// vecint : vector 배열 이름
	// { 0, 1, 2, 3, 4 } : vecint 초기값 넣기
	std::vector<int> vecint{ 0, 1, 2, 3, 4 };

	// vecint.size() : 벡터배열의 원소 갯수
	// [] : 명확한 위치를 넣어 접근 가능
	for (int i = 0; i < vecint.size(); i++) {
		printf("vecint[%d] : %d\n", i, vecint[i]);
	} drawLine();

	// 값 전달로 값을 변경하면 원본 데이터 값 수정 안 됨
	for (int value : vecint) {
		value = 1;
		printf("value : %d\n", value);
	} drawLine();

	for (int value : vecint) {
		printf("value : %d\n", value);
	} drawLine();

	// 참조전달로 값을 변경하면 원본 데이터 값 변경
	for (int& value : vecint) {
		value = 2;
		printf("value : %d\n", value);
	} drawLine();

	// 참조전달 시 const로 참조하면 데이터 값 변경 불가
	for (const int& value : vecint) {
		// value = 0;
		printf("value : %d\n", value);
	} drawLine();
}

void vector02() {
	std::vector<int> vecint{ 0, 1, 2, 3, 4 };
	int* pData = vecint.data();		// 벡터 배열 실제 데이터 메모리 공간의 주소(포인터) 반환
	int vCap = vecint.capacity();	// 데이터 크기 측면에서의 저장 공간 크리 반환
	printf("vecint capacity: %d\n", vCap);
}

void vector03() {
	std::vector<int> vecInt{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int>::iterator vecIter = vecInt.begin();
	printf("vecIter: %d\n", *vecIter);	// 첫 값 0

	vecIter++;	// 다음 배열의 원소를 가리키겠다
	printf("vecIter: %d\n", *vecIter);	// 하나 증가한 1

	vecIter--;	// 이전 배열의 원소를 가리키겠다
	printf("vecIter: %d\n", *vecIter);	// 다시 0
	drawLine();

	// vecIter = vecInt.end();	// 배열의 끝을 의미, 마지막 원소 아님

	vecInt.push_back(100);	// 배열에 top에 원소 추가
	printf("for iter: \n");
	for (std::vector<int>::iterator iter = vecInt.begin(); iter != vecInt.end(); iter++) {
		printf("%d\t", *iter);
	} printf("\n");
	printf("vecint size: %d\n", (int)vecInt.size());
	drawLine();

	vecInt.pop_back();	// 배열의 top에서 원소 제거
	printf("while iter: \n");
	vecIter = vecInt.begin();
	while (vecIter != vecInt.end()) {
		printf("%d\t", *vecIter);
		vecIter++;
	} printf("\n");
	printf("vecint size: %d\n", (int)vecInt.size());
	drawLine();

	vecIter = vecInt.begin();
	while (vecIter != vecInt.end()) {
		if (*vecIter == 5) {
			vecIter = vecInt.erase(vecIter);	// vecIter가 가리키고 있는 배열 요소를 제거.
			printf("iter 5 erased.\n");
		}
		else vecIter++;
	}

	vecIter = vecInt.begin();
	while (vecIter != vecInt.end()) {
		printf("%d\t", *vecIter);
		vecIter++;
	} printf("\n");
	printf("vecint size: %d\n", (int)vecInt.size());

}

void list01() {
	// std::list<int> : int형 list
	// listInt : 생성할 list 이름
	// { 0, 2, 4, 6, 8 } : listInt 초기값 넣기
	std::list<int> listInt{ 0, 2, 4, 6, 8 };

	// for는 안 되지만 for each는 사용 가능
	for (int value : listInt) {
		printf("value : %d\n", value);
	} drawLine();

	// 참조전달로 값을 변경하면 원본 데이터 값 변경
	for (int& value : listInt) {
		value = 3;
		printf("value : %d\n", value);
	} drawLine();

	// 참조전달 시 const로 참조하면 데이터 값 변경 불가
	for (int& value : listInt) {
		// value = 4;
		printf("value : %d\n", value);
	} drawLine();
}

void list02() {
	std::list<int> listInt{ 0, 2, 4, 6, 8 };
	std::list<int>::iterator listIter = listInt.begin();
	printf("listIter: %d\n", *listIter);	// 첫 값 0
	drawLine();

	printf("for listInt value: \n");
	for (std::list<int>::iterator iter = listInt.begin(); iter != listInt.end(); iter++) {
		printf("%d\t", *iter);
	} printf("\n");
	printf("listInt size: %d\n", (int)listInt.size());
	drawLine();

	printf("while iter: \n");
	listIter = listInt.begin();
	while (listIter != listInt.end()) {
		printf("%d\t", *listIter);
		listIter++;
	} printf("\n");
	printf("listInt size: %d\n", (int)listInt.size());
	drawLine();
}

void list03() {
	std::list<int> listInt{ 0, 2, 4, 6, 8 };

	// 앞뒤로 추가 가능
	listInt.push_back(100);
	listInt.push_front(200);
	for (std::list<int>::iterator iter = listInt.begin(); iter != listInt.end(); iter++) {
		printf("%d\t", *iter);
	} printf("\n");
	printf("listInt size: %I64d\n", listInt.size());
	drawLine();

	// 앞뒤로 제거 가능
	listInt.pop_back();
	listInt.pop_front();
	for (std::list<int>::iterator iter = listInt.begin(); iter != listInt.end(); iter++) {
		printf("%d\t", *iter);
	} printf("\n");
	printf("listInt size: %I64d\n", listInt.size());
	drawLine();

}

void list04() {
	std::list<int> listInt{ 0, 2, 4, 6, 8 };

	// 리스트에서 특정 원소 찾기, 위 리스트에서 2 찾기
	std::list<int>::iterator it = std::find(listInt.begin(), listInt.end(), 2);
	if (it != listInt.end()) {
		printf("Elemnet %d Found!\n", *it);	// 찾았다
	}
	else {
		printf("Element Not Found!\n");	// 못 찾았다
	}

	// 리스트에서 특정 원소 찾기, 위 리스트에서 5 찾기(없음)
	it = std::find(listInt.begin(), listInt.end(), 5);
	if (it != listInt.end()) {
		printf("Elemnet %d Found!\n", *it);	// 찾았다
	}
	else {
		printf("Element 5 Not Found!\n");	// 못 찾았다
	}
}

void list05() {
	std::list<int> listInt{ 98, 6, 9, 30, 1, 0 };

	// 리스트에서 특정 원소 제거
	std::list<int>::iterator it = std::find(listInt.begin(), listInt.end(), 1);
	if (it != listInt.end()) {
		printf("Elemnet %d Found!\n", *it);	// 찾았다

		// 리스트에서 특정 원소 제거
		listInt.erase(it);	

		int value = 91;
		// 특정요소 앞에 새로운 요소 끼워넣기
		listInt.insert(it, value);	
		listInt.emplace(it, value);

	}
	else {
		printf("Element Not Found!\n");	// 못 찾았다
	}
}

void list06() {
	std::list<stMonster> arrMon;

	for (int i = 0; i < 5; i++) {
		stMonster temp;
		temp.index = i;
		arrMon.push_back(temp);
	}

	std::list<stMonster>::iterator monIter;
	// monIter = std::find_if(arrMon.begin(), arrMon.end(), isFindMonIndex);
	monIter = std::find_if(arrMon.begin(), arrMon.end(), [](const stMonster& mon) { return mon.index == 3; });

	if (monIter != arrMon.end()) {
		printf("Monster %d Found!\n", monIter->index);
	}
	else {
		printf("Monster Not Found!\n");
	}

	for (const stMonster& value : arrMon) {
		printf("Monster Index : %d\n", value.index);
	}
}

int main() {
	// STL(표준 템플릿 라이브러리) : 고정되지 않은 유동적인 배열
	// 배열 생성하면서 처음부터 공간을 점유하지 않고 필요할 때마다 늘리고 줄일 수 있는 배열

	/*
	* 벡터(vector) : 스택(stack) 구조; 후입선출
	* 연속적인 메모리를 확보, 자신의 요소를 내부의 동적 배열(dynamic array)에 복사
	* 임의 접근 연산자 '[]'를 제공하기에 어떠한 값에 접근하든 상수시간(고정된 시간)이 소요됨; 읽기 속도 매우 빠름
	* 동적배열이기 때문에 배열의 중간에 새로 추가 및 삭제하면 많은 값을 이동해야함; 비용이 큼
	* 중간에 추가하는 것이 오버헤드가 크기 때문에 보통 뒤에 추가(push_back)
	* 크기의 확정 축소가 자유롭지만 재할당 비용이 큼
	*/
	// vector01();
	// vector02();
	// vector03();

	/* 
	* 리스트(list) : 원소들을 양방향 연결 리스트으 형태로 관리(Doubly Linked List)
	* 리스트 객체는 앵커라고 불리는 포인터 두 개를 제공(head, tail), 이들을 위한 추가적인 메모리를 소모함
	* 새로운 요소를 삽입하기 위해서는 이 포인터(앵커)를 조작함
	* 벡터와 다르게, 임의 접근 연산자 '[]' 제공하지 않음(n번째 요소에 접근하기 위해서는 노드들을 거쳐가야 함)
	* 임의접근이 불가능하기 대문에 선형 탐색해 위치를 찾아야 함
	* 특정 위치에 추가/삭제 자유로움 (특정 위치 찾는 시간은 아님)
	* 재할당 연산자 없음, 연속적인 메모리가 아니기 때문에 메모리 한도 내에서 무한히 추가 가능
	*/
	// list01();
	// list02();
	// list03();
	// list04();
	// list05();
	list06();

	system("pause");
}