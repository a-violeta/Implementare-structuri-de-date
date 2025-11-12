//numar maxim cu toate cif pare dintr un vector
#include <iostream>
int numar(int* v, int nr)
{
	int i, *frecv;
	frecv = new int[10]();
	for (i = 0; i < nr; i++)
	{
		while (v[i])
		{
			if (!(v[i]%10 % 2))
				frecv[v[i]%10]++;
			v[i] = v[i] / 10;
		}
	}
	long long int noul_nr=0;
	for (i = 9; i >= 0; i--)
		while (frecv[i])
		{
			noul_nr = noul_nr * 10 + i;
			frecv[i]--;
		}
	delete[] frecv;
	return noul_nr;
}
int main()
{
	int nr, * v;
	std::cin >> nr;
	v = new int[nr];
	for (int i = 0; i < nr; i++)
		std::cin >> v[i];
	std::cout << numar(v, nr);
	delete[] v;
	return 0;

}
