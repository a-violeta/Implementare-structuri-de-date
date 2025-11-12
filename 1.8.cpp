//mat, a) chenare, b) medie, c) piramida
#include <iostream>
#include <vector>

struct valori
{
	double min, max;
};

void rezolvare_b(int n, double** mat, std::vector<double> medie)
{
	int startLinie = 0, endLinie = n - 1, startColoana = 0, endColoana = n - 1, nr, i, j;
	double suma;
	while (startLinie <= endLinie && startColoana <= endColoana)
	{
		suma = 0;
		nr = 0;
		for (i = startColoana; i <= endColoana; ++i)
		{
			suma = suma + mat[startLinie][i];
			nr++;
		}
		startLinie++;
		for (i = startLinie; i <= endLinie; ++i)
		{
			suma = suma + mat[i][endColoana];
			nr++;
		}
		endColoana--;
		if (startLinie <= endLinie)
		{
			for (i = endColoana; i >= startColoana; --i)
			{
				suma = suma + mat[endLinie][i];
				nr++;
			}
			endLinie--;
		}
		if (startColoana <= endColoana)
		{
			for (i = endLinie; i >= startLinie; --i)
			{
				suma = suma + mat[i][startColoana];
				nr++;
			}
			startColoana++;
		}
		medie.emplace_back(suma / nr); //e double/nr
	}
	std::cout << "Mediile sunt:\n";
	for (const auto& it : medie)
		std::cout << it << " ";
}

int main()
{
	//std::vector<std::pair<double, double>> chenar; //first e min, second e max
	int n, m, i, j, k=0;
	std::cin >> n;
	valori* chenar=new valori[n/2+2]; //folosesc maxim n/2+1 spatii
	std::vector<double> medie;
	double** mat;
	mat = new double* [n];
	mat[0] = new double[n * n];
	for (i = 1; i < n; i++)
		mat[i] = mat[0] + n * i;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			std::cin >> mat[i][j];
	/*
	for (k = 0; k < (m + 1) / 2 && k < (n + 1) / 2; k++)
	{
		for (j = k; j < n - k; j++)
			sir[contor++] = mat[k][j];
		for (i = k + 1; i < m - k; i++)
			sir[contor++] = mat[i][n - k - 1];
		for (j = n - k - 2; j >= k && m - k - 1 != k; j--)
			sir[contor++] = mat[m - k - 1][j];
		for (i = m - k - 2; i > k && n - k - 1 != k; i--)
			sir[contor++] = mat[i][k];
	}
	*/
	int startLinie = 0, endLinie = n - 1, startColoana = 0, endColoana = n - 1, nr;
	double suma, min, max;
	for (k = 0; k <= (n + 1) / 2; k++)  //vreau sa ia si centrul piramidei
	{
		//suma = 0;
		//nr = 0;
		min = mat[startLinie][startColoana];
		max = mat[startLinie][startColoana];
		for (i = startColoana; i <= endColoana; ++i)
		{
			//suma=suma + mat[startLinie][i];
			//nr++;
			if (min > mat[startLinie][i])
				min = mat[startLinie][i];
			if (max < mat[startLinie][i])
				max = mat[startLinie][i];
		}
		startLinie++;
		for (i = startLinie; i <= endLinie; ++i)
		{
			//suma=suma+ mat[i][endColoana];
			//nr++;
			if (min > mat[i][endColoana])
				min = mat[i][endColoana];
			if (max < mat[i][endColoana])
				max = mat[i][endColoana];
		}
		endColoana--;
		if (startLinie <= endLinie)
		{
			for (i = endColoana; i >= startColoana; --i)
			{
				//suma=suma+ mat[endLinie][i];
				//nr++;
				if (min > mat[endLinie][i])
					min = mat[endLinie][i];
				if (max < mat[endLinie][i])
					max = mat[endLinie][i];
			}
			endLinie--;
		}
		if (startColoana <= endColoana)
		{
			for (i = endLinie; i >= startLinie; --i)
			{
				//suma=suma+ mat[i][startColoana];
				//nr++;
				if (min > mat[i][startColoana])
					min = mat[i][startColoana];
				if (max < mat[i][startColoana])
					max = mat[i][startColoana];
			}
			startColoana++;
		}
		//chenar.emplace_back(min, max);
		chenar[k].max = max;
		chenar[k].min = min;
		//medie.emplace_back(suma/nr); //e double/nr
	}
	//std::cout << "\n";
	//for (i = 0; i <= n / 2; i++)
		//std::cout << chenar[i].min << " " << chenar[i].max << "\n";
	std::cout << "\n";
	bool ok = 1;
	for (i=0; i<n/2; i++)
	{
		//std::cout << chenar[i].max << " " << chenar[i + 1].min << "\n";
		if (chenar[i].max >= chenar[i+1].min)
		{
			//std::cout << ok << "\n";
			ok = 0;
			break;
		}
	}
	if (ok)
		std::cout << "Piramida\n";
	else
		std::cout << "Nu e piramida\n";
	rezolvare_b(n, mat, medie);
	delete[] chenar;
	return 0;

}
