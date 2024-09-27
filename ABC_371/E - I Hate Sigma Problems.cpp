#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<long long> dp(n);
    unordered_map<int, int> last_pos;
    dp[0] = 1;
    last_pos[arr[0]] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + i - (last_pos.count(arr[i]) ? last_pos[arr[i]] : -1);
        last_pos[arr[i]] = i;
        // cout << dp[i] << endl;
    }

    cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
}
// Let dp[i] be sigma(f(j, i)) for j in 0 to i
// dp[i] = dp[i - 1] + 