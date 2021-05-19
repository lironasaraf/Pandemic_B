#include "GeneSplicer.hpp"
using namespace pandemic;

GeneSplicer &GeneSplicer::discover_cure(pandemic::Color color)
{
    bool researches = this->board.get_board()[this->curr_city].get_Station();
    if (!researches)
    
    {throw std::invalid_argument{"no research station"};
    }

    bool iscure = this->board.get_madicines(color);
    int counter_cards = this->cards.size();

    if (counter_cards < curr_card)
    {
        throw std::invalid_argument{"not enough cards"}; }
        if (!iscure)
        {
            counter_cards = curr_card;
            for (auto itr = this->cards.begin(); itr != this->cards.end() && counter_cards > 0;)
            {
                itr = this->cards.erase(itr);
                counter_cards--;
            }
            this->board.set_madicines(color, true);
        }


    return *this;
}





string GeneSplicer::role()
{
    return this->vox;
}