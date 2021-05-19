#include "Researcher.hpp"
using namespace pandemic;

Researcher& Researcher::discover_cure(pandemic::Color color){
    bool cure = this->board.get_madicines(color);

    int count = 0;
    for (auto itr: this->cards)
    {
        if (this->board.get_board()[itr].get_Color() == color)
        {
            count++;
        }
    }

    if (count < curr_card)
    {
        throw std::invalid_argument{" not enough cards"};
    }
    if (!cure)
    {
            count = curr_card;
            for ( auto itr = this->cards.begin(); itr != this->cards.end() && count > 0;)
            {
                if (this->board.get_board()[*itr].get_Color() == color)
                {
                    itr = this->cards.erase(itr);
                    count--;
                }
                else
                {
                    ++itr;
                }
            }
            this->board.set_madicines(color, true);
        }
    


    return *this;
}

string Researcher::role()
{
    
    string st ="Researcher";
    return st;
}