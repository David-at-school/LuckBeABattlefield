#include "Deck.h"
#include "Player.h"
#include "Battle.h"
#include <iostream>

int main(int argc, char** argv) {
	srand(time(NULL));
	Deck deck;
	Player p1(1, deck);
	Player p2(2, deck);
	std::cout << "Player " << battle2Players(p1, p2) << " WINS!" << std::endl;
}