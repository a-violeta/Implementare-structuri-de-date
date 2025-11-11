//merge pe sandbox
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
std::string longestPalindrome(const std::string& s)
{
    std::unordered_map<char, int> charCount;
    std::string result;
    // Numărăm numărul de apariții ale fiecărui caracter
    for (char c : s)
        charCount[c]++;
    // Verificăm dacă există mai multe caractere impare
    int oddCount = 0;
    for (const auto& pair : charCount)
        if (pair.second % 2 == 1)
        {
            oddCount++;
            if (oddCount > 1)
                return ""; // Nu putem forma palindrom
        }
    // Construim jumătatea stângă a palindromului
    for (const auto& pair : charCount)
        result += std::string(pair.second / 2, pair.first);
    // Identificăm caracterul central (dacă există)
    char oddChar = '\0';
    for (const auto& pair : charCount)
        if (pair.second % 2 == 1)
        {
            oddChar = pair.first;
            break;
        }
    // Construim palindromul adăugând caracterul central (dacă există)
    std::string palindrome = result;
    if (oddChar != '\0')
        palindrome += oddChar;
    // Adăugăm jumătatea dreaptă a palindromului (inversând jumătatea stângă)
    result += std::string(result.rbegin(), result.rend());
    return result;
}
int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile)
    {
        std::cout << "Error opening file.\n";
        return 1;
    }
    std::string input;
    if (!(inputFile >> input))
    {
        std::cout << "Error reading strings from file.\n";
        return 1;
    }
    inputFile.close();
    std::string palindrome = longestPalindrome(input);
    if (palindrome.empty())
        std::cout << "Unable to construct a palindrome.\n";
    else
        std::cout << "Longest palindrome: " << palindrome << "\n";
    return 0;
}