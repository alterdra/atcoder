#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    vector<int> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Online brute force: nlogn * q * k
    // Precompute: nlogn * k
    const int MAXK = 20;
    vector<vector<int>> top_k(n, vector<int>(MAXK, -1));
    function<void(int, int)> dfs = [&](int curr, int prev) {
        vector<int> merged_top_k{ x[curr] };
        for(int& next: adj[curr]){
            if(next == prev) 
                continue;
            dfs(next, curr);
            merged_top_k.insert(merged_top_k.end(), top_k[next].begin(), top_k[next].end());
        }
        sort(merged_top_k.rbegin(), merged_top_k.rend());
        for(int i = 0; i < min(int(merged_top_k.size()), MAXK); i++){
            top_k[curr][i] = merged_top_k[i];
        }
    };
    dfs(0, -1);

    for(int i = 0; i < q; i++){
        int v, k;
        cin >> v >> k;
        v--;
        k--;   
        cout << top_k[v][k] << endl;
    }
}