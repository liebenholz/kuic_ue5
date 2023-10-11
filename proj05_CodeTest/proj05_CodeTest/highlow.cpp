#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "highlow.h"

using namespace std;

// 숫자 순위(뒤로 갈수록 높음)
string num[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

// 문양 순위(뒤로 갈수록 높음)
enum cardMark {
	clover = 0, 
	heart, 
	diamond, 
	spade,
	null_mark	// unable
};

// 트럼프 카드 클래스
class cCard {
public:
	cCard(string num, cardMark mark) : m_num(num), m_mark(mark) {}
	string m_num = "0";
	cardMark m_mark = null_mark;

	// 카드의 문양 반환
	string getMark() {
		switch (m_mark) {
		case clover:
			return "Clovers";
			break;
		case heart:
			return "Hearts";
			break;
		case diamond:
			return "Diamonds";
			break;
		case spade:
			return "Spades";
			break;		
		}
		return "None";
	}

	// 카드의 숫자, 문양 출력하기
	void printCard() {
		printf("%s of %s\n", m_num.c_str(), getMark().c_str());
	}
};

// 다음 카드가 현재 카드보다 높은가?
bool isHigh(cCard curr, cCard next) {
	if (curr.m_num < next.m_num)
		return 1;
	else if (curr.m_num == next.m_num && curr.m_mark < next.m_mark)
		return 1;

	return 0;
}

// 다음 카드가 현재 카드보다 낮은가?
bool isLow(cCard curr, cCard next) {
	if (curr.m_num > next.m_num) 
		return 1;
	else if (curr.m_num == next.m_num && curr.m_mark > next.m_mark) 
		return 1;
	
	return 0;
}

void gameResult(bool isCorrect, int& credit, int bet) {
	if (isCorrect) {
		credit += bet;
		printf("High is Correct! (your credit:%d)\n", credit);
	}
	else {
		credit -= bet;
		printf("Wrong! (your credit:%d)\n", credit);
	}
}

void drawLine() {
	printf("-------------------------------------------\n");
}

/*
* 하이로우 게임
* 1. 52개의 카드로 게임을 진행하며, 이 카드를 무작위로 섞는다.
* 2. 게임이 시작되면 카드 하나를 오픈한다.
* 3. 플레이어는 다음 카드가 오픈된 카드보다 높은 카드인지, 낮은 카드인지에 베팅을 한다.
* 4. 다음 카드를 오픈하고 높은지 낮은지에 대한 선택이 맞으면 승리, 틀리면 패배.
* 5. 카드는 A가 가장 낮고, K가 가장 높다.
* 6. 문양은 스페이드 > 다이아 > 하트 > 클로버 순으로 높다.
*/


int highlow() {
	// 카드 한 벌
	vector<cCard> Cards;

	// 카드 한 벌 만들기
	for (int i = 0; i < cardMark::null_mark; i++) {
		for (int j = 0; j < 13; j++) {
			cCard card(num[j], (cardMark)i);
			Cards.push_back(card);
		}
	}

	// 만든 카드 한 벌 출력하기
	// for (cCard& card : Cards) card.printCard();
	// drawLine();

	// 섞기
	random_shuffle(Cards.begin(), Cards.end());
	// for (cCard& card : Cards) card.printCard();

	// 덱에서 카드를 드로우
	cCard currCard = Cards.back();
	Cards.pop_back();
	// drawLine();

	// for (cCard& card : Cards) card.printCard();

	// 나의 크레딧
	int credit = 10000;

	while (1) {
		// 현재 카드를 출력해줌
		printf("curr card :");
		currCard.printCard();

		// 다음 카드가 현재 카드보다 높을지 낮을지를 예측
		int expect = 0;
		while (1) {
			printf("Expect next card : High(0) ? Low(1) : ");
			scanf_s("%d", &expect);
			if (expect == 0 || expect == 1) break;
			else printf("Not an appropriate choice. Please try again.\n");
		}

		// 해당 예측에 얼마를 베팅할 것인가?
		int bet = 0;
		while (1) {
			printf("How much would you bet? (your credit:%d) : ", credit);
			scanf_s("%d", &bet);
			if (bet > 0 && bet <= credit) // 베팅 금액은 0 초과, 크레딧 이하
				break;
			else printf("Not an appropriate betting. Please try again.\n");
		}

		// 다음 카드를 저장
		cCard nextCard = Cards.back();

		// 예측에 따라 결과 출력. 맞추면 크레딧에서 베팅 금액만큼 추가, 틀리면 차감.
		if (expect == 0) {
			gameResult(isHigh(currCard, nextCard), credit, bet);
		}
		else {
			gameResult(isLow(currCard, nextCard), credit, bet);
		}

		// 크레딧이 부족하면 패배로 게임 종료
		if (credit <= 0) {
			printf("******************You Lose!!*******************\n");
			return 0;
		}
		
		// 덱에서 카드를 드로우
		currCard = Cards.back();
		Cards.pop_back();
		drawLine();

		// 모든 카드를 드로우 한 이후에도 생존했다면 승리로 게임 종료
		if (Cards.empty()) {
			printf("All cards have drawed!! (your credit:%d)\n", credit);
			printf("******************You Won!!*******************\n");
			return 0;
		}
	}
	return 0;
}