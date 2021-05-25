#pragma once
#include <iostream>

using namespace std;

// -------------------- Enums --------------------
enum class Orientation
{
    VERTICAL,
    HORIZONTAL
};

enum class BoardSpace
{
    OCCUPIED,
    EMPTY,
    DESTROYED,
    SHOT
};

enum class ShipType
{
    ONE_MASTED = 1,
    DOUBLE_MASTED,
    TRIPLE_MASTED,
    QUAD_MASTED
};

static BoardSpace m_PlayerBoard[10][10];
static BoardSpace m_AIBoard[10][10];


// -------------------- Ship class --------------------
class Ship
{
public:
    Ship(ShipType type, Orientation _oritentation, bool _isPlayer);
    Ship();
    void askForInput();//const ShipType& type, int& x, int& y, Orientation& _orientation);
    bool placeShip(int _x, int _y);
    bool ifInBounds(int _x, int _y);
    bool overlapsShip(int _x, int _y);
    inline ShipType GetType() const { return m_Type; }

private:
    unsigned int x, y;
    ShipType m_Type;
    Orientation m_Orientation;
    unsigned int m_Health;
};
