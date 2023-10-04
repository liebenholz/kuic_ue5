#pragma once

class cMyClass2 {
	int a1, a2;

public:
	cMyClass2(int value);
	cMyClass2(int valA, int valB);
	~cMyClass2();
	void printAA();
	void printABC();
	void setPrivA(int n);

private:	
	int a;
protected:  
	int b;
public:	
	int c;
};


