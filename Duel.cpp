#include "Duel.h"
#include "Card.h"
#include "GameManager.h"
#include "PlayerState.h"

Duel::Duel()
{}

void Duel::InitalizeDuel()
{
    // If I had time to implement an actual round-based system, InitializeDuel() would be called at the beginning of every round to start the duel. 
    // This function would basically serve as a clean up function, resetting the middle cards, grand totals, and values.
}

void Duel::RenderAttributes(Card& card, int attributesX, int screenHeight)
{
    // Renders card's attributes at bottom right of screen
    DrawText(card.GetName().c_str(), attributesX, screenHeight - 175, 20, WHITE);
    DrawText(card.GetDescription().c_str(), attributesX, screenHeight - 130, 10, WHITE);
    DrawText(("Power: " + std::to_string(card.GetPowerLevel())).c_str(), attributesX, screenHeight - 70, 20, WHITE);
    DrawText(card.UnitToString(card.GetUnit()).c_str(), attributesX, screenHeight - 40, 20, WHITE);
}

void Duel::RenderPlayerHand(std::vector<Card>& playerCards, std::vector<Card*>& weatherCards, std::vector<std::vector<Card*>>& playerMiddleCards, GameManager& gameManager, PlayerState& player, int screenWidth, int screenHeight, int attributesX, int cardWidth, int cardHeight, bool& turn)
{
    int x_offset = 0;

    for (Card &card : playerCards)
    {
        if (card.isRemoved) continue;

        int x = x_offset * cardWidth;
        int y = screenHeight - cardHeight;
        x_offset++;

        DrawTexture(card.GetTexture(), x, y, WHITE);

        // When hovering over a card in player hand:
        if (CheckCollisionPointRec(GetMousePosition(), { (float)x, (float)y, (float)cardWidth, (float)cardHeight })) 
        {
            RenderAttributes(card, attributesX, screenHeight);

            player.DrawCard(card, playerMiddleCards, weatherCards, gameManager, turn);
        }
    }
}

void Duel::CalculatePowerTotals(std::vector<int>& powerTotals, std::vector<std::vector<Card*>>& boardCards)
{
    for (int i = 0; i < 3; i++) 
    {
        for (Card* card : boardCards[i]) 
        {
            powerTotals[i] += card->GetPowerLevel();
        }
    }
}

void Duel::CalculateGrandTotal(int& grandTotal, std::vector<int>& powerTotals, std::vector<Card*>& weatherCards)
{
    for (int total : powerTotals) 
    {
        grandTotal += total;
    }

    for (Card* card : weatherCards)
    {
        grandTotal += card->GetPowerLevel();
    }
}

void Duel::RenderBoardCards(std::vector<std::vector<Card*>>& boardCards, std::vector<Card*>& weatherCards, GameManager& gManager, int screenWidth, int screenHeight, int attributesX, int cardWidth, int cardHeight, int denominator, int& grandTotal, std::vector<int>& powerTotals)
{
    int middleCardWidth = cardWidth / 2;
    int middleCardHeight = cardHeight / 2;

    CalculatePowerTotals(powerTotals, boardCards);

    CalculateGrandTotal(grandTotal, powerTotals, weatherCards);

    int startX = screenWidth / 2 - (boardCards[0].size() * middleCardWidth) / 2;

    for (int i = 0; i < 3; i++) 
    {
        int middleX = startX;    
        int y;

        switch(i) {
            case 0: // infantry
                y = (screenHeight / denominator) - (middleCardHeight) + 10;
                break;
            case 1: // ranged
                y = (screenHeight / denominator) + 23;
                break;
            default: // siege
                y = (screenHeight / denominator) + (middleCardHeight) + 40;
        }

        for (Card* card : boardCards[i])
        {
            Rectangle sourceRec = { 0, 0, (float)cardWidth, (float)cardHeight };
            Rectangle destRec = { (float)middleX, (float)y, (float)middleCardWidth, (float)middleCardHeight };

            DrawTexturePro(card->GetTexture(), sourceRec, destRec, { 0, 0 }, 0.0f, WHITE);
            DrawText((std::to_string(powerTotals[i])).c_str(), 440, y + middleCardHeight/2 - 5, 30, WHITE);

            // When hovering over a middle card:
            if (CheckCollisionPointRec(GetMousePosition(), { (float)middleX, (float)y, (float)middleCardWidth, (float)middleCardHeight })) 
            {
                RenderAttributes(*card, attributesX, screenHeight);
            }

            middleX += middleCardWidth;
        }
    }
}

void Duel::RenderWeatherCards(std::vector<Card*>& weatherCards, GameManager& gManager, PlayerState player, int screenWidth, int screenHeight, int attributesX, int cardWidth, int cardHeight)
{
    int middleCardWidth = cardWidth / 2;
    int middleCardHeight = cardHeight / 2;

    int weatherXStart = 10;
    int weatherX = weatherXStart + 40; 
    int weatherY = screenHeight / 2 - middleCardHeight / 2 - 105;

    for (Card* card : weatherCards) {
        Rectangle sourceRec = { 0, 0, (float)cardWidth, (float)cardHeight };
        Rectangle destRec = { (float)weatherX, (float)weatherY, (float)middleCardWidth, (float)middleCardHeight };
        DrawTexturePro(card->GetTexture(), sourceRec, destRec, { 0, 0 }, 0.0f, WHITE);

        // When hovering over a weather card:
        if (CheckCollisionPointRec(GetMousePosition(), { (float)weatherX, (float)weatherY, (float)middleCardWidth, (float)middleCardHeight })) 
        {
            RenderAttributes(*card, attributesX, screenHeight);
        }

        weatherX += middleCardWidth;
    }
}

void Duel::ExecuteTurn()
{
    // Called in between player and AI turns
}