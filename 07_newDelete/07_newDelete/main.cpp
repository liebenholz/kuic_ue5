#include <stdio.h>
#include <iostream>

int main() {
	/*
	// 정적 메모리 할당
	// 정적으로 멤리를 할당하면 컴파일 시 Stack 영역에 할당되며, 함수를 빠져나갈 때 소멸된다.
	// 프로그램 컴파일 시 Stack에 얼마만큼의 크기로 할당해야하는지 결정되기 때문에, 컴파일 이후 크기를 변경할 수 없다.
	// 따라서 정적 배열 선언 시 가변적으로 명시하면 문제가 발생할 수 있다.
	int a = 0;
	int arr[10];	// 만드는 순간 크기가 정해짐

	// 동적 메모리 할당
	// 동적으로 메모리를 할당하는 경우 데이터가 heap 영역에 할당된다.
	// heap은 프로그래머에 의해 할당(new) 및 소멸(delete)된다.
	// 프로그래머가 원할 때 원하는 크기로 할당할 수 있다.
	// 포인터 변수는 stack 영역에 할당된다.

	// c에서 사용하는 동적 할당
	int* pm = (int*)malloc(4);
	free(pm);

	// cpp에서 동적 할당하는 기능 추가
	// new & delete
	// new 연산자로 생성 시 반드시 이후에 delete 연산자로 해제해야 한다.
	// new 연산자로 배열 생성 시 delete[] 연산자로 배열임을 명시해야 한다.
	int* pa = new int(0);
	int* parr = new int[10];
	
	delete pa;
	delete[] parr;
	*/

	int* parr = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < 10; i++) {
		printf("%d ", parr[i]);
	}
	delete[] parr;

	// 깊은 복사 & 얕은 복사 
	int* a;
	a = new int(10);
	int* b = new int(20);

	// 가리키고 있는 대상이 바뀌면서 기존의 것이 낙동강 오리알 신세가 되는 문제.
	a = b;		// 얕은 복사: a의 주소값에 b의 주소값을 넣는다 b가 가리키고 있는 것을 a도 가리키게 하겠다.
	*a = *b;	// 깊은 복사: a가 가리키고 있는 값을 b가 라기키고 있는 값으로 수정한다.

	delete a, b;

	system("pause");
}