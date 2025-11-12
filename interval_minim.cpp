//Se citesc n intervale si un nr, se cere cel mai restrans interval in care se afla nr

//pair pt intervale
//functie cu param nr returneaza interval
#include <iostream>
#include <vector>

void rezolvare(const std::vector<std::pair<int, int>>& intervale, int nr)
{
	int min = 100000000; //se putea si mai bine
	bool ok = 0;
	std::pair<int, int> solutie;
	for (const auto& it : intervale)
	{
		if (nr - it.first && it.second - nr) //se afla in interval
		{
			ok = 1;
			if (min > nr - it.first + it.second - nr) //nr - nr e redundant, dar functioneaza
			{
				min = nr - it.first + it.second - nr;
				solutie.first = it.first;
				solutie.second = it.second;
			}
		}
	}
	if (ok)
		std::cout << "[" << solutie.first << ", " << solutie.second << "]\n";
	else
		std::cout << "Numarul dat nu se afla in niciun interval din vector\n";
}

int main()
{
	std::vector<std::pair<int, int>> intervale;
	int dim, i, nr, a, b;
	std::cin >> dim;
	for (i = 0; i < dim; i++)
	{
		std::cin >> a >> b;
		intervale.emplace_back(a, b);
	}
	std::cin >> nr;
	rezolvare(intervale, nr);
	return 0;

}

