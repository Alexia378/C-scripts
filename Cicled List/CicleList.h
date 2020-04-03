#include <iostream>

const int MWORD=30;

struct Link{
    char word[MWORD];
    Link* next;
    Link* prev;
};
class LinkList{
private:
    Link* first;
    Link* last;

public:
    LinkList(){
        first=NULL;
        last=NULL;
    }

    ~LinkList(){
        while(first!=last){
            Link* temp=first;
            first=first->prev;
            delete temp;
        }
        delete last;
    }

    void pushback(char* str);

    void pushfront(char* str);

    void showList_front();

    void showList_back();

    char* popback();

    char* popfront();

    void deleteLink(Link* temp);

    Link* find_data(char* dt);

    void sortList();

    LinkList operator =(LinkList& 1);

    int howmany_links();

    void clear();
};