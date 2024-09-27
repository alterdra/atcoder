#include <iostream>
#include <vector>
#include <stack>
#include <functional>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // next greater elements: Mono decreasing
    vector<int> next_greater(n, -1);
    stack<int> st;
    for(int i = 1; i < n; i++){
        while(st.size() && arr[i] > arr[st.top()]){
            next_greater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Depth for increasing sequence
    vector<int> depth(n, -1);
    function<int(int)> dfs = [&](int curr){
        if(curr == -1)
            return 0;
        if(depth[curr] != -1)
            return depth[curr];
        return depth[curr] = 1 + dfs(next_greater[curr]);
    };
    for(int i = 1; i < n; i++){
        dfs(i);
    }

    for(int i = 0; i < n - 1; i++){
        cout << depth[i + 1] << " ";
    }
    cout << 0 << endl;

}