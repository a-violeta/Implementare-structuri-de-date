//virus
//merge pe sandbox
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
bool isPermutation(const std::string& str1, const std::string& str2)
{
    if (str1.length() != str2.length())
        return false;
    std::unordered_map<char, int> charCount;
    // Incrementăm contorul pentru fiecare caracter din primul șir
    for (char c : str1)
        charCount[c]++;
    // Decrementăm contorul pentru fiecare caracter din al doilea șir
    for (char c : str2)
        charCount[c]--;
    // Verificăm dacă toate contoarele sunt zero
    for (const auto& pair : charCount)
        if (pair.second != 0)
        {
            std::cout << "Character '" << pair.first << "' appears " << pair.second << " times.\n";
            return false;
        }
    return true;
}
int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile)
    {
        std::cout << "Error opening file.\n";
        return 1;
    }
    std::string str1, str2;
    if (!(inputFile >> str1 >> str2))
    {
        std::cout << "Error reading strings from file.\n";
        return 1;
    }
    inputFile.close();
    if (isPermutation(str1, str2))
        std::cout << "Second string is a permutation of the first.\n";
    else
        std::cout << "Second string is not a permutation of the first.\n";
    return 0;
}