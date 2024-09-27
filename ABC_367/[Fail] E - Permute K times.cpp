#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> a(n), x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i]; 
        x[i]--;
    }
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++){
        indegree[x[i]]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> group_ids(n, 0), ;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        int h = 0;
        while(heights[curr] != -1){
            heights[curr] = h++;
        }
        int size
    }
    for(int i = 0; i < n; i++){

    }

    vector<int> b(n);
    for(int i = 0; i < n; i++){
        int sz = group_size[group_ids[i]];
        b[i] = a[(ids[i] + k % sz) % sz];
        cout << b[i] << " ";
    }
    cout << '\n';

}