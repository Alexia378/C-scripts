#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void dfs1(int v, vector<vector<bool>>& relations, vector<bool>& used, vector<int>& order)
{
    used[v] = true;
    for(size_t i = 0; i < relations.size(); ++i)
    {
        if(!used[i] && relations[v][i])
        {
            dfs1(i, relations, used, order);
        }
    }

    order.emplace_back(v);
}

void dfs2(int v, vector<vector<bool>>& relations, vector<bool>& used, vector<string>& component, vector<string>& names)
{
    used[v] = true;
    component.emplace_back(names[v]);
    for(size_t i = 0; i < relations.size(); ++i)
    {
        if(used[i] != true && relations[i][v])
        {
            dfs2(i, relations, used, component, names);
        }
    }
}

vector<vector<string>> getList(vector<string>& names, vector<vector<bool>>& relations)
{
    vector<vector<string>> result;
    vector<int> order;
    vector<bool> used(relations.size(), false);

    for(int i = 0; i < relations.size(); ++i)
    {
        if(used[i] == false)
            dfs1(i, relations, used, order);
    }
    used.assign(relations.size(), false);

    for (int i = relations.size() - 1; i >= 0; --i)
    {
        int v = order[i];
        if (!used[v])
        {
            vector<string> component;
            dfs2(order[i], relations, used, component, names);
            sort(component.begin(), component.end());
            result.emplace_back(component);
        }
    }
    sort(result.begin(), result.end(), [](vector<string> l, vector<string> r) { return l.front() < r.front(); });
    return result;
}

int main()
{
    vector<string> names = vector<string>();
    vector<vector<bool>> relations;
    int startIndex;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        string str = "";
        getline(fin, str);

        while (str != "#")
        {
            names.emplace_back(str.substr(str.find(' ') + 1));
            getline(fin, str);
        }

        relations = vector<vector<bool>>(names.size());

        for (int i = 0; i < names.size(); i++)
        {
            relations[i] = vector<bool>(names.size());
            for (int j = 0; j < names.size(); j++)
                relations[i][j] = false;
        }

        getline(fin, str);

        while (fin)
        {
            int a = stoi(str.substr(0, str.find(' '))) - 1;
            int b = stoi(str.substr(str.find(' '))) - 1;
            relations[a][b] = true;
            getline(fin, str);
        }

        fin.close();
    }

    vector<vector<string>> res = getList(names, relations);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            fout << res[i][j] << "\n";
        fout << "\n";
    }
    fout.close();

    return 0;
}