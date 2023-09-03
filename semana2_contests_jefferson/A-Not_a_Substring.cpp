/*
A bracket sequence is a string consisting of characters '(' and/or ')'.
A regular bracket sequence is a bracket sequence that can be transformed
into a correct arithmetic expression by inserting characters '1' and '+'
between the original characters of the sequence. For example:

bracket sequences "()()" and "(())" are regular (they can be transformed
into "(1)+(1)" and "((1+1)+1)", respectively);
bracket sequences ")(", "(" and ")" are not regular.
You are given a bracket sequence s; let's define its length as n. Your
task is to find a regular bracket sequence t of length 2n such that s
does not occur in t as a contiguous substring, or report that there is no
such sequence.

Input
The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases.

The only line of each test case contains a string s
 (2≤|s|≤50
), consisting of characters "(" and/or ")".

Output
For each test case, print the answer to it. If there is no required regular
bracket sequence, print NO in a separate line. Otherwise, print YES in the
first line, and the required regular bracket sequence t itself in the
second line. If there are multiple answers — you may print any of them.

Example
inputCopy
4
)(
(()
()
))()
outputCopy
YES
(())
YES
()()()
NO
YES
()(()())

*/
#include <bits/stdc++.h>
#define debug(x) cout << #x << ' = ' << x << endl
using namespace std;
/*
    Time complexity: O(n^2)
    Space complexity: O(n)
*/
bool isOpened(char c) {
    if (c == '(') return true;
    else return false;
}
bool isBalanced(string &s) {
    stack<char> st;
    for (char c : s) {
        if (isOpened(c)) {
            st.push(c);
        } else {
            if (!st.empty()) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
void transformedRegular(string &s) {
    int n = s.size();
    stack<char> v;
    for (int j = 0; j < (n * 2) / 2; ++j) {
        v.push(')');
    }
    for (int j = 0; j < (n * 2) / 2; ++j) {
        v.push('(');
    }
    while (!v.empty()) {
        cout << v.top();
        v.pop();
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (isBalanced(s)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            transformedRegular(s);
        }
    }

    return 0;
}