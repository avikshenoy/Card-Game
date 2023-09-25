
~~~~~~~~~ Simplified Gwent by Avik Shenoy ~~~~~~~~~

This card game is a simplified version of Gwent, the card game from the famous Witcher series.

This card game took me a total of about 27 hours to create. I tried to go above and beyond for this assessment.

Programmed using C++ with raylib framework for rendering images to window.

All artwork is from the game Witcher 3: Wild Hunt.

INSTALLATION AND SETUP (MUST READ):

1. Install Visual Studio Code
2. In VSCode, go to Extensions -> search for "C/C++" -> install the first result (by C/C++ Microsoft).
3. Download raylib (https://www.raylib.com/). raylib is necessary to run the code.
4. Download raylib 4.5 Windows Installer (with MinGW compiler).
5. Run raylib installer. Windows may warn you about the file, click run anyway.
6. Open VSCode, file -> open workspace from file -> select "main.code-workspace" in the card game directory.

You should be able to run the code now.

GAME RULES:

This is a two player game (player and AI).

There are 20 unique cards in a deck. Each card has a name, description, power level, and unit. Each player gets 10 cards from the deck.

A card's name and description are for personality/identification. The power level indicates how strong the card is (higher, the better).
The unit determines where on the board the card is placed. There is a row for infantry, ranged, and siege. Each player has their own infantry,
ranged, and siege rows. There are also weather cards that effect both sides of the board.

The player can draw any of their 10 cards first. After the player draws a card, the enemy AI will place down their own card. The total power level
for each row is summed to the left of each row. The grand total of all rows is displayed to the far left for each player.

The game ends when all 20 cards are placed on the board. Whoever has the highest grand total at the end of the game wins.

The game is simplified from the original Gwent card game. The original Gwent is a best of 2 where you can pass your turns to save your cards for the
next round. In addition, the original Gwent cards have special effects.