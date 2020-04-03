#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string AssembleLCS(string& x, string& y, vector<vector<int>>& LCS, int i, int j)
{
    if (LCS[i][j] == 0)
        return "";

    if (x[i - 1] == y[j - 1])
        return AssembleLCS(x, y, LCS, i-1, j-1) + x[i - 1];
    else
    {
        if (LCS[i-1][j] < LCS[i][j-1])
            return AssembleLCS(x, y, LCS, i, j-1);
        else
            return AssembleLCS(x, y, LCS, i-1, j);
    }
}


int getLCS(string& x, string& y)
{
    int x_leng = x.length() + 1;
    int y_leng = y.length() + 1;

    vector<vector<int>> LCS = vector<vector<int>>(x_leng, vector<int>(y_leng, 0));

    for (int i = 1; i < x_leng; ++i)
    {
        for (int j = 1; j < y_leng; ++j)
        {
            if (x[i-1] == y[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
        }
    }

    return AssembleLCS(x, y, LCS, x.length(), y.length()).length();
}


int main()
{
    string x;
    string y;
    int res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, x);
        getline(fin, y);
        fin.close();
    }

    res = getLCS(x, y);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}