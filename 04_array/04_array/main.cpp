#include <stdio.h>
#include <iostream>
#include "bank.h"
#include "calcFunc.h"

static int s_balance; // 정적변수. 데이터영역에 존재

void bankAccount() {
	int t_balance = 1000;	// 코드영역에 존재
	myBalance(t_balance);
	deposit(2000, t_balance);
	withdraw(1000, t_balance);
	withdraw(5000, t_balance);
	myBalance(t_balance);
}

void calculator() {
	bool bRun = true;
	while (bRun) {
		typeNums();
		chooseCalc();
		bRun = isContinue(bRun);
		drawLine();
	}
}

int main() {
	// bankAccount();
	calculator();
	system("pause");
}

