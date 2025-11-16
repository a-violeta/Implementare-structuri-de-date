//problema parantezarii rezolvata cu o stiva simulata prin 2 cozi stl
//citire string de la tastatura
//utilizare std::queue
//functionalitati:
//push(element) : Adaugă un element la sfârșitul cozii
//pop() : Elimină primul element din coadă
//front() : Returnează referința către primul element din coadă
//back() : Returnează referința către ultimul element din coadă
//empty() : Verifică dacă coada este goală
//size() : Returnează numărul de elemente din coadă

//std::list
//push_back(element) : Adaugă un element la sfârșitul listei
//push_front(element) : Adaugă un element la începutul listei
//pop_back() : Elimină ultimul element din listă
//pop_front() : Elimină primul element din listă
//insert(iterator, element) : Adaugă un element înaintea poziției indicată de iterator
//iterator e pointer la ceva din lista

//Iteratorul este o abstractizare a poziției din structura de date și poate fi văzut ca un pointer către un element din listă
//Astfel, nu este nevoie să transmitem elemente specifice din listă ca argument, ci doar poziția lor, indicată de iterator
//Pentru insert, iteratorul indică locul unde va fi inserat noul element înainte. Pentru erase, iteratorul indică elementul care trebuie eliminat
//Aceste funcții lucrează cu poziții în listă, iar iteratorii sunt utilizati pentru a specifica aceste poziții

//erase(iterator) : Elimină elementul de la poziția indicată de iterator
//begin() : Returnează un iterator către primul element al listei
//end() : Returnează un iterator către poziția următoare după ultimul element al listei
//size() : Returnează numărul de elemente din listă
//empty() : Verifică dacă lista este goală
//clear() : Elimină toate elementele din listă

//for (auto it = myList.begin(); it != myList.end(); ++it)
//    std::cout << *it << " ";

//for clasic, range based si folosind iteratori
//for (const auto& element : container)
    // Accesează elementul din container
//Acest tip de for permite itearea prin toate elementele containerului într-un mod mai ușor de citit și de gestionat
//Este folosit pentru a itera prin containeri care suportă iterația secvențială (listele sunt secventiale pt ca nu poti accesa direct un element), cum ar fi vectori, liste, seturi, map uri, etc
//for (auto it = container.begin(); it != container.end(); ++it)
//Acest tip de for utilizează iteratori pentru a itera prin container
//Este utilizat pentru toate tipurile de containeri și oferă un control mai mare asupra iterației, permițând manipularea explicită a iteratorilor
//Utilizarea auto în aceste contexte face codul mai ușor de citit și mai ușor de menținut, deoarece nu este nevoie să specifici manual tipurile, ci să lași compilatorul să le deducă
//Totuși, în anumite situații, specificarea tipului poate fi mai clară și poate oferi mai multă claritate în cod

#include <iostream>
#include <queue>
#include <string>

struct stiva
{
    std::queue<char> q1;
    std::queue<char> q2;
    void push(char c)
    {
        q1.push(c);
    }
    void pop()
    {
        // Mutăm elementele din q1 în q2, cu excepția ultimului element
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        // Eliminăm ultimul element din q1
        q1.pop();
        // Inversăm rolurile celor două cozi
        std::swap(q1, q2);
    }
    bool empty()
    {
        if (q1.empty() && q2.empty())
            return 1;
        return 0;
    }
};

bool paranteze_corecte(const std::string& sir, stiva s) //permite [] si {}
{
    char perechea;
    for (char c : sir)
    {
        if (c == '(')
            s.push(c);
        else
            if (c == '[')
            {
                if (!s.q1.empty()) //nu e goala
                    if (s.q1.back() != '{')
                        return false;
                s.push(c);
            }
            else
                if (c == '{')
                {
                    if (!s.q1.empty())
                        if (s.q1.back() == '(' || s.q1.front() == '[')
                            return false;
                    s.push(c);
                }
                else
                    if (c == ')')  //avem o paranteza inchisa si cautam daca are corespondent
                    {
                        if (s.empty())
                            return false;  // stiva goala si paranteza deschisa
                        if (!s.q1.empty())
                            perechea = s.q1.back(); //speram sa fie perechea deschisa a parantezei inchise gasite
                        s.pop(); //o scot deja daca e buna
                        if (perechea != '(')
                            return false;  // Parantezele nu se potrivesc
                    }
                    else
                        if (c == ']')
                        {
                            if (s.empty())
                                return false;
                            if (!s.q1.empty())
                                perechea = s.q1.back();
                            s.pop();
                            if (perechea != '[')
                                return false;
                        }
                        else
                            if (c == '}')
                            {
                                if (s.empty())
                                    return false;
                                if (!s.q1.empty())
                                    perechea = s.q1.back();
                                s.pop();
                                if (perechea != '{')
                                    return false;
                            }
                            else
                            {
                                std::cout << "Caracter invalid\n";
                                return false;
                            }
    }
    return s.empty();  // Stiva ar trebui să fie goală la sfârșit
}

int main()
{
    stiva s;
    std::string sir;
    std::cout << "Introduceti sirul de paranteze: ";
    std::getline(std::cin, sir);
    if (paranteze_corecte(sir, s))
        std::cout << "Sirul este corect parantezat.\n";
    else
        std::cout << "Sirul NU este corect parantezat.\n";
    return 0;
}

