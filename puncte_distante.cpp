//citim n puncte, cautam cele 2 puncte cu distanta minima intre ele si cele 2 puncte cu distanta maxima intre ele

//nu merge inca
//nu e functie
//struct punct cu coord x si y si functie distanta(punct a, punct b)
//cout cele mai departate si cele mai apropiate

#include <iostream>
#include "punct.h"
#include <vector>
#include <limits>

int main()
{
	std::vector<punct> puncte;
	int nr, x, y;
	std::cin >> nr;
	for (int i = 0; i < nr; i++)
	{
		std::cin >> x >> y;
		puncte.emplace_back(x, y);
	}
	int distanta_maxima = -1, distanta_minima = std::numeric_limits<int>::max(); // ar trebui initializata cu ceva
	punct a, b, c, d;
	for (const auto& it : puncte)
		for (const auto& it2 : puncte)
			if (it.get_x() != it2.get_x() || it.get_y() != it2.get_y())
			{
				if (it.distanta(it2) > distanta_maxima)
				{
					distanta_maxima = it.distanta(it2);
					a = it;
					b = it2;
				}
				else
					if (it.distanta(it2) < distanta_minima)
					{
						distanta_minima = it.distanta(it2);
						c = it;
						d = it2;
					}
			}
	std::cout << "Distanta maxima se afla intre punctele: (" << a.get_x() << "; " << a.get_y() << ") si (" << b.get_x() << "; " << b.get_y() << ") iar distanta minima se afla intre punctele: (" << c.get_x() << "; " << c.get_y() << ") si (" << d.get_x() << "; " << d.get_y() << ")\n";
	return 0;
}

