#include <iostream>
#include <vector>
using namespace std;

int valid(vector<int>& arr, int min_val, int k, int n)
{
    vector<int> next(2 * n + 2, 2 * n + 1);     // 2 * n + 1 be the infinite point
    // 2 * n be last end point (outside) from n - 1
    int sum = 0;
    for(int r = 0, l = 0; r < 2 * n; r++){
        sum += arr[r];
        while(l <= r && sum >= min_val){
            next[l] = r + 1;
            sum -= arr[l];
            l++;
        }
    }

    // Sparse Table
    const int MAXBIT = 21;
    vector<vector<int>> st(MAXBIT, vector<int>(2 * n + 2));     // n <= 2e5
    for(int i = 0; i < 2 * n + 2; i++)
        st[0][i] = next[i];
    for(int i = 1; i < MAXBIT; i++){
        for(int j = 0; j < 2 * n + 2; j++){
            st[i][j] = st[i - 1][st[i - 1][j]];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int jump = k, curr = i;     // Number of jump, current pos
        for(int j = MAXBIT - 1; j >= 0; j--){
            if(jump & (1 << j))
                curr = st[j][curr];
        }
        if(curr <= i + n)
            cnt++;
    }
    return cnt ? n - cnt : -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(2 * n); // Circular
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    
    int l = 1, r = 2e9 + 5;
    while(l < r){
        int mid = r - (r - l) / 2;
        int res = valid(arr, mid, k, n);
        if(res != -1) 
            l = mid;
        else 
            r = mid - 1;
    }
    cout << l << " " << valid(arr, l, k, n) << endl;
}
// binary search for the answer
// For normal array validation: one pass greedily divide
// For circular array: we should check all starting points form 0 - (n - 1)
// Sliding window to find first end points for all i
// sparse table for doubling