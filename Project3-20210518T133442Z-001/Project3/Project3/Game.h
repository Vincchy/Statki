#pragma once
#include "Ship.h"

// -------------------- Game class --------------------
class Game
{
public:
    // Default constructor
    Game();

    void PlaceShip(const ShipType& _type, const Orientation& _orientation, const unsigned short& _xPos, const unsigned short& _yPos);
    inline bool IsPlaying() const { return IsPlaying; }
    void DrawPlayerMap() const;
    void DrawAIMap() const;

    // Game boards
    Ship m_AIShips[10];
    Ship m_PlayerShips[10];

private:
    // How many ships of given type are left
    unsigned short m_OneLeft = 4;
    unsigned short m_DoubleLeft = 3;
    unsigned short m_TripleLeft = 2;
    unsigned short m_QuadLeft = 1;

    // Used for accessing the m_PlayerShips[] array
    unsigned short m_LastPlacedShip = 0;

    // Game state bool
    bool IsPlaying = true;

    // Private methods used for placing the ships
    void PlaceOneMasted(const unsigned short& _xPos, const unsigned short& _yPos);
    void PlaceDoubleMasted(const unsigned short& _xPos, const unsigned short& _yPos);
    void PlaceTripleMasted(const unsigned short& _xPos, const unsigned short& _yPos);
    void PlaceQuadMasted(const unsigned short& _xPos, const unsigned short& _yPos);
};