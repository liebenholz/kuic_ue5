#include <stdio.h>
#include <iostream>
#include "depositLoan.h"

using namespace std;

// �����ǹ� �������� 34�� ����
// �����ǹ� ������ 39�� ����
bool availAge(int mil, int age) {
	if (mil == 0 && age <= 34) return true;
	else if (mil != 0 && age <= 39) return true;
	return false;
}

// �ҵ� 5000 ����
bool availSalary(int sal) {
	if (sal > 5000) return false;
	return true;
}

// �߼ұ�� ����� �Ǵ� û��â����
bool availJob(int isE, int isF) {
	if (isE != 0 || isF != 0) return true;
	return false;
}

void depositLoan() {
	int age = 0;		// ����
	int isMilitary = 0;	// �����ǹ�
	int isHomeless = 0;	// ������
	int salary = 0;		// �ҵ�
	int isEmployer = 0;	// �߼ұ�� �����
	int isFounder = 0;	// û��â����

	// �������࿩��
	cout << "Did you fulfilled yout military service? (no:0) : ";
	cin >> isMilitary;

	// ����
	cout << "Type your age : ";
	cin >> age;

	// ��������
	cout << "Are you homeless? (no:0) : ";
	cin >> isHomeless;

	// �ҵ�
	cout << "Type your salary : ";
	cin >> salary;

	// �߼ұ�� �����
	cout << "Are you midsize business employer? (no:0) : ";
	cin >> isEmployer;

	// û�� â����
	cout << "Are you midsize youth business founder? (no:0) : ";
	cin >> isFounder;

	// �ڰ� Ȯ��
	if (!availAge(isMilitary, age) || !isHomeless || !availSalary(salary) || !availJob(isEmployer, isFounder)) {
		printf("Not an invitee.\n");
	}
	else printf("You are an invitee.\n");

	system("pause");
}