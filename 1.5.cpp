//nu are functii
//std::vector<float> note;
//cin>>nr si elem vector
//cout note din intervalele [1,5), [5,5.50), [5.50,6), .., [9.50, 10]
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int nr, i;
	std::vector<float> note;
	std::cin >> nr;
	float nota;
	for (i = 0; i < nr; i++)
	{
		std::cin >> nota;
		note.emplace_back(nota);
	}
	sort(note.begin(), note.end());
	int* statistica = new int[21]();
	for (float& it : note)
	{
		if (it < 5)
			statistica[0]++;
		else
			if (it == 10)
			statistica[19]++;
			else
				statistica[static_cast<int>(it*2.00)]++; //static_cast<int>(it) face int
	}
	for (i = 0; i < 20; i++)
		if (statistica[i])
			if (!i)
				if(statistica[i]>1)
				std::cout << "Exista " << statistica[i] << " note in intervalul [1; 5)\n";
				else
					std::cout << "Exista 1 nota in intervalul [1; 5)\n";
			else
				if (!(i % 2))
					if(statistica[i]>1)
					std::cout << "Exista " << statistica[i] << " note in intervalul [" << i / 2 << ", " << i / 2 + 0.5 << ")\n";
					else
						std::cout << "Exista 1 nota in intervalul [" << i / 2 << ", " << i / 2 + 0.5 << ")\n";
				else
					if(statistica[i]>1)
					std::cout << "Exista " << statistica[i] << " note in intervalul [" << i / 2+0.5 << ", " << i / 2 + 1 << ")\n";
					else
						std::cout << "Exista 1 nota in intervalul [" << i / 2 + 0.5 << ", " << i / 2 + 1 << ")\n";
	delete[] statistica;
	return 0;

}
