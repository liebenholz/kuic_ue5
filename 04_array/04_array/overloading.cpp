#include <stdio.h>
#include "overloading.h"

int add(int a, int b) {
	printf("int add\n");
	return a + b;
}

float addF(float a, float b) {
	printf("float add\n");
	return a + b;
}

double add(double a, double b) {
	printf("double add\n");
	return a + b;
}