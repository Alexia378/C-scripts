//
// Created by Alexandra(Student) on 22.11.2019.
//

#ifndef SEM_22_11_B_TREE_HPP
#define SEM_22_11_B_TREE_HPP

#include "BTree.h"

template<typename T>

template <class Value, class Key, class Node>
Node *BTree<T>::Search(T k)
{
    return (_node ==NULL)?NULL:_node->Search(k);
}

#endif //SEM_22_11_B_TREE_HPP
