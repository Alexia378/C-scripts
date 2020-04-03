#include "ReadWriter.h"
//iostream, fstream, Student_and_Ski.h включены в ReadWriter.h
using namespace std;

//Можно создавать любое количество любых вспомогательных методов для решения задачи.
//Рекомендуется использовать имеющиеся классы Student и Ski для решения задачи.
void sortStudents(Student* students, int l, int r)
{
    int left = l;
    int right = r;

    int pivot = students[(left + right) / 2].id;

    while(left < right)
    {
        while(students[left].id < pivot)
            left++;

        while(students[right].id > pivot)
            right--;

        if(left <= right)
        {
            swap(students[left].id, students[right].id);

            left++;
            right--;
        }
    }

    if(l < right)
        sortStudents(students, l, right);

    if(left < r)
        sortStudents(students, left, r);
}
//Задача - реализовать этот метод.
//Ответ должен быть упорядочен по возрастанию номеров студентов(!), то есть их id.
//Ответы должны быть в этих же массивах.
void findPairs(Student* students, Ski* skis, int n)
{
    sortStudents(students, 0, n-1);

    for(int i = 0; i < n - 1; i++){


        int j = i;
        while(compare(students[i], skis[j]) != 0)
        {
            j++;
        }

        swap(skis[j], skis[i]);
    }
}

int main()
{
    ReadWriter rw;

    Student* students = nullptr;
    Ski* skis = nullptr;
    int n;

    //Read n from file
    n = rw.readInt();

    //Create arrays
    students = new Student[n];
    skis = new Ski[n];

    //read Students and Skis from file
    rw.readStudents(students, n);
    rw.readSkis(skis, n);

    //Find pairs
    findPairs(students, skis, n);

    //Write answer to file
    rw.writeStudentsAndSkis(students, skis, n);

    delete[] students;
    delete[] skis;
    return 0;
}
