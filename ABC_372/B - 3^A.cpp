#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int m;
    cin >> m;

    vector<int> arr;
    int power = 0;
    while(m){
        int cnt = m % 3;
        for(int i = 0; i < cnt; i++)
            arr.push_back(power);
        power++;
        m /= 3;
    }
    cout << arr.size() << endl;
    for(int& num: arr)
        cout << num << " ";
    cout << endl;
}