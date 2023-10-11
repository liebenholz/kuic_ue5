#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "baseball.h"

void baseball() {
	int comBall[3];	// 컴퓨터가 생성한 숫자 세 개
	int usrBall[3];	// 플레이어가 예측하는 숫자 세 개
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++) {
		int temp = (rand() % 9) + 1;	// 1~9 랜덤숫자
		comBall[i] = temp;

		// 현재 temp값과 이전에 넣은 값 중 동일한 게 있다면 이전으로 돌아가기
		for (int j = 0; j < i; j++) {
			if (temp == comBall[j] && i != j)
				i--;
		}
	}
	// printf("Answer : %d %d %d\n", comBall[0], comBall[1], comBall[2]);

	int count = 1;
	while (1) {
		printf("[Inning %d Baseball Game]\n", count);

		while (1) {
			printf("Type three numbers from 1 to 9: ");
			scanf_s("%d %d %d", &usrBall[0], &usrBall[1], &usrBall[2]);

			if (usrBall[0] < 1 || usrBall[0] > 9 || usrBall[1] < 1
				|| usrBall[1] > 9 || usrBall[2] < 1 || usrBall[2] > 9) {
				printf("Warning: Input number out of range.\n");
				continue;
			}
			else if (usrBall[0] == usrBall[1] || usrBall[0] == usrBall[2]
				|| usrBall[1] == usrBall[2]) {
				printf("Warning: Duplicatied number input.\n");
				continue;
			}
			break;
		}
		int ball = 0, strike = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (comBall[i] == usrBall[j]) {
					if (i == j) 
						strike++;
					else 
						ball++;
				}
			}
		}
		printf("Result : %d ball %d strike.\n", ball, strike);
		if (strike == 3) {
			printf("*********You Won!!*********\n");
			break;
		}
		else if (count == 9) {
			printf("*********You Lose!!*********\n");
			printf("Answer : %d %d %d\n", comBall[0], comBall[1], comBall[2]);
			break;
		}
		count++;
	}
	system("pause");
}