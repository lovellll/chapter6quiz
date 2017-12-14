#pragma once
#include "stdafx.h"
#include <array>
#include <vector>

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

int getCardValue(const Cards & card, bool isAce_11);

char getPlayerInput();

void drawCard(std::vector<Cards>& hands, const Cards *& cardPtr);

int calcHands(const std::vector<Cards>& hands);

int betCredit();

int playBlackjack(const Cards * cardPtr);


