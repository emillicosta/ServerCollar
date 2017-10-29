#ifndef _GPS_H_
#define _GPS_H_

#include <string> 

class Gps 
{
public:

	float latitude, longitude;
    std::string elevation, date;
    int id_dog;

	Gps( float latitude_, float longitude_, std::string elevation_, std::string date_, int id_)
	{
		latitude = latitude_;
		longitude = longitude_;
		elevation = elevation_;
		date = date_;
		id_dog = id_;
	}

};

#endif