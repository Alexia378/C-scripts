//
// Created by Alexandra(Student) on 15.11.2019.
//

#ifndef QWERTY_VECTOR_HPP
#define QWERTY_VECTOR_HPP

template<typename T>

class Vector{
public:
    typedef T value_type;
    typedef const T& ref_value_type;
    typedef const T& const_ref_type;

    T* _bend;

    Vector()
    {

    }

    ~Vector(){
        delete;
    }
    Vector operator [](size_t i)
    {

    }

    int size(Vector vec){

    }
};
#endif //QWERTY_VECTOR_HPP
