#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int ans = s.size() == t.size() ? 0 : min(s.size(), t.size()) + 1;
    for(int i = 0; i < min(s.size(), t.size()); i++)
        if(s[i] != t[i]){
            ans = i + 1;
            break;
        }
    cout << ans << endl;
}