#include <stdio.h>
#include <iostream>

// ���: ���� Ŭ������ ����� �߰��ϰų� �������� ���ο� Ŭ������ ����
// ����: �⺻ �ֻ��� Ŭ����
// ����: ���� + �����δ�, ������ ����� ��ӹ���
// ������: ���� + ������, ������ ����� ��ӹ���
// ���: ������ + �����ɷ�, �������� ����� ��ӹ���

void drawLine() {
	printf("------------------------------------\n");
}

class CBase {
public:
	CBase(int x) : m_X(x) {
		printf("Parent Class Generated!\n");
	}
	int m_X;

	~CBase() { printf("Parent Class Destroyed!\n"); }
};

class CChild : public CBase { // : ��ӹ��� Ŭ����
public:
	// ":" �ڿ� �θ�Ŭ������ �־� �θ�Ŭ������ �����ڸ� ȣ��
	// �θ�Ŭ���� ������ �� ȣ��, ���� �ڽ�Ŭ���� ������
	CChild(int x, int y) : m_Y(y), CBase(x) {
		printf("Child Class Generated!\n"); 
	}
	int m_Y;

	// �ڽ�Ŭ���� �ı��� �� ȣ��, ���� �θ�Ŭ���� �ı���
	~CChild() { printf("Child Class Destroyed!\n"); }
};

int main() {
	CBase base(10);
	base.m_X = 100;

	CChild child(10, 20);
	base.m_X = 200;	// ��ӹ��� �θ��� ����� �״�� ��� ����
	drawLine();

}

