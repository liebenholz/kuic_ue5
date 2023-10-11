#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "highlow.h"

using namespace std;

// ���� ����(�ڷ� ������ ����)
string num[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

// ���� ����(�ڷ� ������ ����)
enum cardMark {
	clover = 0, 
	heart, 
	diamond, 
	spade,
	null_mark	// unable
};

// Ʈ���� ī�� Ŭ����
class cCard {
public:
	cCard(string num, cardMark mark) : m_num(num), m_mark(mark) {}
	string m_num = "0";
	cardMark m_mark = null_mark;

	// ī���� ���� ��ȯ
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

	// ī���� ����, ���� ����ϱ�
	void printCard() {
		printf("%s of %s\n", m_num.c_str(), getMark().c_str());
	}
};

// ���� ī�尡 ���� ī�庸�� ������?
bool isHigh(cCard curr, cCard next) {
	if (curr.m_num < next.m_num)
		return 1;
	else if (curr.m_num == next.m_num && curr.m_mark < next.m_mark)
		return 1;

	return 0;
}

// ���� ī�尡 ���� ī�庸�� ������?
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
* ���̷ο� ����
* 1. 52���� ī��� ������ �����ϸ�, �� ī�带 �������� ���´�.
* 2. ������ ���۵Ǹ� ī�� �ϳ��� �����Ѵ�.
* 3. �÷��̾�� ���� ī�尡 ���µ� ī�庸�� ���� ī������, ���� ī�������� ������ �Ѵ�.
* 4. ���� ī�带 �����ϰ� ������ �������� ���� ������ ������ �¸�, Ʋ���� �й�.
* 5. ī��� A�� ���� ����, K�� ���� ����.
* 6. ������ �����̵� > ���̾� > ��Ʈ > Ŭ�ι� ������ ����.
*/


int highlow() {
	// ī�� �� ��
	vector<cCard> Cards;

	// ī�� �� �� �����
	for (int i = 0; i < cardMark::null_mark; i++) {
		for (int j = 0; j < 13; j++) {
			cCard card(num[j], (cardMark)i);
			Cards.push_back(card);
		}
	}

	// ���� ī�� �� �� ����ϱ�
	// for (cCard& card : Cards) card.printCard();
	// drawLine();

	// ����
	random_shuffle(Cards.begin(), Cards.end());
	// for (cCard& card : Cards) card.printCard();

	// ������ ī�带 ��ο�
	cCard currCard = Cards.back();
	Cards.pop_back();
	// drawLine();

	// for (cCard& card : Cards) card.printCard();

	// ���� ũ����
	int credit = 10000;

	while (1) {
		// ���� ī�带 �������
		printf("curr card :");
		currCard.printCard();

		// ���� ī�尡 ���� ī�庸�� ������ �������� ����
		int expect = 0;
		while (1) {
			printf("Expect next card : High(0) ? Low(1) : ");
			scanf_s("%d", &expect);
			if (expect == 0 || expect == 1) break;
			else printf("Not an appropriate choice. Please try again.\n");
		}

		// �ش� ������ �󸶸� ������ ���ΰ�?
		int bet = 0;
		while (1) {
			printf("How much would you bet? (your credit:%d) : ", credit);
			scanf_s("%d", &bet);
			if (bet > 0 && bet <= credit) // ���� �ݾ��� 0 �ʰ�, ũ���� ����
				break;
			else printf("Not an appropriate betting. Please try again.\n");
		}

		// ���� ī�带 ����
		cCard nextCard = Cards.back();

		// ������ ���� ��� ���. ���߸� ũ�������� ���� �ݾ׸�ŭ �߰�, Ʋ���� ����.
		if (expect == 0) {
			gameResult(isHigh(currCard, nextCard), credit, bet);
		}
		else {
			gameResult(isLow(currCard, nextCard), credit, bet);
		}

		// ũ������ �����ϸ� �й�� ���� ����
		if (credit <= 0) {
			printf("******************You Lose!!*******************\n");
			return 0;
		}
		
		// ������ ī�带 ��ο�
		currCard = Cards.back();
		Cards.pop_back();
		drawLine();

		// ��� ī�带 ��ο� �� ���Ŀ��� �����ߴٸ� �¸��� ���� ����
		if (Cards.empty()) {
			printf("All cards have drawed!! (your credit:%d)\n", credit);
			printf("******************You Won!!*******************\n");
			return 0;
		}
	}
	return 0;
}