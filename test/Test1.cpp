#include <iostream>

using namespace std;

int main() {
    string str1 = "abcde";
    cout << str1.append("fgh") << endl;
    char *p = &str1[0];
    cout << *++p << endl;
}