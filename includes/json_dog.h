#ifndef _JSONDOG_H_
#define _JSONDOG_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector>
#include <math.h> 

#include "pot.h"
#include "gps.h"
#include "pulse.h"
#include "accelerometer.h"

#include "../utility/json.hpp"

using json = nlohmann::json;

class JsonDog
{
    public:
        static std::vector<Gps> json_gps ( std::string file);
        static std::vector<Pulse> json_pulse ( std::string file);
        static std::vector<Accelerometer> json_accelerometer( std::string file);
        static std::vector<Pot> json_pot( std::string file);
};

/*
 * Opens the json file and generates the image data
 * Return the image file name
 */
std::vector<Gps> JsonDog::json_gps( std::string file)
{

    // read the json file and put it inside 'j'
    std::ifstream i("../scenes_files/" + file);
    json j;
    i >> j;
    int id_dog = j["id"];


    // Scene Creation
    int qtd = j["segments"]["coordenadas"].size();
    std::vector<Gps> gps;

    for(int i=0; i<qtd; i++)
    {
        float latitude =  j["segments"]["coordenadas"][i]["latitude"];
        float longitude = j["segments"]["coordenadas"][i]["longitude"];
        std::string elevation = j["segments"]["coordenadas"][i]["elevation"];
        std::string date = j["segments"]["coordenadas"][i]["date"];

        Gps a(latitude, longitude, elevation, date, id_dog);

        gps.push_back( a );
    }

    return gps;
}

std::vector<Pulse> JsonDog::json_pulse( std::string file)
{

    // read the json file and put it inside 'j'
    std::ifstream i("../scenes_files/" + file);
    json j;
    i >> j;
    int id_dog = j["id"];


    // Scene Creation
    int qtd = j["segments"]["pulse"].size();
    std::vector<Pulse> pulse;

    for(int i=0; i<qtd; i++)
    {
        float beat =  j["segments"]["pulse"][i]["beat"];
        std::string date = j["segments"]["pulse"][i]["date"];

        Pulse a(beat, date, id_dog);

        pulse.push_back( a );
    }

    return pulse;
}

std::vector<Accelerometer> JsonDog::json_accelerometer( std::string file)
{

    // read the json file and put it inside 'j'
    std::ifstream i("../scenes_files/" + file);
    json j;
    i >> j;
    int id_dog = j["id"];


    // Scene Creation
    int qtd = j["segments"]["pulse"].size();
    std::vector<Accelerometer> accelerometer;

    for(int i=0; i<qtd; i++)
    {
        float x =  j["segments"]["accelerometer"][i]["x"];
        float y =  j["segments"]["accelerometer"][i]["y"];
        float z =  j["segments"]["accelerometer"][i]["z"];
        std::string date = j["segments"]["accelerometer"][i]["date"];

        Accelerometer a(x, y, z, date, id_dog);

        accelerometer.push_back( a );
    }

    return accelerometer;
}

std::vector<Pot> JsonDog::json_pot( std::string file)
{

    // read the json file and put it inside 'j'
    std::ifstream i("../scenes_files/" + file);
    json j;
    i >> j;
    int id_dog = j["id"];


    // Scene Creation
    int qtd = j["segments"]["feeding"].size();
    std::vector<Pot> pot;

    for(int i=0; i<qtd; i++)
    {
        std::string type =  j["segments"]["feeding"][i]["type"];
        std::string date_start =  j["segments"]["feeding"][i]["date_start"];
        std::string date_end = j["segments"]["feeding"][i]["date_end"];

        Pot a(type, date_start, date_end, id_dog);

        pot.push_back( a );
    }

    return pot;
}

#endif