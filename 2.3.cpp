//speram sa mearga si cu fisiere
//random number generator
//citire string din fisier
//coada ce are elevi ce dau examen in mai multe zile si fiecare are un timp aleatoriu pt examen
//elevii ramasi merg in fisier pt urmatoarea zi
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
std::ifstream fin("fis.in");
std::ofstream fout("fis.out");
struct nod
{
    char info[50];
    nod* urm = nullptr;
};
struct coada
{
    nod* primul = nullptr;
    nod* ultimul = nullptr;
    int nr_elem = 0;
    void push(char key[50])  //pare ok
    {
        nod* nod_nou = new nod;
        strcpy(nod_nou->info, key);
        if (ultimul != nullptr)
        {
            ultimul->urm = nod_nou;
            ultimul = nod_nou;
        }
        else
        {
            primul = nod_nou;
            ultimul = nod_nou;
        }
    }
    void pop() //pare ok
    {
        if (primul != nullptr)
        {
            nod* nod_suplimentar = primul;
            primul = primul->urm;
            delete nod_suplimentar;
            nr_elem--;
        }
    }
    char* front() {
        if (primul != nullptr)
            return primul->info;
        else
            return nullptr; // În cazul în care coada este goală
    }
    char* back() {
        if (ultimul != nullptr)
            return ultimul->info;
        else
            return nullptr; // În cazul în care coada este goală
    }
    bool empty() //merge
    {
        if (primul == nullptr)
            return 0;
        return 1;
    }
    void clear() //pare ok
    {
        while (primul != nullptr)
            pop();
        nr_elem = 0;
    }
    int size()  //pare ok
    {
        return nr_elem;
    }
};
int main()
{
    coada c;
    int t, n, i;
    if (!fin)
    {
        std::cerr << "Nu s-a putut deschide fisierul!" << std::endl;
        return 1;
    }
    fin >> t;
    fin >> n;
    fin.ignore();
    char nume[50];
    while (fin.getline(nume, 50))
        c.push(nume);
    fin.close();
    int nr;
    srand(time(nullptr)); // Inițializarea generatorului de numere aleatorii cu o valoare de timp
    while (c.size() && t)
    {
        //generez nr aleatoriu intre 5 si 15
        nr = rand() % 11 + 5; // Restul împărțirii la 11 și adăugarea lui 5, incepe de la 5
        t = t - nr;
        c.pop();
    }
    while(c.size())
    {
        fout << c.front() << "\n";
        c.pop();
    }
    fout.close();
    return 0;
}