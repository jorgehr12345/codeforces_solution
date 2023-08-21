#include <bits/stdc++.h>
using namespace std;
using Long = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a_current, a_before;
        bool different_values = false;
        vector<int> even, odd;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a_current;
            if (i != 0 and !different_values and a_current != a_before)
                different_values = true;
            if (a_current % 2 == 0) even.push_back(a_current);
            else odd.push_back(a_current);
            a_before = a_current;
        }
        if (different_values) {
            if (even.size() > 0 and odd.size() > 0) {
                cout << odd.size() << " " << even.size() << "\n";
                for (int i = 0; i < odd.size(); i++) cout << odd[i] << " ";
                cout << "\n";
                for (int i = 0; i < even.size(); i++) cout << even[i] << " ";
                cout << "\n";
            } else {
                int number_max = 0, max;
                string answer = "";
                if (even.size() > 0) {
                    max = *max_element(even.begin(), even.end());
                    for (int i = 0; i < even.size(); i++) {
                        if (even[i] != max) answer += to_string(even[i]) + " ";
                        else number_max++;
                    }
                    cout << even.size() - number_max << " " << number_max << "\n";
                    cout << answer << "\n";
                    while (number_max--) cout << max << " ";
                } else {
                    max = *max_element(odd.begin(), odd.end());
                    for (int i = 0; i < odd.size(); i++) {
                        if (odd[i] != max) answer += to_string(odd[i]) + " ";
                        else number_max++;
                    }
                    cout << odd.size() - number_max << " " << number_max << "\n";
                    cout << answer << "\n";
                    while (number_max--) cout << max << " ";
                }
                cout << "\n";
            }
        } else cout << "-1\n";
    }
    return 0;
}