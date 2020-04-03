#include <iostream>

using namespace std;

int* HuffmanCoding(int* arr, int n){
    int* b;
    int i, j;

    int* ans;

    for(int k = 0; arr < n;k++)
}
int main() {
    int* arr;
    int n;

    cin >> n;

    cout << "Enter arr: ";

    for(int i = 0;i<n;i++)
        cin >> arr[i];

    int* ans = HuffmanCoding(arr, n);

    for(int i = 0; i< n; i++)
        cout << ans[i] << endl;
}