#pragma once
#include "Card.h"
#include "Player.h"

/// <summary>
/// A Battle Between 2 Players
/// </summary>
/// <param name="player1">First Player in Battle</param>
/// <param name="player2">Second Player in Battle</param>
/// <param name="reversed">Checks to see if the battle is currently reversed</param>
/// <returns></returns>
int battle2Players(Player player1, Player player2, bool reversed = false);

/// <summary>
/// A Battle between all Players
/// </summary>
/// <param name="player1">First Player in Battle</param>
/// <param name="player2">Second Player in Battle</param>
/// <param name="player3">Third Player in Battle</param>
/// <param name="player4">Fourth Player in Battle</param>
/// <returns>ID of the winner</returns>
int battle4Players(Player player1, Player player2, Player player3, Player player4);