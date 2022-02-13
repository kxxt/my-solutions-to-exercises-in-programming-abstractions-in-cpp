#include <iostream>
#include <string>

using namespace std;

string removeDoubledLetters(string str){
    int cur=0;
    while(cur+1<str.length()){
        if(str[cur]==str[cur+1]){
            str.erase(cur, 1);
            continue;
        }
        cur++;
    }
    return str;
}

int main()
{
    cout << removeDoubledLetters("bookkeeper") << endl;
    cout << removeDoubledLetters("committee") << endl;
    return 0;
}
