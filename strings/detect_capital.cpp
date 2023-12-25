#include <iostream>
bool detectCapitalUse(std::string word)
{
    bool isCapitalUseCorrect = false;
    bool frontLetterCapital = word.front() >= 'A' && word.front() <= 'Z';
    for (int i = 1; i < word.length(); i++)
    {
        if (frontLetterCapital)
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                isCapitalUseCorrect = true;
            }
            else if (word[i] >= 'A' && word[i] <= 'Z')
            {
                isCapitalUseCorrect = true;
                if (word[i + 1] >= 'a' && word[i + 1] <= 'z')
                {
                    isCapitalUseCorrect = false;
                }
            }
        }
        else
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                if (word[i + 1] >= 'A' && word[i + 1] <= 'Z')
                {
                    isCapitalUseCorrect = false;
                }
                else
                {
                    isCapitalUseCorrect = true;
                }
            }
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