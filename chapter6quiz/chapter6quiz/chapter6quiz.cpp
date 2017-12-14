// chapter6quiz.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "card.h"





int main()
{
	int playerPoint(1000);
	std::array<Cards, 52> deckCards;
	initializeCards(deckCards);
	
	//play the game
	while(true)
	{ 
		shuffleDeck(deckCards);
		printDeck(deckCards);		std::cout << "\n";//for debugging
		int betcredit = betCredit();
		int result = playBlackjack(&deckCards[0]);
		if (result == 1)
		{
			std::cout << "You won " << betcredit << " credits! \n";
		}
		else if (result == -1)
		{
			std::cout << "Oops! You lost " << betcredit << " credits! \n";
		}
		else
		{
			std::cout << "Your credits did not change. \n";
		}
		playerPoint += betcredit * result;
		std::cout << "Your credit is now " << playerPoint << ".\n";
		while (true)
		{
			std::cout << "Do you want to play one more round, y or n? \n";
			char playerInput;
			std::cin >> playerInput;
			std::cin.ignore(32767, '\n');
			//check players choice
			if (playerInput == 'y')
				break;
			else if (playerInput == 'n')
				return 0;
		}

	}

    return 0;
}
