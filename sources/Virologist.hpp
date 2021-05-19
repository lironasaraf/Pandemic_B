#pragma once
#include "Player.hpp"
namespace pandemic{
    class Virologist:public Player
    {
    private:
        
    public:
        Virologist(pandemic::Board& board,City cityid):Player(board,cityid){};
        Virologist& treat(City)  override;
        string role()override;

       


    };
    


    
}