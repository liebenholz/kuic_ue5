#include <stdio.h>
#include <iostream>

// RTTI(Run Time Type Information/Identification)
// x64�� ��� Ŭ���� ũ�⸦ 8/16/24/32 ������ 8����Ʈ �������� �Ҵ�
// RTTI ���� �Ҵ� 8����Ʈ + 4����Ʈ = 12����Ʈ
// 12����Ʈ ���� �� �ִ� �ּ� ������ 16����Ʈ

class CBase {
public:
	// �����Լ� virtual function
	// �ڽ� Ŭ�������� �Լ��� override�� �ؼ� �籸�� ����
	// �����Լ��� �Ǹ� RTTI ������ ����Ű�� ������ ���� ���� (x64����) 8����Ʈ �Ҵ�
	// RTTI �����ʹ� �ش� Ŭ������ ������ ����Ű�� �� 
	// ���� ����ȯ �� Ŭ������ ũ�⸦ �����ϴ� �� �ƴ϶�
	// �߰��� �Ҵ�� RTTI �����Ϳ� Ŭ������ ������ ����
	// ��Ÿ�� �� �������� �Ҵ�
	virtual void printX() {
		printf("x : %d\n", m_X);
	}
	int m_X = 10;
};

// RTTI ���� �Ҵ� 8����Ʈ + 8����Ʈ = 16����Ʈ
// 16����Ʈ ���� �� �ִ� �ּ� ������ 24����Ʈ
class CChild1 : public CBase {
public:
	void printY() {
		printf("y : %d\n", m_Y);
	}
	int m_Y = 20;
};

class CChild2 : public CBase {
public:
	void printZ() {
		printf("z : %d\n", m_Z);
	}
	int m_Z = 30;
};

void dcast01() {
	printf("CBase Size : %I64d\n", sizeof(CBase));		// CBase ��ü�� ũ�� ��ȯ ���� (%I64d: int64 ���)
	printf("CChild Size : %I64d\n", sizeof(CChild1));	// CChild ��ü�� ũ�� ��ȯ ����

	int64_t* pB = (int64_t*)new CBase;
	int64_t* pC = (int64_t*)new CChild1;
	// RTTI ������ �ּ�, m_X(, m_Y)�� ���ʴ�� ���
	printf("pB[0] : %I64d, pB[1] : %d\n", pB[0], (int)pB[1]);
	printf("pC[0] : %I64d, pC[1] : %d, pC[2] : %d\n", pC[0], (int)pC[1], (int)pC[2]);

	delete pB;	delete pC;
}

void dcast02() {

}

int main() {
	dcast01();

	CBase* pBase[] = { new CChild1, new CChild2 };

	for (CBase* pTemp : pBase) {
		pTemp->printX();	// base�� �ֱ� ������ �� ��

		// Dynamic Casting : ���� ����ȯ
		// <CChild1*> : ����ȯ�� Ŭ���� Ÿ��
		// (pTemp) : ����ȯ�� ��ü
		// CChild1* pChild : ����ȯ ��� ��ȯ ��
		CChild1* pChild = dynamic_cast<CChild1*>(pTemp);
		if (pChild == nullptr) continue;	// ���������� ����ȯ���� ������ nullptr�� ����
		pChild->printY();	// ���������� ����ȯ�Ǹ� ��ü�� ��ȯ��. CChild1�� printY ��� ����
	}

	for (CBase* pTemp : pBase) {
		delete pTemp;
	}
	
}