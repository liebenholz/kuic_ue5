#include <stdio.h>
#include <iostream>
#include "depositLoan.h"

using namespace std;

// 병역의무 미이행자 34세 이하
// 병역의무 이행자 39세 이하
bool availAge(int mil, int age) {
	if (mil == 0 && age <= 34) return true;
	else if (mil != 0 && age <= 39) return true;
	return false;
}

// 소득 5000 이하
bool availSalary(int sal) {
	if (sal > 5000) return false;
	return true;
}

// 중소기업 취업자 또는 청년창업자
bool availJob(int isE, int isF) {
	if (isE != 0 || isF != 0) return true;
	return false;
}

void depositLoan() {
	int age = 0;		// 나이
	int isMilitary = 0;	// 병역의무
	int isHomeless = 0;	// 무주택
	int salary = 0;		// 소득
	int isEmployer = 0;	// 중소기업 취업자
	int isFounder = 0;	// 청년창업자

	// 병역이행여부
	cout << "Did you fulfilled yout military service? (no:0) : ";
	cin >> isMilitary;

	// 나이
	cout << "Type your age : ";
	cin >> age;

	// 무주택자
	cout << "Are you homeless? (no:0) : ";
	cin >> isHomeless;

	// 소득
	cout << "Type your salary : ";
	cin >> salary;

	// 중소기업 취업자
	cout << "Are you midsize business employer? (no:0) : ";
	cin >> isEmployer;

	// 청년 창업자
	cout << "Are you midsize youth business founder? (no:0) : ";
	cin >> isFounder;

	// 자격 확인
	if (!availAge(isMilitary, age) || !isHomeless || !availSalary(salary) || !availJob(isEmployer, isFounder)) {
		printf("Not an invitee.\n");
	}
	else printf("You are an invitee.\n");

	system("pause");
}