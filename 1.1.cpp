//merge
//interclasare cu vect sortati invers unul fata de celalat
#include <iostream>
void vect(int nr1, int nr2, int nr3, int*& v1, int*& v2, int*& v3)
{
	int i;
	v1 = new int[nr1];
	v2 = new int[nr2];
	v3 = new int[nr3];
	for (i = 0; i < nr1; i++)
		std::cin >> v1[i];
	for (i = 0; i < nr2; i++)
		std::cin >> v2[i];
}
int main()
{
	int nr1, nr2, nr3, * v1, * v2, * v3, i, j, k=0;
	std::cin >> nr1 >> nr2;
	nr3 = nr1 + nr2;
	vect(nr1, nr2, nr3, v1, v2, v3);
	i = 0;
	j = nr2-1;
	while (i<nr1 && j>-1)
	{
		if (v1[i] < v2[j])
		{
			v3[k] = v1[i];
			k++;
			i++;
		}
		else
		{
			v3[k] = v2[j];
			k++;
			j--;
		}
	}
	while (i < nr1)
	{
		v3[k] = v1[i];
		i++;
		k++;
	}
	while (j > -1)
	{
		v3[k] = v2[j];
		j--;
		k++;
	}
	delete [] v1;
	delete [] v2;
	for (i = 0; i < nr3; i++)
		std::cout << v3[i] << " ";
	delete[] v3;
	return 0;
}