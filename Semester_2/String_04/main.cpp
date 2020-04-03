#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<int> countChars(string &s)
{
    int n = s.length();
    vector<int> z(n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int main() {
    string input;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, input);
        fin.close();
    }

    res = countChars(input);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        fout << *i << "\n";
    fout.close();

    return 0;
}