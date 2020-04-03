#include <iostream>

int main() {
    string s;
    getline(cin, s);
    int max = 0;    // Длина наибольшей грани
    for(int i = 1; i < s.length() && s.length() - i > max; i++) {
        int j = 0;
        /*
        Перебираем различные длины префиксов (суффиксов), пока не дойдем до длины 1 и пока можем встретить грань, длиннее хранящейся.
        i - первый символ очередного суффикса
        j - длина текущей грани и первый символ очередного префикса
        */
        while(j < s.length() - i && s.at(j) == s.at(i + j))  // Накапливаем длину, пока символы префикса и суффикса совпадают
            j++;
        if(j > max)  // Если длина текущей грани больше хранящейся, обновляем максимум
            max = j;
    }
    cout << max;
    return 0;
}