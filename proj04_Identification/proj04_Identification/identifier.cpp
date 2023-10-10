#include <stdio.h>
#include <iostream>
#include "identifier.h"

// ���� ����ϴ� �Լ�
void isMale(int last) {
	if (last % 2 == 1) printf(" ����\n");
	else printf(" ����\n");
}

// ��ȿ�� ����������� Ȯ��
void isLeapYear(int y, int m, int d) {

	// ���� ���� �ϼ� üũ
	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// ���� ���
	// 4�⸶�� ����, 100�⸶�� ���, 400�⸶�� ����
	if (y % 4 == 0) {
		if (y % 100 != 0 || y % 400 == 0) {
			mon[1] = 29;
		}
	}
	int date = mon[m - 1];

	// 2024�� ���� ���� ����ó��
	if (y > 2023) {
		printf("Incorrect Input: There is no human born after 2023.\n");
		system("pause");
	}

	// ���� 12������: �̿ܿ��� ����ó��
	if (m > 12 || m == 0) {
		printf("Incorrect Input: There is no month after 12.\n");
		system("pause");
	}

	// üũ�� �ϼ��� ���� ����ó��
	if (d > date || d == 0) {
		printf("Incorrect Input: There is no date after %d.\n", date);
		system("pause");
	}
}

void isBorn(int first, int last) {

	// �ֹι�ȣ ���ڸ��� 6�ڸ����� Ȯ��
	if (first / 1000000 != 0) {
		printf("Incorrect Input: First ID must be 6 digits.\n");
		system("pause");
	}

	// ���� ���ڸ��� ��
	int date = first % 100;
	// �߰� ���ڸ��� ��
	int month = first / 100 % 100;
	// ���� ���ڸ��� ��
	int year = first / 10000;

	// �ֹι�ȣ ���ڸ� �Է¹޾��� ��
	// 1,2�� 1900����, 3,4�� 2000����
	// �̿ܿ��� ����ó��
	switch (last) {
	case 1:
	case 2:
		year += 1900;
		break;
	case 3:
	case 4:
		year += 2000;
		break;
	default:	// ����ó��
		printf("Incorrect Input: Last ID must be from 1 to 4.\n");
		system("pause");
	}

	// �Է¹��� ��������� �ùٸ��� Ȯ���Ѵ�.
	isLeapYear(year, month, date);

	// ������� ���
	printf("%d�� %d�� %d��", year, month, date);
	isMale(last);	// ���� ���
}

void identifier() {
	int firstID = 0, lastID = 0;
	// �ֹι�ȣ ���ڸ� �Է�
	printf("Type your first ID number: ");
	scanf_s("%d", &firstID);
	// �ֹι�ȣ ���ڸ� ù��° ��ȣ �Է�
	printf("Type your last ID number: ");
	scanf_s("%d", &lastID);

	// �Է¹��� �����͸� ���� ���� �¾��, ������ ��� Ȯ��.
	isBorn(firstID, lastID);
	system("pause");
}