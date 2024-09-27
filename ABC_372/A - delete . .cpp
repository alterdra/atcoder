#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = 0;
    for(int r = 0; r < s.size(); r++){
        if(s[r] != '.')
            s[l++] = s[r];
    }
    s.resize(l);
    cout << s << endl;
}