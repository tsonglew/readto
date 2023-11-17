
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("sample.txt");
    char ch;
    std::string pattern = "$ND$\n";
    std::string readPattern;
    int cnt = 0;

    // Check if file is successfully opened
    if (!file.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    // Read the file character by character until pattern is matched
    while (file.get(ch))
    {
        if (ch == pattern[cnt])
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        std::cout << ch;
        if (cnt == pattern.length())
        {
            break;
        }
    }

    // Close the file
    file.close();

    return 0;
}