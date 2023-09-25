#pragma once

#include "raylib.h"
#include <vector>

class Card;
class GameManager;

class PlayerState
{
public:
    PlayerState();

    void InitializePlayer();
    void DrawCard(Card& card, std::vector<std::vector<Card*>>& playerMiddleCards, std::vector<Card*>& weatherCards, GameManager& gManager, bool& turn);
};