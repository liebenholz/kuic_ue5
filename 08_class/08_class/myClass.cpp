#include <stdio.h>
#include "myClass.h"

cMyClass2::cMyClass2(int value) : a(0), b(0), c(0) {
	printf("Class A Generated!\n");
	a1 = value; a2 = value;
}

cMyClass2::cMyClass2(int valA, int valB) : a(0), b(0), c(0) {
	printf("Class B Generated!\n");
	a1 = valA; a2 = valB;
}

cMyClass2::~cMyClass2() {
	printf("Class Destroyed!\n");
}

void cMyClass2::printAA() {
	printf("%d %d\n", a1, a2);
}

void cMyClass2::printABC() {
	printf("%d %d %d\n", a, b, c);
}
void cMyClass2::setPrivA(int n) {
	a = n;
}

