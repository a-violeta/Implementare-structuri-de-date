//lista dublu inlantuita cu functii si meniu
#include <iostream>
struct nod
{
    int info;
    nod* ant=nullptr;
    nod* urm=nullptr;
};

struct lista
{
    nod* primul=nullptr;
    nod* ultimul=nullptr;
    void push_front(int key) //merge
    {
        nod* nod_nou = new nod;
        nod_nou->info = key;
        nod_nou->urm = primul;
        if (primul != nullptr)
        {
            primul->ant = nod_nou;
            primul = nod_nou;
        }
        else
        {
            primul = nod_nou;
            ultimul = nod_nou;
        }
    }
    void push_back(int key) //merge
    {
        nod* nod_nou = new nod;
        nod_nou->info = key;
        nod_nou->ant = ultimul;
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
    void pop_front() //merge
    {
        if (primul != nullptr)
        {
            nod* nod_suplimentar = new nod;
            nod_suplimentar= primul;
            primul = primul->urm;
            if (primul != nullptr)
                primul->ant = nullptr;
            delete nod_suplimentar;
        }
        else
        {
            std::cerr << "Eroare: Lista este goalã. Nu se poate elimina primul nod.\n";
            return;
        }
    }
    void pop_back() //merge
    {
        if (ultimul != nullptr)
        {
            nod* nod_suplimentar = ultimul;
            if (ultimul != nullptr)
            {
                ultimul = ultimul->ant;
                ultimul->urm = nullptr;
            }
            delete nod_suplimentar;
        }
    }
    nod* find(int key) //merge
    {
        if (primul != nullptr)
        {
            nod* nod_cautat = primul;
            if (nod_cautat->info == key)
                return primul;
            else
            {
                while (nod_cautat != nullptr && nod_cautat->info != key) //adica are ceva in lista si nu se duce mai departe de ultimul
                    nod_cautat = nod_cautat->urm;
                return nod_cautat; //returnez un pointer care nu era in lista
            }
        }
    }
    void erase(nod* nod_de_sters)
    {
        if (nod_de_sters != nullptr)
        {
            if (nod_de_sters == primul)
            {
                pop_front();
                return;
            }
            if (nod_de_sters == ultimul)
            {
                pop_back();
                return;
            }
            nod_de_sters->ant->urm = nod_de_sters->urm;
            nod_de_sters->urm->ant = nod_de_sters->ant;
            delete nod_de_sters;
        }
    }
    void remove(int key)
    {
        nod* nod_cautat=find(key);
        while (nod_cautat != nullptr)
        {
            erase(nod_cautat);
            nod_cautat = find(key);
        }
        delete nod_cautat;
    }
    void insert(nod* nod_succesor, int val)
    {
        if (nod_succesor != nullptr)
        {
            nod* nod_nou = new nod;
            nod_nou->info = val;

            // Actualizãm legãturile pentru noul nod
            nod_nou->ant = nod_succesor->ant;
            nod_nou->urm = nod_succesor;

            // Verificãm dacã nodul succesor este primul nod al listei
            if (nod_succesor == primul)
            {
                primul = nod_nou; // Actualizãm primul nod al listei
            }
            else
            {
                nod_succesor->ant->urm = nod_nou; // Actualizãm legãtura urmãtoare pentru nodul anterior
            }

            nod_succesor->ant = nod_nou; // Actualizãm legãtura anterioarã pentru nodul succesor
        }
    }
    bool empty() //merge
    {
        if (primul == nullptr)
            return 0;
        return 1;
    }
    void clear() //merge
    {
        while(primul!=nullptr)
            pop_front();
    }
    void print() //merge sper
    {
        nod* nod_suplimentar = primul;
        while (nod_suplimentar != nullptr)
        {
            std::cout << nod_suplimentar->info << " ";
            nod_suplimentar = nod_suplimentar->urm;
        }
    }
    int size()  //merge
    {
        int nr = 0;
        nod* nod_suplimentar = primul;
        while (nod_suplimentar != nullptr)
        {
            nr++;
            nod_suplimentar = nod_suplimentar->urm;
        }
        delete nod_suplimentar;
        return nr;
    }
};
bool palindrom(lista l1) //merge
{
    int nr = 0, marime=l1.size();
    nod* nod1 = l1.primul;
    nod* nod2 = l1.ultimul;
    if (l1.primul != nullptr)
    {
        while (nod1!=nullptr && nod2!=nullptr && nod1->info == nod2->info)  //parcurge tot, nu doar jumate
        {
            nod1 = nod1->urm;
            nod2 = nod2->ant;
            nr++;
        }
    }
    delete nod1;
    delete nod2;
    if (nr < marime)
        return 0;
    return 1;
}
bool compare(lista l1, lista l2) //merge
{
    if (l1.size() != l2.size())
        return 0;
    int nr = 0;
    nod* nod1 = l1.primul;
    nod* nod2 = l2.primul;
    while (nod1!=nullptr && nod2!=nullptr && nod1->info == nod2->info)
    {
        nod1 = nod1->urm;
        nod2 = nod2->urm;
        nr++;
    }
    delete nod1;
    delete nod2;
    if (nr < l1.size())
        return 0;
    return 1;
}
int main()
{
    int choice, key;  //am initializari si in case uri
    lista l1, l2;
    bool ok = 1;
    while (ok)
    {
        std::cout << "Meniu:\n";
        std::cout << "1. Push front\n";
        std::cout << "2. Push back\n";
        std::cout << "3. Pop front\n";
        std::cout << "4. Pop back\n";
        std::cout << "5. Find\n";
        std::cout << "6. Erase\n";
        std::cout << "7. Remove\n";
        std::cout << "8. Insert\n";
        std::cout << "9. Empty\n";
        std::cout << "10. Clear\n";
        std::cout << "11. Print\n";
        std::cout << "12. Size\n";
        std::cout << "13. Palindrom\n";
        std::cout << "14. Compare\n";
        std::cout << "15. Exit\n";
        std::cout << "Select: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cin >> key;
            l1.push_front(key);
            std::cout << "\n";
            break;
        case 2:
            std::cin >> key;
            l1.push_back(key);
            std::cout << "\n";
            break;
        case 3:
            l1.pop_front();
            std::cout << "\n";
            break;
        case 4:
            l1.pop_back();
            std::cout << "\n";
            break;
        case 5:
        {
            std::cin >> key;
            nod* nodul = l1.find(key);
            if (nodul != nullptr)
                std::cout << "A fost gasit\n";
            else
                std::cout << "Nu a fost gasit\n";
            std::cout << "\n";
            break;
        }
        case 6:
        {
            std::cin >> key;
            nod* nodul = l1.find(key);
            if (nodul != nullptr)
                l1.erase(nodul);
            std::cout << "\n";
            break;
        }
        case 7:
            std::cin >> key;
            l1.remove(key);
            std::cout << "\n";
            break;
        case 8:
        {
            std::cin >> key; //insereaza dupa el dar trebuia inaintea
            nod* nodul = l1.find(key);
            if (nodul != nullptr)
            {
                int val;
                std::cin >> val;
                l1.insert(nodul, val);
            }
            std::cout << "\n";
            break;
        }
        case 9:
            std::cout<<l1.empty();
            std::cout << "\n";
            break;
        case 10:
            l1.clear();
            std::cout << "\n";
            break;
        case 11:
            l1.print();
            std::cout << "\n";
            break;
        case 12:
            std::cout<<l1.size();
            std::cout << "\n";
            break;
        case 13:
            std::cout<<palindrom(l1);
            std::cout << "\n";
            break;
        case 14:
            std::cout<<compare(l1, l2);
            std::cout << "\n";
            break;
        case 15:
            ok = 0;
            std::cout << "\n";
            break;
        default:
            std::cout << "Optiune invalida. Te rog sa alegi din nou.\n";
            break;
        }
    }
    return 0;

}
