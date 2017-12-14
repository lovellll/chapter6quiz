// chapter6quiz.cpp : 定义控制台应用程序的入口点。
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

