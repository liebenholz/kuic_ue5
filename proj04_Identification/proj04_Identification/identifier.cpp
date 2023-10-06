#include <stdio.h>
#include <iostream>
#include "identifier.h"

void isMale(int last) {
	if (last % 2 == 1) printf(" 남자\n");
	else printf(" 여자\n");
}

void isLeapYear(int y, int m, int d) {

	// 월에 따른 일수 체크
	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// 윤년 계산
	// 4년마다 윤년, 100년마다 평년, 400년마다 윤년
	if (y % 4 == 0) {
		if (y % 100 != 0 || y % 400 == 0) {
			mon[1] = 29;
		}
	}
	int date = mon[m - 1];

	// 2024년 이후 생은 예외처리
	if (y > 2023) {
		printf("Incorrect Input: There is no human born after 2023.\n");
		system("pause");
	}

	// 월은 12월까지: 이외에는 예외처리
	if (m > 12 || m == 0) {
		printf("Incorrect Input: There is no month after 12.\n");
		system("pause");
	}

	// 체크한 일수에 따라 예외처리
	if (d > date || d == 0) {
		printf("Incorrect Input: There is no date after %d.\n", date);
		system("pause");
	}
}

void isBorn(int first, int last) {

	// 주민번호 앞자리가 6자리인지 확인
	if (first / 1000000 != 0) {
		printf("Incorrect Input: First ID must be 6 digits.\n");
		system("pause");
	}

	int date = first % 100;
	int month = first / 100 % 100;
	int year = first / 10000;

	// 1,2면 1900년대생
	// 3,4면 2000년대생
	// 이외에는 예외처리
	switch (last) {
	case 1:
	case 2:
		year += 1900;
		break;
	case 3:
	case 4:
		year += 2000;
		break;
	default:
		printf("Incorrect Input: Last ID must be from 1 to 4.\n");
		system("pause");
	}

	isLeapYear(year, month, date);

	printf("%d년 %d월 %d일", year, month, date);
	isMale(last);
}

void identifier() {
	int firstID = 0, lastID = 0;
	printf("Type your first ID number: ");
	scanf_s("%d", &firstID);
	printf("Type your last ID number: ");
	scanf_s("%d", &lastID);

	isBorn(firstID, lastID);
	system("pause");
}