//merge
//citire string din fisier
//std::vector<std::tuple<std::string, std::string, int, int, int>>
//sortare descrescatoare elevi dupa medie
//afisare
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
typedef std::tuple<std::string, std::string, int, int, int> elev;
void citire_elevi(const std::string& fisier, std::vector<elev> & toti_elevii)
{
	std::ifstream fis(fisier);
	if (!fis.is_open())
	{
		std::cerr << "Eroare la deschiderea fisierului!\n";
		return;
	}
	std::string nume, prenume;
	int n1, n2, n3;
	while (fis >> nume >> prenume >> n1 >> n2 >> n3)
		toti_elevii.emplace_back(nume, prenume, n1, n2, n3);
	fis.close();
}
double medie(const elev& e)
{
	return (std::get<2>(e) + std::get<3>(e) + std::get<4>(e)) / 3.0; //get<0> exista
}
int main()
{
	std::vector<elev> toti_elevii;
	citire_elevi("catalog.txt", toti_elevii);
	auto comparator = [](const elev& a, const elev& b)
		{
			return medie(a) > medie(b);
		};
	std::sort(toti_elevii.begin(), toti_elevii.end(), comparator);
	for (const auto& elev : toti_elevii)
	{
		std::cout << std::get<0>(elev) << " " << std::get<1>(elev) << " " << std::get<2>(elev) << " " << std::get<3>(elev) << " " << std::get<4>(elev) << " ";
		if (medie(elev) < 5)
			std::cout << "Elevul are media sub 5\n";
		else
			std::cout << "\n";
	}
	return 0;
}