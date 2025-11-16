#include <iostream>
#include <vector>

// Definirea unei matrice folosind std::vector
using Matrice = std::vector<std::vector<int>>;

// Funcție pentru a crea o matrice și a inițializa dimensiunile acesteia
Matrice creare_matrice(int linii, int coloane) {
    return Matrice(linii, std::vector<int>(coloane));
}

// Funcție pentru a initializa matricea cu valori date de utilizator
void initializare_matrice(Matrice& matrice) {
    int linii = matrice.size();
    int coloane = matrice[0].size();

    std::cout << "Introduceti elementele matricei:\n";
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < coloane; ++j) {
            std::cin >> matrice[i][j];
        }
    }
}

// Funcție pentru a afișa matricea
void afisare_matrice(const Matrice& matrice) {
    int linii = matrice.size();
    int coloane = matrice[0].size();

    std::cout << "Matricea:\n";
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < coloane; ++j) {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int linii, coloane;
    std::cout << "Introduceti numarul de linii si coloane ale matricei: ";
    std::cin >> linii >> coloane;

    // Creare matrice
    Matrice matrice = creare_matrice(linii, coloane);

    // Inițializare matrice
    initializare_matrice(matrice);

    // Afișare matrice
    afisare_matrice(matrice);

    return 0;
}
