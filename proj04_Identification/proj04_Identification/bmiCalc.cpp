#include <stdio.h>
#include <iostream>
#include "bmiCalc.h"

using namespace std;

// 키를 통해 표준 몸무게를 반환하는 함수
float stdWeight(float height) {
	return (height - 100) * 0.9;
}

// 내 몸무게와 표준몸무게를 통해 BMI를 반환하는 함수
float getBMI(float weight, float stdWgt) {
	return (weight - stdWgt) * 100 / stdWgt;
}

void bmiCalc() {
	int bRun = 1;
	int weight = 0;
	int height = 0;

	while (bRun) {
		// bRun의 입력을 통해 BMI 계산을 이어갈것인지 확인
		printf("Calculate BMI? (no:0) : ");
		scanf_s("%d", &bRun);
		// 0을 입력하면 종료
		if (bRun == 0) continue;

		// 몸무게 입력
		cout << "Type your weight: ";
		cin >> weight;
		// 키 입력
		cout << "Type your height: ";
		cin >> height;

		// 입력받은 키와 몸무게를 이용해 BMI 계산
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
