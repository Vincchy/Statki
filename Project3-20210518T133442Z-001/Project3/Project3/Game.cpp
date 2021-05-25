#include <time.h>
#include "Game.h"

Game::Game()
{
    // Random initialization
    srand(time(NULL));

    for (unsigned short i = 0; i < 10; i++)
        for (unsigned short j = 0; j < 10; j++)
            m_AIBoard[i][j] = BoardSpace::EMPTY;

    // AI ships initialization
    // Quad 
    m_AIShips[0] = Ship((ShipType)4, Orientation(rand() % 2), false);
    // Trzymasztowce
    for (unsigned short i = 1; i < 3; i++)
    {
        m_AIShips[i] = Ship((ShipType)3, Orientation(rand() % 2), false);
        while (!(m_AIShips[i].placeShip(rand() % 10, rand() % 10)));
    }
    // Dwumasztowiec
    for (unsigned short i = 3; i < 6; i++)
    {
        m_AIShips[i] = Ship((ShipType)2, Orientation(rand() % 2), false);
        while (!(m_AIShips[i].placeShip(rand() % 10, rand() % 10)));
    }
    // Jednomasztowiec
    for (unsigned short i = 6; i < 10; i++)
    {
        m_AIShips[i] = Ship((ShipType)1, Orientation(rand() % 2), false);
        while (!(m_AIShips[i].placeShip(rand() % 10, rand() % 10)));
    }
}

void Game::PlaceShip(const ShipType& _type, const Orientation& _orientation, const unsigned short& _xPos, const unsigned short& _yPos)
{
    m_PlayerShips[m_LastPlacedShip] = Ship(_type, _orientation, true); // TODO: TURN IT INTO POINTER ARRAY AND CALL "NEW"
}

void Game::DrawPlayerMap()
{
    for (unsigned int y = 0; y < 10; y++)
    {
        for (unsigned int x = 0; x < 10; x++)
        {
            if ()
                std::cout << "x";
            else
                std::cout << "o";
        }
        std::cout << std::endl;
    }
}

















#if 0
void Game::PlaceShip(const ShipType& _type, const unsigned short& _xPos, const unsigned short& _yPos)
{
    switch (_type)
    {
        // One masted ship placement
    case ShipType::ONE_MASTED:
        if (m_OneLeft > 0)
            PlaceOneMasted(_xPos, _yPos);
        else
            std::cout << "Can't place another one masted ship - limit reached.\n";
        break;
        // Double masted ship placement
    case ShipType::DOUBLE_MASTED:
        if (m_DoubleLeft > 0)
            PlaceDoubleMasted(_xPos, _yPos);
        else
            std::cout << "Can't place another one masted ship - limit reached.\n";
        break;
        // Triple masted ship placement
    case ShipType::TRIPLE_MASTED:
        if (m_TripleLeft > 0)
            PlaceTripleMasted(_xPos, _yPos);
        else
            std::cout << "Can't place another one masted ship - limit reached.\n";
        break;
        // Quad masted ship placement
    case ShipType::QUAD_MASTED:
        if (m_QuadLeft > 0)
            PlaceQuadMasted(_xPos, _yPos);
        else
            std::cout << "Can't place another one masted ship - limit reached.\n";
        break;
    }
}

// ---------------- Private methods ---------------
void Game::PlaceOneMasted(const unsigned short& _xPos, const unsigned short& _yPos)
{
    m_OneLeft--;
    m_PlayerShips[++m_LastPlacedShip] = Ship(ShipType::ONE_MASTED, Orientation::VERTICAL, true); // add ship rotation to every private method
    if (!m_PlayerShips[m_LastPlacedShip].placeShip(_xPos, _yPos))
        std::cout << "Failed to place ship.\n";
}

void Game::PlaceDoubleMasted(const unsigned short& _xPos, const unsigned short& _yPos)
{
    m_DoubleLeft--;
}

void Game::PlaceTripleMasted(const unsigned short& _xPos, const unsigned short& _yPos)
{
    m_TripleLeft--;
}

void Game::PlaceQuadMasted(const unsigned short& _xPos, const unsigned short& _yPos)
{
    m_QuadLeft--;
}
#endif