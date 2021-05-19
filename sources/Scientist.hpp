#pragma once
#include "Player.hpp"
namespace pandemic{
    class Scientist:public Player
    {
    private:
        int n;
    public:
        Scientist(pandemic::Board& board,City cityid, int n): n(n), Player(board,cityid){};
        Scientist& discover_cure(Color)  override;

      
        string role() override;

    };
    

    
}