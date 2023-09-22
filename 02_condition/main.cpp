#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>

// cpp税 陳督析
// cpp拭辞 紫寓戚 拙失廃 社什坪球研 陳濃斗亜 石聖 呪 赤澗 坪球稽 痕発馬食 叔楳拝 呪 赤澗 督析稽 痕発馬澗 引舛.


// 五乞軒 慎蝕
// 1. Code 慎蝕 : 叔楳拝 坪球亜 煽舌鞠嬢赤澗 慎蝕(奄域嬢 莫殿稽).
// 2. Data 慎蝕 : 穿蝕痕呪, 舛旋痕呪 煽舌, 覗稽室什 曽戟吃 企猿走 五乞軒拭 煽舌喫.
// 3. Stack 慎蝕: 走蝕痕呪, 古鯵痕呪 煽舌, 敗呪亜 硲窒鞠檎 持失鞠壱 曽戟鞠檎 獣什奴拭 鋼発.
// 4. Heap 慎蝕 : malloc 暁澗 new 敗呪拭 税背辞 疑旋生稽 拝雁鞠澗 慎蝕.
//				  malloc(), new 尻至切稽 拝雁, free(), delete 尻至切稽 背薦.

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

	//// 脊径吉 舛呪亜 100 段引, 耕幻昔 井酔拭 企馬食 窒径 坦軒
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

	//// 鎧 繊呪亜 雌企 繊呪左陥 滴檎 3繊, 旭生檎 1繊, 拙生檎 0繊.
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
	//// 爽肯腰硲 急切軒税 湛 収切拭 魚虞 筈呪檎 害切, 焼艦檎 食切.
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

	//// 爽肯腰硲 急切軒税 湛 収切拭 魚虞 1,2檎 20室奄持, 3,4檎 21室奄持.
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


	// 搾闘尻至切: C++11採斗 蒋拭 0b研 細戚檎 戚遭狛 妊奄 亜管
	// 戚遭狛 妊奄 蒋拭 0b研 細昔陥(0b01011101)
	// 独遭狛 妊奄 蒋拭 0聖 細昔陥(0123)
	// 16遭狛 妊奄 蒋拭 Ox研 細昔陥(0xE83F)

	/*int a = 0b01011101;
	int b = 0123;
	int c = 0xE83F;

	printf("2遭狛(0b01011101): %d\n", a);
	printf("8遭狛(0123): %d\n", b);
	printf("16遭狛(0xE83F): %d\n", c);*/

	// 搾闘尻至 奄硲
	// 咽(&) : 却 陥 1戚檎 1, 焼艦檎 0
	// 杯(|) : 却 掻拭 馬蟹虞亀 1戚檎 1, 焼艦檎 0
	// XOR(^) : 却戚 旭生檎 0, 焼艦檎 1
	// 鋼穿(~) : 0戚檎 1, 1戚檎 0

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

	// 1. 巴掘益 室特(葵聖 1稽)
	// 2. 閤紹澗走 照 閤紹澗走 溌昔(伊装)
	// 3. 昼社馬壱 粛聖 凶 段奄鉢(葵聖 0生稽)
	char myLevelReward = 0b00000000;
	
	// 搾闘 1稽 竺舛
	// myLevelReward = myLevelReward | 0b00000001;	
	myLevelReward = myLevelReward | LEVELREWARD_10;	// 10傾婚 含失!
	std::cout << "My Reward: " << std::bitset<8>(myLevelReward) << std::endl;

	myLevelReward = myLevelReward | LEVELREWARD_20;	// 20傾婚 含失!
	std::cout << "My Reward: " << std::bitset<8>(myLevelReward) << std::endl;
	printf("-------------------\n");

	// 搾闘亜 醗失鞠嬢赤澗走 溌昔
	bool isEnable = false;
	// isEnable = myLevelReward & 0b00000010;
	isEnable = myLevelReward & LEVELREWARD_20;	// 20傾婚 左雌 閤紹蟹?
	// isEnable = 0b00000010 = true
	std::cout << "Got my Lv20 Reward?: " << isEnable << std::endl;

	isEnable = myLevelReward & LEVELREWARD_30;	// 30傾婚 左雌 閤紹蟹?
	// isEnable = 0b00000000 = false
	std::cout << "Got my Lv30 Reward?: " << isEnable << std::endl;
	printf("-------------------\n");

	// 搾闘研 0生稽 竺舛
	myLevelReward = myLevelReward & ~LEVELREWARD_20; // 20傾婚 左雌 巷反!!
	std::cout << "Lv20 reward deleted.\n" << "My Reward: " << std::bitset<8>(myLevelReward) << std::endl;

	system("pause");

}