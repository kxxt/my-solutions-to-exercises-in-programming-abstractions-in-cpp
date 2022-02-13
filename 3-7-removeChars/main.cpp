#include <iostream>
#include <string>

using namespace std;

void removeCharactersInPlace(string& str, string remove){
    size_t cur = 0;
    while(cur<str.length()){
        char ch = str[cur];
        bool shouldMoveNext = true;
        for(size_t i=0;i<remove.length();i++){
            if (ch==remove[i]) {
                str.erase(cur, 1);
                shouldMoveNext = false;
                break;
            }
        }
        if(shouldMoveNext) cur++;
    }
}

string removeCharacters(string str, string remove){
    removeCharactersInPlace(str, remove);
    return str;
}

int main()
{
    cout << removeCharacters("counterrevolutionaries", "aeiou") << endl;
    string str = "counterrevolutionaries";
    removeCharactersInPlace(str, "aeiou");
    cout << str <<  endl;
    return 0;
}
