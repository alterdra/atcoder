#include <iostream>
#include <vector>
#include <climits>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n;
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
        cin >> pos[i];

    vector<pair<int, int>> pos_and_cnt(n);
    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        pos_and_cnt[i] = {pos[i], number};
    }
    sort(pos_and_cnt.begin(), pos_and_cnt.end());

    vector<long long> prefix(n + 1);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + pos_and_cnt[i].second;
    }

    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        int left_idx = lower_bound(pos_and_cnt.begin(), pos_and_cnt.end(), make_pair(l, 0)) - pos_and_cnt.begin();
        int right_idx = lower_bound(pos_and_cnt.begin(), pos_and_cnt.end(), make_pair(r + 1, 0)) - pos_and_cnt.begin();
        // cout << left_idx << " " << right_idx << endl;
        cout << prefix[right_idx] - prefix[left_idx] << endl;
    } 
}