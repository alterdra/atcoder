#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> has_boy(n + 1, false);
    for(int i = 0; i < m; i++){
        int family;
        char gender;
        cin >> family >> gender;
        if(gender == 'M'){
            if(has_boy[family]) cout << "No";
            else{
                has_boy[family] = true;
                cout << "Yes";
            }
        }
        else cout << "No";
        cout << endl;
    }
}