#pragma once

#include "raylib.h"
#include <vector>

class Card;
class GameManager;
class PlayerState;

class Duel
{
public:
    Duel();

    void InitalizeDuel();
    void ExecuteTurn();
    void RenderPlayerHand(std::vector<Card>& playerCards, std::vector<Card*>& weatherCards, std::vector<std::vector<Card*>>& playerMiddleCards, GameManager& gameManager, PlayerState& player, int screenWidth, int screenHeight, int attributesX, int cardWidth, int cardHeight, bool& turn);
    void RenderBoardCards(std::vector<std::vector<Card*>>& boardCards, std::vector<Card*>& weatherCards, GameManager& gManager, int screenWidth, int screenHeight, int attributesX, int cardWidth, int cardHeight, int denominator, int& grandTotal, std::vector<int>& powerTotals);
    void RenderWeatherCards(std::vector<Card*>& weatherCards, GameManager& gManager, PlayerState player, int screenWidth, int screenHeight, int attributesX, int cardWidth, int cardHeight);
    void RenderAttributes(Card& card, int attributesX, int screenHeight);
    void CalculatePowerTotals(std::vector<int>& powerTotals, std::vector<std::vector<Card*>>& boardCards);
    void CalculateGrandTotal(int& grandTotal, std::vector<int>& powerTotals, std::vector<Card*>& weatherCards);

private:
    // If true, player's turn. If false, AI's turn
    bool turn { true };

public:
    bool GetTurn() { return turn; }
    void SetTurn(bool value) { turn = value; }
};