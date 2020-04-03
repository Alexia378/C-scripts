#include<iostream>
#include<cstring>
#include<iomanip>
#include<stdio.h.>
#include<fstream>
#include <Windows.h>
#include "CicleList.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    LinkList li;
    char** mass = NULL;
    int mass_size=0;
    char menu;

    while(true)
    {
        cin.sync();
        cout<<"\nВыберите действие:"
            <<"\n1 - дополнить список"
            <<"\n2 - показать список(начиная с последнего звена)"
            <<"\n3 - удалить элемент из списка"
            <<"\n4 - копировать элементы списка в массив"
            <<"\n5 - сортировать список"
            <<"\n6 - найти элемент в списке"
            <<"\n7 - считывания данных из файла в список"
            <<"\n8 - сохранение списка в файл"
            <<"\n9 - очистить список"
            <<"\nВаш выбор: ";
        cin>>menu;
        switch(menu)
        {
            case '1':
            {
                char data[MWORD];
                cout<<"\nВведите данные:\n";
                cin>>data;
                li.pushfront(data);
                break;
            }
            case '2':
            {
                if(li.howmany_links() != 0)    //если список создан
                {
                    cout<<"\nCписок начиная с последнего звена: "<<endl;
                    li.showList_back();      //показать список
                }
                else
                    cout<<"\nСписок пуст"<<endl;
                break;
            }
            case '3':
            {
                char data[MWORD];
                if(li.howmany_links() != 0)
                {
                    cout<<"\nВведите данные которые хотите удалить"<<endl;
                    cin>>data;
                    Link* d = li.find_data(data);
                    if(d)
                        li.deleteLink(d);
                    else
                        cout<<"\nДанных нет в списке"<<endl;
                }
                else
                    cout<<"\nСписок пуст"<<endl;
                break;
            }
            case '4':
            {
                LinkList li2;
                li2 = li;
                if(mass)                   //удаление предыдущего массива
                    for(int i = 0; i<mass_size; i++ )
                        delete []mass;

                mass_size = li.howmany_links();
                if(mass_size)
                {
                    LinkList li2;
                    li2 = li;
                    mass = new char*[mass_size];
                    for(int i = 0; i<mass_size; i++)
                        mass[i] = new char[MWORD];

                    for(int i = 0; i<mass_size; i++)
                        strcpy(mass[i], li2.popfront());

                    for(int i = 0; i<mass_size; i++)
                        cout<<mass[i]<<"  ";
                }
                else
                    cout<<"\nСписок не создан"<<endl;
                break;
            }
            case '5':
            {
                li.sortlist();
                cout<<"\n";
                li.showList_back();
                break;
            }
            case '6':
            {
                char data[MWORD];
                cout<<"\nВведите данные которые необходимо найти"<<endl;
                cin>>data;
                if(li.find_data(data))
                    cout<<"\nДанные есть в списке"<<endl;
                else
                    cout<<"\nДанных нет в списке"<<endl;
                break;
            }
            case '7':
            {
                cin.sync();
                char adres[MWORD];
                char ch;
                char data[MWORD];

                cout<<"\nВведите адрес файла: ";
                cin>>adres;
                ifstream fail(adres);
                if(fail)
                    while(fail)
                    {
                        fail.get(ch);
                        int y = 0;
                        for ( ;isalpha((unsigned char)ch) && fail;  fail.get(ch))
                            data[y++] = ch;
                        data[y] = '';

                        if(y)
                            li.pushfront(data);
                    }
                else
                    cout<<"\nНевозможно открыть файл!\n";
                break;
            }
            case '8':
            {
                cin.sync();
                char adres[MWORD];
                LinkList li2;
                li2 = li;

                cout<<"\nВведите адрес файла: ";
                cin>>adres;
                ofstream fail(adres);
                for(int i = 0; i<li.howmany_links(); i++)
                    fail<<li2.popback()<<" ";
                break;
            }
            case '9':
            {
                li.clear();
                break;
            }

            case '0':
            {
                for(int i = 0; i<mass_size; i++ )
                    delete []mass;
                return 0;
            }
            default:
                cout<<"\nНеизвестное действие\n";
        }
    }

    return 0;
}