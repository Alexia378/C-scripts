#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

int maximumArray(int *numbers, int array_size)
{
    int max = 0;
    for(int i=0;i<array_size;i++)
        if(max<numbers[i])
            max = numbers[i];

    return max;
}

int digit(int number, int i)
{
    int k = 0;
    for(int j = 1;j<=i;j++){
        k = number%10;
        number/=10;
    }

    return k;
}

// Функция цифровой сортировки
void radixSort(int *numbers, int array_size)
{
    int *B, exp = 1, max = maximumArray(numbers, array_size);

    B = (int*)malloc(array_size * sizeof(int));

    while(max / exp >0)
    {
        int C[256] = {0};
        for(int i=0;i<array_size;i++)
            C[numbers[i] / exp %256]++;

        for(int i=1; i<256; i++)
            C[i]+=C[i-1];

        for(int i=array_size-1; i>=0; i--)
            B[--C[numbers[i] / exp % 256]] = numbers[i];

        for(int i=0; i<array_size; i++)
            numbers[i] = B[i];

        exp *= 256;
    }

    delete[] B;
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    radixSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}

