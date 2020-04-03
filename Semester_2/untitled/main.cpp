#include <iostream>

using namespace std;

void merge(int* arr, int left, int right)
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
    merge(arr, left, middle);
    merge(arr, middle + 1, right);

    int* brr = new int[100];
    int k = 0;


    int _left = left;
    int _right = middle + 1;
    while(right - left +1 != k)
    {
        if (_left > middle)
            brr[k++] = arr[_right++];
        else if (_right > right)
            brr[k++] = arr[_left++];
        else if (arr[_left] > arr[_right])
            brr[k++] = arr[_right++];
        else brr[k++] = arr[_left++];

    }

    for (int i = 0; i < k; i++)
        arr[i + left] = brr[i];
}
int main() {

    int length;
    cin >> length;
    int* arr=new int[8];

    for(int i=0;i<length; i++)
        cin >> arr[i];

    if(length > 1)
    {
        merge(arr, 0, length-1);
    }

    cout << "Sorted array: ";
    for(int i=0;i<length; i++)
        cout << arr[i] << " ";
}