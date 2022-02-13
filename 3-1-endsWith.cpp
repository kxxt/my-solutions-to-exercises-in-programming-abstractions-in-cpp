#include <string>
#include <iostream>

bool endsWith(std::string str, std::string suffix)
{
    if (str.length() < suffix.length())
    {
        return false;
    }
    return str.substr(str.length() - suffix.length()) == suffix;
}

bool endsWith(std::string str, char suffix)
{
    if (str.length() < 1)
    {
        return false;
    }
    return str[str.length() - 1] == suffix;
}

int main()
{
    std::cout << endsWith("abc", "c") << std::endl;
    std::cout << endsWith("abc", "b") << std::endl;
    std::cout << endsWith("abc", 'a') << std::endl;
    std::cout << endsWith("abc", 'c') << std::endl;
    return 0;
}