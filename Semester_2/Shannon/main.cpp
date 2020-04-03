#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

class ShannonFano
{
private:
    vector<int> frequences;
    vector<string> codes;
    int sum;

private:
    pair<int,int> getDividePosition(int left, int right, int sum)
    {
        if (left == right - 1)
            return make_pair(-1, -1);

        int e = 0;
        double sumHalf = (double)sum / 2;

        for (int i = left; i < right; ++i)
        {
            if (abs(frequences[i] + e - sumHalf) >= abs(e - sumHalf))
                return make_pair(i - 1, e);
            else
                e += frequences[i];
        }
    }

    void writeCodeShannon(int left, int division, int right)
    {
        for (int i = left; i <= division; ++i)
            codes[i] += '0';
        for (int i = division + 1; i < right; ++i)
            codes[i] += '1';

    }

    void divide(int left, int division, int right, int sum_left, int sum_right)
    {
        writeCodeShannon(left, division, right);
        pair<int,int> pos;

        pos = getDividePosition(left, division + 1, sum_left);
        if (pos.first != -1)
            divide(left, pos.first, division + 1, pos.second, sum_left - pos.second);

        pos = getDividePosition(division + 1, right, sum_right);
        if (pos.first != -1)
            divide(division + 1, pos.first, right, pos.second, sum_right - pos.second);
    }

public:
    ShannonFano()
            : frequences(), codes() {
        sum = 0;
    }

    void build()
    {
        int n = frequences.size();
        pair<int, int> divisionParams = getDividePosition(0, n, sum);
        divide(0, divisionParams.first, n, divisionParams.second, sum - divisionParams.second);
    }

    void addChance (int chance)
    {
        frequences.push_back(chance);
        sum += chance;
        codes.emplace_back("");
    }

    string get (int i)
    {
        return codes[i];
    }
};


int main() {

    int n;
    auto * shf = new ShannonFano();

    fstream fin;
    fin.open("input.txt",ios::in);
    if(fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            fin >> x;
            shf->addChance (x);
        }

        fin.close();

        shf->build();

        fstream fout;
        fout.open("output.txt",ios::out);
        for (int i = 0; i < n; i++){
            fout <<shf->get(i) << (i==n-1?"":" ");
        }
        fout.close();

        delete shf;
    }
    return 0;
}