#include "ReadWriter.h"
//vector, string, iostream included in "ReadWriter.h"

using namespace std;

void rockWay(vector<int>& res, vector<vector<int>>& a, int* stones, int i, int j)
{
    if (a[i][j] == 0)
        return;

    if (a[i][j] == a[i-1][j])
        rockWay(res, a, stones, i-1, j);
    else
    {
        rockWay( res, a, stones, i-1, j-stones[i - 1]);
        res.push_back(stones[i - 1]);
    }
}

vector<vector<int>> getWeights(int n, int* stones, int w)
{
    vector<vector<int>> a = vector<vector<int>>(n + 1, vector<int>(w + 1, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < w + 1; ++j)
        {
            if (j - stones[i] <= 0)
                a[i + 1][j] = a[i][j];
            else
                a[i + 1][j] = max(a[i][j], a[i][j - stones[i]] + stones[i]);
        }
    }
    return a;
}

//Можно добавлять любые вспомогательные методы и классы для решения задачи.

//Задача реализовать этот метод
//param N - количество камней
//param M - ограничения на вес
//param stones - массив размера N, с весами камней
//param res - вектор результатов (вес камней, которые надо взять)
void solve(int N, int W, int* stones, vector<int>& res)
{
    res = vector<int>();
    vector<vector<int>> A = getWeights(N, stones, W);
    rockWay(res,A, stones, N, W);
}

int main(int argc, const char * argv[])
{
    ReadWriter rw;
    int N = rw.readInt(); //камни
    int W = rw.readInt(); //ограничения на вес
    int* arr = new int[N]; //имеющиеся камни
    rw.readArr(arr, N);

    //основной структурой выбран вектор, так как заранее неизвестно какое количество камней будет взято
    vector<int> res;
    //решаем задачу
    solve(N, W, arr, res);
    int sum = 0;
    for (int i = 0; i < res.size(); i++)
        sum += res.at(i);

    //записываем ответ в файл
    rw.writeInt(sum); //итоговый вес
    rw.writeInt(res.size()); //количество взятых камней
    rw.writeVector(res); //сами камни

    delete[] arr;
    return 0;
}