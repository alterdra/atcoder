#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <cfloat>
#include <math.h>
#include <iomanip>
using namespace std;

double sqrt_dist(int r1, int c1, int r2, int c2){
    return sqrt((r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2));
}
int main()
{
    int n, move_speed, draw_speed;
    cin >> n >> move_speed >> draw_speed;
    vector<vector<int>> lines(n, vector<int>(4));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> lines[i][j];
        }
    }

    vector<int> perms(n);
    for(int i = 0; i < n; i++)
        perms[i] = i;

    function<double(int, int, int)> dfs = [&](int curr, int r, int c) -> double {
        if(curr == lines.size())
            return 0;
        double ans = DBL_MAX;
        for(int i = curr; i < lines.size(); i++){
            swap(perms[curr], perms[i]);
            vector<int>& pos = lines[perms[curr]];
            int r1 = pos[0], c1 = pos[1];
            int r2 = pos[2], c2 = pos[3];
            // From (r, c) to (r1, c1) than draw
            double move_time_1 = sqrt_dist(r, c, r1, c1) / move_speed;
            double move_time_2 = sqrt_dist(r, c, r2, c2) / move_speed;
            double draw_time = sqrt_dist(r1, c1, r2, c2) / draw_speed;
            double res1 = dfs(curr + 1, r2, c2) + move_time_1 + draw_time;
            double res2 = dfs(curr + 1, r1, c1) + move_time_2 + draw_time;
            ans = min({ans, res1, res2});
            swap(perms[curr], perms[i]);
        }
        return ans;
    };
    
    cout << setprecision(12) << dfs(0, 0, 0) << endl;
}