#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;


void heap_shift(int *numbers, int first, int second)
{
    int max;
    int completed = 0;

    while ((first * 2 <= second) && (!completed))
    {
        if ((first * 2 == second) || (numbers[first * 2] > numbers[first * 2 + 1]))
            max = first * 2;
        else
            max = first * 2 + 1;

        if (numbers[first] >= numbers[max])
            completed = 1;
        else
            {
            int temp = numbers[first];
            numbers[first] = numbers[max];
            numbers[max] = temp;

            first = max;
        }
    }
}

//Функция сортировки на куче
//Необходимо реализовать данную функцию.
//Результат должен быть в массиве numbers.
void heapSort(int *numbers, int array_size)
{
    for (int i = (array_size / 2) - 1; i > -1; i--)
        heap_shift(numbers, i, array_size - 1);

    for (int i = array_size - 1; i >= 1; i--)
    {
        int t = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = t;

        heap_shift(numbers, 0, i - 1);
    }
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
    heapSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}