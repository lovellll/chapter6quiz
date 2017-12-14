#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "card.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()


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

int getCardValue(const Cards &card)
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

char getPlayerInput()
{
	while (true)
	{
		std::cout << "Do you want hits or stands? \n" << "Input H for hits,S for stands \n";
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

//play the BlackJack and return if player is winner
bool playBlackjack(const Cards *cardPtr)
{
	int dealerPoint(0);
	int playerPoint(0);
	int dealerValue(0);
	int playerValue(0);
	//Dealer gets one card
	dealerValue += getCardValue(*cardPtr++);
	std::cout << "Delaer draw one card. \nDealer's value is now " << dealerValue << "\n";
	//Player gets two cards 
	playerValue += getCardValue(*cardPtr++);
	playerValue += getCardValue(*cardPtr++);
	//Player's turn
	std::cout << "Delaer draw two cards. \nYour value is now " << playerValue << "\n";
	while (playerValue <= 21)
	{
		char playerChoice;
		playerChoice = getPlayerInput();
		if (playerChoice == 'h')
		{
			playerValue += getCardValue(*cardPtr++);
			std::cout << "You get one card and your value is now " << playerValue << "\n";
			if (playerValue > 21)
			{
				//busted,and lose.Return false
				std::cout << "You bust, Gameover \n";
				return false;
			}
		}
		if (playerChoice == 's')
		{
			std::cout << "You choose to stand and your value is now " << playerValue << "\n";
			break;
		}
	}

	//Dealer's turn
	std::cout << "Now dealer is playing \n";
	while (dealerValue < 17)
	{
		std::cout << "Dealer chose to hits another card! \n";
		dealerValue += getCardValue(*cardPtr++);
		if (dealerValue > 21)
		{
			std::cout << "dealer's value is now " << dealerValue << ". He busted. You won! \n";
			return true;
		}
	}
	std::cout << "Dealer stands. Now compare. \n";
	//both's turns done.Now compare
	std::cout << "Dealer's final value is now " << dealerValue << "\n";
	std::cout << "Player's final value is now " << playerValue << "\n";
	if (playerValue > dealerValue)
	{
		std::cout << "You won! \n";
		return true;
	}
	else if (playerValue < dealerValue)
	{
		std::cout << "You lost.Good luck next time! \n";
		return false;
	}
	else if (playerValue == dealerValue)
	{
		std::cout << "You draw!What a game. \n";
		return false;
	}
}