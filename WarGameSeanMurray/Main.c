#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define TOTAL_CARDS 52
#define CARDS_PER_PLAYER 13
#define MAX_PLAYERS 4

typedef struct {
	char* rank;
	char* suit;
} Card;


void createDeck(Card* deck) {
	int position = 0;
	char* ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
	char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[position].rank = ranks[j];
			deck[position].suit = suits[i];
			position++;
		}
	}
}

int main()
{
	// Create array
	Card deck[TOTAL_CARDS];

	// Initialise the deck
	createDeck(deck);

	// Test to make sure deck is created
	for (int i = 0; i < TOTAL_CARDS; i++) {
		printf("%s of %s\n", deck[i].rank, deck[i].suit);
	}

	return 0;
}


