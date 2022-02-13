#include <iostream>

using namespace std;

// The `cipher` should be a 26-character uppercase string.
// The `str` should be uppercased.
string letterSubstitutionCipher(string str, string cipher);
void substituteCharacter(char& ch, const string& cipher);

int main()
{
    cout << letterSubstitutionCipher("WORKERS OF THE WORLD UNITE!", "QWERTYUIOPASDFGHJKLZXCVBNM") << endl;
    return 0;
}

string letterSubstitutionCipher(string str, string cipher){
    for(char& ch:str) if(isupper(ch))substituteCharacter(ch, cipher);
    return str;
}

void substituteCharacter(char& ch, const string& cipher){
    ch = cipher.at(ch-'A');
}
