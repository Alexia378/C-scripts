#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1000;

void input(int *a, int size){
    for(int i = 0; i < size; ++i){
        cin >> a[i];
    }
}

void Sort(int *array, int size){
    int swap_counter = 0;
    for(int i = 1; i < size; ++i){
        for(int j = 1; j < size - i; ++j){
            if(array[j - 1] > array[j]){
                swap(array[j - 1], array[j]);
                swap_counter++;
            }
        }
    }
    cout << swap_counter;
}
int main() {
    int Array[MAX_SIZE], size;

    cout << "ENter size:\n";
    cin >> size;
    input(Array,size);
    Sort(Array,size);
    return 0;
}