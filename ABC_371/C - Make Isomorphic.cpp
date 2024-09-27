#include <iostream>
#include <vector>
#include <climits>
#include <functional>
using namespace std;

int main()
{
    int n, m1, m2;
    cin >> n;
    cin >> m1;

    vector<vector<bool>> adj1(n, vector<bool>(n, false));
    vector<vector<bool>> adj2(n, vector<bool>(n, false));
    for(int i = 0; i < m1; i++){
        int u, v; 
        cin >> u >> v;
        adj1[v - 1][u - 1] = adj1[u - 1][v - 1] = true;
    }
    cin >> m2;
    for(int i = 0; i < m2; i++){
        int u, v; 
        cin >> u >> v;
        adj2[v - 1][u - 1] = adj2[u - 1][v - 1] = true;
    }

    vector<vector<int>> cost(n, vector<int>(n, false));
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int val;
            cin >> val;
            cost[i][j] = cost[j][i] = val;
        }
    }

    // Get the permutations
    vector<vector<int>> permutations;
    vector<int> cand(n);
    for(int i = 0; i < n; i++)
        cand[i] = i;

    function<void(int)> dfs = [&](int curr){
        if(curr == n) {
            permutations.push_back(cand);
            return;
        }
        for(int i = curr; i < n; i++){
            swap(cand[curr], cand[i]);
            dfs(curr + 1);
            swap(cand[curr], cand[i]);
        }
    };
    dfs(0);

    int min_cost = INT_MAX;
    for(auto& perm: permutations){
        int curr_cost = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(adj1[perm[i]][perm[j]] && !adj2[i][j]
                || !adj1[perm[i]][perm[j]] && adj2[i][j])
                    curr_cost += cost[i][j];
            }
        }
        min_cost = min(min_cost, curr_cost);
    }
    cout << min_cost << endl;
}