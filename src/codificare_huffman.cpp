//codificare huffman
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
// Structura pentru un nod din arborele de codificare Huffman
struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    // Constructor pentru un nod intern
    HuffmanNode(int freq) : data('\0'), freq(freq), left(nullptr), right(nullptr) {}
    // Constructor pentru o frunză (caracter)
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};
// Comparator pentru prioritățile nodurilor (min-heap)
struct CompareNodes
{
    bool operator()(HuffmanNode* a, HuffmanNode* b) const
    {
        return a->freq > b->freq;
    }
};
// Funcție pentru citirea textului dintr-un fișier și calcularea frecvenței de apariție a fiecărui caracter
std::unordered_map<char, int> calculeazaFrecventa(const std::string& numeFisier)
{
    std::unordered_map<char, int> frecventa;
    std::ifstream fisier(numeFisier);
    if (!fisier.is_open())
    {
        std::cerr << "Eroare la deschiderea fisierului.\n";
        return frecventa;
    }
    char caracter;
    while (fisier >> std::noskipws >> caracter)
        frecventa[caracter]++;
    fisier.close();
    return frecventa;
}
// Funcție pentru construirea arborelui de codificare Huffman
HuffmanNode* construiesteArboreHuffman(const std::unordered_map<char, int>& frecventa)
{
    // Creare o coadă de priorități pentru nodurile arborelui Huffman
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> coadaPrioritati;
    // Adăugare noduri pentru fiecare caracter în coadă
    for (const auto& par : frecventa)
        coadaPrioritati.push(new HuffmanNode(par.first, par.second));
    // Construirea arborelui Huffman
    while (coadaPrioritati.size() > 1)
    {
        HuffmanNode* stanga = coadaPrioritati.top();
        coadaPrioritati.pop();
        HuffmanNode* dreapta = coadaPrioritati.top();
        coadaPrioritati.pop();
        HuffmanNode* radacina = new HuffmanNode(stanga->freq + dreapta->freq);
        radacina->left = stanga;
        radacina->right = dreapta;
        coadaPrioritati.push(radacina);
    }
    // Returnarea rădăcinii arborelui Huffman
    return coadaPrioritati.top();
}
// Funcție pentru construirea tabelei de codificare pe baza arborelui Huffman
void construiesteTabelaCodificare(HuffmanNode* radacina, const std::string& cod, std::unordered_map<char, std::string>& tabelaCodificare)
{
    if (radacina == nullptr) return;
    // Dacă nodul este o frunză, adaugă codul în tabelă
    if (radacina->left == nullptr && radacina->right == nullptr)
        tabelaCodificare[radacina->data] = cod;
    // Parcurge în continuare arborele pentru a construi codurile pentru fiecare caracter
    construiesteTabelaCodificare(radacina->left, cod + "0", tabelaCodificare);
    construiesteTabelaCodificare(radacina->right, cod + "1", tabelaCodificare);
}
// Funcție pentru codificarea textului utilizând tabela de codificare
std::string codificaText(const std::string& text, const std::unordered_map<char, std::string>& tabelaCodificare)
{
    std::string codificare;
    for (char caracter : text)
        codificare += tabelaCodificare.at(caracter);
    return codificare;
}
// Funcție pentru afișarea tabelului de codificare și codificarea textului
void afiseazaCodificare(const std::unordered_map<char, std::string>& tabelaCodificare, const std::string& codificare)
{
    std::cout << "Tabela de codificare:\n";
    for (const auto& pereche : tabelaCodificare)
        std::cout << "Caracter: " << pereche.first << ", Cod: " << pereche.second << "\n";
    std::cout << "\nTextul codificat:\n" << codificare << "\n";
}
// Funcție pentru eliberarea memoriei alocată pentru arborele Huffman
void elibereazaArbore(HuffmanNode* radacina)
{
    if (radacina == nullptr) return;
    elibereazaArbore(radacina->left);
    elibereazaArbore(radacina->right);
    delete radacina;
}
int main()
{
    // Citirea textului și calcularea frecvenței de apariție a fiecărui caracter
    std::unordered_map<char, int> frecventa = calculeazaFrecventa("text.txt");
    // Construirea arborelui de codificare Huffman
    HuffmanNode* radacina = construiesteArboreHuffman(frecventa);
    // Construirea tabelului de codificare pe baza arborelui Huffman
    std::unordered_map<char, std::string> tabelaCodificare;
    construiesteTabelaCodificare(radacina, "", tabelaCodificare);
    // Codificarea textului utilizând tabela de codificare
    std::ifstream fisier("text.txt");
    std::string text((std::istreambuf_iterator<char>(fisier)), std::istreambuf_iterator<char>());
    std::string codificare = codificaText(text, tabelaCodificare);
    // Afisarea tabelului de codificare și a textului codificat
    afiseazaCodificare(tabelaCodificare, codificare);
    // Eliberarea memoriei alocate pentru arborele Huffman
    elibereazaArbore(radacina);
    return 0;
}


//+----------------------------------+
//|     "pleosc pleosc pic poc"      |
//+----------+------------+----------+
//| caracter | algoritmul | chat gpt |
//+----------+------------+----------+
//|    ' '   |     100    |    101   |
//+----------+------------+----------+
//|    'p'   |     00     |   1101   |
//+----------+------------+----------+
//|    'l'   |     010    |   1111   |
//+----------+------------+----------+
//|    'e'   |     011    |   1110   |
//+----------+------------+----------+
//|    'o'   |     101    |    10    |
//+----------+------------+----------+
//|    'i'   |    1100    |     0    |
//+----------+------------+----------+
//|    'c'   |     111    |    100   |
//+----------+------------+----------+
//|    's'   |    1101    |   1100   |

//+----------+------------+----------+
