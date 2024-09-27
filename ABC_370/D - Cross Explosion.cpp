#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, q;
    cin >> h >> w >> q;

    // Sorted containers
    vector<set<int>> rows(h), cols(w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            rows[i].insert(j);
            cols[j].insert(i);
        }
    } 

    auto erase = [&](int r, int c){
        rows[r].erase(c);
        cols[c].erase(r);
    };

    for(int i = 0; i < q; i++)
    {
        int r, c; cin >> r >> c;
        r--, c--;
        if(rows[r].count(c)){
            erase(r, c);
            continue;
        }

        auto it_right = rows[r].lower_bound(c);
        auto it_down = cols[c].lower_bound(r);
        if(rows[r].size() && it_right != rows[r].begin()) //left
            erase(r, *prev(it_right));
        if(it_right != rows[r].end())
            erase(r, *it_right);
        if(cols[c].size() && it_down != cols[c].begin())  //top
            erase(*prev(it_down), c);
        if(it_down != cols[c].end())
            erase(*it_down, c);
    }

    int ans = 0;
    for(int i = 0; i < h; i++)
        ans += rows[i].size();
    cout << ans << '\n';
}

// Destroy closet top, down, left, and right walls