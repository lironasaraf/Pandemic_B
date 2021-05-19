#include "Virologist.hpp"
using namespace pandemic;

Virologist& Virologist::treat(City city){
    auto card = find(this->cards.begin(), this->cards.end(), city);
    if (this->curr_city != city && (card == this->cards.end()))
    {
     throw std::invalid_argument{" not the same card of the city"}; }
    

    if (this->board[city] == 0)
    { throw std::invalid_argument{" no sick at this place"}; }
    

    pandemic::Color col = this->board.get_board()[city].get_Color();
    if (this->board.get_madicines(col))
    {
        this->board[city] = 0;
    }
    else
    {
        this->board[city]--;
    }
    
    if (this->curr_city != city)
    {
        this->cards.erase(card);
    }

    return *this;
}

string Virologist::role()
{
    string st="Virologist";
    return st;
}