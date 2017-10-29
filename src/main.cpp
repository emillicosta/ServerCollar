#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector>

#include "../includes/json_dog.h"


int main( int argc, const char * argv[] )
{
    std::vector<Gps> gps = JsonDog::json_gps("gps.json");

    std::cout <<"|  Id | Latitude | Longitude |  Elevação |      Data      |\n";
    std::cout <<"===========================================================\n";


    for (int i = 0; i < gps.size(); ++i)
    {
        std::cout <<"   "<< gps[i].id_dog << "    ";
        std::cout << gps[i].latitude << "    ";
        std::cout << gps[i].longitude << "     ";
        std::cout << gps[i].elevation << "     ";
        std::cout << gps[i].date << "\n";
    }

    std::cout << "\n";
    std::vector<Pulse> pulse = JsonDog::json_pulse("sensors.json");

    std::cout <<"|  Id | Batimento |       Data       |\n";
    std::cout <<"======================================\n";


    for (int i = 0; i < pulse.size(); ++i)
    {
        std::cout <<"   "<< pulse[i].id_dog << "    ";
        std::cout << pulse[i].beat << " BPM    ";
        std::cout << pulse[i].date << "\n";
    }


    std::cout << "\n";
    std::vector<Accelerometer> accelerometer = JsonDog::json_accelerometer("sensors.json");

    std::cout <<"|  Id |   X   |   Y   |   Z   |       Data       |\n";
    std::cout <<"==================================================\n";


    for (int i = 0; i < accelerometer.size(); ++i)
    {
        std::cout <<"   "<< accelerometer[i].id_dog << "     ";
        std::cout << accelerometer[i].x << "    ";
        std::cout << accelerometer[i].y << "    ";
        std::cout << accelerometer[i].z << "   ";
        std::cout << accelerometer[i].date << "\n";
    }


    std::cout << "\n";
    std::vector<Pot> pot = JsonDog::json_pot("pot.json");

    std::cout <<"|  Id |    Início      |       Fim       |   Tipo   |\n";
    std::cout <<"=====================================================\n";


    for (int i = 0; i < pot.size(); ++i)
    {
        std::cout <<"   "<< pot[i].id_dog << "   ";
        std::cout << pot[i].date_start << "  ";
        std::cout << pot[i].date_end << "  ";
        std::cout << pot[i].type  << "\n";
    }

    return 0;

}