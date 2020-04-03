#include <iostream>
#include "AnotherCicles.cpp"
using namespace std;
int main() {
    int tmp;
    char key;
    do
    {
        cout << rus("\nAuaa?eoa aaenoaea.\n1.Aiaaaeou yeaiaio\n2.Oaaeeou yeaiaio\n3.Iieacaou nienie\n4.Auoia");
        key = getch();
        switch(key)
        {
            case '1':
                cout << rus("\nAaaaeoa yeaiaio :");
                cin >> tmp;
                add(tmp);
                break;
            case '2':
                cout << rus("\nAaaaeoa iiia? yeaiaioa :");
                cin >> tmp;
                del(tmp);
                break;
            case '3':
                show();
                break;
        }
    } while(key != '4');
    return 0;
}