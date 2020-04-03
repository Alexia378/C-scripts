#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

//Основная задача - реализовать данный метод
//Можно изменить передачу параметров на ссылки (&)
//Можно добавлять любое количество любых вспомогательных методов, структур и классов
void getSubstrings(string& source, string& substring, vector<int>& res)
{
    vector<int> z;
    z.resize(substring.size());
    z[0] = 0;
    for (int i=1;i<z.size();++i) {
        int pos = z[i-1];
        while (pos > 0 && substring[pos] != substring[i])
            pos = z[pos-1];
        z[i] = pos + (substring[pos] == substring[i] ? 1 : 0);
    }

    int p = 0;

    for (int i=0; i<source.size(); ++i) {
        while (p > 0 && (p >= substring.size() || substring[p] != source[i]) )
            p = z[p-1];

        if (source[i] == substring[p])
            p++;

        if (p == substring.size())
            res.push_back(i - p + 1);
    }
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main()
{
	string t;
	string p;
	vector<int> res;

	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
	{
		getline(fin, t);
		getline(fin, p);
		fin.close();
	}

	getSubstrings(t, p, res);

	fstream fout;
	fout.open("output.txt", ios::out);
	fout << res.size() << "\n";
	for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
		fout << *i << "\n";
	fout.close();

	return 0;
}
