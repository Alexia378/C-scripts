#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int Minimun(int del, int ins, int sub){
    return  (del = del < ins ? del : ins) < sub ? del : sub;
}

//Необходимо реализовать метод
//о алгоритме можно прочитать в источниках указанных в программе курса, или на странице курса в ЛМС или в презентациях к семинару.
int Wagner_Fischer(string& s, string& t)
{
    int m = s.length() + 1;
    int n = t.length() + 1;

    int d[m][n];

    d[0][0] = 0;
    for(int i = 1; i < m; i++)
        d[i][0] = d[i - 1][0] + 1;

    for(int j = 1; j < n; j++)
        d[0][j] = d[0][j - 1] + 1;

    for(int j = 1; j < n; j++){
        for(int i = 1; i < m; i++){
            if(s[i] == t[j])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = Minimun(d[i - 1][j] + 1,
                        d[i][j - 1] + 1,
                        d[i - 1][j - 1] + 1);

        }
    }

    return d[m - 1][n - 1];

}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main(int argc, const char * argv[])
{
    int n;
    fstream fin;
    fstream fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    if(fin.is_open()) {
        string N;
        getline(fin,N);
        n = atoi( N.c_str());
        for (int i = 0; i < n; i++) {
            string s;
            string t;

            //поменяла ввод, так как иначе s включал пробел
            fin >> s;
            fin >> t;
            fout << Wagner_Fischer(s, t) << (i == n-1 ? "" : " ");
        }
        fout.close();
        fin.close();
    }
    return 0;
}