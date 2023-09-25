#include "Card.h"
#include "iostream"

Card::Card(const std::string& nam, const std::string& des, int powlev, unit uni, Texture2D tex) :
    name(nam),
    description(des),
    powerLevel(powlev),
    cardUnit(uni),
    texture(tex)
{
    width = texture.width;
    height = texture.height;
}

std::string Card::UnitToString(unit uni)
{
    // Converts enum unit to string
    switch (uni) 
    {
        case unit::infantry: return "Infantry";
        case unit::ranged: return "Ranged";
        case unit::siege: return "Siege";
        case unit::weather: return "Weather";
        default: return "Unknown";
    }
}
