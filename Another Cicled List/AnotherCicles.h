#include <windows.h>
#include <conio.h>

struct list{
    int data;
    list *next;
};

list *last = NULL;

char *rus(const char *source);
void add(int a);
void del(int n);
void show();