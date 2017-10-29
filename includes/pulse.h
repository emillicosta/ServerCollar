#ifndef _PULSE_H_
#define _PULSE_H_

#include <string> 

class Pulse 
{
public:

	float beat;
    std::string date;
    int id_dog;

	Pulse( float beat_, std::string date_, int id_)
	{
		beat = beat_;
		date = date_;
		id_dog = id_;
	}

};

#endif