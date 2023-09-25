#include "PlayerState.h"
#include "card.h"
#include "GameManager.h"

PlayerState::PlayerState()
{}

void PlayerState::InitializePlayer()
{
    // Set up inital player values
}

void PlayerState::DrawCard(Card& card, std::vector<std::vector<Card*>>& playerMiddleCards, std::vector<Card*>& weatherCards, GameManager& gManager, bool& turn)
{
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) 
    {
        card.isRemoved = true;
        turn = false;

        // When player clicks on a card, this switch statement checks the card's unit so that it can be inserted into the correct row in the multi-dimensional array (middlePlayerCards).
        switch (card.GetUnit()) 
        {
            case Card::unit::infantry:
                playerMiddleCards[0].push_back(&card);
                break;
            case Card::unit::ranged:
                playerMiddleCards[1].push_back(&card);
                break;
            case Card::unit::siege:
                playerMiddleCards[2].push_back(&card);
                break;
            case Card::unit::weather:
                weatherCards.push_back(&card);
                break;
        }
    }
}