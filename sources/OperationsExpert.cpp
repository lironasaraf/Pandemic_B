#include "OperationsExpert.hpp"
using namespace pandemic;

OperationsExpert &OperationsExpert::build()
{
    this->board.get_board()[this->curr_city].set_Station(true);
    return *this;
}
string OperationsExpert::role()
{
    string st ="OperationsExpert";
    return st;
}