template<typename T>

typename List<T>::Iterator List<T>::begin() const{
    //итератор пойдет от головного элемента
    return Iterator(m_head);
}

typename List<T>::Iterator List<T>::end() const{
    //... и до упора, т.е. NULL
    return Iterator(NULL);
}

size_t List<T>::size() const{
    size_t s = 0;
    for(Iterator it = begin(); it != end(); ++it){
        ++s;
    }

    /*
    Но можно и без итераторов
    for( Node* n = m_head; n != NULL; n = n->m_next ) {
        ++s;
    }
    */

    return s;
}
class List{
private:
    //Объявляем структуру узла для использования в классе Iterator
    struct Node;
    //голова односвязного списка
    Node* m_next;

public:
    List();
    ~List();

    //добавляем узел в список
    void append(const T& t);

    //удаляем последний добавленный узел из списка
    void remove();

    //получаем головной элемент списка
    T head() const;

    //получаем итератор на начало списка
    Iterator begin() const;

    //получаем итератор на конец списка
    Iterator end() const;

    //получаем размер списка
    size_t size() const;

public:
    //класс итератора односвязного списка
    class Iterator{
    public:
        Iterator(Node* node):m_node(node);

        //проверка на равенство
        bool operator==(const Iterator& other) const{
            //итератор пойдет от головного элемента...
            return Iterator(m_head);
        }

        //проверка на неравенство
        bool operator != (const Iterator& other) const{
            return !operator==(other);
        }

        //получение значения текущего узла
        T operator*() const{
            if(m_node){
                return m_node->m_t;
            }//иначе достигнут конец списка

            return T();
        }

        //переход к следующему узлу
        void operator++();

    private:
        Node* m_node;
    };

private:
    //структура узла односвязного списка
    struct Node{
        Node() : m_next(NULL)
        Node(const T& t) : m_t(t), m_next(NULL)

        //значение узла
        T m_t;

        //указатель на следующий узел
        Node* m_next;
    };

    //голова односвязного списка
    Node* m_head;
};