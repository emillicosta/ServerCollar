#ifndef _JSONSENSORS_H_
#define _JSONSENSORS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector>
#include <math.h> 

#include "gps.h"

#include "../utility/json.hpp"

using json = nlohmann::json;

class JsonSensors
{
    public:
        static std::vector<Gps> jsonHandler ( std::string file);
};

/*
 * Opens the json file and generates the image data
 * Return the image file name
 */
std::vector<Gps> JsonSensors::jsonHandler( std::string file)
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

#endif