// chapter6quiz.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "card.h"





int main()
{
	std::array<Cards, 52> deckCards;
	initializeCards(deckCards);
	shuffleDeck(deckCards);
	printDeck(deckCards);


    return 0;
}

