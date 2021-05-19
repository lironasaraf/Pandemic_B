#include "Medic.hpp"
using namespace pandemic;

Medic &Medic::treat(pandemic::City city)
{
    if (this->curr_city != city)
    {throw std::invalid_argument{" you're not in the current city"};}

    if (this->board[city] == 0)
    {throw std::invalid_argument{" this city is not sick"};}
    this->board[city] = 0;

    return *this;
}

Medic &Medic::drive(pandemic::City city)
{
    Player::drive(city);
    pandemic::Color col = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(col))
    {this->board[city] = 0; }
    return *this;
}

Medic &Medic::fly_direct(pandemic::City city)
{
    Player::fly_direct(city);
    pandemic::Color col = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(col))
    {this->board[city] = 0; }
    return *this;
}

Medic &Medic::fly_charter(pandemic::City city)
{
    Player::fly_charter(city);
    pandemic::Color col = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(col))
    {this->board[city] = 0;}
    return *this;
}

Medic &Medic::fly_shuttle(pandemic::City city)
{
    Player::fly_shuttle(city);
    pandemic::Color col = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(col))
    {this->board[city] = 0;}
    return *this;
}

string Medic::role()
{
    string st= "Medic";
    return st;
}