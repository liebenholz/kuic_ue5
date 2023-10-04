#include <stdio.h>
#include <iostream>
#include "myClass.h"

// ����, �ڷ���
struct stMyStruct {
	int a; int b; int c;

	// ����ü�� �ʱ�ȭ
	stMyStruct() : a(0), b(0) {
		c = 0;
	}

	void printABC() {
		printf("%d %d %d\n", a, b, c);
	}
};

// ����, �ڷ���
// Class�� ����� ���� type�̶� �Ѵ�. struct�� Ȯ��.
// cpp�� Ŭ������ �� ���� ���� ������(private, protected, public)�� ����
// ������ ����Ǵ� ����� ������ �� �Լ��� �ִ� ����� ���� ����, ������ ������ �����.

// ���� �����ڸ� ����Ͽ� ������ �� �Լ��� ����� ���� ĸ��ȭ(capsulization) ��� �Ѵ�.
// Class�� �����ϸ� '��Ʋ'��, ��밡���� ��ü�� �ƴ�. ��ü�� ����ϱ� ���� ����� ��Ÿ��.
class cMyClass {
	// ���� ���� �����ڰ� ������ �⺻������ private.
	// int a1, a2;

	// ������: Ŭ���� ���� �� ȣ��. �������� �ʾƵ� �⺻ �����ڰ� ����.
	// �ݵ�� �ı��ڴ� public�̾�� �Ѵ�. private�̸� �ܺο��� ȣ�� �Ұ�.
public:	
	cMyClass() : a(0), b(0), c(0) {
		// a1 = value; a2 = value;
	}

	// �����ڵ� �Ķ������ ������ Ÿ�Կ� ���� Overload(Ÿ�Ժ� �������� �Լ� ����) ����
	// (int valA = 0) �������� �Ķ���� �ʱ�ȭ�� ����
	// :a(valA), b(valB), c(0) �������� ������� �ʱ�ȭ�� ����
	// �Ķ���� ������ ���°� �Է� ��Ŀ� ���� ������ �Ұ����ϸ� ������ �߻��Ѵ�.
	cMyClass(int value) : a(value), b(value), c(value) {
		// printf("Class A Generated!\n");
		// a1 = value; a2 = value;
	}

	cMyClass(int valA, int valB) : a(valA), b(valB), c(0) {
		// printf("Class B Generated!\n");
		// a1 = valA; a2 = valB;
	}

	cMyClass(int valA, int valB, int valC) : a(valA), b(valB), c(valC) {
		// printf("Class B Generated!\n");
		// a1 = valA; a2 = valB;
	}

	// �ı���: Ŭ���� �ı� �� ȣ��. �������� �ʾƵ� �⺻ �ı��ڰ� ����.	
	// �ݵ�� �����ڴ� public�̾�� �Ѵ�. private�̸� �ܺο��� ȣ�� �Ұ�.
	~cMyClass() {
		// printf("Class Destroyed!\n");
	}

	/*
	void printAA() {
		printf("%d %d\n", a1, a2);
	}
	*/

	void printABC() {
		printf("%d %d %d\n", a, b, c);
	}

	void setPrivA(int n) {
		// �Ϲ������δ� this Ű����� ����
		// Ŭ���� ���� �Լ��� ȣ���� ��� ��ü�� �ǹ�
		this->a = n;
	}

	// ������ �����ε�(Operator Overloading) 
	// ���Կ�����: ���� �������� �ʾƵ� �ڵ�������
	// const cMyClass& : �������� ��ȯ�� ������
	// operator= �����ε��� ������
	// (const cMyClass& other) : �����ʿ� �Էµ� ����
	// a = b
	const cMyClass& operator=(const cMyClass& other) {
		a = other.a;
		b = other.b;
		c = other.c;
		// a1 = other.a1;
		// a2 = other.a2;

		return *this;
	}

	// myCl3 = myCl + myCl2;
	// myCl3 = cMyClass(a+other.a, b+other.b, c+other.c);

	// a + b
	// cMyClass(a+other.a, b+other.b, c+other.c);
	const cMyClass& operator+(const cMyClass& other) {
		return cMyClass(a+other.a, b+other.b, c+other.c);
	}

private:	// �ܺο��� ���� �Ұ�
	int a;		
protected:  // ��Ӱ����� ��� ���� ����, �̿ܿ��� ���� �Ұ�
	int b;	
public:		// �ܺ� ��𼭵� ���� ����
	int c;		
};

// ��ü(Object)
// Class�� ����ؼ� ������ ��, Class�� ������ �������� �����ǰ�, �޸𸮿��� ������ ����.

// ��ü ���� ���α׷���(Object-Oriented Programming)
// ��ǻ�� ���α׷��� ��ɾ��� ������� ���� �ð����� ��� 
// ���� ���� ������ ����(��ü)�� �������� ������ ����� �з�����
// ������ ��ü�� �޼����� �ְ� �ް�, �����͸� ���������� ó�� ����.

void class01() {
	stMyStruct mySt;
	mySt.a = 0;

	cMyClass myCl(10);	// ������ ȣ���
	myCl.c = 10;

	// Ư�� ������ �����ϱ� ���� �Լ��� �����ؼ� �����ϴ� �� �⺻ ��Ģ
	myCl.setPrivA(2);
	myCl.setPrivA(3);
	myCl.setPrivA(5);
	myCl.setPrivA(8);
	myCl.setPrivA(13);

	// ���� ������ private�� �Ǿ��ִٸ� �����ڰ� ���� �������� ����� �ǵ��� ����.
	// myCl.a = 21;
} // �ı��� ȣ���

void class02() {
	cMyClass myClA(10);
	cMyClass myClB(10, 20);

	myClA.printABC();
	myClB.printABC();
}

// ���� ������(Reference, &)
// �޸� ������ ���� �ʰ� ������ ������ �޸𸮸� ȿ�������� ����ϱ� ���� ������
void ref01() {
	int num = 100;
	stMyStruct stTest;

	// ������ ������ ������ ������ �ּҰ��� �����Ѵ�.
	// ������ ������ �ּҰ� != �����Ͱ� ����Ű�� �ִ� �ּҰ�
	int* pNum = &num;
	stMyStruct* ptest = &stTest;
	ptest->a = 0;
	printf("&pNum == &num ? : %d\n %d\n %d\n", (int(& pNum) == int(&num)), int(&pNum), int(&num));	// false

	// ���� �����ڴ� ���� ����� �ּ� ���� ����.
	int& refNum = num;
	stMyStruct& refTest = stTest;
	refTest.a = 0;
	printf("&refNum == &num ? : %d\n %d\n %d\n", (int(&refNum) == int(&num)), int(&refNum), int(&num));	// true
}

void drawLine() {
	printf("--------------------------\n");
}

int main() {
	// class01();
	// ref01();
	// class02();

	cMyClass myCl(100);
	cMyClass myCl2(0, 50);

	myCl.printABC();
	myCl2.printABC();
	drawLine();

	myCl = myCl2;
	myCl.printABC();
	myCl2.printABC();
	drawLine();

	cMyClass myCl3;
	myCl3 = myCl + myCl2;
	myCl3.printABC();
	drawLine();

	system("pause");
}