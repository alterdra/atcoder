#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <climits>
using namespace std;

int div_ceil(int x, int div){
    return (x + div - 1) / div;
}
int main()
{
    int n, budget;
    cin >> n >> budget;
    vector<vector<int>> processes(n, vector<int>(4, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++)
            cin >> processes[i][j];
    }

    // Find minimum cost with value1, cost1, value2, cost2
    auto min_cost = [](const int& value1, const int& cost1, const int& value2, const int& cost2, const int& target) -> long long {
        // A * x + B * y >= target
        // If x >= B or y >= A: we can interchange cost1 * B with cost2 * A
        long long process_cost = LLONG_MAX;
        for(int i = 0; i <= value2; i++){
            long long machine1_cost = 1LL * cost1 * i;
            long long machine2_cost = (target - value1 * i > 0) ? 
                1LL * cost2 * div_ceil(target - value1 * i, value2) : 0;
            process_cost = min(process_cost, machine1_cost + machine2_cost);
        }
        for(int i = 0; i <= value1; i++){
            long long machine2_cost = 1LL * cost2 * i;
            long long machine1_cost = (target - value2 * i > 0) ? 
                1LL * cost1 * div_ceil(target - value2 * i, value1) : 0;
            process_cost = min(process_cost, machine1_cost + machine2_cost);
        }
        return process_cost;
    };

    auto valid = [&](int target, long long curr_budget) -> bool {
        // If all process can have capacity >= target with budget
        for(auto& vec: processes){
            int value1 = vec[0], cost1 = vec[1];
            int value2 = vec[2], cost2 = vec[3];
            curr_budget -= min_cost(value1, cost1, value2, cost2, target);
        }
        return curr_budget >= 0;
    };

    int l = 0, r = INT_MAX;
    while(l < r){
        int mid = r - (r - l) / 2;
        if(valid(mid, budget)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}