#include <stdio.h>
#include <iostream>
#include "bmiCalc.h"

using namespace std;

// Ű�� ���� ǥ�� �����Ը� ��ȯ�ϴ� �Լ�
float stdWeight(float height) {
	return (height - 100) * 0.9;
}

// �� �����Կ� ǥ�ظ����Ը� ���� BMI�� ��ȯ�ϴ� �Լ�
float getBMI(float weight, float stdWgt) {
	return (weight - stdWgt) * 100 / stdWgt;
}

void bmiCalc() {
	int bRun = 1;
	int weight = 0;
	int height = 0;

	while (bRun) {
		// bRun�� �Է��� ���� BMI ����� �̾������ Ȯ��
		printf("Calculate BMI? (no:0) : ");
		scanf_s("%d", &bRun);
		// 0�� �Է��ϸ� ����
		if (bRun == 0) continue;

		// ������ �Է�
		cout << "Type your weight: ";
		cin >> weight;
		// Ű �Է�
		cout << "Type your height: ";
		cin >> height;

		// �Է¹��� Ű�� �����Ը� �̿��� BMI ���
		float bmi = getBMI(weight, stdWeight(height));
		if (bmi <= 10) {
			printf("Your BMI: %.2f; Normal\n", bmi);
		}
		else if (bmi <= 20) {
			printf("Your BMI: %.2f; Overweight\n", bmi);
		}
		else {
			printf("Your BMI: %.2f; Obesity\n", bmi);
		}
		printf("=====================\n");
	}

	system("pause");
}
