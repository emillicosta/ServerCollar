#ifndef _accelerometer_H_
#define _accelerometer_H_

#include <string> 

class Accelerometer 
{
public:

	float x,y,z;
    std::string date;
    int id_dog;

	Accelerometer( float x_, float y_, float z_, std::string date_, int id_)
	{
		x = x_;
		y = y_;
		z = z_;
		date = date_;
		id_dog = id_;
	}

};

#endif