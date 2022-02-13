#include <string>
#include <iostream>

using namespace std;

bool isSentencePalindrome(string str){
    auto l = str.begin(), r = str.end();
    while(l<r){
        while(!isalpha(*l))l++;
        while(!isalpha(*r))r--;
        if(tolower(*l)!=tolower(*r))return false;
        l++;r--;
    }
    return true;
}

int main()
{
    cout <<isSentencePalindrome("Madam, I'm Adam") << endl;
    cout <<isSentencePalindrome("A man, a plan, a canal -- Panama!") << endl;
    cout <<isSentencePalindrome("Not a palindrome") << endl;
    return 0;
}
