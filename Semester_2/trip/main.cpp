#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Основная задача - реализовать данный метод
int countMaxCross(string& riverMap)
{
    int n = riverMap.length();
    vector<vector<int>> paths = vector<vector<int>>(2, vector<int>(n + 1, INT32_MAX));

    paths[0][0] = 0;
    paths[1][0] = 1;

    for (int i = 0; i < n; ++i)
    {
        switch (riverMap[i])
        {
            case 'B':
            {
                paths[0][i + 1] = min(paths[1][i] + 2, paths[0][i] + 1);
                paths[1][i + 1] = min(paths[1][i] + 1, paths[0][i] + 2);
                break;
            }
            case 'R':
            {
                paths[0][i + 1] = min(paths[1][i] + 1, paths[0][i]);
                paths[1][i + 1] = min(paths[1][i] + 1, paths[0][i] + 1);
                break;
            }
            case 'L':
            {
                paths[0][i + 1] = min(paths[1][i] + 1, paths[0][i] + 1);
                paths[1][i + 1] = min(paths[1][i], paths[0][i] + 1);
                break;
            }
            default:{ throw exception(); }
        }
    }

    return paths[1][n];
}


int main()
{
    string riverMap;
    int res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, riverMap);
        fin.close();
    }

    res = countMaxCross(riverMap);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}