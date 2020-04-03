#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 31;


int getMax(vector<float> k)
{
    int maximum = -1;
    int ind = -1;
    for (int i = 0; i < k.size(); ++i)
        if (k[i] > maximum)
        {
            ind = i;
            maximum = k[i];
        }

    return maximum;
}

int getMin(vector<float> k)
{
    int minimum = 1000000000;
    int ind = -1;

    for (int i = 0; i < k.size(); ++i)
        if (k[i] < minimum)
        {
            ind = i;
            minimum = k[i];
        }

    return ind;
}

int countMinSum(int seconds, vector<int>& values)
{
    int count = 0;
    vector<float> k;

    for (int i = 0; i < values.size(); ++i)
        k.push_back(pow(2, i) / values[i]);

    while(seconds > 0){
        seconds-=values[getMin(k)];
        count+=pow(2,getMin(k));

        if(seconds-values[getMin(k)] < 0)
            k[getMin(k)] +=getMax(k);
    }
    return count;
}

int main()
{
    vector<int> values;
    int value = 0, seconds = 0;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> seconds;
        for (int i = 0; i < N; i++)
        {
            fin>>value;
            values.push_back(value);
        }
        fin.close();
    }

    int res = countMinSum(seconds, values);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}