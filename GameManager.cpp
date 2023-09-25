#include "GameManager.h"
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>

GameManager::GameManager()
{
}

void GameManager::InitializeGame(std::vector<Card>& allCards)
{
    ShuffleDeck(allCards);
}

void GameManager::ShuffleDeck(std::vector<Card>& allCards)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(allCards.begin(), allCards.end(), g);
}

void GameManager::StartDuel()
{
    // Called at the beginning to start the game.
    // Set initial values.
}

void GameManager::EndDuel(int playerGrandTotal, int enemyGrandTotal, int screenHeight, int screenWidth)
{

    if (playerGrandTotal > enemyGrandTotal)
    {
        DrawText("Player Wins!", screenWidth/4 + 90, screenHeight/2 - 120, 50, GREEN);
    }
    else
    {
        DrawText("Enemy Wins!", screenWidth/4 + 90, screenHeight/2 - 120, 50, RED);
    }
}