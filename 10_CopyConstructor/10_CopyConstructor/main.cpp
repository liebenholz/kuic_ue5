#include <stdio.h>
#include <iostream>

class cName {

public:
	// ������(�̸�): �̸� �� ���� �ʱ�ȭ
	cName(const wchar_t* name) :szName(nullptr), len(0) {
		// szName = name;	 // ���̰� �ٸ� �� �ֱ� ������ �Ұ�
		len = wcslen(name) + 1;		// ���鹮�ڱ��� ����
		szName = new wchar_t[len];	// �����Ҵ�

		// szName�� ���� �Է��� �̸��� ����
		wcscpy_s(szName, len, name);
	}

	// ���� ������ �� �����Ҵ� ������
	// �Ķ���ͷ� (const cName& other) �� ���� �ڽ��� Ŭ���� ī���� ���۷����� ���� ��
	cName(const cName& other) :szName(nullptr), len(0) {
		if (szName != nullptr) { delete[] szName; }
		len = wcslen(other.szName) + 1;	
		szName = new wchar_t[len];	
		wcscpy_s(szName, len, other.szName);
	}

	// �ı���
	~cName() { delete[] szName; }

	// �̸� ��������
	wchar_t* getName() { return szName; }

	// ���Կ����� �����ε�
	const cName& operator=(const cName& other) {
		// ���� ����: other.szName�� ����Ű�� �ִ� ���� szName�� ����Ű�� �ϰڴ�
		// szName = other.szName;
		// len = other.len;
		// main���� name1 = name2; �� �����ϸ� ���� �߻�

		// ���� ����: other.szName�� �����ؼ� szName�� �ִ´�
		if (szName != nullptr) { delete[] szName; }
		len = wcslen(other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, other.szName);

		return *this;
	}

	wchar_t* szName;
	size_t len;
};

int main() {

	_wsetlocale(LC_ALL, L"korean");

	cName name1(L"����");
	cName name2(L"��");
	wprintf(L"name1: %s,\t name2: %s\n", name1.getName(), name2.getName());

	// ���Կ����� ó��
	// const cName& operator=(const cName & other)
	name1 = name2;	

	// ���� ������ �� �����Ҵ� ������
	// cName(const cName & other) :szName(nullptr), len(0)
	cName name3 = name1;

	wprintf(L"name1: %s,\t name3: %s\n", name1.getName(), name3.getName());

}