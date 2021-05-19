#pragma once
#include "Player.hpp"
namespace pandemic{
    class OperationsExpert:public Player
    {

    public:
        OperationsExpert(pandemic::Board& board,City cityid): Player(board,cityid){};
        OperationsExpert& build()  override;
        string role()override;

       


    };
    
   
}