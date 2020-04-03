#include <string>
#include <vector>
#include <iostream>

using namespace std;

int longestBorder(const string& s) {
    int len = s.length();
    vector<int> prefixFunc(len);
    prefixFunc[0] = 0;

    int curBorderLen = 0;
    for (int i = 1; i < len; ++i) {
        while (curBorderLen > 0 && s[curBorderLen] != s[i])
            curBorderLen = prefixFunc[curBorderLen - 1];

        if (s[curBorderLen] == s[i])
            ++curBorderLen;

        prefixFunc[i] = curBorderLen;
    }

    return prefixFunc[len-1];
}

int main() {
    string s;
    cin >> s;
    cout << longestBorder(s) << endl;
}