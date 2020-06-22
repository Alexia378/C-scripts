#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

//getting values which are not overflowed
pair<size_t, size_t> getValues(size_t left, size_t count) {
    size_t temp = 1;

    for (size_t i = 0; i < count; ++i) {
        size_t last = temp;
        temp *= left;

        if (last != temp / left)
            return make_pair(last, i);
    }

    return make_pair(temp, count);
}

void writeNumber(fstream &fout, size_t &m, size_t x, size_t &pos) {
    if (++pos == m)
        fout << x + 1;
    else
        fout << x + 1 << " ";
}

void get(size_t n, size_t k, size_t m, size_t& pos, fstream& fout)
{
    pair<size_t, size_t > _pair = getValues(n, m);

    size_t N_pow_M = _pair.first;
    size_t M = _pair.second;

    for (int i = 0; i < (int)m - (int)M - 1; ++i) {
        if (i < 0)
            continue;

        writeNumber(fout, m, 0, pos);
    }
    --k;
    for (int i = (int)m - (int)M - 1; i < (int)m; ++i) {
        if (i < 0)
            continue;

        if (M == m)
            N_pow_M /= n;

        size_t xToWrite = (N_pow_M == 0) ? n : k / N_pow_M;
        writeNumber(fout, m, xToWrite, pos);

        // уменьшаем значние k
        k -= xToWrite * N_pow_M;

        // уменьшаем NpowM в N раз
        if (M != m)
            N_pow_M /= n;
    }
}

int main()
{
    size_t M, N, k;

    fstream fin("input.txt", ios::in);
    fstream fout("output.txt", ios::out);

    fin >> N >> M >> k;

    size_t position = 0;

    get(N, k, M, position, fout);
}