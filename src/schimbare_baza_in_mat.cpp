//citim mat cu nr in baza 10 si le transformam in nr in baza j+2 pe coloane
#include <iostream>
bool validare(int n, int m, int** mat)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (mat[i][j] >= j + 2)
				return false;
	return true;
}
void conversie(int n, int m, int** mat, int* numbers)
{
	if (validare(n, m, mat))
	{
		int i, j, baza, suma=0;
		for (j = 0; j <= m; j++)
		{
			baza = 1;
			suma = 0;
			for (i = n-1; i >=0; i--)
			{
				suma = suma + baza * mat[i][j];
				baza = baza * (j+2);
			}
			numbers[j] = suma;
		}
		for (i = 0; i < m; i++)
			std::cout << numbers[i] << " ";
		return;
	}
	std::cout << "Invalid\n";
	return;
}
int main()
{
	int** mat;
	int n, m, i, j;
	std::cin >> n >> m;
	mat = new int*[n];
	mat[0] = new int[n*m];
	for (i = 1; i < n; i++)
		mat[i] = mat[i - 1] + m; //sper
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			std::cin >> mat[i][j];
	int* numbers = new int[m + 1]; //siguranta?
	conversie(n, m, mat, numbers);
	delete[] mat[0];
	delete[] mat;
	return 0;

}
