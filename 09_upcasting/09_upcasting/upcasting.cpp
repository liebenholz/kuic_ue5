#include <stdio.h>
#include <iostream>

void drawLine() {
	printf("------------------------------------\n");
}

// ���: ���� Ŭ������ ����� �߰��ϰų� �������� ���ο� Ŭ������ ����
// ����: �⺻ �ֻ��� Ŭ����
// ����: ���� + �����δ�, ������ ����� ��ӹ���
// ������: ���� + ������, ������ ����� ��ӹ���
// ���: ������ + �����ɷ�, �������� ����� ��ӹ���

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

class CChild : public CBase { // : ��ӹ��� Ŭ����
public:
	// ":" �ڿ� �θ�Ŭ������ �־� �θ�Ŭ������ �����ڸ� ȣ��
	// �θ�Ŭ���� ������ �� ȣ��, ���� �ڽ�Ŭ���� ������
	CChild(int x = 1, int y = 2, int z = 3) : m_Z(z), CBase(x,y) {
		printf("Child Class Generated!\n"); 
	}

	// �ڽ�Ŭ���� �ı��� �� ȣ��, ���� �θ�Ŭ���� �ı���
	~CChild() { printf("Child Class Destroyed!\n"); }

	// �����Լ� : �ڽ� Ŭ�������� �������� ������ ����ϴ� ��� �Լ�
	/*
	virtual void printValue() override {
		CBase::printValue();	// �θ��� ó���� �״�� ����
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
	base.m_X = 200;	// ��ӹ��� �θ��� ����� �״�� ��� ����
	// child.printValue();
	drawLine();
}

// Upcasting : �ڽĿ��� �θ�� ����ȯ�� ���� 
// ���ٸ� ������ ���� �ڵ����� ����ȯ�� �̷����
void printObject(CBase** pBase, int n) {
	for (int i = 0; i < n; i++) {
		printf("xpos : %d, ypos : %d\n", pBase[i]->m_X, pBase[i]->m_Y);
	}
}

/*
void upcast01() {
	CChild* pArrChild = new CChild[10];
	printObject(pArrChild, 10);	// ��ĳ����
	delete[] pArrChild;
}
*/

// ���� STL ���.. �׳� �� ���°���
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

