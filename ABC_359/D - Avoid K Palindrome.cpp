#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    // Let 0:'A', 1:'B' in bitmask
    // Get bitmasks for s[0:k-2]
    vector<int> masks{0};
    for(int i = 0; i < k - 1; i++){
        vector<int> new_masks;
        for(int& mask: masks){
            if(s[i] == '?' || s[i] == 'A')
                new_masks.push_back(mask << 1);
            if(s[i] == '?' || s[i] == 'B')
                new_masks.push_back((mask << 1) + 1);
        }
        masks = new_masks;
    }
    
    // Check palindrome for a bitmask
    auto is_palindrome = [](int mask, const int& k){
        string mask_s;
        for(int j = 0; j < k; j++){
            mask_s.push_back((mask & 1) + '0');
            mask >>= 1;
        }
        for(int j = 0; j < (k + 1) / 2; j++){
            if(mask_s[j] != mask_s[k - j - 1])
                return false;
        }
        return true;
    };

    // Initialization
    vector<int> dp(1 << k, 0);      // Last k bit
    for(int& mask: masks)
        dp[mask] = 1;

    // O(n * 2^k * k)
    const int MOD = 998244353;
    for(int i = k - 1; i < n; i++){
        vector<int> new_dp(1 << k, 0);
        for(int mask = 0; mask < (1 << k); mask++){
            if(!dp[mask]) continue;
            if(s[i] == '?' || s[i] == 'A'){
                int new_mask = (mask << 1) & ~(1 << k);
                if(!is_palindrome(new_mask, k)){
                    new_dp[new_mask] += dp[mask];
                    new_dp[new_mask] %= MOD;
                }
            }
            if(s[i] == '?' || s[i] == 'B'){
                int new_mask = ((mask << 1) & ~(1 << k)) | 1;
                if(!is_palindrome(new_mask, k)){
                    new_dp[new_mask] += dp[mask];
                    new_dp[new_mask] %= MOD;
                }
            }
            // cout << i << " " << bitset<4>(mask) << endl;
        }
        dp = new_dp;
    }

    int ans = 0;
    for(int& num: dp)
        ans = (ans + num) % MOD;
    cout << ans << endl;
}

// You are given a string S of length N consisting of characters A, B, and ?.

// You are also given a positive integer K. A string T consisting of A and B is considered a good string if it satisfies the following condition:
//  - No contiguous substring of length K in T is a palindrome.
// Let q be the number of ? characters in S. There are 2 ^ q strings that can be obtained by replacing each ? in 
// S with either A or B. Find how many of these strings are good strings.