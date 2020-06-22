#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

size_t position = 0;
size_t N, k;

fstream fin("input.txt", ios::in);
fstream fout("output.txt", ios::out);

pair<size_t, size_t> getValues(size_t n) {
    size_t N = n;
    size_t t = 1;

    for (size_t i = 0; i < N; ++i) {
        size_t last = t;
        t *= n;

        if (last != t / n)
            return make_pair(last, i);

        --n;
    }

    return make_pair(t, N);
}

void writeNum(size_t xToIncrement, size_t& m) {
    if (++position == m)
        fout << xToIncrement + 1;
    else
        fout << xToIncrement + 1 << " ";
}

void get()
{
    --k;

    pair<size_t, size_t > _pair = getValues(N);

    size_t power_m = _pair.first;
    size_t m = _pair.second;

    for (int i = 0; i < (int)N - (int)m - 1; ++i) {
        if (i < 0)
            continue;

        writeNum(0, N);
    }

    for (int i = (int)N - (int)m - 1; i < (int)N; ++i) {
        if (i < 0)
            continue;

        if (m == N)
            power_m /= (position + 1);

        size_t x = (power_m != 0) ? k / power_m : (position);

        writeNum(x, N);

        k -= x * power_m;

        if (m != N)
            power_m /= (position + 1);
    }
}

int main()
{
    fin >> N >> k;
    get();
}