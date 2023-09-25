#pragma once

#include "raylib.h"
#include <vector>

class Card;

class GameManager
{
public:
    GameManager();

    void InitializeGame(std::vector<Card>& allCards);
    void ShuffleDeck(std::vector<Card>& allCards);
    void StartDuel();
    void EndDuel(int playerGrandTotal, int enemyGrandTotal, int screenHeight, int screenWidth);
};