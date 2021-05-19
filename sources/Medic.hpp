#pragma once
#include "Player.hpp"
namespace pandemic{
    class Medic:public Player
    {
    private:
        /* data */
    public:
        Medic(pandemic::Board& board,City cityid): Player(board,cityid){};
        Medic &treat(City) override;
        Medic &drive(pandemic::City city)override;
        Medic &fly_direct(pandemic::City city)override;
        Medic &fly_charter(pandemic::City city)override;
        Medic &fly_shuttle(pandemic::City city)override;
        string role()override;


   


    };
    
    
}