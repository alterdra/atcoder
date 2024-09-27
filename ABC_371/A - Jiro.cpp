#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char ab, ac, bc;
    cin >> ab >> ac >> bc;
    char ans;
    if(ab == '>'){
        if(bc == '>') ans = 'B';
        else{
            if(ac == '>') ans = 'C';
            else ans = 'A';
        }
    } 
    else if(ab == '<'){
        if(bc == '<') ans = 'B';
        else{
            if(ac == '<') ans = 'C';
            else ans = 'A';
        }
    }
    cout << ans << endl;
}