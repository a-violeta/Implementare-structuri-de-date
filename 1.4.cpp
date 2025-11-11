//merge
//pair cu coord puncte
//a acelasi cadran?
//b lungime cu sqrt((x1-x2)^2+(y1-y2)^2)
//c marime unghi cu ox
#include <iostream>
#include <utility>
#include <cmath>
void cadran(std::pair<float, float> a, std::pair<float, float> b)
{
	if ((a.first > 0 && b.first > 0) || (a.first < 0 && b.first < 0))
		if ((a.second > 0 && b.second > 0) || (a.second < 0 && b.second < 0))
		{
			std::cout << "Da";
			return;
		}
	std::cout<<"Nu";
	return;
}
float lungime(std::pair<float, float>a, std::pair<float, float> b)
{
	return sqrt((a.first - b.first) * (a.first - b.first)  + (a.second - b.second) * (a.second - b.second));
}
double unghi(std::pair<float, float> a, std::pair<float, float> b)
{
	std::pair<float, float> c;
	c.second = 0;
	float panta = (a.second - b.second) / (a.first - b.first);
	//std::cout << panta << " ";
	c.first = (panta*b.first-b.second)/panta;
	//std::cout << c.first << " " << c.second << " ";
	double sin = a.second / lungime(a, c);
	double cos = sqrt(1 - sin * sin);
	return std::atan2(sin, cos); //returneaza si nr negativ pt unghi obtuz
}
int main()
{
	std::pair<int, double> pereche1;
	std::cout << "Introduceti datele perechii 1: ";
	std::cin >> pereche1.first >> pereche1.second;
	std::pair<int, double> pereche2;
	std::cout << "Introduceti datele perechii 2: ";
	std::cin >> pereche2.first >> pereche2.second;
	cadran(pereche1, pereche2);
	std::cout<<"\n";
	std::cout << lungime(pereche1, pereche2) << "\n";
	std::cout << unghi(pereche1, pereche2) << "\n";
	return 0;
}