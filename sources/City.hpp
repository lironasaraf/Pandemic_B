
#pragma once
#include <iostream>
#include <list>
#include <map>
#include <array>
#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;
using namespace std;

namespace pandemic {
        enum City
    {  
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris ,
        Riyadh ,
        SanFrancisco,
        Santiago ,
        SaoPaulo ,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington};
        
    class iCity
    {
        pandemic::City city;
        pandemic::Color color;
        int diseases;
        bool station;
        list<pandemic::City> neighbors;

    public:
        iCity(){};
        iCity(const City c, const Color col, const int dis, const bool st, const list<pandemic::City> ne_connect) : city(c), color(col), diseases(dis), station(st)
        {
            neighbors = ne_connect;
        };
        ~iCity(){};
        int &get_Diseases();
        int get_City() const;
        pandemic::Color get_Color() const;
        bool get_Station() const;
        void set_Station (bool station);
        list<pandemic::City> &get_neighbors();
        friend ostream &operator<<(ostream &os, const iCity &ver);
    };
       // friend ostream &operator<<(ostream &os, const City_data &c);
    };
    



    
    
