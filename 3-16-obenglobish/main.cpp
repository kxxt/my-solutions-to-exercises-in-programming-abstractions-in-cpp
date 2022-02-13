#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c){
    const char vowels[] = "aeiou";
    for(int i=0;i<5;i++){
        if(vowels[i]==c) return true;
    }
    return false;
}

string obenglobish(string word){
    bool insideVowels = false;
    string result = "";
    size_t cur=0;
    while(cur<word.length()){
        cout<< ".";
        auto ch = word[cur];
        if(isVowel(ch)){
            if(!insideVowels){
                insideVowels = true;
                if(ch!='e' || cur!=word.length()-1)result += "ob";
            }
        }else{
            insideVowels = false;
        }
        result+=ch;
        cur++;
    }
    return result;
}

int main() {
    while (true) {
        string word;
        cin >> word;
        if (word == "") break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
    return 0;
}
