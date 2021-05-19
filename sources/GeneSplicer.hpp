#pragma once
#include "Player.hpp"
namespace pandemic{
    class GeneSplicer:public Player
    {
    private:
        const string vox = "GeneSplicer";
    public:
        GeneSplicer(pandemic::Board& board,City cityid): Player(board,cityid){}
        ~GeneSplicer() {};
        GeneSplicer& discover_cure(Color) override;
        string role()override;

        

    };
}