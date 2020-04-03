#include <iostream>
#include "ReadWriter.h"
#include "MergeSort.h"
//iostream, fstream включены в ReadWriter.h

//Не рекомендуется добавлять собственные вспомогательные классы и методы.
//Необходимо использовать уже имеющиеся классы и методы, добавив реализацию, соответствующую описанию.
using namespace std;

/*
 * i =l
 * j=m+1
 * for(k=l;k<=r;k++)
 * if(ai<aj)
 * {bk=ai;
 * i++}
 */
//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
void MergeSort::sort(int *arr, int length)
{
    if(length > 1)
        divide_and_merge(arr, 0, length - 1);
    return;
}

void MergeSort::merge(int* arr, int first, int second, int end)
{
    int* brr = new int[1000000];
    int k = 0;

    int _left = first;
    int _right = second + 1;

    while(end - first +1 != k)
    {
        if (_left > second)
            brr[k++] = arr[_right++];

        else if (_right > end)
            brr[k++] = arr[_left++];

        else if (arr[_left] > arr[_right])
            brr[k++] = arr[_right++];

        else brr[k++] = arr[_left++];
    }

    for (int i = 0; i < k; i++)
        arr[i + first] = brr[i];

    delete[] brr;
}

void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    if(right == left)
        return;
    else if(right - left ==1)
    {
        if(arr[right] < arr[left])
        {
            swap(arr[right], arr[left]);
            return;
        }
    }

    int middle = (left + right)/2;
    divide_and_merge(arr, left, middle);
    divide_and_merge(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read data from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}
