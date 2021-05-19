
#include "Scientist.hpp"
using namespace pandemic;

Scientist& Scientist::discover_cure(pandemic::Color color){
    bool researches = this->board.get_board()[this->curr_city].get_Station();
    if (!researches)
    {
        throw std::invalid_argument{" no research station"};
    }

    bool iscure = this->board.get_madicines(color);
    int count = 0;
    for (auto itr : this->cards)
    {
        if (this->board.get_board()[itr].get_Color() == color)
        {count++;}
        
    }

    if (count < (this->n))
    { throw std::invalid_argument{" not enough cards"}; }
        if (!iscure)
        {
            count = this->n;
            for (auto itr = this->cards.begin(); itr != this->cards.end() && count > 0;)
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

string Scientist::role()
{
    string st = "Scientist";
    return st;
}
