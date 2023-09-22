#include <iostream>

int main() 
{

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
	int light = 0;
	printf("Set the light: ");
	scanf_s("%d", &light);
	if (light != 0) {
		printf("blue.\n");
	}
	else {
		printf("red.\n");
	}
	printf("-------------------\n");

	// 입력된 정수가 100 초과, 미만인 경우에 대하여 출력 처리
	int nInput = 0;
	printf("Enter the number : ");
	scanf_s("%d", &nInput);
	if (nInput > 100) {
		printf("Over 100.\n");
	}
	else if (nInput < 100) {
		printf("Under 100.\n");
	}
	else 
		printf("It is 100.\n");
	printf("-------------------\n");

	// 내 점수가 상대 점수보다 크면 3점, 같으면 1점, 작으면 0점.
	int myScore = 0, otherScore = 0;
	printf("Enter my score : ");
	scanf_s("%d", &myScore);
	printf("Enter enemy's score : ");
	scanf_s("%d", &otherScore);

	if (myScore > otherScore) 
		printf("Get 3!\n");
	else if (myScore = otherScore) 
		printf("Get 1!\n");
	else
		printf("Get 0!\n");
	printf("-------------------\n");
	
	// 주민번호 뒷자리의 첫 숫자에 따라 홀수면 남자, 아니면 여자.
	int nCode = 0;
	printf("Enter your ID number : ");
	scanf_s("%d", &nCode);

	switch (nCode) {
	case 1:
	case 3: printf("You are Man.\n"); break;
	case 2:
	case 4: printf("You are Woman.\n"); break;
	default: printf("Wrong Number!\n"); break;
	}
	printf("-------------------\n");

	// 주민번호 뒷자리의 첫 숫자에 따라 1,2면 20세기생, 3,4면 21세기생.
	int nCode2 = 0;
	printf("Enter your ID number : ");
	scanf_s("%d", &nCode2);

	switch (nCode2) {
	case 1:
	case 2: printf("You were born in 20th century!\n"); break;
	case 3:
	case 4: printf("You were born in 21th century!\n"); break;
	default: printf("Wrong Number!\n"); break;
	}
	printf("-------------------\n");

}