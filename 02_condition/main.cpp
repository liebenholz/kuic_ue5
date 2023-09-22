#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>

// cpp의 컴파일
// cpp에서 사람이 작성한 소스코드를 컴퓨터가 읽을 수 있는 코드로 변환하여 실행할 수 있는 파일로 변환하는 과정.


// 메모리 영역
// 1. Code 영역 : 실행할 코드가 저장되어있는 영역(기계어 형태로).
// 2. Data 영역 : 전역변수, 정적변수 저장, 프로세스 종료될 대까지 메모리에 저장됨.
// 3. Stack 영역: 지역변수, 매개변수 저장, 함수가 호출되면 생성되고 종료되면 시스템에 반환.
// 4. Heap 영역 : malloc 또는 new 함수에 의해서 동적으로 할당되는 영역.
//				  malloc(), new 연산자로 할당, free(), delete 연산자로 해제.

#define LEVELREWARD_10 0b00000001;	// 1
#define LEVELREWARD_20 0b00000010;	// 2
#define LEVELREWARD_30 0b00000100;	// 4
#define LEVELREWARD_40 0b00001000;	// 8
#define LEVELREWARD_50 0b00010000;	// 16
#define LEVELREWARD_60 0b00100000;	// 32

int main()  {

	//{
	//	int a = 0;
	//	std::cin >> a;
	//	std::cout << a << "를 입력하였습니다.";
	//}

	//{
	//	int a = 0, b = 0;
	//	printf("Enter numbers: ");
	//	scanf_s("%d %d", &a, &b);	// 주소값 전달, 안전하게 동작하도록 _s 사용.
	//	printf("a = %d, b = %d", a, b);
	//}

	//bool bResult = false;
	//if (true) 
	//	printf("true1.\n");	// ㅇㅇ
	//if (-1) 
	//	printf("true2.\n");	// ㅇㅇ
	//if (0) 
	//	printf("true3.\n");	// ㄴㄴ
	//
	//if (bResult) 
	//	printf("true4.\n");  // ㄴㄴ
	//else
	//	printf("false4.\n"); // ㅇㅇ

	//while (1) {
	//	int score = 0;
	//	printf("Enter your score: ");
	//	scanf_s("%d", &score);

	//	printf("your score is %d\n", score);

	//	if (score >= 90)
	//		printf("your GPA is A!\n");
	//	else if(score >=80)
	//		printf("your GPA is B!\n");
	//	else if (score >= 70)
	//		printf("your GPA is C!\n");
	//	else if (score >= 60)
	//		printf("your GPA is D!\n");
	//	else
	//		printf("your GPA is F!\n");
	//	printf("-------------------\n");
	//}

	//while (1) {
	//	int backNum = 0;

	//	printf("Enter player back number: ");
	//	scanf_s("%d", &backNum);

	//	switch (backNum) {	// 4-3-3
	//	case 1:	 printf("GK\n"); break;
	//	case 2:  
	//	case 3:	
	//	case 4:
	//	case 5:  printf("DF\n"); break;
	//	case 7: 
	//	case 9: 
	//	case 10: printf("FW\n"); break;
	//	case 11:
	//	case 13:
	//	case 15: printf("MF\n"); break;
	//	default: // 위의 케이스가 모두 해당되지 않으면 실행
	//		printf("Bench\n");
	//	}
	//}

	// light 값을 입력받아 true면 파란불, 아니면 빨간불
	//int light = 0;
	//printf("Set the light: ");
	//scanf_s("%d", &light);
	//if (light != 0) {
	//	printf("blue.\n");
	//}
	//else {
	//	printf("red.\n");
	//}
	//printf("-------------------\n");

	//// 입력된 정수가 100 초과, 미만인 경우에 대하여 출력 처리
	//int nInput = 0;
	//printf("Enter the number : ");
	//scanf_s("%d", &nInput);
	//if (nInput > 100) {
	//	printf("Over 100.\n");
	//}
	//else if (nInput < 100) {
	//	printf("Under 100.\n");
	//}
	//else 
	//	printf("It is 100.\n");
	//printf("-------------------\n");

	//// 내 점수가 상대 점수보다 크면 3점, 같으면 1점, 작으면 0점.
	//int myScore = 0, otherScore = 0;
	//printf("Enter my score : ");
	//scanf_s("%d", &myScore);
	//printf("Enter enemy's score : ");
	//scanf_s("%d", &otherScore);

	//if (myScore > otherScore) 
	//	printf("Get 3!\n");
	//else if (myScore = otherScore) 
	//	printf("Get 1!\n");
	//else
	//	printf("Get 0!\n");
	//printf("-------------------\n");
	//
	//// 주민번호 뒷자리의 첫 숫자에 따라 홀수면 남자, 아니면 여자.
	//int nCode = 0;
	//printf("Enter your ID number : ");
	//scanf_s("%d", &nCode);

	//switch (nCode) {
	//case 1:
	//case 3: printf("You are Man.\n"); break;
	//case 2:
	//case 4: printf("You are Woman.\n"); break;
	//default: printf("Wrong Number!\n"); break;
	//}
	//printf("-------------------\n");

	//// 주민번호 뒷자리의 첫 숫자에 따라 1,2면 20세기생, 3,4면 21세기생.
	//int nCode2 = 0;
	//printf("Enter your ID number : ");
	//scanf_s("%d", &nCode2);

	//switch (nCode2) {
	//case 1:
	//case 2: printf("You were born in 20th century!\n"); break;
	//case 3:
	//case 4: printf("You were born in 21th century!\n"); break;
	//default: printf("Wrong Number!\n"); break;
	//}
	//printf("-------------------\n");


	// 비트연산자: C++11부터 앞에 0b를 붙이면 이진법 표기 가능
	// 이진법 표기 앞에 0b를 붙인다(0b01011101)
	// 팔진법 표기 앞에 0을 붙인다(0123)
	// 16진법 표기 앞에 Ox를 붙인다(0xE83F)

	/*int a = 0b01011101;
	int b = 0123;
	int c = 0xE83F;

	printf("2진법(0b01011101): %d\n", a);
	printf("8진법(0123): %d\n", b);
	printf("16진법(0xE83F): %d\n", c);*/

	// 비트연산 기호
	// 곱(&) : 둘 다 1이면 1, 아니면 0
	// 합(|) : 둘 중에 하나라도 1이면 1, 아니면 0
	// XOR(^) : 둘이 같으면 0, 아니면 1
	// 반전(~) : 0이면 1, 1이면 0

	//char bitNum = 0b01011101;
	//char bitResult = 0;

	////  0b01011101
	////& 0b11011010
	////= 0b01011000
	//bitResult = bitNum & 0b11011010;
	//std::cout << std::bitset<8>(bitResult) << std::endl; // std::endl == printf("\n")

	////  0b01011101
	////| 0b11011010
	////= 0b11011111
	//bitResult = bitNum | 0b11011010;
	//std::cout << std::bitset<8>(bitResult) << std::endl;

	////  0b01011101
	////^ 0b11011010
	////= 0b10000111
	//bitResult = bitNum ^ 0b11011010;
	//std::cout << std::bitset<8>(bitResult) << std::endl;

	////~ 0b01011101
	////= 0b10100010
	//bitResult = ~ bitNum;
	//std::cout << std::bitset<8>(bitResult) << std::endl;

	//printf("-------------------\n");

	// 1. 플래그 세팅(값을 1로)
	// 2. 받았는지 안 받았는지 확인(검증)
	// 3. 취소하고 싶을 때 초기화(값을 0으로)
	char myLevelReward = 0b00000000;
	
	// 비트 1로 설정
	// myLevelReward = myLevelReward | 0b00000001;	
	myLevelReward = myLevelReward | LEVELREWARD_10;	// 10레벨 달성!
	std::cout << "My Reward: " << std::bitset<8>(myLevelReward) << std::endl;

	myLevelReward = myLevelReward | LEVELREWARD_20;	// 20레벨 달성!
	std::cout << "My Reward: " << std::bitset<8>(myLevelReward) << std::endl;
	printf("-------------------\n");

	// 비트가 활성되어있는지 확인
	bool isEnable = false;
	// isEnable = myLevelReward & 0b00000010;
	isEnable = myLevelReward & LEVELREWARD_20;	// 20레벨 보상 받았나?
	// isEnable = 0b00000010 = true
	std::cout << "Got my Lv20 Reward?: " << isEnable << std::endl;

	isEnable = myLevelReward & LEVELREWARD_30;	// 30레벨 보상 받았나?
	// isEnable = 0b00000000 = false
	std::cout << "Got my Lv30 Reward?: " << isEnable << std::endl;
	printf("-------------------\n");

	// 비트를 0으로 설정
	myLevelReward = myLevelReward & ~LEVELREWARD_20; // 20레벨 보상 무효!!
	std::cout << "Lv20 reward deleted.\n" << "My Reward: " << std::bitset<8>(myLevelReward) << std::endl;

	system("pause");

}