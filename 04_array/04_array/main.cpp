#include <stdio.h>
#include <iostream>
#include "bank.h"
#include "calcFunc.h"

static int s_balance; // ��������. �����Ϳ����� ����

void bankAccount() {
	int t_balance = 1000;	// �ڵ念���� ����
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

