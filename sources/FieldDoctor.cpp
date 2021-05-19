#include "FieldDoctor.hpp"
using namespace pandemic;

FieldDoctor &FieldDoctor::treat(pandemic::City city)
{
    list<pandemic::City> &fd = this->board.get_board()[this->curr_city].get_neighbors();
    if (this->curr_city == city || find(fd.begin(), fd.end(), city) != fd.end())
    {
        if (this->board[city] == 0)
        {
            throw std::invalid_argument{"the city is not sick"};
        }

        pandemic::Color c = this->board.get_board()[city].get_Color();
        if (this->board.get_madicines(c))
        {
            this->board[city] = 0;
        }
        else
        {
            this->board[city]--;
        }
    }
    else
    {
        throw std::invalid_argument{"can't make treatment"};
    }

    return *this;
}

string FieldDoctor::role()
{
    string st = "FieldDoctor";
    return st;
}