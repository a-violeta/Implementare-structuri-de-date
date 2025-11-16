
#pragma once
#include <cmath>
class punct
{
	int x;
	int y;
public:
	int distanta(const punct& p) const;
	punct(); //constructor fara param
	punct(int x, int y); //constructor cu param
	punct& operator=(const punct& p);
	int get_x() const { return x; }
	int get_y() const { return y; }
};
