#include <stdio.h>
#include <iostream>

class CBase {
public: 
	int a = 1;
};

class CChild1 : public CBase {
public:
	void printB() {
		printf("Child1::printB = %f\n", b);
	}

	float b = 3.14f;
};

class CChild2 : public CBase {
public:
	void printC() {
		printf("Child2::printC = %d\n", c);
	}
	int c = 3;
};


int main() {

	CBase* pBase = new CChild1;

	// CBase* ����Ʈ�� ĳ�����ϱ� ������ printB�� ���� �Ұ�
	// pBase->printB();

	// �⺻ ĳ���� ���
	// ������ CBase* �������� �޸𸮸� 
	// CChild Ŭ������ �޸� Ʋ�� ���� �о�´�.
	CChild1* pChild1 = (CChild1*)pBase;
	// pChild1->printB();

	// �Ʒ��� ���� ����Ʈ�� �߸� ����Ű�� �Ǽ��� �� ���� ������ �߻��� �� �ִ�.
	// ������ int* �����Ϳ� �޸𸮸� CChild*�� ���߸� ���� ���� �ʾ� ������ ���� �߻��� �� ����
	// ������ �������� ��.. �׷��� ���߿� ��� ������ �߻��ߴ��� ã�� �����.
	int* a = new int(0);
	pChild1 = (CChild1*)a;

	// static_cast : ���� ĳ����. ������ �ܰ迡�� ��ȯ��
	// ������ int* �����Ϳ� �޸𸮸� CChild*�� ���߷��� �ϸ� ������ �Ұ�.
	// pChild1 = static_cast<CChild1*>(a); ���� "�߸��� ���� ��ȯ"
	// CBase*�� ĳ���� �� ���������� ������ ����
	pChild1 = static_cast<CChild1*>(pBase);
	// pChild1->printB();

	// static_cast�� �θ��� ���¸� Ȯ��, ������ �ܰ迡�� ����ǹǷ� � ���°� �������� �� �� ����
	// �ڽ��� �ٸ��� Ȯ������ �ʱ� ������ ���� �� ������ ����X. ���� �����
	// ��� ������ �߻��ߴ��� ã�� �����. �ݵ�� ĳ�����ϴ� ����� ���¸� Ȯ���ؾ�...
	CBase* pBase2 = new CChild1;
	CChild2* pChild2 = static_cast<CChild2*>(pBase2);
	pChild2->printC();

	// float�� int������ ������ �о� ����ؼ� 3.14f �� int ���·� ��µ�
	float fvalue = 3.14f;
	int* pi = (int*)&fvalue;
	printf("pi : %d\n", *pi);

	delete pBase;
	delete a;
	delete pBase2;

	system("pause");
}

