//merge
//nu are functii
//mat si sume pe puncte cardinale
#include <iostream>
int main()
{
	int n, i, j, s_nord=0, s_sud=0, s_vest=0, s_est=0;
	std::cin >> n;
	int** mat = new int* [n];
	//mat[0] = new int[n*n];
	for (i = 0; i < n; i++)
		mat[i] = new int [n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			std::cin >> mat[i][j];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			if (i < j)
			{
				if (i + j < n - 1)
					s_nord = s_nord + mat[i][j];
				else
					if (i + j > n - 1)
						s_est = s_est + mat[i][j];
			}
			else
				if (i > j)
				{
					if (i + j < n - 1)
						s_vest = s_vest + mat[i][j];
					else
						if (i + j > n - 1)
							s_sud = s_sud + mat[i][j];
				}
		}
	//std::cout << s_nord << " " << s_sud << " " << s_vest << " " << s_est << "\n";
	if (std::max(std::max(s_nord, s_sud), std::max(s_vest, s_est)) == s_nord)
		std::cout << "\nMaximul este nord\n";
	if (std::max(std::max(s_nord, s_sud), std::max(s_vest, s_est)) == s_sud)
		std::cout << "\nMaximul este sud\n";
	if (std::max(std::max(s_nord, s_sud), std::max(s_vest, s_est)) == s_est)
		std::cout << "\nMaximul este est\n";
	if (std::max(std::max(s_nord, s_sud), std::max(s_vest, s_est)) == s_vest)
		std::cout << "\nMaximul este vest\n";
	for(i=0; i<n; i++)
	    delete[] mat[i];
	delete[] mat;
	return 0;
}