#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insert_sort(int* numbers, int size){
    for(int i=0;i<size;i++){
        int temp = numbers[i];
        int j=i-1;
        while(numbers[j]>temp && j>=0){
            numbers[j+1]=numbers[j];
            j-=1;
        }
        numbers[j+1]=temp;
    }
}

int main() {

    int size;
    int* numbers;
    cin >> size;
    for(int i=0;i<size;i++){
        cin >> numbers[i];
    }

    insert_sort(numbers, size);
    for(int i=0; i<size ;i++)
        cout << numbers[i] << " ";
}