#include <iostream>
#include <vector>
#include <string>
using namespace std;

int is_abc(string& s, int start_idx){
    if(start_idx < 0 || start_idx + 2 >= s.size())
        return 0;
    return s[start_idx] == 'A' && s[start_idx + 1] == 'B' && s[start_idx + 2] == 'C';
}
int main()
{
    int n, q;
    string s;
    cin >> n >> q >> s;

    int total_abc_cnt = 0;
    for(int i = 0; i < n - 2; i++){
        if(s[i] == 'A'){
            total_abc_cnt += s[i + 1] == 'B' && s[i + 2] == 'C';
        }
    }
    for(int i = 0; i < q; i++){
        int pos;
        char ch;
        cin >> pos >> ch;
        pos--;
        int prev_abc_cnt = is_abc(s, pos - 2) + is_abc(s, pos - 1) + is_abc(s, pos);
        s[pos] = ch;
        int curr_abc_cnt = is_abc(s, pos - 2) + is_abc(s, pos - 1) + is_abc(s, pos);
        total_abc_cnt += curr_abc_cnt - prev_abc_cnt;
        cout << total_abc_cnt << endl;
    }
}