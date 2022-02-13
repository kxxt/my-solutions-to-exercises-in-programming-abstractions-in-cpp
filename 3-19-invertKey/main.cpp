#include <iostream>

using namespace std;

// The `cipher` should be a 26-character uppercase string.
// The `str` should be uppercased.
string letterSubstitutionCipher(string str, string cipher);
void substituteCharacter(char& ch, const string& cipher);
string invertKey(string cipher);

int main()
{
    string const key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string const encrypted = letterSubstitutionCipher("WORKERS OF THE WORLD UNITE!", key);
    cout << encrypted << endl;
    string const decryptKey = invertKey(key);
    cout << decryptKey << endl;
    string const decrypted = letterSubstitutionCipher(encrypted, decryptKey);
    cout << decrypted << endl;
    return 0;
}

string invertKey(string cipher){
    auto result = string(26, ' ');
    for(int i=0;i<26;i++){
        result[cipher[i]-'A'] = i + 'A';
    }
    return result;
}

string letterSubstitutionCipher(string str, string cipher){
    for(char& ch:str) if(isupper(ch))substituteCharacter(ch, cipher);
    return str;
}

void substituteCharacter(char& ch, const string& cipher){
    ch = cipher.at(ch-'A');
}
