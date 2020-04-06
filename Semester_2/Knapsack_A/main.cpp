#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getMaxMoney(int n, int m, vector<int>& weights, vector<int>& prices)
{
    vector<vector<int>> knap = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= m; ++w)
        {
            if (w-weights[i-1] >= 0)
                knap[i][w] = max(knap[i-1][w], knap[i-1][w-weights[i-1]] + prices[i-1]);
            else
                knap[i][w] = knap[i-1][w];
        }
    }
    return knap[n][m];
}

int main()
{
    vector<int> weights = vector<int>();
    vector<int> prices = vector<int>();

    int n, m, x;
    int res;

    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            fin >> x;
            weights.push_back(x);
        }

        for (int i = 0; i < n; ++i)
        {
            fin >> x;
            prices.push_back(x);
        }
        fin.close();
    }
    res = getMaxMoney(n, m, weights, prices);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();
    return 0;
}