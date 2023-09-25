#include "raylib.h"
#include <string>

class Card
{
public:
    enum class unit
    {
        infantry,
        ranged,
        siege,
        weather
    };

    Card(const std::string& nam, const std::string& des, int powlev, unit uni, Texture2D tex);
    
    std::string UnitToString(unit uni);
    bool isRemoved {false};

private:
    std::string name{};
    std::string description{};
    int powerLevel{};
    unit cardUnit{};
    Texture2D texture{};
    
    int width{};
    int height{};

public:
    std::string GetName() { return name; }
    std::string GetDescription() { return description; }
    int GetPowerLevel() { return powerLevel; }
    unit GetUnit() { return cardUnit; }
    Texture2D GetTexture() { return texture; }
    int GetCardWidth() { return width; }
    int GetCardHeight() { return height; }
};