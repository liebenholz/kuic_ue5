#include <iostream>

int main() 
{

	//{
	//	int a = 0;
	//	std::cin >> a;
	//	std::cout << a << "研 脊径馬心柔艦陥.";
	//}

	//{
	//	int a = 0, b = 0;
	//	printf("Enter numbers: ");
	//	scanf_s("%d %d", &a, &b);	// 爽社葵 穿含, 照穿馬惟 疑拙馬亀系 _s 紫遂.
	//	printf("a = %d, b = %d", a, b);
	//}

	//bool bResult = false;
	//if (true) 
	//	printf("true1.\n");	// しし
	//if (-1) 
	//	printf("true2.\n");	// しし
	//if (0) 
	//	printf("true3.\n");	// いい
	//
	//if (bResult) 
	//	printf("true4.\n");  // いい
	//else
	//	printf("false4.\n"); // しし

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
	//	default: // 是税 追戚什亜 乞砧 背雁鞠走 省生檎 叔楳
	//		printf("Bench\n");
	//	}
	//}

	// light 葵聖 脊径閤焼 true檎 督空災, 焼艦檎 察娃災
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

	// 脊径吉 舛呪亜 100 段引, 耕幻昔 井酔拭 企馬食 窒径 坦軒
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

	// 鎧 繊呪亜 雌企 繊呪左陥 滴檎 3繊, 旭生檎 1繊, 拙生檎 0繊.
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
	
	// 爽肯腰硲 急切軒税 湛 収切拭 魚虞 筈呪檎 害切, 焼艦檎 食切.
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

	// 爽肯腰硲 急切軒税 湛 収切拭 魚虞 1,2檎 20室奄持, 3,4檎 21室奄持.
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