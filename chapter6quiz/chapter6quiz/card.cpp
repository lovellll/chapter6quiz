#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "card.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <vector>


void printCard(const Cards &card)
{
	switch (card.rank)
	{
	case Ranks::RANK2:	std::cout << "2";	break;
	case Ranks::RANK3:	std::cout << "3";	break;
	case Ranks::RANK4:	std::cout << "4";	break;
	case Ranks::RANK5:	std::cout << "5";	break;
	case Ranks::RANK6:	std::cout << "6";	break;
	case Ranks::RANK7:	std::cout << "7";	break;
	case Ranks::RANK8:	std::cout << "8";	break;
	case Ranks::RANK9:	std::cout << "9";	break;
	case Ranks::RANK10:	std::cout << "T";	break;
	case Ranks::JACK:	std::cout << "J";	break;
	case Ranks::QUEEN:	std::cout << "Q";	break;
	case Ranks::KING:	std::cout << "K";	break;
	case Ranks::ACE:	std::cout << "A";	break;
	}

	switch (card.suit)
	{
	case	Suits::CLUB:		std::cout << "C ";	break;
	case	Suits::DIAMOND:		std::cout << "D ";	break;
	case	Suits::HEART:		std::cout << "H ";	break;
	case	Suits::SPADES:		std::cout << "S ";	break;
	}
}

//initialize cards

void initializeCards(std::array<Cards,52> &deckCards)
{
	for (int i_suit = 0; i_suit < 4; ++i_suit)
	
	{
		for (int j_rank = 0; j_rank < 13; ++j_rank)
		{
			deckCards[i_suit * 13 + j_rank].rank = static_cast<Ranks>(j_rank);
			deckCards[i_suit * 13 + j_rank].suit = static_cast<Suits>(i_suit);

		}
	}
}

void printDeck(const std::array<Cards,52> &deckCards)
{
	for (const auto &ref : deckCards)
	{
		printCard(ref);
	}
}

void swapCards(Cards &card1, Cards &card2)
{
	std::swap(card1, card2);
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}


void shuffleDeck(std::array<Cards, 52> &deckCards)
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber;
	for (auto &ref : deckCards)
	{
		randomNumber = getRandomNumber(0, 51);
		swapCards(ref, deckCards[randomNumber]);
	}

}

int getCardValue(const Cards &card,bool isAce_11)
{
	if(isAce_11)
	{
		if (static_cast<int>(card.rank) <= 8)
			return static_cast<int>(card.rank) + 2;
		else
			switch (card.rank)
			{
			case Ranks::JACK:	return 10;
			case Ranks::QUEEN:	return 10;
			case Ranks::KING:	return 10;
			case Ranks::ACE:	return 11;
			}
	}
	else
	{
		if (static_cast<int>(card.rank) <= 8)
			return static_cast<int>(card.rank) + 2;
		else
			switch (card.rank)
			{
			case Ranks::JACK:	return 10;
			case Ranks::QUEEN:	return 10;
			case Ranks::KING:	return 10;
			case Ranks::ACE:	return 1;
			}
	}
	
}

char getPlayerInput()
{
	while (true)
	{
		std::cout << "Do you want hits or stands? \n" << "Input h for hits,s for stands \n";
		char playerInput;
		std::cin >> playerInput;
		std::cin.ignore(32767, '\n');
		//check players choice
		if (playerInput == 'h')
			return 'h';
		else if (playerInput == 's')
			return 's';
	}
}

void drawCard(std::vector<Cards> &hands,const Cards *&cardPtr)
{
	int nowSize = hands.size();
	hands.resize(nowSize + 1);
	hands[nowSize] = *cardPtr++;
}

int calcHands(const std::vector<Cards> &hands)
{
	int sum(0);
	//ace = 11
	for (const auto &ref : hands)
		sum += getCardValue(ref, true);
	if (sum <= 21)
		return sum;
	else
	{
		//ace =1
		sum = 0;
		for (const auto &ref : hands)
			sum += getCardValue(ref, false);
		return sum;
	}

}

int betCredit()
{
	std::cout << "How much do you want to bet? \n";
	int bet;
	std::cin >> bet;
	std::cin.ignore(32767, '\n');
	return bet;
}

//play the BlackJack and return if player is winner
int playBlackjack(const Cards *cardPtr)
{
	//initialize some storage
	int dealerValue(0);
	int playerValue(0);
	std::vector<Cards> dealerHands{0};
	std::vector<Cards> playerHands{0};
	//dealer draw first card
	drawCard(dealerHands, cardPtr);
	std::cout << "Delaer draw one card. \nDealer's value is now " << calcHands(dealerHands) << "\n";
	//Player gets two cards 
	drawCard(playerHands, cardPtr);
	drawCard(playerHands, cardPtr);
	//Player's turn
	std::cout << "You draw two cards. \nYour value is now " << calcHands(playerHands) << "\n";
	while (calcHands(playerHands) <= 21)
	{
		char playerChoice;
		playerChoice = getPlayerInput();
		if (playerChoice == 'h')
		{
			drawCard(playerHands, cardPtr);
			std::cout << "You get one card and your value is now " << calcHands(playerHands) << "\n";
			if (calcHands(playerHands) > 21)
			{
				//busted,and lose.Return false
				std::cout << "You bust, GAME OVER! \n";
				return -1;
			}
		}
		if (playerChoice == 's')
		{
			std::cout << "You choose to stand and your value is now " << calcHands(playerHands) << "\n";
			break;
		}
	}

	//Dealer's turn
	std::cout << "Now dealer is playing \n";
	while (calcHands(dealerHands) < 17)
	{
		std::cout << "Dealer chose to hits another card! \n";
		drawCard(dealerHands, cardPtr);
		if (calcHands(dealerHands) > 21)
		{
			std::cout << "dealer's value is now " << calcHands(dealerHands) << ". He busted. You won! \n";
			return 1;
		}
	}
	std::cout << "Dealer stands. Now compare. \n";
	//both's turns done.Now compare
	std::cout << "Dealer's final value is now " << calcHands(dealerHands) << "\n";
	std::cout << "Player's final value is now " << calcHands(playerHands) << "\n";
	dealerValue = calcHands(dealerHands);
	playerValue = calcHands(playerHands);
	if (playerValue > dealerValue)
	{
		std::cout << "You won! \n";
		return 1;
	}
	else if (playerValue < dealerValue)
	{
		std::cout << "You lost.Good luck next time! \n";
		return -1;
	}
	else if (playerValue == dealerValue)
	{
		std::cout << "You draw!What a game. \n";
		return 0;
	}
}