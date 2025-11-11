//merge
#include <iostream>
#include <vector>
// Functie pentru a face o transformare (down-heap) in jos pentru a mentine proprietatea de heap
void downHeap(std::vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Daca copilul stang este mai mare decat radacina
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Daca copilul drept este mai mare decat radacina
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // Daca cel mai mare element nu este radacina
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        // Apel recursiv pentru a face o transformare in jos
        downHeap(arr, n, largest);
    }
}
// Functie pentru a efectua algoritmul Heap-Sort
void heapSort(std::vector<int>& arr)
{
    int n = arr.size();
    // Construieste un heap (transforma vectorul in heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        downHeap(arr, n, i);
    // Extrage elemente din heap unul cate unul
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        // Aplica down-heap la radacina redusa
        downHeap(arr, i, 0);
    }
}
int main()
{
    std::vector<int> vec = { 12, 11, 13, 1334, 9, 3, 194, 5, 6, 7 };
    std::cout << "Vectorul initial: ";
    for (int num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    heapSort(vec);
    std::cout << "Vectorul sortat: ";
    for (int num : vec)
        std::cout << num << " ";
    std::cout << "\n";
    return 0;
}