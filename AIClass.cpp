#include "AIClass.h"
#include "GameManager.h"
#include "Card.h"
#include <cstdlib>

AIClass::AIClass()
{}

void AIClass::ChooseCard(bool& playerTurn, GameManager& gManager, std::vector<std::vector<Card*>>& enemyMiddleCards, std::vector<Card>& enemyCards, std::vector<Card*>& weatherCards, std::vector<int>& availableIndices, int& rounds, int& playerGrandTotal, int& enemyGrandTotal)
{
    if (playerTurn == false && availableIndices.size() > 0)
    {
        PredictPlayerMove(playerGrandTotal, enemyGrandTotal);

        // Picks a random card to place on board. In a more complex build, the AI would choose a specific card based on player behavior
        int randomAvailableIndex = std::rand() % availableIndices.size();
        int randomCardIndex = availableIndices[randomAvailableIndex];
        Card& randomCard = enemyCards[randomCardIndex];
        availableIndices.erase(availableIndices.begin() + randomAvailableIndex);
        randomCard.isRemoved = true;

        switch (randomCard.GetUnit()) 
        {
        case Card::unit::infantry:
            enemyMiddleCards[0].push_back(&randomCard);
            break;
        case Card::unit::ranged:
            enemyMiddleCards[1].push_back(&randomCard);
            break;
        case Card::unit::siege:
            enemyMiddleCards[2].push_back(&randomCard);
            break;
        case Card::unit::weather:
            weatherCards.push_back(&randomCard);
            break;
        }

        playerTurn = true;
        rounds++;
    }
}

void AIClass::PredictPlayerMove(int& playerGrandTotal, int& enemyGrandTotal)
{
    if (EvaluateBoard(playerGrandTotal, enemyGrandTotal)) // if in advantage state...
    {
        // Perform a risky move (pass a turn, place a low power level card, etc.)
    }
    else
    {
        // Play desperately/defensively (place high power level cards)
    }
}

bool AIClass::EvaluateBoard(int& playerGrandTotal, int& enemyGrandTotal)
{
    if (playerGrandTotal < enemyGrandTotal)
    {
        return true; // true means that enemy is in advantage state
    }
    else
    {
        return false; // false means that enemy is in disadvantage state
    }
}