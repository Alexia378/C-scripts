#include <iostream>
#include "CicleList.h"
#include <cstring>

void LinkList::pushback(char *str) {
        Link* newlink = new Link;
        strcpy(newlink ->word, str);

        if(first){
            newlink->prev = first;
            first ->next=newlink;
        } else
            last = newlink;

        newlink ->next = last;
        last ->prev = newlink;
        first = newlink;
    }

void LinkList::pushfront(char *str) {
    Link* newlink = new Link;
    strcpy(newlink ->word, str);

    if(last)
    {
        newlink ->next = last;
        last ->prev =  newlink;
    }

    else
        first = newlink;

    newlink ->prev = first;
    first ->next = newlink;
    last = newlink;
}

void LinkList::showList_front() {
    Link* temp = last;
    if(first)
        do
        {
            cout<<temp ->word<<endl;
            temp = temp ->next;
        } while(temp  != last);
}
void LinkList::showList_back() {
    Link* temp = first;
    if(first)
        do
        {
            cout<<temp ->word<<endl;
            temp = temp ->prev;
        } while(temp  != first);
}

char *LinkList::popback() {
    Link* temp = last;
    deleteLink(last);
    return temp ->word;
}

char *LinkList::popfront() {
    Link* temp = first;
    deleteLink(first);
    return temp ->word;
}

void LinkList::deleteLink(Link *temp) {
    if(first)                   //если в списке есть данные
    {
        if(temp ->next == temp)    //если в списке единственный элемент
        {
            first = NULL;
            last  = NULL;
        }
        else
        {
            if(temp == last)     //если эдемент на удаление последний
                last = last ->next;

            if(temp == first)     //если элемент на удаление первый
                first = first ->prev;

            (temp ->next) ->prev = temp ->prev;
            (temp ->prev) ->next = temp ->next;

            delete temp;
        }
    }
}

Link *LinkList::find_data(char *dt) {
    Link* temp = first;
    if(first)
        do
        {
            if(strcmp( dt, temp ->word) == 0)
                return temp;

            temp = temp ->prev;
        } while(temp  != first);

    temp = NULL;
    return temp;
}

void LinkList::sortList() {
    char tempdata[100];
    Link* temp1 = first;

    int n = howmany_links();

    for(int x = 0; x<n-1; x++)
    {
        Link* temp2 = temp1 ->prev;

        for(int i = x; i<n-1; i++)
        {
            if(strcmp(temp1 ->word, temp2 ->word) > 0)
            {
                strcpy(tempdata,temp2 ->word);
                strcpy(temp2 ->word,temp1 ->word);
                strcpy(temp1 ->word,tempdata);
            }

            temp2 = temp2 ->prev;
        }
        temp1 = temp1 ->prev;
    }
}

LinkList LinkList::operator=(LinkList& 1) {
if(l.first)
{
Link* temp = l.first;
do
{
pushfront( temp ->word);
temp = temp ->prev;
} while(temp  != l.first);
}

return *this;
}

int LinkList::howmany_links() {
    if(first)
    {
        Link* temp = first;
        int i = 0;
        do
        {
            temp = temp ->prev;
            i++;
        } while(temp  != first);

        return i;
    }
    else
        return 0;
}

void LinkList::clear() {
    while(first ->prev != last)
    {
        Link*temp = first ->prev;
        first = first ->prev;
        delete temp;
    }
    last = NULL;
    first = NULL;
}
