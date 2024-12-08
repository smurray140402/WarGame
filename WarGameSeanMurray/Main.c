#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define TOTAL_CARDS 52
#define CARDS_PER_PLAYER 13
#define MAX_PLAYERS 4

// Structure that represents a card with a rank and suit.
// "rank" is a pointer to a string representing the card's value 
// "suit" is a pointer to a string representing the card's suit.
typedef struct {
	char* rank;
	char* suit;
} Card;

// Function to create the deck
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

// Function to shuffle the deck
void shuffleDeck(Card* deck) {
	// Seed the random number generator so each run creates a unique shuffled deck
	srand(time(NULL));
	for (int i = 0; i < TOTAL_CARDS; i++) {
		int randomPosition = rand() % TOTAL_CARDS;

		// Swap the current card with the card at randomPosition
		Card tempCard = deck[i];
		deck[i] = deck[randomPosition];
		deck[randomPosition] = tempCard;
	}
}

// Distributes 13 unique cards to each player
void distributeCards(Card* deck, Card players[MAX_PLAYERS][CARDS_PER_PLAYER], int numPlayers) {
	int cardPosition = 0;
	for (int i = 0; i < numPlayers; i++) {
		printf("\nPlayer %d\n", i + 1);
		for (int j = 0; j < CARDS_PER_PLAYER; j++) {
			players[i][j] = deck[cardPosition];
			printf("%s of %s\n", players[i][j].rank, players[i][j].suit);
			cardPosition++;
		}
	}

	// Test distribute function
	printf("\nPlayer two's 3rd card is %s of %s\n", players[1][2].rank, players[1][2].suit);
}

int main()
{
	// Variables
	int numPlayers;

	// Create arrays
	Card deck[TOTAL_CARDS];
	Card players[MAX_PLAYERS][CARDS_PER_PLAYER];

	// Initialise the deck
	createDeck(deck);

	// Shuffle the deck
	shuffleDeck(deck);

	// Prompt and read user input
	printf("Enter the number of players (2-4): ");
	scanf("%d", &numPlayers);

	if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
		printf("Invalid number of players. Please choose between 2 and 4 players.\n");
		return 1;
	}

	// Give each player 13 cards
	distributeCards(deck, players, numPlayers);

	return 0;
}


