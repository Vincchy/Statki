#include "Ship.h"
#include <iostream>

using namespace std;

Ship::Ship(ShipType type, Orientation _orientation, bool _isPlayer)
    : m_Type(type), m_Orientation(_orientation)
{
    if (_isPlayer)
    {
        std::cout << "Player's ship placed.\n";
        askForInput();
        placeShip(x, y);
    }
}

Ship::Ship() {}

void Ship::askForInput()
{
    cout << "Enter a column between 1 and 10 ";
    cin >> x;
    x--;
    cout << "Enter a row between 1 and 10: ";
    cin >> y;
    cout << "Enter in an orientation - 1 for vertical, 0 for horizontal: ";
    bool _orientation;
    cin >> _orientation;

    if (_orientation)
        m_Orientation = Orientation::VERTICAL;
    else
        m_Orientation = Orientation::HORIZONTAL;
}



bool Ship::placeShip(int _x, int _y) //returns true if successful
{
    x = _x;
    y = _y;

    if (!ifInBounds(x, y))
    {
        cout << "Not in bounds!!!\n";
        return false;
    }

    //int _y = y, _x = x;
    if (m_Orientation == Orientation::VERTICAL)
    {
        // Checking if the ship position is valid
        // Returns if not
        for (int i = 0; i < (int)m_Type; i++)
        {
            if (ifInBounds(x, _y))
            {
                if (!overlapsShip(x, _y))
                {
                     _y--;
                }
                else
                {
                    //cout << "OVERLAPPING\n";
                    return false;
                }
            }
            else
            {
                   return false;
            }
        }

        for (int i = 0; i < (int)m_Type; i++)
        {
            m_PlayerBoard[x][y--] = BoardSpace::OCCUPIED;
        }
    }
    else
    {
        for (int i = 0; i < (int)m_Type; i++)
        {
            if (ifInBounds(_x, y) && !overlapsShip(_x, y))
            {
                _x++;
            }
            else
            {
                //cout << "Wrong Input!!!\n";
                return false;
            }
        }

        for (int i = 0; i < (int)m_Type; i++)
        {
            m_PlayerBoard[x--][y] = BoardSpace::OCCUPIED;
        }

    }
}

bool Ship::ifInBounds(int _x, int _y)
{
    if (_x > 9 || _x < 0 || _y>9 || _y < 0)
    {
        return false;
    }
    return true;
}

bool Ship::overlapsShip(int _x, int _y)
{
    if (m_PlayerBoard[x][y] == BoardSpace::OCCUPIED)
    {
        return true;
    }
    return false;
}