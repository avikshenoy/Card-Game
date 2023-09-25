#pragma once

#include "raylib.h"
#include <vector>

class GameManager;
class Card;

class AIClass
{
public:
    AIClass();

    void ChooseCard(bool& playerTurn, GameManager& gManager, std::vector<std::vector<Card*>>& enemyMiddleCards, std::vector<Card>& enemyCards, std::vector<Card*>& weatherCards, std::vector<int>& availableIndices, int& rounds, int& playerGrandTotal, int& enemyGrandTotal);
    void PredictPlayerMove(int& playerGrandTotal, int& enemyGrandTotal);
    bool EvaluateBoard(int& playerGrandTotal, int& enemyGrandTotal);
};