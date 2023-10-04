#include <stdio.h>
#include <iostream>

// ����, �ڷ���
struct stMyStruct {
	int a; int b; int c;

	// ����ü�� �ʱ�ȭ
	stMyStruct() : a(0), b(0) {
		c = 0;
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
	int a1, a2;

	// ������: Ŭ���� ���� �� ȣ��. �������� �ʾƵ� �⺻ �����ڰ� ����.
	// �ݵ�� �ı��ڴ� public�̾�� �Ѵ�. private�̸� �ܺο��� ȣ�� �Ұ�.
public:	
	cMyClass(int value) : a(0), b(0), c(0) {
		printf("Class Generated!\n");
		a1 = value; a2 = value;
	}

	// �ı���: Ŭ���� �ı� �� ȣ��. �������� �ʾƵ� �⺻ �ı��ڰ� ����.	
	// �ݵ�� �����ڴ� public�̾�� �Ѵ�. private�̸� �ܺο��� ȣ�� �Ұ�.
	~cMyClass() {
		printf("Class Destroyed!\n");
	}

private:	// �ܺο��� ���� �Ұ�
	int a;		
protected:  // ��Ӱ����� ��� ���� ����, �̿ܿ��� ���� �Ұ�
	int b;	
public:		// �ܺ� ��𼭵� ���� ����
	int c;		
};

int main() {
	stMyStruct mySt;
	mySt.a = 0;

	cMyClass myCl(10);	// ������ ȣ���
	myCl.c = 10;
	// �ı��� ȣ���
}