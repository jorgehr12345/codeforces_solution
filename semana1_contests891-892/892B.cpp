/* Jefferson*/
#include <bits/stdc++.h>
#define debug(x) cout << #x << ' = ' << x << endl
using namespace std;
using Long = long long;
/*
    Time complexity: O(n*m*d)
    Space complexity: O(n*m*d)
*/
int min_second(vector<int> &a) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (int num : a) {
        if (num <= min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    return min2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int INF = 1e9 + 7;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        int min_max = INF;
        vector<int> min_2;
        for (int j = 0; j < m; ++j) {
            int d;
            cin >> d;
            vector<int> v;
            Long mini = INF; // Inicializar con valor máximo
            for (int k = 0; k < d; ++k) {
                Long num;
                cin >> num;
                mini = min(mini, num);
                v.push_back(num);
            }
            if (min_max > mini) {
                min_max = mini;
            }
            min_2.push_back(min_second(v));
        }
        int tsec_min = INF;
        Long sum_sec_min = 0;
        for (int c : min_2) {
            sum_sec_min += c;
            tsec_min = min(tsec_min, c);
        }
        cout << min_max + sum_sec_min - tsec_min << "\n"; // Imprimir el mínimo para cada caso
    }

    return 0;
}