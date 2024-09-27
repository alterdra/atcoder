#include <iostream>
#include <vector>
using namespace std;

int main(){

    long long n, k;
    cin >> n >> k;
    vector<int> a(n), x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i]; 
        x[i]--;
    }
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> sparse_table(65, vector<int>(n));    //1e18 <= 2^60
    for(int i = 0; i < n; i++) sparse_table[0][i] = x[i];
    for(int i = 1; i < 61; i++){
        for(int j = 0; j < n; j++){
            sparse_table[i][j] = sparse_table[i - 1][sparse_table[i - 1][j]];
        }
    }

    vector<int> b(n);
    for(int idx = 0; idx < n; idx++){
        int curr = idx;
        for(int i = 60; i >= 0; i--){
            if(k & (1LL << i)){
                curr = sparse_table[i][curr];
            }
        }
        b[idx] = a[curr];
        cout << b[idx] << ' ';
    }
    cout << '\n';
}