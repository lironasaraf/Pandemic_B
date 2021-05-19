#include "Board.hpp"
#include "City.hpp"
#include <iostream>
#include <stdexcept>
#include <map>
using namespace std;

using namespace pandemic;
// bool Board::get_madicines(Color c) const
// {
//     return this->med.at(c);
// }

// void Board::set_madicines(Color color, bool med)
// {
//     this->med.at(color) = med;
// }

// bool Board::has_research_station(City &city)
// {
//     return research_station.find(city) != research_station.end();
// }
// void Board::add_research_station(City city)
// {
//     research_station.insert(city);
// }
int &iCity::get_Diseases()
{
    return this->diseases;
}
int iCity::get_City() const
{
    return this->city;
}
pandemic::Color iCity::get_Color() const
{
    return this->color;
}
list<pandemic::City> &iCity::get_neighbors()
{
    return this->neighbors;
}
bool iCity::get_Station() const
{
    return this->station;
}
void iCity::set_Station(bool station)
{
    this->station = station;
    
}
map<pandemic::City, iCity> &Board::get_board()
{
    return this->connects;
}
bool Board::get_madicines(Color c) const
{
    return this->med.at(c);
}

void Board::set_madicines(Color col, bool medicine)
{
    this->med.at(col) = medicine;
}



void Board::remove_cures()
{
 
    med[Color::Yellow]=false; med[Color::Red]=false; med[Color::Red]=false; med[Color::Black] = false;
}

bool Board::is_clean()
{
    if (connects.empty()){ return true;}
    for (auto &itr : this->connects)
    {
        if (itr.second.get_Diseases() > 0)
        {
            return false;
        }
    }
    return true;
}
//     void Board::remove_stations()
// {
//     for (auto itr : this->research_station)
//     { 
//         if(research_station.find(City)){
//         research_station.

//     }



// const unsigned int Board::operator[](int city) const
// {
    
//     return 1;
// }

int &Board::operator[](pandemic::City city)
{
    return connects[city].get_Diseases();
}



ostream &pandemic::operator<<(ostream &os, const Board &b)
{
    for (const auto &itr : b.connects)
    {
        os << itr.second << endl;
    }
    return os;
}

ostream &pandemic::operator<<(ostream &os, const iCity &ver)
{
    os << ver.city << "- " << ver.diseases << "diseases, ";
    if (ver.station)
    { os << "research station" << endl;}
    else
    {  os << "not a research station" << endl; }
    return os;
}
void Board::remove_stations()
{
    for (auto itr : this->connects)
    {
        if (itr.second.get_Station())
        {
            itr.second.set_Station(false);
        }
    }
}
    void Board::connections(){

        ////////////////////all yellow city 
    connects[City::Bogota] = iCity(City::Bogota, Color::Yellow, 0, false, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires});
    connects[City::BuenosAires] = iCity(City::BuenosAires, Color::Yellow, 0, false, {City::Bogota, City::SaoPaulo});
    connects[City::Johannesburg] = iCity(City::Johannesburg, Color::Yellow, 0, false, {City::Kinshasa, City::Khartoum});
    connects[City::Khartoum] = iCity(City::Khartoum, Color::Yellow, 0, false, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg});
    connects[City::Kinshasa] = iCity(City::Kinshasa, Color::Yellow, 0, false, {City::Lagos, City::Khartoum, City::Johannesburg});
    connects[City::Lagos] = iCity(City::Lagos, Color::Yellow, 0, false, {City::SaoPaulo, City::Khartoum, City::Kinshasa});
    connects[City::Lima] = iCity(City::Lima, Color::Yellow, 0, false, {City::MexicoCity, City::Bogota, City::Santiago});
    connects[City::LosAngeles] = iCity(City::LosAngeles, Color::Yellow, 0, false, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney});
    connects[City::MexicoCity] = iCity(City::MexicoCity, Color::Yellow, 0, false, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota});
    connects[City::Miami] = iCity(City::Miami, Color::Yellow, 0, false, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota});
    connects[City::Santiago] = iCity(City::Santiago, Color::Yellow, 0, false, {City::Lima});
    connects[City::SaoPaulo] = iCity(City::SaoPaulo, Color::Yellow, 0, false, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid});
    
    
    ////////////////////all black city
    connects[City::Algiers] = iCity(City::Algiers, Color::Black, 0, false, {City::Paris, City::Istanbul, City::Cairo, City::Madrid});
    connects[City::Baghdad] = iCity(City::Baghdad, Color::Black, 0, false, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi});
    connects[City::Cairo] = iCity(City::Cairo, Color::Black, 0, false, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh});
    connects[City::Chennai] = iCity(City::Chennai, Color::Black, 0, false, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta});
    connects[City::Delhi] = iCity(City::Delhi, Color::Black, 0, false, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata});
    connects[City::Istanbul] = iCity(City::Istanbul, Color::Black, 0, false, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow});
    connects[City::Karachi] = iCity(City::Karachi, Color::Black, 0, false, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi});
    connects[City::Kolkata] = iCity(City::Kolkata, Color::Black, 0, false, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong});
    connects[City::Moscow] = iCity(City::Moscow, Color::Black, 0, false, {City::StPetersburg, City::Istanbul, City::Tehran});
    connects[City::Mumbai] = iCity(City::Mumbai, Color::Black, 0, false, {City::Karachi, City::Delhi, City::Chennai});
    connects[City::Riyadh] = iCity(City::Riyadh, Color::Black, 0, false, {City::Baghdad, City::Cairo, City::Karachi});
    connects[City::Tehran] = iCity(City::Tehran, Color::Black, 0, false, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi});

                ////////////////////all blue city
    connects[City::Atlanta] = iCity(City::Atlanta, Color::Blue, 0, false, {City::Chicago, City::Miami, City::Washington});
    connects[City::Chicago] = iCity(City::Chicago, Color::Blue, 0, false, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal});
    connects[City::Essen] = iCity(City::Essen, Color::Blue, 0, false, {City::London, City::Paris, City::Milan, City::StPetersburg});
    connects[City::London] = iCity(City::London, Color::Blue, 0, false, {City::NewYork, City::Madrid, City::Essen, City::Paris});
    connects[City::Madrid] = iCity(City::Madrid, Color::Blue, 0, false, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers});
    connects[City::Milan] = iCity(City::Milan, Color::Blue, 0, false, {City::Essen, City::Paris, City::Istanbul});
    connects[City::Montreal] = iCity(City::Montreal, Color::Blue, 0, false, {City::Chicago, City::Washington, City::NewYork});
    connects[City::NewYork] = iCity(City::NewYork, Color::Blue, 0, false, {City::Montreal, City::Washington, City::London, City::Madrid});
    connects[City::Paris] = iCity(City::Paris, Color::Blue, 0, false, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London});
    connects[City::SanFrancisco] = iCity(City::SanFrancisco, Color::Blue, 0, false, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila});
    connects[City::StPetersburg] = iCity(City::StPetersburg, Color::Blue, 0, false, {City::Essen, City::Istanbul, City::Moscow});
    connects[City::Washington] = iCity(City::Washington, Color::Blue, 0, false, {City::Atlanta, City::NewYork, City::Montreal, City::Miami});
  
                        ////////////////////all red city
  
    connects[City::Beijing] = iCity(City::Beijing, Color::Red, 0, false, {City::Shanghai, City::Seoul});
    connects[City::HongKong] = iCity(City::HongKong, Color::Red, 0, false, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei});
    connects[City::Tokyo] = iCity(City::Tokyo, Color::Red, 0, false, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco});
    connects[City::Seoul] = iCity(City::Seoul, Color::Red, 0, false, {City::Beijing, City::Shanghai, City::Tokyo});
    connects[City::Shanghai] = iCity(City::Shanghai, Color::Red, 0, false, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo});
    connects[City::Taipei] = iCity(City::Taipei, Color::Red, 0, false, {City::Shanghai, City::HongKong, City::Osaka, City::Manila});
    connects[City::Sydney] = iCity(City::Sydney, Color::Red, 0, false, {City::Jakarta, City::Manila, City::LosAngeles});
    connects[City::Jakarta] = iCity(City::Jakarta, Color::Red, 0, false, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney});
    connects[City::Manila] = iCity(City::Manila, Color::Red, 0, false, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney,City::HongKong});
    connects[City::Osaka] = iCity(City::Osaka, Color::Red, 0, false, {City::Taipei, City::Tokyo});
    connects[City::HoChiMinhCity] = iCity(City::HoChiMinhCity, Color::Red, 0, false, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila});
    connects[City::Bangkok] = iCity(City::Bangkok, Color::Red, 0, false, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong});
   
   
}


