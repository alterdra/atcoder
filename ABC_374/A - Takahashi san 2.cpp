#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans = "No";
    int n = s.size();
    if(s.size() >= 3 && s[n - 3] == 's' && s[n - 2] == 'a' && s[n - 1] == 'n')
        ans = "Yes";
    cout << ans << endl;
}