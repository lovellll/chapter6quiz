#pragma once
#include "stdafx.h"
#include <array>

enum class Ranks
{
	RANK2,
	RANK3,
	RANK4,
	RANK5,
	RANK6,
	RANK7,
	RANK8,
	RANK9,
	RANK10,
	JACK,
	QUEEN,
	KING,
	ACE,

};

enum class Suits
{
	CLUB,
	DIAMOND,
	HEART,
	SPADES,
};

struct Cards
{
	Ranks rank;
	Suits suit;
};



void printCard(Cards & card);

void initializeCards(std::array<Cards, 52>& deckCards);

void printDeck(const std::array<Cards, 52>& deckCards);

void swapCards(Cards & card1, Cards & card2);

int getRandomNumber(int min, int max);

void shuffleDeck(std::array<Cards, 52>& deckCards);

int getCardValue(const Cards & card);

char getPlayerInput();

bool playBlackjack(const Cards * cardPtr);

