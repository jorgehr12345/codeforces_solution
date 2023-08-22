#include <bits/stdc++.h>
using namespace std;
using Long = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, min_element_test = INT_MAX;
        cin >> n;
        vector<int> second_min(n);
        for (int i = 0; i < n; i++) {
            int m, min_element_vector = INT_MAX;
            cin >> m;
            while (m--) {
                int x;
                cin >> x;
                if (x < min_element_vector) {
                    second_min[i] = min_element_vector;
                    min_element_vector = x;
                } else if (x < second_min[i]) {
                    second_min[i] = x;
                }
            }
            if (min_element_vector < min_element_test) min_element_test = min_element_vector;
        }
        Long beauty = min_element_test - *min_element(second_min.begin(), second_min.end());
        for (int i = 0; i < n; i++) beauty += second_min[i];
        cout << beauty << "\n";
    }
    return 0;
}
