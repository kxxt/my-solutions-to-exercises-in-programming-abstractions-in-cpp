#include <iostream>
#include <string>

using namespace std;



string encodeCaesarCipher(string str, int shift);
char shiftCharacter(char ch, int shift);
inline char shiftCharacterWithStartCharacter(char ch, char shift, char startChar);

int main()
{
    cout << encodeCaesarCipher("This is a secret message", 13) << endl;
    cout << encodeCaesarCipher("IBM 9000", -1) << endl;
    return 0;
}

string encodeCaesarCipher(string str, int shift){
    for(char& ch:str){
        ch = shiftCharacter(ch, shift);
    }
    return str;
}

char shiftCharacter(char ch, int shift){
    if(islower(ch)){
        return shiftCharacterWithStartCharacter(ch, shift, 'a');
    }else if (isupper(ch)){
        return shiftCharacterWithStartCharacter(ch, shift, 'A');
    }else return ch;
}

inline char shiftCharacterWithStartCharacter(char ch, char shift, char startChar) {
    int index, shifted;
    index = ch - (startChar);
    shifted = index + shift;
    while(shifted<0)shifted+=26;
    return (shifted%26) + (startChar);
}
