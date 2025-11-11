//Se citeste dintr-un fisier un text în care cuvintele sunt separate prin spatii.
//Pot exista si semne de punctuatie. Se cere la final afisarea în ordine alfabetica a cuv
//Fiecare cuvânt se afiseaza o singura data, având alaturi numarul de aparitii.
//Utilizaµi map din STL. Semnele de punctuatie se ignora.

//cu strtok iau cuv, separatorul fiind { " " , ", " , ". " , "? ",  "! ",  "; ",  ": ", " (", ") ", " "", "" " }
//oare cate sunt considerate semne de punctuatie

//sau: caut char intre anumite val ca sa stiu ca sunt litere: [65, 90] sau [97, 122]

#include <iostream>
#include <fstream>
#include <map>
#include <string>
void citire(const std::string& cale, std::map<std::string, int>& cuvinte)
{
	//verificare fis deschis
	std::ifstream fin(cale);
	if (!fin.is_open())
	{
		std::cerr << "Eroare la deschiderea fisierului!\n";
		return;
	}
	std::string cuv;
	int i = 0;
	char c;
	//while (fin >> c)
	//{
	//	//std::cout << c << ":";
	//	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) //daca e litera o pun in cuv
	//	{
	//		cuv[i] = c;
	//		i++;
	//		//std::cout << cuv << "\n";
	//	}
	//	else  //altfel inchei cuv si il pun in map
	//	{
	//		cuv[i] = '\0';
	//		if (cuvinte.find(cuv) == cuvinte.end())
	//			cuvinte.insert({ cuv, 1 });
	//		else
	//			cuvinte[cuv]++;
	//		//std::cout << cuv << " \n";
	//		cuv[0] = '\0';
	//		i = 0;
	//	}
	//}
	while (fin.get(c))
	{
		if (std::isalpha(c)) // daca e litera o adaugam in cuv
			cuv += std::tolower(c); // convertim la litera mica pentru a evita diferentele intre majuscule si minuscule
		else
			if (!cuv.empty()) // altfel incheiem cuv si il punem in map
		    {
		    	cuvinte[cuv]++;
			    cuv.clear(); // golim cuv pentru urmatorul cuvant
		    }
	}
	if (!cuv.empty())
		cuvinte[cuv]++;
}
void afisare(const std::map<std::string, int>& cuvinte)
{
	for (const auto& it : cuvinte)
		std::cout << it.first << " " << "cu frecventa: " << it.second << "\n";
}
int main()
{
	std::map<std::string, int> cuvinte;
	citire("fis.txt", cuvinte);
	afisare(cuvinte);
	return 0;
}