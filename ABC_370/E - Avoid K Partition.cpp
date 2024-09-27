#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    const int MOD = 998244353;

    // (prefix_sum, sum of dp[j] with prefix sum)
    unordered_map<long long, int> prefix_dict;
    prefix_dict[0] = 1;
    vector<long long> dp(n);
    long long prefix_sum = 0, dp_sum = 1;
    for(int i = 0; i < n; i++){
        prefix_sum += arr[i];
        dp[i] = (dp_sum - prefix_dict[prefix_sum - k] + MOD) % MOD;   // sum of dp[j] != k
        prefix_dict[prefix_sum] = (prefix_dict[prefix_sum] + dp[i]) % MOD;
        dp_sum = (dp_sum + dp[i]) % MOD;
    }
    cout << dp[n - 1] << endl;
}
/*
How many of these divisions have no subsequence whose elements sum to K
*/
// dp[i] += dp[j - 1] for sum(j, i) != k