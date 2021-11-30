#include "Card.h"

bool Card::isHigher(Card other) {
	if (this->number < other.number)
		return false;
	return true;
}

bool Card::isEqual(Card other)
{
	if (this->number == other.number)
		return true;
	return false;
}