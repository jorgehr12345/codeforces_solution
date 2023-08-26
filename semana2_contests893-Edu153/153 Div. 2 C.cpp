//https://codeforces.com/contest/1860/problem/C
#include <bits/stdc++.h>
using namespace std;
using Long = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, min_num = INT_MAX, min_lucky = INT_MAX, ans = 0;
        cin >> n;
        while (n--) {
            cin >> x;
            if (x < min_num) min_num = x;
            else {
                if (x < min_lucky) {
                    min_lucky = x;
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
