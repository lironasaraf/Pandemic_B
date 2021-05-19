#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <stdexcept>
#include <map>
#include <set>
using namespace std;

namespace pandemic{
    class Board
    {
    
        map<pandemic::City, iCity> connects;
        map<City, int> disease_level;
        set<City> research_station;
        array<bool, 4> med;
        void connections();
    public:
        Board()
        {
            med = {false, false, false, false};
            connections();
      

        };

    public:
        
        Board(pandemic::Board& board){


        };
        ~Board(){};
        map<pandemic::City, iCity>& get_board();
        bool is_clean();
        const unsigned int operator[](int city) const; 
        int &operator[](pandemic::City city);  
        friend ostream &operator<<(ostream &ostream, const Board &board);
        void remove_cures();
        void remove_stations();
        void build(City city);
        bool get_madicines(Color c) const;
        void set_madicines(Color color, bool med);
        void add_research_station(City city);
        bool has_research_station( City&c);
    };
    

    
};