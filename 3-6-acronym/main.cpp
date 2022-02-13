#include <iostream>
#include <string>

using namespace std;

string acronym(string str){
    bool found = false;
    string result = "";
    for(size_t i=0;i<str.length();i++){
        char ch = str[i];
        if(isalpha(ch)){
            if(!found){
                found=true;
                result+=ch;
            }
        }else{
            found=false;
        }
    }
    return result;
}

int main()
{
    cout << acronym("asd213Adsa-Hello World!") << endl;
    return 0;
}
