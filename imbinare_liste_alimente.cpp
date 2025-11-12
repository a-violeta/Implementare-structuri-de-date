//2 liste de produse si cantitati devin o noua lista unde nu se repeta nimic si au cantitatea noua
#include <iostream>
#include <fstream>
#include <vector>

typedef std::pair<std::string, int> aliment;

void citire(const std::string& fisier, std::vector<aliment>& lista)
{
	std::ifstream fis(fisier);
	if (!fis.is_open())
	{
		std::cerr << "Eroare la deschiderea fisierului!\n";
		return;
	}
	std::string nume;
	int cantitate;
	while (fis >> nume>>cantitate)
		lista.emplace_back(nume, cantitate);
	fis.close();
}

void combinare(const std::vector<aliment>& lista1, const std::vector<aliment>& lista2, std::vector<aliment>& lista3)
{
	bool ok = 0;
	//iterez prin lista1 si daca alimentul nu se gaseste in lista2 il bag in lista3, altfel il bag cu cantitatea mai mare
	for (const auto& it : lista1)
	{
		ok = 0; //ok se refera la aparitia precedenta a produsului
		for (const auto& it2 : lista2)
			if (it.first == it2.first)
			{
				lista3.emplace_back(it.first, std::max(it.second, it2.second));
				ok = 1;
			}
		if (!ok)
			lista3.emplace_back(it.first, it.second);
	}
	//iterez prin lista2 si daca alimentul apare deja in lista3 trec mai departe
	for (const auto& it : lista2)
	{
		ok = 0; //apare deja sau nu
		for (const auto& it2 : lista3) //const pt ca merge?
			if (it.first == it2.first)
				ok = 1;
		if (!ok)
			lista3.emplace_back(it.first, it.second);
	}
}

int main()
{
	std::vector<aliment> lista1;
	citire("lista1.txt", lista1);
	std::vector<aliment> lista2;
	citire("lista2.txt", lista2);
	std::vector<aliment> lista3;
	combinare(lista1, lista2, lista3);
	for (const auto& it : lista3)
		std::cout << it.first << " " << it.second << "\n";
	return 0;

}
