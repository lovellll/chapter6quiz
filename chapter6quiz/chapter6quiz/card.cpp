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