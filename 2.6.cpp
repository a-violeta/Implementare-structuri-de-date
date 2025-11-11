/*
#include <iostream>
#include <stack>
#include <vector>

// Functie pentru a combina doua subvectori sortati
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Creeaza doua vectori temporari
    std::vector<int> L(n1), R(n2);

    // Copiaza datele in vectorii temporari L[] si R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // Combina vectorii temporari inapoi in arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copiaza elementele ramase din L[] sau R[], daca exista
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Functie pentru a implementa MergeSort iterativ
void mergeSort(std::vector<int>& arr) {
    int n = arr.size();
    int curr_size;

    // Start cu subvectori de dimensiune 1 si dubleaza dimensiunea la fiecare pas
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // Parcurge subvectorii
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = std::min(left_start + curr_size - 1, n - 1); // Determina mijlocul subvectorului
            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1); // Determina capatul drept al subvectorului
            merge(arr, left_start, mid, right_end); // Combina subvectorii sortati
        }
    }
}

int main() {
    // Citirea vectorului de la tastatura
    int n;
    std::cout << "Introduceti numarul de elemente din vector: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Introduceti elementele vectorului:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Sortarea vectorului folosind MergeSort iterativ
    mergeSort(arr);

    // Afisarea vectorului sortat
    std::cout << "Vectorul sortat este: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/
#include <iostream>
#include <stack>
void merge(int* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSortIterative(int* arr, int n) {
    std::stack<std::pair<int, int>> stk;
    stk.push(std::make_pair(0, n - 1));

    while (!stk.empty()) {
        int l = stk.top().first;
        int r = stk.top().second;
        stk.pop();

        if (l < r) {
            int m = l + (r - l) / 2;

            stk.push(std::make_pair(l, m));
            stk.push(std::make_pair(m + 1, r));

            merge(arr, l, m, r);
        }
    }
}
int main()
{
    int n, i;
    std::cout << "Introduceti numarul de elemente din vector: ";
    std::cin >> n;
    int* v = new int[n];
    std::cout << "Introduceti elementele vectorului:\n";
    for (i = 0; i < n; ++i)
        std::cin >> v[i];
    mergeSortIterative(v, n);
    std::cout << "\n";
    for (i = 0; i < n; ++i)
        std::cout << v[i] << " ";
    delete[] v;
    return 0;
}