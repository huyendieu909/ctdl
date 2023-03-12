#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "ss";
    char a;
    cin >> a;
    int b = (int)(a)+3;
    cout << b;
    if (b > 'z') b -= 26,cout << "\n" <<(char)(b);
    else cout << "\n" << (char)(b);
}