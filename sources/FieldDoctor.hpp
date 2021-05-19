#pragma once
#include "Player.hpp"
namespace pandemic{
    class FieldDoctor:public Player
    {
    private:
        /* data */
    public:
        FieldDoctor(pandemic::Board& board,City cityid): Player(board,cityid){}
        FieldDoctor& treat(City) override;
        string role()override;

       

    };
}