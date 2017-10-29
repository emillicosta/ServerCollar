#ifndef _POT_H_
#define _POT_H_

#include <string> 

class Pot
{
public:

    std::string type, date_start, date_end;
    int id_dog;

	Pot( std::string type_, std::string date_start_, std::string date_end_, int id_)
	{
		type = type_;
		date_start = date_start_;
		date_end = date_end_;
		id_dog = id_;
	}

};

#endif