
#include "AnotherCicles.h"
#include <iostream>

using namespace std;

char *rus(const char *source) {
    char *res = new char[strlen(source)+1];
    CharToOemA(source, res);
    return res;
}

void add(int a)
{
    list *newlist = new list;
    newlist->data = a;
    if(last){
         newlist->next = last->next;
     last->next = newlist;
    } else
        newlist->next = newlist;

    last = newlist;
}

void del(int n) {
    list *temp = last;
    if(last == NULL) return;
    if(last->next != last)
    {
        while(temp->next != last && temp->next->data != n)
            temp = temp->next;
        if (temp->next->data == n)
        {
            if(temp->next == last)
                last = temp;
            list* delelem = temp->next;
            temp->next = temp->next->next;
            delete delelem;
        }
    }
    else if (last->data == n)
    {
        delete last;
        last = NULL;
    }
}

void show() {
    list *temp = last;
    cout<<endl;
    if(last == NULL)
    {
        cout << rus("\nNienie iono\n");
        return;
    }
    do {
        cout << rus("Yeaiaio ? ") << " " <<temp->next->data << endl;
        temp = temp->next;
    } while(temp != last);
}
