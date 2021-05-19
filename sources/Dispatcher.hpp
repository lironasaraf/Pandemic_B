#pragma once
#include "Player.hpp"
namespace pandemic{
    class Dispatcher:public Player
    {
    private:
        /* data */
    public:
        Dispatcher(pandemic::Board& board,City cityid): Player(board,cityid){}
        Dispatcher& fly_direct(City) override;
        string role() override;

       
    };
}