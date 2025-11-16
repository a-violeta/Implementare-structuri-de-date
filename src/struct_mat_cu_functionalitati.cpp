//nu merge dublarea si nu merge nimic pe mat>2*2
//structura matrice cu n, m, mat
//functii pt alocare, dealocare, citire, afisare, dublare linii cu elem pare, sortare prima coloana

#include <iostream>
struct matrice
{
	int n=0, m=0;
	int** mat = nullptr;
};
	void alocare(matrice* matrix, int n, int m)
	{
		//std::cin >> (*matrix).n >> (*matrix).m;  //sau ->
		matrix->n = n;
		matrix->m = m;
		(*matrix).mat = new int* [(*matrix).n];
		(*matrix).mat[0] = new int[(*matrix).n *(*matrix).m];
		for (int i = 1; i < (*matrix).n; i++)
			(*matrix).mat[i] = (*matrix).mat[i - 1] + i * (*matrix).m;
	}
	void eliberare(matrice* matrix)
	{
		delete[] matrix->mat[0];
		delete[] matrix->mat;  //a mai dat eroare si aici
		matrix->n=0;
		matrix->m=0;
	}
	void citire(matrice* matrix)
	{
		int i, j;
		if (matrix->n)
		{
			for (i = 0; i < matrix->n; i++)
				for (j = 0; j < matrix->m; j++)
					std::cin >> matrix->mat[i][j];
			return;
		}
		std::cout << "Matrice nealocata ajunge in functia citire\n";
	}
	void afisare(matrice& matrix)
	{
		std::cout << "\n";
		int i, j;
		for (i = 0; i < matrix.n; i++)
		{
			for (j = 0; j < matrix.m; j++)
				std::cout << matrix.mat[i][j] << " ";
			std::cout << "\n";
		}
	}
	void dublare_linii_pare(matrice* matrix) //nu merge
	{
		std::cout << "\nDublare:\n";
		int l, i, j, p, q;
		bool ok;
		if (matrix->n) //daca e alocat
		{
			for (i = 0; i < matrix->n; i++)
			{
				ok = 1;
				for (j = 0; j < matrix->m; j++)
					if (matrix->mat[i][j] % 2)
					{
						ok = 0;
						break;
					}
				if (ok)
				{
					l = i;
					//dublare inseamna creare alta matrice si umplere si stergere mat
					//apoi toti pointerii lui mat vor pointa catre noul mat
					matrice mat2;
					//mat2.n = matrix->n + 1;
					//mat2.m = matrix->m;
					alocare(&mat2, matrix->n+1, matrix->m);
					for (p = 0; p <= l; p++)
						for (q = 0; q < matrix->m; q++)
							mat2.mat[p][q] = matrix->mat[p][q];
					for (q = 0; q < matrix->m; q++)
						mat2.mat[l + 1][q] = matrix->mat[l][q];
					for (p = l + 2; p < matrix->n + 1; p++)
						for (q = 0; q < matrix->m; q++)
							mat2.mat[p][q] = matrix->mat[p - 1][q]; //daca e prima sau ultima linie merge?
					for (p = 0; p < mat2.n; p++) //mat2.mat arata bine
					{
						for (q = 0; q < mat2.m; q++)
							std::cout << mat2.mat[p][q] << " ";
						std::cout << "\n";
					}
					eliberare(matrix);
					//matrix->n++;
					alocare(matrix, mat2.n, mat2.m);
					//for (p = 0; p < matrix->n; p++)
						//matrix->mat[i] = mat2.mat[i];
					for (int p = 0; p < matrix->n; p++)
						for (int q = 0; q < matrix->m; q++)
							matrix->mat[i][j] = mat2.mat[i][j];
					eliberare(&mat2);
				}
			}
			return;
		}
		std::cout << "Matrice nealocata ajunge in functia dublare\n";
		return;
	}
	int partitionare(matrice* matrix, int st, int dr)
	{
		int pivot = matrix->mat[dr][0];
		int i = st - 1;
		for (int j = st; j < dr; j++)
		{
			if (matrix->mat[j][0] <= pivot)  //crescator
			{
				i++;
				std::swap(matrix->mat[i][0], matrix->mat[j][0]);
			}
		}
		i++;
		std::swap(matrix->mat[dr][0], matrix->mat[i][0]);
		return i;
	}
	void quicksort(matrice* matrix, int st, int dr)
	{
		if (st < dr)
		{
			int poz_pivot = partitionare(matrix, st, dr);
			quicksort(matrix, st, poz_pivot - 1);
			quicksort(matrix, poz_pivot + 1, dr);
		}
	}
	void sortare_col_intai(matrice* matrix)
	{
		std::cout << "\nSortare:\n";
		if (matrix->n)
		{
			quicksort(matrix, 0, matrix->n - 1);
			return;
		}
		else
			std::cout << "Matrice nealocata ajunge in functia sortare\n";
		return;
	}
int main()
{
	matrice matrix;
	int n, m;
	std::cin >> n >> m;
	alocare(&matrix, n, m);
	citire(&matrix);
	dublare_linii_pare(&matrix);
	afisare(matrix);
	sortare_col_intai(&matrix);
	afisare(matrix);
	eliberare(&matrix);
	return 0;
}
