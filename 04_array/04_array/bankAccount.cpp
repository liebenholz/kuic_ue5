#include <stdio.h>
#include "bank.h"

int g_balance = 1000; // 전역변수. 코드영역에 존재
static int s_balance = 1000; // 정적변수. 코드영역에 존재
extern int e_balance = 1000; // 정적전역변수

void drawLine() {
	printf("-----------------------\n");
}

int myBalance(int t_balance) {
	printf("your balance(g): %d\n", g_balance);
	printf("your balance(t): %d\n", t_balance);
	printf("your balance(s): %d\n", s_balance);
	printf("your balance(e): %d\n", e_balance);
	drawLine();
	return 0;
}

int deposit(int n, int t_balance) {
	g_balance += n;	t_balance += n;
	s_balance += n; e_balance += n;
	printf("deposited: %d\n", n);
	printf("your balance(g): %d\n", g_balance);
	printf("your balance(t): %d\n", t_balance);
	printf("your balance(s): %d\n", s_balance);
	printf("your balance(e): %d\n", e_balance);
	drawLine();
	return 0;
}

int withdraw(int n, int t_balance) {
	if (g_balance < n) {
		printf("not enough money!\n");
		drawLine();
		return 0;
	}
	g_balance -= n; t_balance -= n;
	s_balance -= n; e_balance -= n;
	printf("withdrawed: %d\n", n);
	printf("your balance(g): %d\n", g_balance);
	printf("your balance(t): %d\n", t_balance);
	printf("your balance(s): %d\n", s_balance);
	printf("your balance(e): %d\n", e_balance);
	drawLine();
	return 0;
}

