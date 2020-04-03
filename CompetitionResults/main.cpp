#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct results{
    int IDnumber;
    int mark;
};

bool cmp(results a, results b){
    if(a.mark==b.mark)
        return a.IDnumber < b.IDnumber;
    return a.mark > b.mark;
}
int main() {
    int amount;
    cin >> amount;

    vector <results> table(amount);

    for(int i = 0; i<amount; i++){
        int temp;
        int s_temp;
        cin >> temp >> s_temp;
        results struct_temp;
        struct_temp.IDnumber = temp;
        struct_temp.mark = s_temp;
        table[i] = struct_temp;
    }

    sort(table.begin(), table.end(),cmp);

    for(auto now : table){
        cout << now.IDnumber << " " << now.mark << endl;
    }
    return 0;
}