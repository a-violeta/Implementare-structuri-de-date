
#include "punct.h"
int punct::distanta(const punct& p) const
{
	return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

punct::punct() : x(0), y(0) {}

punct::punct(int x, int y) //constructor fara param
{
    this->x = x;
    this->y = y;
}

punct& punct::operator=(const punct& p)
{
    if (this != &p)
    {
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}
