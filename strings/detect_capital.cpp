#include <iostream>
bool detectCapitalUse(std::string word)
{
    bool isCapitalUseCorrect = false;
    for (int i = 0; i <= word.length(); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            isCapitalUseCorrect = true;
        }
        else if (word[0] >= 'A' && word[0] <= 'Z')
        {
            isCapitalUseCorrect = true;
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            isCapitalUseCorrect = false;
        }
    }
    return isCapitalUseCorrect;
}
int main()
{
    std::string s;
    std::cout << "Enter your word:"
              << "\n";
    std::cin >> s;
    std::cout << detectCapitalUse(s);
}