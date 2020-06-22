#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Задача - реализовать этот метод, можно добавлять любое количество других вспомогательных методов.
void getPlaces(int n, vector<string>& out)
{

}

int main()
{
    int n;
    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> n;
        fin.close();
    }

    vector<string> res;
    getPlaces(n, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size() - 1; i++)
        fout << res[i] << endl;
    fout << res[res.size() - 1];
    fout.close();
    return 0;
}