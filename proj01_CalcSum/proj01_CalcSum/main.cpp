#include <stdio.h>
#include <iostream>
#include "calcFunc.h"

int main() {
	bool bRun = true;

	while (bRun) {
		typeNums();
		chooseCalc();
		bRun = isContinue(bRun);
	}
	system("pause");
 }