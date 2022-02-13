#include <iostream>
#include<string>

using namespace std;

string replaceAll(string str, string s1, string s2){
    int pos;
    while((pos=str.find(s1))!=string::npos){
        str.replace(pos, s1.length(), s2);
    }
    return str;
}

int main()
{
    cout << replaceAll("Hello WorldDSasdasd as dasd asdasd sdasdasd", "asd", "kxxt") << endl;
    return 0;
}
