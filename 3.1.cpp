//merge
#include <iostream>
#include <list>
#include <utility>
#include <fstream>
// Structura pentru un nod din lista înlănțuită
struct Node
{
    int key;
    std::string value;
    Node(int k, const std::string& v) : key(k), value(v) {}
};
// Clasa pentru tabela de dispersie (hash table)
class HashTable
{
private:
    static const int tableSize = 10;
    std::list<Node> table[tableSize];
    // Funcție de dispersie simplă
    int hashFunction(int key)
    {
        // Acesta este un exemplu simplu de funcție de dispersie
        // Poți implementa una mai complexă, în funcție de nevoile tale
        return key % tableSize;
    }
public:
    // Metoda pentru adăugarea unui element în tabela de dispersie
    void insert(int key, const std::string& value)
    {
        int index = hashFunction(key);
        table[index].emplace_back(key, value);
    }
    // Metoda pentru căutarea unui element în tabela de dispersie
    std::string search(int key)
    {
        int index = hashFunction(key);
        for (const auto& node : table[index])
            if (node.key == key)
                return node.value;
        throw std::runtime_error("Element not found.");
    }
    // Metoda pentru parcurgerea și afișarea elementelor în tabela de dispersie
    void display()
    {
        for (int i = 0; i < tableSize; ++i)
        {
            std::cout << "Bucket " << i << ": ";
            for (const auto& node : table[i])
                std::cout << "(" << node.key << ", " << node.value << ") ";
            std::cout << "\n";
        }
    }
};
int main()
{
    HashTable ht;
    std::ifstream inputFile("input.txt"); // Deschidem fișierul pentru citire
    // Citim elementele din fișier și le inserăm în tabela de dispersie
    int key;
    std::string value;
    while (inputFile >> key >> value)
        ht.insert(key, value);
    inputFile.close(); // Închidem fișierul după ce am terminat de citit
    // Meniu pentru utilizator
    int choice;
    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Search element\n";
        std::cout << "2. Insert element\n";
        std::cout << "3. Display elements\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter key to search: ";
            std::cin >> key;
            try
            {
                std::cout << "Value: " << ht.search(key) << "\n";
            }
            catch (const std::runtime_error& e)
            {
                std::cout << e.what() << "\n";
            }
            break;
        }
        case 2:
        {
            std::cout << "Enter key and value to insert: ";
            std::cin >> key >> value;
            ht.insert(key, value);
            std::cout << "Element inserted successfully.\n";
            break;
        }
        case 3:
        {
            std::cout << "Displaying elements:\n";
            ht.display();
            break;
        }
        case 4:
        {
            std::cout << "Exiting program.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 4);
    return 0;
}