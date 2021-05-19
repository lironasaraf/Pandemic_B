#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <vector>

namespace pandemic{
    class Player
    {
    protected:
        std::vector<pandemic::City> cards;
        Board &board;
        int curr_card=5;
        City curr_city;
    public:
        Player(pandemic::Board &board, pandemic::City c):board(board), curr_city(c){};

        virtual Player& drive (City city_Id);
        virtual Player& fly_direct (City city_Id);
        virtual Player& fly_shuttle (City city_Id);
        virtual Player& fly_charter (City city_Id);
        virtual Player& build ();
        virtual Player& discover_cure (pandemic::Color color);
        virtual Player& treat (City city_Id);
        virtual Player& take_card (City city_Id);
        virtual std::string role ();
        ~Player(){};
        Player &remove_cards();
        
    };

    
}