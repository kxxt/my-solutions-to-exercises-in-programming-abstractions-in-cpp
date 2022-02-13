#include <iostream>
#include <string>

using namespace std;

string substr(string str, size_t pos=0, size_t n=string::npos){
    if(pos>=str.length())throw invalid_argument("`pos` out of range.");
    if(str.length()-pos > n) str.erase(pos+n);
    str.erase(0, pos);
    return str;
}

int main(int argc, char *argv[])
{
    cout << substr("Hello World", 1, 4) <<endl;
    cout << substr("Hello World", 1) <<endl;
    cout << substr("Hello World", 1, 10) <<endl;
    cout << substr("Hello World", 1, 12) <<endl;
    cout << substr("Hello World", 6, 6) <<endl;
    return 0;
}
