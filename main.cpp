#include "raylib.h"
#include "Card.h"
#include "PlayerState.h"
#include "GameManager.h"
#include "Duel.h"
#include "AIClass.h"
#include "iostream"
#include <vector>
#include <algorithm>
#include <random> 
#include <cstdlib>

int main()
{
    const int screenWidth{1200};
    const int screenHeight{900};

    // Window dimensions
    InitWindow(screenWidth, screenHeight, "Simplified Gwent");

    // Construct classes
    GameManager gameManager;
    Duel duel;
    PlayerState player;
    AIClass enemy;

    // Player can input when true
    bool playerTurn { true };

    // increments by 1 every turn
    int rounds { 1 };

    // Construct cards
    Card card1 {"Geralt", "'If that's what it takes to save \nthe world, it's better to let it die.'.", 15, Card::unit::infantry, LoadTexture("Card/Geralt.png")};
    Card card2 {"Ciri", "'Know when fairy tales cease to be \ntales?, When people believe them.'", 15, Card::unit::infantry, LoadTexture("Card/Ciri.png")};
    Card card3 {"Yennefer", "'Magic is Chaos, Art, and Science.\n'", 7, Card::unit::ranged, LoadTexture("Card/Yennefer.png")};
    Card card4 {"Triss", "'I can take care of myself. Trust me.'", 7, Card::unit::ranged, LoadTexture("Card/Triss.png")};
    Card card5 {"Crinfrid", "'Haven't had much luck with monsters\n of late, so we enlisted.'", 5, Card::unit::infantry, LoadTexture("Card/Crinfrid.png")};
    Card card6 {"Dandelion", "'Dandelion, you're a cynic and liar\n - and my best friend.'", 2, Card::unit::ranged, LoadTexture("Card/Dandelion.png")};
    Card card7 {"Clear Weather", "'The sun's shinin', Dromle!'", 5, Card::unit::weather, LoadTexture("Card/Clear.png")};
    Card card8 {"Dethmold", "'I once made a prisoner vomit his own \nentrails... Ah, good times...'", 6, Card::unit::siege, LoadTexture("Card/Dethmold.png")};
    Card card9 {"Keira", "'If I'm to die today, I wish to look \n smashing for the occasion.'", 5, Card::unit::siege, LoadTexture("Card/Keira.png")};
    Card card10 {"Roche", "'A patriot... and a real son of a dog.'", 10, Card::unit::ranged, LoadTexture("Card/Roche.png")};
    Card card11 {"Sabrina", "'The Daughter of the Kaedweni \n Wilderness.'", 4, Card::unit::siege, LoadTexture("Card/Sabrina.png")};
    Card card12 {"Siegfried", "'We're on the same side, witcher. \nYou'll realize this one day.'", 5, Card::unit::siege, LoadTexture("Card/Siegfried.png")};
    Card card13 {"Sile", "'The lodge lacks humility.'", 5, Card::unit::infantry, LoadTexture("Card/Sile.png")};
    Card card14 {"Stennis", "'He ploughin' wears golden armor. \nGolden. 'Course he's an a-hole.'", 5, Card::unit::infantry, LoadTexture("Card/Stennis.png")};
    Card card15 {"Ves", "'Better to live one day as a king then\n a whole life as a begger.'", 5, Card::unit::ranged, LoadTexture("Card/Ves.png")};
    Card card16 {"Vesemir", "If you're to be hanged, as for water.", 6, Card::unit::infantry, LoadTexture("Card/Vesemir.png")};
    Card card17 {"Zoltan", "'Life without old mates and booze sucks.'", 5, Card::unit::siege, LoadTexture("Card/Zoltan.png")};
    Card card18 {"Fog", "'A good commander's dream... a bad one's\n horror'", -5, Card::unit::weather, LoadTexture("Card/Fog.png")};
    Card card19 {"Frost", "Cold!", -10, Card::unit::weather, LoadTexture("Card/Frost.png")};
    Card card20 {"King Foltest", "The king!", 10, Card::unit::weather, LoadTexture("Card/Foltest.png")};

    // All cards vector
    std::vector<Card> allCards = 
    {
        card1, card2, card3, card4, card5, card6, card7, card8, card9, card10,
        card11, card12, card13, card14, card15, card16, card17, card18, card19, card20
    };

    gameManager.InitializeGame(allCards);

    // Assign the cards
    std::vector<Card> playerCards(allCards.begin(), allCards.begin() + 10);
    std::vector<Card> enemyCards(allCards.begin() + 10, allCards.end());

    std::cout << "Vector a: ";
    for (Card& card : allCards) {
        std::cout << card.GetName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector b: ";
    for (Card& card : playerCards) {
        std::cout << card.GetName() << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector c: ";
    for (Card& card : enemyCards) {
        std::cout << card.GetName() << " ";
    }
    std::cout << std::endl;

    std::vector<int> availableIndices { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::vector<std::vector<Card*>> playerMiddleCards(3);
    std::vector<std::vector<Card*>> enemyMiddleCards(3);

    std::vector<Card*> weatherCards;

    gameManager.StartDuel();
    player.InitializePlayer();

    Texture2D board = LoadTexture("Card/board_.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BROWN);

        DrawTexture(board, 0.0, 0.0, WHITE);

        int cardWidth = playerCards[0].GetTexture().width;
        int cardHeight = playerCards[0].GetTexture().height;
        int middleCardHeight = cardHeight / 2;

        int playerDenominator { 2 };
        int enemyDenominator { 9 };

        int playerGrandTotal { 0 };
        int enemyGrandTotal { 0 };

        std::vector<int> playerPowerTotals(3, 0);  
        std::vector<int> enemyPowerTotals(3, 0);  

        int attributesX = 10 * cardWidth + 5; // 10 cards * width of each card + a small gap

        // Render player hand
        duel.RenderPlayerHand(playerCards, weatherCards, playerMiddleCards, gameManager, player, screenWidth, screenHeight, attributesX, cardWidth, cardHeight, playerTurn);

        // render player board cards
        duel.RenderBoardCards(playerMiddleCards, weatherCards, gameManager, screenWidth, screenHeight, attributesX, cardWidth, cardHeight, playerDenominator, playerGrandTotal, playerPowerTotals);

        // Render enemy board cards
        duel.RenderBoardCards(enemyMiddleCards, weatherCards, gameManager, screenWidth, screenHeight, attributesX, cardWidth, cardHeight, enemyDenominator, enemyGrandTotal, enemyPowerTotals);

        // Render weather cards
        duel.RenderWeatherCards(weatherCards, gameManager, player, screenWidth, screenHeight, attributesX, cardWidth, cardHeight);

        // enemy chooses card
        enemy.ChooseCard(playerTurn, gameManager, enemyMiddleCards, enemyCards, weatherCards, availableIndices, rounds, playerGrandTotal, enemyGrandTotal);

        int playerMiddleRowY = (screenHeight / playerDenominator) + 18; 
        int enemyMiddleRowY = (screenHeight / enemyDenominator) + 18; 

        // Render grand total
        DrawText((std::to_string(playerGrandTotal)).c_str(), 125, playerMiddleRowY + middleCardHeight / 2 + 30, 30, WHITE);
        DrawText((std::to_string(enemyGrandTotal)).c_str(), 125, enemyMiddleRowY + middleCardHeight / 2 - 40, 30, WHITE);

        // End game condition
        if (rounds > 10)
        {
            gameManager.EndDuel(playerGrandTotal, enemyGrandTotal, screenHeight, screenWidth);
        }

        EndDrawing();
    }

    CloseWindow();
}