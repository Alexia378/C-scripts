//
// Created by Alexandra(Student) on 22.11.2019.
//

#ifndef SEM_22_11_BTREE_H
#define SEM_22_11_BTREE_H

template<typename T>
class BTree{
    class Node{

        Node* parent;
        Node* left;
        Node* right;
        T key;
    };

protected:
    Node* _node;
    T _key;
    int elemNum;
    int* tree;
public:
    BTree(int n)
    {
        _node = new Node();
        this->tree;
        elemNum = n;
    }

    ~BTree()
    {
        _node= nullptr;
        delete[] tree;
    }

    Node* Search(T k);

    void traverse()
    {
        if (_node != NULL) _node->traverse();
    }

    void Sort(int n, int* tr)
    {
        for(int i=0;i<n; i++)
        {
            for(int j=i; j<n; j++)
            {

            }
        }
    }

};



#endif //SEM_22_11_BTREE_H
