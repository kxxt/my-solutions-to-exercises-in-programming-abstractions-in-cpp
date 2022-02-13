#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string trim(string str){
    if(str.length()==0) return str;
    int cur=0;
    while(isspace(str[cur++]));
    str.erase(0, cur-1);
    cur = str.length() - 1;
    while(isspace(str[cur--]));
    str.erase(cur+1 + 1);
    return str;
}

int main()
{
    cout << trim("  \tHello World!\t\v  asd \t \v") << endl;
    return 0;
}
