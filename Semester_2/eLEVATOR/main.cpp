#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int countEvaluation (int n, int a, int b, int c)
{
    int eval = 1;
    vector<int> floors = vector<int>(n + 1, -1);
    floors[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        if (i - a >= 1 && floors[i - a] != -1)
        {
            floors[i] = 1;
            ++eval;
            continue;
        }
        if (i - b >= 1 && floors[i - b] != -1)
        {
            floors[i] = 1;
            ++eval;
            continue;
        }
        if (i - c >= 1 && floors[i - c] != -1)
        {
            floors[i] = 1;
            ++eval;
            continue;
        }
    }
    return eval;
}

int main()
{
    int n;
    int a, b, c, eval;
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n;
        fin >> a >> b >> c;

        fin.close();
    }

    eval = countEvaluation(n, a, b, c);
    fstream fout;
    fout.open("output.txt", ios::out);
    fout << eval;
    fout.close();
    return 0;
}