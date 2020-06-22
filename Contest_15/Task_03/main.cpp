#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

fstream fin("input.txt",ios::in);
fstream fout("output.txt",ios::out);

void sumElem(vector<int> &res)
{
    int sum = res[res.size() - 1];

    for (int i = res.size() - 2; i >=0; --i)
    {
        if (res[i] != 0)
        {
            --res[i];
            res[i + 1] = sum + 1;

            for (int j  = i + 2; j < res.size(); ++j)
                res[j] = 0;

            return;
        }

        sum +=  res[i];
    }
}

void writeVector(vector<int>& res)
{
    for(int i = 0; i < res.size() - 1; ++i)
        fout << res[i] << " ";

    fout << res[res.size() - 1];
}

void getVector(int n, int m, int k)
{
    --k;
    vector<int> res = vector<int>(m);
    res[0] = n;

    while (k != 0){
        sumElem(res);
        --k;
    }

    writeVector(res);
}

int main()
{
    int n, m, k;

    fin >> n >> m >> k;

    getVector(n, m, k);

    fin.close();
    fout.close();

    return 0;
}
