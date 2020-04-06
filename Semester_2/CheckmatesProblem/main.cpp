#include "ReadWriter.h"
//string, iostream included in "ReadWriter.h"

using namespace std;

long long** s;
//Можно добавлять любые вспомогательные методы и классы для решения задачи.

long long countSolutions(int x, int y, int n, int m)
{
    if(x<0||y<0||m<=y||x>=n)
        return 0;
    if(s[x][y] !=-1)
        return s[x][y];
    if(x==0)
        return s[x][y]=y>=2?countSolutions(x+1, y-2,n,m):0;
    else if (x==1)
        return s[x][y]=y>=2?countSolutions(x+1, y-2,n,m)+
                countSolutions(x-1, y-2, n,m):0;
    if(y==0)
        return s[x][y] = x >= 2 ? countSolutions(x - 2, y + 1, n, m) : 0;
    else if(y == 1)
        return s[x][y] = x >= 2 ? countSolutions(x - 2, y - 1, n, m) +
                countSolutions(x - 2, y + 1, n, m) : 0;

    return s[x][y] = countSolutions(x + 1, y - 2, n, m) +
            countSolutions(x - 1, y - 2, n, m)
                     + countSolutions(x - 2, y - 1, n, m) +
                     countSolutions(x - 2, y + 1, n, m);
}

//Задача реализовать этот метод
//param N - количество строк (rows) доски
//param M - количество столбцов (columns) доски
//return - количество способов попасть в правый нижний угол доски (клетка N-1, M-1, если считать что первая клетка 0,0)
long long solve(int N, int M)
{
    s = new long long*[N];
    for(int i=0; i<N; ++i)
    {
        s[i]=new long long [M];
        for(int j=0;j<M;++j)
            s[i][j]=-1;
    }
    s[0][0] = 1;
    long long sol = countSolutions(N-1, M-1, N,M);
    for(int i=0;i<N;++i)
        delete[] s[i];
    delete[] s;
    return sol;
}

int main(int argc, const char * argv[])
{
    ReadWriter rw;

    int N = rw.readInt(); //количество строк (rows)
    int M = rw.readInt(); //количество столбцов (columns)
    //решение
    long long res = solve(N, M);
    //результат в файл
    rw.writeLongLong(res);

    return 0;
}