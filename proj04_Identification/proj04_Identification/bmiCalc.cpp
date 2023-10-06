#include <stdio.h>
#include <iostream>
#include "bmiCalc.h"

using namespace std;

float stdWeight(float height) {
	return (height - 100) * 0.9;
}

float getBMI(float weight, float stdWgt) {
	return (weight - stdWgt) * 100 / stdWgt;
}

void bmiCalc() {
	int bRun = 1;
	int weight = 0;
	int height = 0;

	while (bRun) {
		printf("Calculate BMI? (no:0) : ");
		scanf_s("%d", &bRun);
		if (bRun == 0) continue;

		cout << "Type your weight: ";
		cin >> weight;
		cout << "Type your height: ";
		cin >> height;

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
