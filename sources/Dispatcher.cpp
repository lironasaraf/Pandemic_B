#include "Dispatcher.hpp"
using namespace pandemic;

Dispatcher &Dispatcher::fly_direct(pandemic::City city)
{
    if (this->curr_city == city)
    { throw std::invalid_argument{"can't fly to the same city"}; }

    if (this->board.get_board()[this->curr_city].get_Station())
    {this->curr_city = city; }
    else
    {   Player::fly_direct(city); }
    return *this;
}

string Dispatcher::role(){
    string st = "Dispatcher";
    return st;
}