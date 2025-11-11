//merge ok
//stiva stl pt parantezare corecta
//citire string de la tastatura
//std::stack
//push(element) : Adaugă un element in vârful stivei
//pop() : Elimină elementul din vârful stivei
//top() : Returnează referința către elementul din vârful stivei
//empty() : Verifică dacă stiva este goala
//size() : Returnează numărul de elemente din stivă
#include <iostream>
#include <stack>
#include <string>
bool paranteze_corecte(const std::string& sir) //permite [] si {}
{
    std::stack<char> stiva;        //pt {}
    char perechea;
    for (char c : sir)
    {
        if (c == '(')
            stiva.push(c);
        else
            if (c == '[')
            {
                if (!stiva.empty()) //nu e goala
                    if(stiva.top() != '{')
                        return false;
                stiva.push(c);
            }
            else
                if (c == '{')
                {
                    if (!stiva.empty())
                        if(stiva.top() == '(' || stiva.top() == '[')
                            return false;
                    stiva.push(c);
                }
                else
                    if (c == ')')  //avem o paranteza inchisa si cautam daca are corespondent
                    {
                        if (stiva.empty())
                            return false;  // stiva goala si paranteza deschisa
                        perechea = stiva.top(); //speram sa fie perechea deschisa a parantezei inchise gasite
                        stiva.pop(); //o scot deja daca e buna
                        if (perechea != '(')
                            return false;  // Parantezele nu se potrivesc
                    }
                    else
                        if (c == ']')
                        {
                            if (stiva.empty())
                                return false;
                            perechea = stiva.top();
                            stiva.pop();
                            if (perechea != '[')
                                return false;
                        }
                        else
                            if (c == '}')
                            {
                                if (stiva.empty())
                                    return false;
                                perechea = stiva.top();
                                stiva.pop();
                                if (perechea != '{')
                                    return false;
                            }
                            else
                            {
                                std::cout << "Caracter invalid\n";
                                return false;
                            }
    }
    return stiva.empty();  // Stiva ar trebui să fie goală la sfârșit
}
int main()
{
    std::string sir;
    std::cout << "Introduceti sirul de paranteze: ";
    std::getline(std::cin, sir);
    if (paranteze_corecte(sir))
        std::cout << "Sirul este corect parantezat.\n";
    else
        std::cout << "Sirul NU este corect parantezat.\n";
    return 0;
}
