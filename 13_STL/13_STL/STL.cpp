#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

class CShop {
public:
	int isOpen = false;
};

void drawLine() {
	printf("-----------------\n");
}

void vector01() {
	// std::vector<int> : int�� vector �迭
	// vecint : vector �迭 �̸�
	// { 0, 1, 2, 3, 4 } : vecint �ʱⰪ �ֱ�
	std::vector<int> vecint{ 0, 1, 2, 3, 4 };

	// vecint.size() : ���͹迭�� ���� ����
	// [] : ��Ȯ�� ��ġ�� �־� ���� ����
	for (int i = 0; i < vecint.size(); i++) {
		printf("vecint[%d] : %d\n", i, vecint[i]);
	} drawLine();

	// �� ���޷� ���� �����ϸ� ���� ������ �� ���� �� ��
	for (int value : vecint) {
		value = 1;
		printf("value : %d\n", value);
	} drawLine();

	for (int value : vecint) {
		printf("value : %d\n", value);
	} drawLine();

	// �������޷� ���� �����ϸ� ���� ������ �� ����
	for (int& value : vecint) {
		value = 2;
		printf("value : %d\n", value);
	} drawLine();

	// �������� �� const�� �����ϸ� ������ �� ���� �Ұ�
	for (const int& value : vecint) {
		// value = 0;
		printf("value : %d\n", value);
	} drawLine();
}

void vector02() {
	std::vector<int> vecint{ 0, 1, 2, 3, 4 };
	int* pData = vecint.data();		// ���� �迭 ���� ������ �޸� ������ �ּ�(������) ��ȯ
	int vCap = vecint.capacity();	// ������ ũ�� ���鿡���� ���� ���� ũ�� ��ȯ
	printf("vecint capacity: %d\n", vCap);
}

void vector03() {
	std::vector<int> vecInt{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int>::iterator vecIter = vecInt.begin();
	printf("vecIter: %d\n", *vecIter);	// ù �� 0

	vecIter++;	// ���� �迭�� ���Ҹ� ����Ű�ڴ�
	printf("vecIter: %d\n", *vecIter);	// �ϳ� ������ 1

	vecIter--;	// ���� �迭�� ���Ҹ� ����Ű�ڴ�
	printf("vecIter: %d\n", *vecIter);	// �ٽ� 0
	drawLine();

	// vecIter = vecInt.end();	// �迭�� ���� �ǹ�, ������ ���� �ƴ�

	vecInt.push_back(100);	// �迭�� top�� ���� �߰�
	printf("for iter: \n");
	for (std::vector<int>::iterator iter = vecInt.begin(); iter != vecInt.end(); iter++) {
		printf("%d\t", *iter);
	} printf("\n");
	printf("vecint size: %d\n", (int)vecInt.size());
	drawLine();

	vecInt.pop_back();	// �迭�� top���� ���� ����
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
			vecIter = vecInt.erase(vecIter);	// vecIter�� ����Ű�� �ִ� �迭 ��Ҹ� ����.
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
	// std::list<int> : int�� list
	// listInt : ������ list �̸�
	// { 0, 2, 4, 6, 8 } : listInt �ʱⰪ �ֱ�
	std::list<int> listInt{ 0, 2, 4, 6, 8 };

	// for�� �� ������ for each�� ��� ����
	for (int value : listInt) {
		printf("value : %d\n", value);
	} drawLine();

	// �������޷� ���� �����ϸ� ���� ������ �� ����
	for (int& value : listInt) {
		value = 3;
		printf("value : %d\n", value);
	} drawLine();

	// �������� �� const�� �����ϸ� ������ �� ���� �Ұ�
	for (int& value : listInt) {
		// value = 4;
		printf("value : %d\n", value);
	} drawLine();
}

void list02() {
	std::list<int> listInt{ 0, 2, 4, 6, 8 };
	std::list<int>::iterator listIter = listInt.begin();
	printf("listIter: %d\n", *listIter);	// ù �� 0
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

	// �յڷ� �߰� ����
	listInt.push_back(100);
	listInt.push_front(200);
	for (std::list<int>::iterator iter = listInt.begin(); iter != listInt.end(); iter++) {
		printf("%d\t", *iter);
	} printf("\n");
	printf("listInt size: %I64d\n", listInt.size());
	drawLine();

	// �յڷ� ���� ����
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

	// ����Ʈ���� Ư�� ���� ã��, �� ����Ʈ���� 2 ã��
	std::list<int>::iterator it = std::find(listInt.begin(), listInt.end(), 2);
	if (it != listInt.end()) {
		printf("Elemnet %d Found!\n", *it);	// ã�Ҵ�
	}
	else {
		printf("Element Not Found!\n");	// �� ã�Ҵ�
	}

	// ����Ʈ���� Ư�� ���� ã��, �� ����Ʈ���� 5 ã��(����)
	it = std::find(listInt.begin(), listInt.end(), 5);
	if (it != listInt.end()) {
		printf("Elemnet %d Found!\n", *it);	// ã�Ҵ�
	}
	else {
		printf("Element 5 Not Found!\n");	// �� ã�Ҵ�
	}

}

int main() {
	// STL(ǥ�� ���ø� ���̺귯��) : �������� ���� �������� �迭
	// �迭 �����ϸ鼭 ó������ ������ �������� �ʰ� �ʿ��� ������ �ø��� ���� �� �ִ� �迭

	/*
	* ����(vector) : ����(stack) ����; ���Լ���
	* �������� �޸𸮸� Ȯ��, �ڽ��� ��Ҹ� ������ ���� �迭(dynamic array)�� ����
	* ���� ���� ������ '[]'�� �����ϱ⿡ ��� ���� �����ϵ� ����ð�(������ �ð�)�� �ҿ��; �б� �ӵ� �ſ� ����
	* �����迭�̱� ������ �迭�� �߰��� ���� �߰� �� �����ϸ� ���� ���� �̵��ؾ���; ����� ŭ
	* �߰��� �߰��ϴ� ���� ������尡 ũ�� ������ ���� �ڿ� �߰�(push_back)
	* ũ���� Ȯ�� ��Ұ� ���������� ���Ҵ� ����� ŭ
	*/
	// vector01();
	// vector02();
	// vector03();

	/* 
	* ����Ʈ(list) : ���ҵ��� ����� ���� ����Ʈ�� ���·� ����(Doubly Linked List)
	* ����Ʈ ��ü�� ��Ŀ��� �Ҹ��� ������ �� ���� ����(head, tail), �̵��� ���� �߰����� �޸𸮸� �Ҹ���
	* ���ο� ��Ҹ� �����ϱ� ���ؼ��� �� ������(��Ŀ)�� ������
	* ���Ϳ� �ٸ���, ���� ���� ������ '[]' �������� ����(n��° ��ҿ� �����ϱ� ���ؼ��� ������ ���İ��� ��)
	* ���������� �Ұ����ϱ� �빮�� ���� Ž���� ��ġ�� ã�ƾ� ��
	* Ư�� ��ġ�� �߰�/���� �����ο� (Ư�� ��ġ ã�� �ð��� �ƴ�)
	* ���Ҵ� ������ ����, �������� �޸𸮰� �ƴϱ� ������ �޸� �ѵ� ������ ������ �߰� ����
	*/
	// list01();
	// list02();
	// list03();
	list04();



	system("pause");
}