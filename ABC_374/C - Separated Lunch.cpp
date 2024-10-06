#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dfs(vector<int>& nums, int i, int take_sum, int& total_sum){
    if(i == nums.size())
        return max(take_sum, total_sum - take_sum);
    return min(
        dfs(nums, i + 1, take_sum + nums[i], total_sum),
        dfs(nums, i + 1, take_sum, total_sum)
    );
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    int sum = 0;
    for(int& num: nums)
        sum += num;

    cout << dfs(nums, 0, 0, sum) << endl;
}