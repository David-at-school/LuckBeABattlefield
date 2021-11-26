#pragma once

class Card {
	
public:
	Card() : number{ 0 } {};
	Card(int number) : number{ number } {};

	/// <summary>
	/// Used to check if the other card is currently higher or lower then the other number
	/// </summary>
	/// <param name="other">The Card you would like to check against</param>
	/// <returns>Returns if the number is higher </returns>
	bool isHigher(Card other);

	/// <summary>
	/// Used to check if the other card is equal to this card
	/// </summary>
	/// <param name="other">The other card you would like to check against</param>
	/// <returns>If it's equal to the number or not</returns>
	bool isEqual(Card other);

	int number;
private:


};