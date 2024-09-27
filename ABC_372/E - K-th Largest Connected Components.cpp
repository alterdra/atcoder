#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_K 10

class DSU {
    public:
    vector<int> root;
    vector<vector<int>> groups;
    DSU(int n){
        root.resize(n);
        groups.resize(n);
        for(int i = 0; i < n; i++){
            root[i] = i;
            groups[i].push_back(i);
        }
    }
    int find_root(int x){
        if(root[x] == x) return x;
        return root[x] = find_root(root[x]);
    }
    void make_union(int x, int y){
        int rx = find_root(x);
        int ry = find_root(y);
        root[ry] = rx;

        if(rx != ry){
            groups[rx].insert(groups[rx].end(), groups[ry].begin(), groups[ry].end());
            groups[ry].clear();
            sort(groups[rx].rbegin(), groups[rx].rend());
            if(groups[rx].size() > MAX_K)
                groups[rx] = { groups[rx].begin(),  groups[rx].begin() + MAX_K};
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            u--, v--;
            dsu.make_union(u, v);
        }
        if(type == 2){
            int v, k;
            cin >> v >> k;
            v--;
            int root_v = dsu.find_root(v);
            // cout << "SIZE" << dsu.groups[root_v].size() << endl;
            if(k > dsu.groups[root_v].size())
                cout << -1 << endl;
            else
                cout << dsu.groups[root_v][k - 1] + 1 << endl;
        }
    }
}