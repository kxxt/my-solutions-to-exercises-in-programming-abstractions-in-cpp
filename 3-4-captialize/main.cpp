#include <iostream>
#include <string>

using namespace std;

void captializeWord(string& str, size_t pos, size_t end){
    str[pos] = toupper(str[pos]);
    for(size_t i=pos+1;i<=end;i++){
        str[i]=tolower(str[i]);
    }
}

string captialize(string str){
    int pos = -1;
    for(size_t i=0;i<str.length();i++){
        if(isspace(str[i])||i==str.length()-1) {
            if(pos!=-1){
                captializeWord(str, pos, i);
                pos=-1;
            }
            continue;
        }
        if(pos==-1) pos = i;
    }
    return str;
}

int main()
{
    cout << captialize("hEllo WORrLd!") << endl;
    return 0;
}
