#include "Player.hpp"
using namespace pandemic;

Player &Player::drive(pandemic::City city)
{
    if (this->curr_city == city)
    {
        throw std::invalid_argument{" Current city is: " + to_string(city)};

    }

    list<pandemic::City> &nb = this->board.get_board()[this->curr_city].get_neighbors();
    if (find(nb.begin(), nb.end(), city) != nb.end())
    {
        this->curr_city = city;
    }
    else
    {
        throw std::invalid_argument{"you can't drive to" + to_string(city) };
    }
    return *this;
}
Player &Player::fly_direct(City city)
{

    if (this->curr_city == city)
    {
        throw std::invalid_argument{"you already at" + to_string(city) };
    }

    auto chosen_card = find(this->cards.begin(), this->cards.end(), city);
    if (chosen_card != this->cards.end())
    {
        this->curr_city = city;
        this->cards.erase(chosen_card);
    }
    else
    {
        throw std::invalid_argument{"you can't drive to" + to_string(city) };
    }
    return *this;
    }
    
    
    
Player &Player::fly_charter(City city)
    {
    if (this->curr_city == city)
    {
        throw std::invalid_argument{"you can't fly the same city" + to_string(city) };
    }

    auto card = find(this->cards.begin(), this->cards.end(), this->curr_city);
    if (card != this->cards.end())
    {
        this->curr_city = city;
        this->cards.erase(card);
    }
    else
    {
        throw std::invalid_argument{"you can't fly to" + to_string(city) };
    }
    return *this;
}
Player &Player::fly_shuttle(City city)
{
    if (this->curr_city == city)
    {
        throw std::invalid_argument{"you can't fly to the same city" + to_string(city) };
    }

    if (this->board.get_board()[this->curr_city].get_Station() && this->board.get_board()[city].get_Station())
    {
        this->curr_city = city;
    }
    else
    {
        throw std::invalid_argument{"you can't fly to" + to_string(city) };
    }

    return *this;
}
Player &Player::build()
{
        if(!(find(cards.begin(), cards.end(), curr_city) != cards.end())) {
        throw std::invalid_argument{"Cant build research station"};
        }
            if (!this->board.get_board()[this->curr_city].get_Station())
    {
        auto card = find(this->cards.begin(), this->cards.end(), this->curr_city);
        if (card != this->cards.end())
        {
            this->board.get_board()[this->curr_city].set_Station(true);
            this->cards.erase(card);
        }
        else
        {
            throw std::invalid_argument{"Cant build research station"};
        }
    }
    return *this;
    }


Player &Player::discover_cure(Color color)
{
    bool researches = this->board.get_board()[this->curr_city].get_Station();
    if (!researches)
    {
        throw std::invalid_argument{"no research station"};
    }

    bool iscure = this->board.get_madicines(color);
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
        throw std::invalid_argument{"not enough cards"}; }
  
        if (!iscure)
        {
            count = curr_card;
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
    
    Player& Player::treat(City city){
    if (curr_city!= city) {
        throw std::invalid_argument{" you are not in city " + to_string(city)};
    }
    if (board[city] == 0) {
        throw std::invalid_argument{" no more cubes remain in city " + to_string(city)};
    }
    if (this->board.get_madicines(this->board.get_board()[city].get_Color())) {
        board[city] = 0;
    }
    else {
        board[city]--;
    }
    return *this;
}
Player& Player::take_card(City city){
    cards.insert(cards.begin(),city);
    return *this;
}
string Player::role()
{
    return "  ";
}
Player &Player::remove_cards()
{
    this->cards.clear();
    return *this;
}